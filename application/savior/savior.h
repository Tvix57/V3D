#ifndef SAVIOR_H
#define SAVIOR_H

#include <QFileDialog>
#include <QObject>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include <QMovie>
#include <QLabel>
#include <QBuffer>
#include <QLayout>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>

#include "qgifimage.h"
#include "v3d_gl.h"

namespace s21 {

class Savior : public QWidget {
 Q_OBJECT
 public:
  explicit Savior(V3D_GL *, QWidget *parent = nullptr);
  ~Savior();
  void SetFormat(const int);

protected:
  virtual void mousePressEvent(QMouseEvent *event);

 private:
  void SaveJpeg();
  void SaveBmp();
  void SaveGif();
  void MakePreview();
  void PrepearToSaveGif();
  void MoveWindow();
  void MakeBackground();
  void SetLifeTimer();

  V3D_GL *m_gl_parent_;
  bool m_gif_flag_; /// заменить на указатель на функции
  QString file_format_;
  QImage m_frame_;
  QBuffer buffer_;
  QTimer *life_timer_;


 private slots:
  void CloseBuffer();
  void RecordGif();
  void SwitchToPopup();
  void SendNewFrame();

 signals:
  void RecordStart();
  void RecordDone();
  void RotateObj(int);
  void SaveBuffer();
  void NewFrame(QImage);
};


class GifToThread : public QObject, public QGifImage {
Q_OBJECT
public:
    GifToThread(QBuffer *);
//    ~GifToThread();
private:
    void SetDurationGif();
    void SetFrequencyFrame();

    QTimer *m_frame_timer_;
    QTimer *m_gif_timer_;
    int m_frameCounter_;
    QBuffer * device_;

private slots:
  void AddFrame(QImage);
  void RecordGif();
  void StartRecord();

signals:
 void GetNewFrame();
 void RecordDone();
 void SaveBuffer();
};

}  // namespace s21

#endif  // SAVIOR_H
