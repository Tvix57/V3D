#include "mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), obj_{nullptr} {
  ui->setupUi(this);
  ConnectModelRegister();
  ConnectLightRegister();
  SetItemList();
  SetLightList();
  ui->PointLightbox->setEnabled(false);
  ui->SpotLightBox->setEnabled(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ConnectModelRegister() {
  connect(ui->bg_translate, SIGNAL(buttonClicked(QAbstractButton *)), this,
          SLOT(ModelTranslate(QAbstractButton *)));

  connect(ui->SetRotateX, SIGNAL(valueChanged(int)), this,
          SLOT(dial_valueChanged(const int)));
  connect(ui->SetRotateY, SIGNAL(valueChanged(int)), this,
          SLOT(dial_valueChanged(const int)));
  connect(ui->SetRotateZ, SIGNAL(valueChanged(int)), this,
          SLOT(dial_valueChanged(const int)));

  connect(ui->spb_rotate_x, SIGNAL(valueChanged(int)), this,
          SLOT(spb_rotate_valueChanged(const int)));
  connect(ui->spb_rotate_y, SIGNAL(valueChanged(int)), this,
          SLOT(spb_rotate_valueChanged(const int)));
  connect(ui->spb_rotate_z, SIGNAL(valueChanged(int)), this,
          SLOT(spb_rotate_valueChanged(const int)));

  connect(ui->SetTranslateX, SIGNAL(valueChanged(double)), this,
          SLOT(SetTranslate_valueChanged(const double)));
  connect(ui->SetTranslateY, SIGNAL(valueChanged(double)), this,
          SLOT(SetTranslate_valueChanged(const double)));
  connect(ui->SetTranslateZ, SIGNAL(valueChanged(double)), this,
          SLOT(SetTranslate_valueChanged(const double)));

  connect(ui->SetScaleX, SIGNAL(valueChanged(double)), this,
          SLOT(dsb_scale_valueChanged(const double)));
  connect(ui->SetScaleY, SIGNAL(valueChanged(double)), this,
          SLOT(dsb_scale_valueChanged(const double)));
  connect(ui->SetScaleZ, SIGNAL(valueChanged(double)), this,
          SLOT(dsb_scale_valueChanged(const double)));
  connect(ui->SetScaleTotal, SIGNAL(valueChanged(double)), this,
          SLOT(dsb_scale_valueChanged(const double)));

  connect(ui->wgt_gl, SIGNAL(curentObj(Model *)), this,
          SLOT(SetCurentModel(Model *)));
  connect(ui->wgt_gl, SIGNAL(getSceneData()), this, SLOT(LoadSettings()));
}

void MainWindow::ConnectLightRegister() {
  Illumination *illumination = ui->wgt_gl->GetIllumation();

  connect(this, SIGNAL(RemoveLight(QString, int)), illumination,
          SLOT(RemoveLight(QString, int)));

  connect(this, SIGNAL(ChangeCurrentLight(QString, int)), illumination,
          SLOT(ChangeCurrent(QString, int)));

  connect(illumination, SIGNAL(CurrentLightInfo(QMap<QString, QVariant>)), this,
          SLOT(SetLightInfo(QMap<QString, QVariant>)));

  connect(ui->directionLight_x_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangeDirectionX(double)));
  connect(ui->directionLight_y_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangeDirectionY(double)));
  connect(ui->directionLight_z_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangeDirectionZ(double)));

  connect(ui->positionLight_x_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangePositionX(double)));
  connect(ui->positionLight_y_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangePositionY(double)));
  connect(ui->positionLight_z_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(ChangePositionZ(double)));

  connect(illumination, SIGNAL(CurentLightDistance(int)), this,
          SLOT(SetCurrentLightDistance(int)));

  connect(ui->distanceLight_cbx, SIGNAL(currentIndexChanged(int)), illumination,
          SLOT(SetItemDistance(int)));

  connect(ui->specularLight_btn, SIGNAL(clicked()), illumination,
          SLOT(GetSpecular()));
  connect(illumination, SIGNAL(Scpecular(QVector3D)), this,
          SLOT(SetSpecular(QVector3D)));

  connect(ui->diffuseLigh_btn, SIGNAL(clicked()), illumination,
          SLOT(GetDiffuse()));
  connect(illumination, SIGNAL(Diffuse(QVector3D)), this,
          SLOT(SetDiffuse(QVector3D)));

  connect(ui->intensityLight_btn, SIGNAL(clicked()), illumination,
          SLOT(GetIntensity()));
  connect(illumination, SIGNAL(Intensity(QVector3D)), this,
          SLOT(SetIntensity(QVector3D)));

  connect(this, SIGNAL(NewSpecular(QVector3D)), illumination,
          SLOT(SetSpecular(QVector3D)));

  connect(this, SIGNAL(NewDiffuse(QVector3D)), illumination,
          SLOT(SetDiffuse(QVector3D)));

  connect(this, SIGNAL(NewIntensity(QVector3D)), illumination,
          SLOT(SetIntensity(QVector3D)));

  connect(ui->cutLight_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(SetCut(double)));
  connect(ui->outerCutLight_spb, SIGNAL(valueChanged(double)), illumination,
          SLOT(SetOuterCut(double)));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  ui->wgt_gl->keyPress(event);
}

