#include "mainwindow.h"
#include <QLayout>
#include "ui_mainwindow.h"

using std::string;
using std::vector;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  size_window = new Dialog_size();
  color_window = new QColorDialog();
  set = new settingController();
  load_conf();
  //  ui->open_GLWidget->get_setting(QSettings("Ajhin_team", "3D_viewer"));
  set_connectiont();
  all_invisible();
}

MainWindow::~MainWindow() {
  set->saveSettings();
  delete ui;
  delete size_window;
  delete color_window;
  delete set;
}

void MainWindow::set_connectiont() {
    connect(ui->Group_btn_move, SIGNAL(buttonClicked(QAbstractButton*)), this,
            SLOT(move(QAbstractButton*)));

    connect(ui->menu_save_file, SIGNAL(triggered(QAction*)), this, SLOT(save_model(QAction*)));

    connect(ui->actionLineColor, SIGNAL(triggered()), this, SLOT(get_color()));
    connect(ui->actionBackColor, SIGNAL(triggered()), this, SLOT(get_color()));
    connect(ui->actionDotsColor, SIGNAL(triggered()), this, SLOT(get_color()));

    connect(ui->actionLineSize, SIGNAL(triggered()), this, SLOT(get_size()));
    connect(ui->actionDotsSize, SIGNAL(triggered()), this, SLOT(get_size()));

    connect(ui->type_line, SIGNAL(triggered(QAction*)), this, SLOT(change_type_line(QAction*)));
    connect(ui->menu_proection, SIGNAL(triggered(QAction*)), this, SLOT(change_center(QAction*)));
    connect(ui->dotsType, SIGNAL(triggered(QAction*)), this, SLOT(type_dots(QAction*)));
}

void MainWindow::get_color() {
  color_window->show();
  if (sender() == ui->actionDotsColor) {
    color_window->setWindowTitle("Цвет вершин");
    color_window->setCurrentColor(set->getParam("dot_color").value<QColor>());
    if (color_window->exec() == QColorDialog::Accepted) {
      set->setParam("dot_color", color_window->selectedColor());
    }
  } else if (sender() == ui->actionLineColor) {
    color_window->setWindowTitle("Цвет ребер");
    color_window->setCurrentColor(set->getParam("line_color").value<QColor>());
    if (color_window->exec() == QColorDialog::Accepted) {
      set->setParam("line_color", color_window->selectedColor());
    }
  } else {
    color_window->setWindowTitle("Цвет фона");
    color_window->setCurrentColor(set->getParam("background_color").value<QColor>());
    if (color_window->exec() == QColorDialog::Accepted) {
      set->setParam("background_color", color_window->selectedColor());
    }
  }
}

void MainWindow::get_size() {
  size_window->show();
  if (sender() == ui->actionDotsSize) {
    size_window->setWindowTitle("Размер вершин");
    size_window->set_default(set->getParam("dots_size").toInt(), set->getParam("dots_color").value<QColor>());
    if (size_window->exec() == QColorDialog::Accepted) {
      set->setParam("dots_size", size_window->get_value());
    }
  } else {
    size_window->setWindowTitle("Размер ребер");
    size_window->set_default(set->getParam("line_size").toInt(), set->getParam("line_color").value<QColor>());
    if (size_window->exec() == QColorDialog::Accepted) {
      set->setParam("line_size",size_window->get_value());
    }
  }
}

void MainWindow::move(QAbstractButton* btn) {
  ui->open_GLWidget->change_position(btn->whatsThis());
}

void MainWindow::change_type_line(QAction* sender) {
    all_disable(ui->type_line->actions());
    sender->setChecked(true);
    set->setParam("type_line", ui->type_line->actions().indexOf(sender));
}

void MainWindow::change_center(QAction* sender) {
    all_disable(ui->menu_proection->actions());
    sender->setChecked(true);
    set->setParam("center", ui->menu_proection->actions().indexOf(sender));
}

