#ifndef SRC_INCLUDE_MAINWINDOW_H_
#define SRC_INCLUDE_MAINWINDOW_H_

#include <QAbstractButton>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QStandardItemModel>

#include "global_settings.h"
#include "illumination.h"
#include "savior.h"
#include "ui_mainwindow.h"
#include "wgt_width.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 signals:
  void RemoveLight(QString, int);
  void ChangeCurrentLight(QString, int);
  void NewSpecular(QVector3D);
  void NewDiffuse(QVector3D);
  void NewIntensity(QVector3D);

 private slots:
  void on_act_open_file_triggered();
  void ModelTranslate(QAbstractButton *btn);

  void dial_valueChanged(const int value);
  void dsb_scale_valueChanged(const double value);
  void on_act_edge_width_triggered();
  void on_act_edge_color_triggered();
  void on_act_vertex_size_triggered();
  void on_act_vertex_color_triggered();
  void on_menu_dots_type_triggered(QAction *);
  void on_menu_texture_parts_triggered(QAction *);
  void on_menu_edge_type_triggered(QAction *);
  void on_menu_projection_type_triggered(QAction *);
  void on_menu_save_file_triggered(QAction *);

  void SetCurentModel(Model *);
  void spb_rotate_valueChanged(const int value);

  void SetTranslate_valueChanged(const double value);
  void on_act_background_color_triggered();

  void on_treeView_clicked(const QModelIndex &index);
  void on_treeView_doubleClicked(const QModelIndex &index);
  void on_btn_focus_clicked();
  void on_btn_normalaze_clicked();
  void LoadSettings();
  void on_treeLights_clicked(const QModelIndex &index);
  void on_add_point_light_btn_clicked();
  void on_add_spot_light_btn_clicked();
  void item_changed(QStandardItem *item);
  void SetLightInfo(QMap<QString, QVariant>);
  void SetCurrentLightDistance(int);

  void SetSpecular(QVector3D);
  void SetDiffuse(QVector3D);
  void SetIntensity(QVector3D);

  void on_btn_texture_add_clicked();
  void on_btn_texture_del_clicked();
  void on_btn_texture_mirrored_clicked();

  void on_btn_surface_ambient_clicked();
  void on_btn_surface_diffuse_clicked();
  void on_btn_surface_specular_clicked();
  void on_dsb_surface_shine_valueChanged(double value);
  void on_dsb_surface_opacity_valueChanged(double value);
  void on_cb_surface_stateChanged(int value);
  void on_btn_surface_default_material_clicked();
  void on_act_light_flat_triggered();
  void on_act_light_soft_triggered();
  void on_act_scene_grid_none_triggered();
  void on_act_scene_grid_draw_triggered();
  void on_dsb_surface_refraction_valueChanged(double value);
  void on_dsb_surface_roughtness_valueChanged(double value);

  void RecordsOn();
  void RecordsOff();

 private:
  void keyPressEvent(QKeyEvent *event);
  void ConnectModelRegister();
  void ConnectLightRegister();
  void AllDisable(QList<QAction *>);
  void SetModelData();
  void AddLightOnTree(int);
  void SetItemList();
  void SetLightList();
  void AddModelLable(QString);
  void SetModelInfo();
  void ShowLightSettings(const int);

  Ui::MainWindow *ui;
  Model *obj_;
  GlobalSetting settings_;
  QString tmp_info_string_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MAINWINDOW_H_