void MainWindow::on_act_open_file_triggered() {
  QString last_path = settings_.getSettings("lastDialogPath").toString();
  if (last_path.isEmpty()) {
    last_path = "\\home";
  }
  last_path = QFileDialog::getOpenFileName(this, tr("Open File"), last_path,
                                           tr("3D model(*.obj)"));
  if (!last_path.isEmpty()) {
    ui->wgt_gl->LoadModel(last_path);
    settings_.setSettings("lastDialogPath", last_path);
    AddModelLable(last_path);
  }
}

void MainWindow::ModelTranslate(QAbstractButton *btn) {
  if (obj_) {
    const TranslateSetting set = obj_->GetSettings().GetTranslateSettings();
    const double step = ui->dsb_translate_step->value();
    if (btn == ui->btn_translation_lx) {
      obj_->GetSettings().SetTranslateX(set.Tx - step);
      ui->SetTranslateX->setValue(set.Tx - step);
    } else if (btn == ui->btn_translation_rx) {
      obj_->GetSettings().SetTranslateX(set.Tx + step);
      ui->SetTranslateX->setValue(set.Tx + step);
    } else if (btn == ui->btn_translation_uy) {
      obj_->GetSettings().SetTranslateY(set.Ty + step);
      ui->SetTranslateY->setValue(set.Ty + step);
    } else if (btn == ui->btn_translation_dy) {
      obj_->GetSettings().SetTranslateY(set.Ty - step);
      ui->SetTranslateY->setValue(set.Ty - step);
    } else if (btn == ui->btn_translate_fz) {
      obj_->GetSettings().SetTranslateZ(set.Tz + step);
      ui->SetTranslateZ->setValue(set.Tz + step);
    } else if (btn == ui->btn_translate_bz) {
      obj_->GetSettings().SetTranslateZ(set.Tz - step);
      ui->SetTranslateZ->setValue(set.Tz - step);
    }
  }
}

void MainWindow::dial_valueChanged(const int value) {
  if (obj_) {
    if (sender() == ui->SetRotateX) {
      obj_->GetSettings().SetRotateX(value);
      if (ui->spb_rotate_x->value() != value) {
        ui->spb_rotate_x->setValue(value);
      }
    } else if (sender() == ui->SetRotateY) {
      obj_->GetSettings().SetRotateY(value);
      if (ui->spb_rotate_y->value() != value) {
        ui->spb_rotate_y->setValue(value);
      }
    } else if (sender() == ui->SetRotateZ) {
      obj_->GetSettings().SetRotateZ(value);
      if (ui->spb_rotate_z->value() != value) {
        ui->spb_rotate_z->setValue(value);
      }
    }
  }
}

void MainWindow::dsb_scale_valueChanged(const double value) {
  if (obj_) {
    if (sender() == ui->SetScaleX)
      obj_->GetSettings().SetScaleX(value / 100.0f);
    else if (sender() == ui->SetScaleY) {
      obj_->GetSettings().SetScaleY(value / 100.0f);
    } else if (sender() == ui->SetScaleZ) {
      obj_->GetSettings().SetScaleZ(value / 100.0f);
    } else {
      obj_->GetSettings().SetScaleTotal(value / 100.0f);
    }
  }
}

