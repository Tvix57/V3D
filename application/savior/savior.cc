#include "savior.h"

namespace Tvix57 {

Savior::Savior(V3D_GL* gl_parent)
    : m_gl_parent_{gl_parent},
      m_timer_{nullptr},
      m_ptr_save_file_{nullptr},
      m_frameCounter_{0} {
  connect(this, SIGNAL(RecordDone()), this, SLOT(CloseSaveFile()));
}

Savior::~Savior() { m_gl_parent_ = nullptr; }
void Savior::SaveFile(const int index) {
  QString fileFormat;
  switch (index) {
    case 1:
      fileFormat = "Image (*.bmp)";
      break;
    case 2:
      fileFormat = "GIF Animation (*.gif)";
      break;
    default:
      fileFormat = "Image (*.jpeg)";
      break;
  }
  if (OpenFileToSave(fileFormat)) {
    if (index == 2) {
      SaveGif();
    } else {
      SaveImage();
    }
  }
}

const bool Savior::OpenFileToSave(QString fileFormat) {
  QString window_title = "Save File";
  window_title.append(" " + fileFormat);
  QString fileName = QFileDialog::getSaveFileName(
      m_gl_parent_, window_title, "/home/Users/home_*", fileFormat);
  m_ptr_save_file_ = new QFile(fileName);
  if (m_ptr_save_file_->open(QIODevice::WriteOnly)) {
    return true;
  } else {
    return false;
  }
}

void Savior::SaveImage() {
  m_gl_parent_->grabFramebuffer().save(m_ptr_save_file_);
  emit RecordDone();
}

void Savior::SaveGif() {
  m_gif_ = new QGifImage();
  m_frameCounter_ = 0;
  m_timer_ = new QTimer(this);
  connect(m_timer_, SIGNAL(timeout()), this, SLOT(RecordGif()));
  m_timer_->start(40);
  emit RecordStart();
}

void Savior::CloseSaveFile() {
  m_ptr_save_file_->close();
  delete m_ptr_save_file_;
  m_ptr_save_file_ = nullptr;
  emit SaveDone();
}

void Savior::RecordGif() {
  emit RotateObj((m_frameCounter_ * 6) % 360);
  ++m_frameCounter_;
  m_gif_->addFrame(m_gl_parent_->grabFramebuffer(), 100);
  if (m_frameCounter_ == 122) {
    m_timer_->stop();
    m_gif_->save(m_ptr_save_file_);
    delete m_gif_;
    m_gif_ = nullptr;
    emit RecordDone();
    emit RotateObj(0);
  }
}

}  // namespace Tvix57
