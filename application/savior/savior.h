#ifndef SAVIOR_H
#define SAVIOR_H

#include <QFileDialog>
#include <QObject>
#include <QTimer>

#include "qgifimage.h"
#include "v3d_gl.h"

namespace s21 {

class Savior : public QObject {
  Q_OBJECT
 public:
  explicit Savior(V3D_GL *);
  ~Savior();
  void SaveFile(const int);

 private:
  void SaveImage();
  void SaveGif();
  const bool OpenFileToSave(QString);

  V3D_GL *m_gl_parent_;
  QTimer *m_timer_;
  QFile *m_ptr_save_file_;
  int m_frameCounter_;
  QGifImage *m_gif_;

 private slots:
  void CloseSaveFile();
  void RecordGif();

 signals:
  void RecordStart();
  void RecordDone();
  void SaveDone();
  void RotateObj(int);
};

}  // namespace s21

#endif  // SAVIOR_H
