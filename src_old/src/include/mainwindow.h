#ifndef SRC_INCLUDE_MAINWINDOW_H_
#define SRC_INCLUDE_MAINWINDOW_H_

#include <QColorDialog>
#include <QDataStream>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QPixmap>
#include <QPushButton>
#include <QSettings>
#include <QSlider>
#include <QTimer>
#include <QVector3D>
#include <QWidget>

#include "dialog_size.h"
#include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_action_open_file_triggered();
  void get_color();
  void get_size();
  void move(QAbstractButton *btn);
  void change_type_line();
  void change_center();
  void type_view();

  void save_model();
  void Record_Gif();


 private:
  void Make_Gif();
  void close_save_file();
  void save_conf();
  void load_conf();
  void set_connectiont();
  void reprint();

  void parsing(QFile *open_file, QString fileName);

  Ui::MainWindow *ui;
  QGifImage *gif;
  QTimer *timer;
  QColorDialog *color_window;
  Dialog_size *size_window;
  QColor dot_color, line_color, background_color;
  QFile *ptr_save_file;
  int line_size, dot_size;
  int frameCounter;
};
#endif  // SRC_INCLUDE_MAINWINDOW_H_
