#include "savior.h"

namespace s21 {

Savior::Savior(V3D_GL* gl_parent, QWidget *parent)
    : m_gl_parent_{gl_parent},
      m_gif_flag_{false}
      {

  setParent(gl_parent->parentWidget()->parentWidget()->parentWidget());
  setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  m_frame_ = m_gl_parent_->grabFramebuffer();
  setFixedSize(m_frame_.scaledToWidth(426).size());
  MoveWindow();
  SetLifeTimer();
  buffer_.open(QIODevice::WriteOnly);
}

Savior::~Savior() { m_gl_parent_ = nullptr;
                  }

void Savior::mousePressEvent(QMouseEvent *event) {
    close();
    QString window_title("Save File " + file_format_);
    QString fileName = QFileDialog::getSaveFileName(
        this, window_title, QDateTime::currentDateTime().toString(), file_format_);
    QFile * m_ptr_save_file_ = new QFile(fileName);
    if (!m_ptr_save_file_->open(QIODevice::WriteOnly)) {
      m_ptr_save_file_ = nullptr;
    } else {
      m_ptr_save_file_->write(buffer_.buffer());
      m_ptr_save_file_->close();
    }
};

void Savior::SetFormat(const int index) {
  switch (index) {
    case 1:
      SaveBmp();
      break;
    case 2:
      SaveGif();
      break;
    default:
      SaveJpeg();
      break;
  }
}

void Savior::SaveJpeg() {
    file_format_ = "Image (*.jpeg)";
    m_frame_.save(&buffer_, "JPEG");
    CloseBuffer();
}

void Savior::SaveBmp() {
    file_format_ = "Image (*.bmp)";
    m_frame_.save(&buffer_, "BMP");
    CloseBuffer();
}

void Savior::SaveGif() {
  file_format_ = "GIF Animation (*.gif)";
  m_gif_flag_ = true;
  GifToThread * gif_thread = new GifToThread(&buffer_);

  connect(gif_thread, SIGNAL(GetNewFrame()), this, SLOT(SendNewFrame()));
  connect(this, SIGNAL(NewFrame(QImage)), gif_thread, SLOT(AddFrame(QImage)));
  connect(gif_thread, SIGNAL(RecordDone()), this, SLOT(RecordGif()));
  connect(gif_thread, SIGNAL(SaveBuffer()), this, SIGNAL(SaveBuffer()));
  QThread * thread1 = new QThread;

  connect(gif_thread, SIGNAL(RecordDone()), thread1, SIGNAL(finished()));

  connect(thread1, SIGNAL(finished()), thread1, SLOT(quit()));
  connect(thread1, SIGNAL(finished()), gif_thread, SLOT(deleteLater()));
  connect(thread1, SIGNAL(finished()), thread1, SLOT(deleteLater()));
  connect(thread1, SIGNAL(started()), gif_thread, SLOT(StartRecord()));
  connect(thread1, SIGNAL(started()), this, SIGNAL(RecordStart()));
  gif_thread->moveToThread(thread1);
  thread1->start(QThread::NormalPriority);
}

void Savior::PrepearToSaveGif() {
    QMessageBox animation_ask;
    animation_ask.addButton(QMessageBox::Yes);
    animation_ask.addButton(QMessageBox::No);
    animation_ask.setWindowTitle("Анимация");
    animation_ask.setDetailedText("Во время стандартной анимации объект будет вращаться вокруг оси Х.");
    animation_ask.setInformativeText("Использовать при записи стандартную анимацию?");
}

void Savior::MoveWindow() {
    QRect rect = this->screen()->geometry();
    int x = (rect.width() - width()-50);
    int y = (rect.height() - height()-50);
    move(x, y);
}

void Savior::MakeBackground() {
  QLabel * lab = new QLabel(this);
  if (m_gif_flag_) {
    QMovie * m_anim_frame_ = new QMovie(&buffer_);
    m_anim_frame_->setScaledSize(this->size());
    lab->setMovie(m_anim_frame_);
    m_anim_frame_->start();
  } else {
    lab->setFixedSize(m_frame_.scaledToWidth(426).size());
    QPixmap pm;
    pm = pm.fromImage(m_frame_);
    lab->setPixmap(pm);
    lab->setScaledContents(true);
  }
}

void Savior::SetLifeTimer() {
    life_timer_ = new QTimer(this);
    life_timer_->setSingleShot(true);
    life_timer_->setInterval(3000);
    connect(life_timer_, SIGNAL(timeout()), this, SLOT(SwitchToPopup()));
}

void Savior::CloseBuffer() {
   buffer_.close();
   buffer_.open(QIODevice::ReadOnly);
   MakeBackground();
   show();
   life_timer_->start();
   emit RecordDone();
}

void Savior::RecordGif() {
    CloseBuffer();
}

void Savior::SwitchToPopup() {
      setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Popup);
      show();
}

void Savior::SendNewFrame() {
  emit NewFrame(m_gl_parent_->grabFramebuffer());
}

GifToThread::GifToThread(QBuffer * out_device) {
    device_ = out_device;
}

void GifToThread::SetDurationGif() {
    m_gif_timer_ = new QTimer(this);
    m_gif_timer_->setSingleShot(true);
    m_gif_timer_->setInterval(5000);
    connect(this, SIGNAL(destroyed()), m_gif_timer_, SLOT(deleteLater()));
    connect(m_gif_timer_, SIGNAL(timeout()), this, SLOT(RecordGif()));
}

void GifToThread::SetFrequencyFrame() {
    m_frame_timer_ = new QTimer(this);
    connect(this, SIGNAL(destroyed()), m_frame_timer_, SLOT(deleteLater()));
    connect(m_frame_timer_, SIGNAL(timeout()), this, SIGNAL(GetNewFrame()));
    connect(m_gif_timer_, SIGNAL(timeout()), m_frame_timer_, SLOT(stop()));
    m_frame_timer_->setInterval(30);
}

void GifToThread::StartRecord() {
    SetDurationGif();
    SetFrequencyFrame();
    m_frame_timer_->start();
    m_gif_timer_->start();
}

void GifToThread::AddFrame(QImage frame) {
    addFrame(frame, 30);
}

void GifToThread::RecordGif() {
    emit SaveBuffer();
    save(device_);
    emit RecordDone();
}

}  // namespace s21