void MainWindow::on_act_edge_width_triggered() {
  if (obj_) {
    const EdgeSetting set = obj_->GetSettings().GetEdgeSettings();
    WgtWidth *wgt = new WgtWidth(this, set.size);
    wgt->setWindowTitle("Ширина граней");
    wgt->show();
    if (wgt->exec() == QDialog::Accepted) {
      obj_->GetSettings().SetEdgeSize(wgt->GetValue());
    }
    delete wgt;
  }
}

void MainWindow::on_act_edge_color_triggered() {
  if (obj_) {
    QColorDialog color(obj_->GetSettings().GetEdgeSettings().color, this);
    color.setWindowTitle("Цвет рёбер");
    if (color.exec() == QColorDialog::Accepted) {
      obj_->GetSettings().SetEdgeColor(color.selectedColor());
    }
  }
}

void MainWindow::on_act_vertex_size_triggered() {
  if (obj_) {
    const VertexSetting set = obj_->GetSettings().GetVertexSettings();
    WgtWidth *wgt = new WgtWidth(this, set.size);
    wgt->setWindowTitle("Размер вершин");
    wgt->show();
    if (wgt->exec() == QDialog::Accepted) {
      obj_->GetSettings().SetVertexSize(wgt->GetValue());
    }
    delete wgt;
  }
}

void MainWindow::on_act_vertex_color_triggered() {
  if (obj_) {
    QColorDialog color(obj_->GetSettings().GetVertexSettings().color, this);
    color.setWindowTitle("Цвет вершин");
    if (color.exec() == QColorDialog::Accepted) {
      obj_->GetSettings().SetVertexColor(color.selectedColor());
    }
  }
}

void MainWindow::on_menu_dots_type_triggered(QAction *sender) {
  if (obj_) {
    VertexType param = VertexType::kNo;
    switch (ui->menu_dots_type->actions().indexOf(sender)) {
      case 1:
        param = VertexType::kCircle;
        break;
      case 2:
        param = VertexType::kSquare;
        break;
      default:
        break;
    }
    obj_->GetSettings().SetVertexType(param);
    AllDisable(ui->menu_dots_type->actions());
    sender->setChecked(true);
  }
}

void MainWindow::on_menu_texture_parts_triggered(QAction *sender) {
  if (obj_) {
    TextureType param = TextureType::kNo;
    switch (ui->menu_texture_parts->actions().indexOf(sender)) {
      case 1:
        param = TextureType::kWireFrame;
        break;
      case 2:
        param = TextureType::kSurface;
        break;
      default:
        break;
    }
    obj_->GetSettings().SetTextureType(param);
    AllDisable(ui->menu_texture_parts->actions());
    sender->setChecked(true);
  }
}

void MainWindow::on_menu_edge_type_triggered(QAction *sender) {
  if (obj_) {
    EdgeType param = EdgeType::kNo;
    switch (ui->menu_edge_type->actions().indexOf(sender)) {
      case 1:
        param = EdgeType::kLine;
        break;
      case 2:
        param = EdgeType::kDotted;
        break;
      default:
        break;
    }
    obj_->GetSettings().SetEdgeType(param);
    AllDisable(ui->menu_edge_type->actions());
    sender->setChecked(true);
  }
}

void MainWindow::on_menu_projection_type_triggered(QAction *sender) {
  ProjectionType param = ProjectionType::kPerspective;
  const int index = ui->menu_projection_type->actions().indexOf(sender);
  if (index) {
    param = ProjectionType::kOrtho;
  }
  ui->wgt_gl->SetProjection(param);
  AllDisable(ui->menu_projection_type->actions());
  sender->setChecked(true);
  settings_.setSettings("projectionType", index);
}

void MainWindow::on_menu_save_file_triggered(QAction *sender) {
  Savior *save = new Savior(ui->wgt_gl);
  connect(save, SIGNAL(RotateObj(int)), ui->SetRotateX,
          SIGNAL(valueChanged(int)));
  connect(save, SIGNAL(RecordStart()), this, SLOT(RecordsOn()));
  connect(save, SIGNAL(RecordDone()), this, SLOT(RecordsOff()));
  save->SaveFile(ui->menu_save_file->actions().indexOf(sender));
}

