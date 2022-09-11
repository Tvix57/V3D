#ifndef SRC_INCLUDE_MAINWINDOW_H_
#define SRC_INCLUDE_MAINWINDOW_H_

#include <QMainWindow>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QTimer>
#include <QWidget>

#include "dialog_size.h"
#include "qgifimage.h"
#include "settingcontroller.h"

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
  void get_color();
  void get_size();
  void move(QAbstractButton *btn);
  void change_type_line(QAction*);
  void change_center(QAction*);
  void type_dots(QAction*);
  void save_model(QAction*);
  void Record_Gif();
  void on_actionOpenFile_triggered();
  void on_tabWidget_tabBarClicked(int index);

 private:
  void Make_Gif();
  void close_save_file();
  void save_conf();
  void load_conf();
  void set_connectiont();
  void all_invisible();
  void all_disable(QList<QAction*>);

  void parsing(QFile *open_file, QString fileName);

  Ui::MainWindow *ui;
  QGifImage *gif;
  QTimer *timer;
  QColorDialog *color_window;
  Dialog_size *size_window;

  QFile *ptr_save_file;

  int frameCounter;///////
  settingController *set;

};
#endif  // SRC_INCLUDE_MAINWINDOW_H_