void MainWindow::type_dots(QAction* sender) {
    all_disable(ui->dotsType->actions());
    sender->setChecked(true);
    set->setParam("type_dots", ui->dotsType->actions().indexOf(sender));
}

void MainWindow::all_disable(QList<QAction*> menu) {
    QAction *elem;
    foreach(elem, menu) {
        elem->setChecked(false);
    }
}

void MainWindow::all_invisible() {
    QWidget *tab;
//    foreach(tab, ui->tabWidget->widget) {
//        tab->setVisible(false);
//    }

    ui->tabWidgetPage1->setVisible(false);
    ui->tabWidgetPage2->setVisible(false);
    ui->tabWidgetPage3->setVisible(false);
}
void MainWindow::load_conf() {
    switch(set->getParam("dots_type").toInt()) {
    case 1: {
        ui->actionQadro->setChecked(true);
        break;
    }
    case 2: {
        ui->actionCircle->setChecked(true);
        break;
    }
    default:
        ui->actionNone->setChecked(true);
        break;
    }
    switch (set->getParam("line_type").toInt()) {
    case 1:
        ui->actionLineDots->setChecked(true);
        break;
    default:
        ui->actionLine->setChecked(true);
        break;
    }
    switch (set->getParam("center").toInt()) {
    case 1:
        ui->actionParallel->setChecked(true);
        break;
    default:
        ui->actionCentrall->setChecked(true);
        break;
    }
}

void MainWindow::save_model(QAction* sender) {
  std::string file_type;
  std::string window_title = "Save File";
  switch (ui->menu_save_file->actions().indexOf(sender)) {
  case 1:
      file_type = "Image (*.bmp)";
      break;
  case 2:
      file_type = "GIF Image (*.gif)";
      break;
  default:
    file_type = "Image (*.jpeg)";
    break;
  }
  window_title += " " + file_type;
  QString fileName =
      QFileDialog::getSaveFileName(this, tr(window_title.c_str()),
                                   "/home/Users/home_*", tr(file_type.c_str()));
  ptr_save_file = new QFile(fileName);
  if (ptr_save_file->open(QIODevice::WriteOnly)) {
    if (sender == ui->actionSaveGif) {
      Make_Gif();
    } else {
      ui->open_GLWidget->grabFramebuffer().save(ptr_save_file);
      close_save_file();
    }
  }
}

void MainWindow::Make_Gif() {
  gif = new QGifImage();
  frameCounter = 0;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(Record_Gif()));
//  ui->record_label->setVisible(true);
  timer->start(100);
}

void MainWindow::Record_Gif() {
  ++frameCounter;
  gif->addFrame(ui->open_GLWidget->grabFramebuffer(), 100);
  if (frameCounter == 50) {
    timer->stop();
    gif->save(ptr_save_file);
    close_save_file();
    delete gif;
    gif = nullptr;
  }
}

void MainWindow::close_save_file() {
  ptr_save_file->close();
  delete ptr_save_file;
  ptr_save_file = nullptr;
}

void MainWindow::on_actionOpenFile_triggered() {
    QString fileName { QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                                    tr("3D model(*.obj)")) };
  if (!fileName.isEmpty()) {
    QFile open_file(fileName);
    if (!open_file.open(QIODevice::ReadOnly)) {
      qDebug() << "cant open model file to load";
    } else {
      ui->open_GLWidget->set_new_model(fileName.toLatin1().data());
      open_file.close();
      ui->statusbar->showMessage(
          "Файл: " + fileName + "    Кол-во вершин: " +
          QString::number(ui->open_GLWidget->get_vertex_count()) +
          "    Кол-во ребер: " +
          QString::number(ui->open_GLWidget->get_face_count()));
    }
  }
}

void MainWindow::on_tabWidget_tabBarClicked(int index) {
    bool flag = ui->tabWidget->widget(index)->isVisible();
    all_invisible();
    if (!flag) {
        ui->tabWidget->widget(index)->setVisible(true);
    }
}