void MainWindow::AllDisable(QList<QAction *> menu) {
  for (auto &it : menu) {
    it->setChecked(false);
  }
}

void MainWindow::SetCurentModel(Model *curent_obj) {
  obj_ = curent_obj;
  SetModelData();
  SetModelInfo();
}

void MainWindow::SetModelInfo() {
  ModelInfo info = obj_->GetInfo();
  QString message = "Object Name: " + info.GetName() + "        ";
  message.append("Poligons count: " + QString::number(info.GetFaceCount()) +
                 "        ");
  message.append("Vertex count: " + QString::number(info.GetVerticeCount()) +
                 "        ");
  ui->statusbar->showMessage(message);
}

void MainWindow::SetModelData() {
  if (obj_) {
    const RotateSetting rotate_set = obj_->GetSettings().GetRotateSettings();
    ui->SetRotateX->setValue(rotate_set.Rx);
    ui->SetRotateY->setValue(rotate_set.Ry);
    ui->SetRotateZ->setValue(rotate_set.Rz);
    const ScaleSetting scale_set = obj_->GetSettings().GetScaleSettings();
    ui->SetScaleX->setValue(scale_set.Sx * 100.0f);
    ui->SetScaleY->setValue(scale_set.Sy * 100.0f);
    ui->SetScaleZ->setValue(scale_set.Sz * 100.0f);
    ui->SetScaleTotal->setValue(scale_set.STotal * 100.0f);
    const TranslateSetting translate_set =
        obj_->GetSettings().GetTranslateSettings();
    ui->SetTranslateX->setValue(translate_set.Tx);
    ui->SetTranslateY->setValue(translate_set.Ty);
    ui->SetTranslateZ->setValue(translate_set.Tz);
    AllDisable(ui->menu_dots_type->actions());
    AllDisable(ui->menu_edge_type->actions());
    AllDisable(ui->menu_texture_parts->actions());
    int index = static_cast<int>(obj_->GetSettings().GetEdgeSettings().type);
    ui->menu_edge_type->actions().at(index)->setChecked(true);
    index = static_cast<int>(obj_->GetSettings().GetVertexSettings().type);
    ui->menu_dots_type->actions().at(index)->setChecked(true);
    index = static_cast<int>(obj_->GetSettings().GetTextureSettings().type);
    ui->menu_texture_parts->actions().at(index)->setChecked(true);
  }
}

void MainWindow::spb_rotate_valueChanged(const int value) {
  if (sender() == ui->spb_rotate_x) {
    if (ui->SetRotateX->value() != value) {
      ui->SetRotateX->setValue(value);
    }
  } else if (sender() == ui->spb_rotate_y) {
    if (ui->SetRotateY->value() != value) {
      ui->SetRotateY->setValue(value);
    }
  } else if (sender() == ui->spb_rotate_z) {
    if (ui->SetRotateZ->value() != value) {
      ui->SetRotateZ->setValue(value);
    }
  }
}

void MainWindow::SetTranslate_valueChanged(const double value) {
  if (obj_) {
    if (sender() == ui->SetTranslateX) {
      obj_->GetSettings().SetTranslateX(value);
    } else if (sender() == ui->SetTranslateY) {
      obj_->GetSettings().SetTranslateY(value);
    } else if (sender() == ui->SetTranslateZ) {
      obj_->GetSettings().SetTranslateZ(value);
    }
  }
}

void MainWindow::LoadSettings() {
  const int index = settings_.getSettings("projectionType").toInt();
  ui->menu_projection_type->actions().at(index)->setChecked(true);
  ProjectionType param = ProjectionType::kPerspective;
  if (index) {
    param = ProjectionType::kOrtho;
  }
  ui->wgt_gl->SetProjection(param);
  ui->wgt_gl->SetBackgroundColor(
      settings_.getSettings("backgroundColor").value<QColor>());
}

void MainWindow::on_act_background_color_triggered() {
  QColorDialog color(settings_.getSettings("backgroundColor").value<QColor>(),
                     this);
  color.setWindowTitle("Цвет фона");
  if (color.exec() == QColorDialog::Accepted) {
    ui->wgt_gl->SetBackgroundColor(color.selectedColor());
    settings_.setSettings("backgroundColor", color.selectedColor());
  }
}

