#ifndef SRC_INCLUDE_GLWIDGET_H_
#define SRC_INCLUDE_GLWIDGET_H_
#define GL_SILENCE_DEPRECATION

#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QSettings>

extern "C" {
#include "parser.h"
}

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit GLWidget(QWidget *parent = nullptr);
  ~GLWidget();
  void get_setting(QSettings current_set);
  void scale_chaged(int value);
  void set_new_model(char *filename);
  void change_position(QString name_btn);
  unsigned int get_vertex_count();
  unsigned int get_face_count();

  void set_sl_x_val(int x);
  void set_sl_y_val(int y);
  void set_sl_z_val(int z);

 public slots:
  void cleanup();

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

 private:
  void drow();
  void set_camera();
  void drow_dots();
  void drow_lines();

  Model *objModel;
  //     входящие настройки
  QColor dot_color, line_color, background_color;
  int line_size, dot_size;
  bool line_type;  // 0-line 1-dot_line
  bool viey_type;  // 0-central 1-paralel
  uint dot_type;   // 0-none 1- circle 2-quad

  GLdouble sl_x, sl_y, sl_z;
  GLdouble step_x, step_y, step_z;
  GLdouble scale;
};

#endif  // SRC_INCLUDE_GLWIDGET_H_