void MainWindow::SetItemList() {
  QStandardItemModel *model = new QStandardItemModel(this);
  model->setHorizontalHeaderLabels(QStringList()
                                   << QStringLiteral("Object name")
                                   << QStringLiteral("Remove object"));
  ui->treeView->setModel(model);
  ui->treeView->header()->resizeSection(0, 170);
}

void MainWindow::AddModelLable(QString file_name) {
  QStringList list = file_name.split("/");
  file_name = list.last();
  QStandardItemModel *model = (QStandardItemModel *)ui->treeView->model();
  QList<QStandardItem *> list_item;
  QStandardItem *item = new QStandardItem(file_name);
  item->setEditable(false);
  list_item.append(item);
  item = new QStandardItem("Remove");
  list_item.append(item);
  model->appendRow(list_item);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
  if (index.column() == 1) {
    ui->treeView->model()->removeRow(index.row());
    ui->wgt_gl->RemoveObj(index.row());
    ui->statusbar->clearMessage();
  } else {
    ui->wgt_gl->ChangeCurentObj(index.row());
  }
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index) {
  if (!index.column()) {
    ui->wgt_gl->ChangeCurentObj(index.row());
    ui->wgt_gl->ModelFocus();
  }
}

void MainWindow::on_btn_focus_clicked() { ui->wgt_gl->ModelFocus(); }

void MainWindow::on_btn_normalaze_clicked() {
  const float ratio = ui->wgt_gl->GetModelRatioToIndentify();
  ui->SetScaleTotal->setValue(ui->SetScaleTotal->value() * ratio);
}

void MainWindow::on_treeLights_clicked(const QModelIndex &index) {
  if (index.isValid()) {
    const QModelIndex parent = index.parent();
    QString type("dirLight");
    if (parent.model() == nullptr) {
      if (index.row() == 0) {
        ShowLightSettings(index.row());
        emit ChangeCurrentLight(type, index.row());
      }
    } else {
      ShowLightSettings(parent.row());
      if (parent.row() == 1) {
        type = "pointLight";
      } else if (parent.row() == 2) {
        type = "spotLight";
      }
      if (index.column() == 2) {
        QStandardItemModel *model = (QStandardItemModel *)parent.model();
        model->removeRow(index.row(), parent);
        emit RemoveLight(type, index.row());
        QModelIndex new_index =
            ui->treeLights->selectionModel()->currentIndex();
        new_index = new_index.siblingAtColumn(0);
        if (new_index.parent().model() == nullptr) {
          new_index = new_index.siblingAtRow(0);
        }
        emit ui->treeLights->clicked(new_index);
      } else {
        emit ChangeCurrentLight(type, index.row());
      }
    }
  }
}

void MainWindow::ShowLightSettings(const int index) {
  switch (index) {
    case 0: {
      ui->PointLightbox->setEnabled(false);
      ui->SpotLightBox->setEnabled(false);
    } break;
    case 1: {
      ui->PointLightbox->setEnabled(true);
      ui->SpotLightBox->setEnabled(false);
    } break;
    case 2: {
      ui->PointLightbox->setEnabled(true);
      ui->SpotLightBox->setEnabled(true);
    } break;
    default:
      break;
  }
}

void MainWindow::SetLightList() {
  QStandardItemModel *model = new QStandardItemModel(this);
  QStringList lines;
  lines << "Lights tree"
        << "On"
        << "Remove";
  model->setHorizontalHeaderLabels(lines);

  lines.clear();
  QStandardItem *item;
  lines << "Direction Light"
        << "Point Light"
        << "Spot Light";
  for (auto &it : lines) {
    item = new QStandardItem(it);
    item->setEditable(false);
    item->setCheckable(true);
    item->setCheckState(Qt::Checked);
    model->appendRow(item);
  }
  connect(model, SIGNAL(itemChanged(QStandardItem *)), this,
          SLOT(item_changed(QStandardItem *)));
  ui->treeLights->setModel(model);
  ui->treeLights->header()->resizeSection(1, 30);
}

void MainWindow::AddLightOnTree(int index) {
  QStandardItemModel *model = (QStandardItemModel *)ui->treeLights->model();
  QStandardItem *Parent_item = model->item(index, 0);
  QString lightName;
  int count = Parent_item->rowCount();
  if (count < 20) {
    switch (index) {
      case 0:
        lightName = "dirLight";
        break;
      case 1:
        lightName = "pointLight";
        break;
      case 2:
        lightName = "spotLight";
        break;
      default:
        break;
    }
    ui->wgt_gl->addLight(lightName);
    lightName += "[" + QString::number(count) + "]";
    QStandardItem *item = new QStandardItem(lightName);
    QList<QStandardItem *> list_item;
    list_item.append(item);
    item = new QStandardItem();
    item->setEditable(false);
    item->setCheckable(true);
    item->setCheckState(Qt::Checked);
    list_item.append(item);
    item = new QStandardItem("Remove");
    item->setEditable(false);
    list_item.append(item);
    Parent_item->appendRow(list_item);
  }
}

void MainWindow::on_add_point_light_btn_clicked() { AddLightOnTree(1); }

void MainWindow::on_add_spot_light_btn_clicked() { AddLightOnTree(2); }

void MainWindow::item_changed(QStandardItem *item) {
  if (item->index().parent().model() == nullptr) {
    if (!item->index().row()) {
      if (item->checkState()) {
        ui->wgt_gl->setEnableLight("dirLight", item->index().row());
      } else {
        ui->wgt_gl->setDisableLight("dirLight", item->index().row());
      }
    } else {
      QStandardItem *item_child;
      for (int i = 0; i < item->rowCount(); i++) {
        item_child = item->child(i, 1);
        item_child->setCheckState(item->checkState());
        emit item->model()->itemChanged(item_child);
      }
    }
  } else {
    if (item->column() == 1) {
      QString type("dirLight");
      switch (item->parent()->row()) {
        case 1:
          type = "pointLight";
          break;
        case 2:
          type = "spotLight";
          break;
        default:
          break;
      }
      if (item->checkState()) {
        ui->wgt_gl->setEnableLight(type, item->index().row());
      } else {
        ui->wgt_gl->setDisableLight(type, item->index().row());
      }
    }
  }
}

void MainWindow::SetLightInfo(QMap<QString, QVariant> light_data) {
  for (auto &property : light_data) {
    if (QString(property.typeName()) == "QVector3D*") {
      if (light_data.key(property) == ".direction") {
        ui->directionLight_x_spb->setValue(property.value<QVector3D *>()->x());
        ui->directionLight_y_spb->setValue(property.value<QVector3D *>()->y());
        ui->directionLight_z_spb->setValue(property.value<QVector3D *>()->z());
      } else if (light_data.key(property) == ".position") {
        ui->positionLight_x_spb->setValue(property.value<QVector3D *>()->x());
        ui->positionLight_y_spb->setValue(property.value<QVector3D *>()->y());
        ui->positionLight_z_spb->setValue(property.value<QVector3D *>()->z());
      }
    } else {
      if (light_data.key(property) == ".cutOff") {
        ui->cutLight_spb->setValue(*property.value<float *>());
      } else if (light_data.key(property) == ".outerCutOff") {
        ui->outerCutLight_spb->setValue(*property.value<float *>());
      }
    }
  }
}

void MainWindow::SetCurrentLightDistance(int index) {
  ui->distanceLight_cbx->setCurrentIndex(index);
}

void MainWindow::SetSpecular(QVector3D data) {
  QColor dataColor;
  dataColor.setRedF(data.x());
  dataColor.setGreenF(data.y());
  dataColor.setBlueF(data.z());
  QColorDialog color(dataColor, this);

  color.setWindowTitle("Цвет отражения света");
  if (color.exec() == QColorDialog::Accepted) {
    data.setX(color.currentColor().redF());
    data.setY(color.currentColor().greenF());
    data.setZ(color.currentColor().blueF());
    emit NewSpecular(data);
  }
}

void MainWindow::SetDiffuse(QVector3D data) {
  QColor dataColor;
  dataColor.setRedF(data.x());
  dataColor.setGreenF(data.y());
  dataColor.setBlueF(data.z());
  QColorDialog color(dataColor, this);
  color.setWindowTitle("Цвет рассеивания света");
  if (color.exec() == QColorDialog::Accepted) {
    data.setX(color.currentColor().redF());
    data.setY(color.currentColor().greenF());
    data.setZ(color.currentColor().blueF());
    emit NewDiffuse(data);
  }
}

void MainWindow::SetIntensity(QVector3D data) {
  QColor dataColor;
  dataColor.setRedF(data.x());
  dataColor.setGreenF(data.y());
  dataColor.setBlueF(data.z());
  QColorDialog color(dataColor, this);
  color.setWindowTitle("Цвет интенсивности света");
  if (color.exec() == QColorDialog::Accepted) {
    data.setX(color.currentColor().redF());
    data.setY(color.currentColor().greenF());
    data.setZ(color.currentColor().blueF());
    emit NewIntensity(data);
  }
}

void MainWindow::on_btn_texture_add_clicked() {
  if (obj_) {
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "/",
                                                tr("bmp(*.bmp)"));
    QImage data(path);
    if (data.width() == data.height() && data.width() <= 1024 &&
        data.height() <= 1024) {
      obj_->ChangeTexture(data, path);
    } else {
      qDebug()
          << "Размер bmp файла должен быть менее 1024 и быть только квадратным";
    }
  }
}

void MainWindow::on_btn_texture_del_clicked() {
  if (obj_) {
    obj_->DelTexture();
  }
}

void MainWindow::on_btn_texture_mirrored_clicked() {
  if (obj_) {
    obj_->MirrorTexture();
  }
}

void MainWindow::on_btn_surface_ambient_clicked() {
  if (obj_) {
    QColorDialog color(this);
    color.setWindowTitle("Ambient color");
    if (color.exec() == QColorDialog::Accepted) {
      obj_->ChangeAmbient(color.currentColor());
    }
  }
}

void MainWindow::on_btn_surface_diffuse_clicked() {
  if (obj_) {
    QColorDialog color(this);
    color.setWindowTitle("Diffuse color");
    if (color.exec() == QColorDialog::Accepted) {
      obj_->ChangeDiffuse(color.currentColor());
    }
  }
}

void MainWindow::on_btn_surface_specular_clicked() {
  if (obj_) {
    QColorDialog color(this);
    color.setWindowTitle("Specular color");
    if (color.exec() == QColorDialog::Accepted) {
      obj_->ChangeSpecular(color.currentColor());
    }
  }
}

void MainWindow::on_dsb_surface_shine_valueChanged(double value) {
  if (obj_) {
    obj_->ChangeShine(value);
  }
}

void MainWindow::on_dsb_surface_opacity_valueChanged(double value) {
  if (obj_) {
    obj_->ChangeOpacity(value);
  }
}

void MainWindow::on_cb_surface_stateChanged(int value) {
  if (obj_) {
    if (value) {
      obj_->GetSettings().SetSurfaceType(SurfaceType::kTexture);
    } else {
      obj_->GetSettings().SetSurfaceType(SurfaceType::kMaterial);
    }
  }
}

void MainWindow::on_btn_surface_default_material_clicked() {
  if (obj_) {
    obj_->SetDefaultMaterial();
  }
}

void MainWindow::on_act_light_flat_triggered() {
  ui->wgt_gl->SetLightType(LightType::kFlat);
}

void MainWindow::on_act_light_soft_triggered() {
  ui->wgt_gl->SetLightType(LightType::kSoft);
}

void MainWindow::on_act_scene_grid_none_triggered() {
  ui->wgt_gl->SetDrawSceneType(false);
}

void MainWindow::on_act_scene_grid_draw_triggered() {
  ui->wgt_gl->SetDrawSceneType(true);
}

void MainWindow::RecordsOn() {
  tmp_info_string_ = ui->statusbar->currentMessage();
  ui->statusbar->showMessage("ИДЁТ ЗАПИСЬ GIF");
  ui->tab_main_setting->setDisabled(true);
}
void MainWindow::on_dsb_surface_refraction_valueChanged(double value) {
  if (obj_) {
    obj_->ChangeReflection(value);
  }
}

void MainWindow::on_dsb_surface_roughtness_valueChanged(double value) {
  if (obj_) {
    obj_->ChangeRoughness(1.0f - value);
  }
}

void MainWindow::RecordsOff() {
  ui->statusbar->showMessage(tmp_info_string_);
  ui->tab_main_setting->setDisabled(false);
  tmp_info_string_.clear();
}

}  // namespace s21
