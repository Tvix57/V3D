#include "mainwindow.h"
#include <QLayout>
#include "ui_mainwindow.h"

using std::string;
using std::vector;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  load_conf();
  ui->open_GLWidget->get_setting(QSettings("Ajhin_team", "3D_viewer"));
  size_window = new Dialog_size();
  color_window = new QColorDialog();
  set = new settingController(this);
  set_connectiont();
}

MainWindow::~MainWindow() {
  save_conf();
  delete ui;
  delete size_window;
  delete color_window;
  delete set;
}

void MainWindow::set_connectiont() {
    connect(ui->get_color_line, SIGNAL(triggered()), this, SLOT(get_color()));
    connect(ui->get_back_color, SIGNAL(triggered()), this, SLOT(get_color()));
    connect(ui->get_color_pick, SIGNAL(triggered()), this, SLOT(get_color()));

    connect(ui->get_size_pick, SIGNAL(triggered()), this, SLOT(get_size()));
    connect(ui->get_size_line, SIGNAL(triggered()), this, SLOT(get_size()));

    connect(ui->Group_btn_move, SIGNAL(buttonClicked(QAbstractButton*)), this,
            SLOT(move(QAbstractButton*)));

    connect(ui->type_line, SIGNAL(triggered()), this, SLOT(change_type_line()));
    connect(ui->type_dot_line, SIGNAL(triggered()), this,
            SLOT(change_type_line()));

    connect(ui->view_type_circle, SIGNAL(triggered()), this, SLOT(type_view()));
    connect(ui->view_type_qadro, SIGNAL(triggered()), this, SLOT(type_view()));
    connect(ui->view_type_none, SIGNAL(triggered()), this, SLOT(type_view()));

    connect(ui->center, SIGNAL(triggered()), this, SLOT(change_center()));
    connect(ui->center_parallel, SIGNAL(triggered()), this,
            SLOT(change_center()));

    connect(ui->save_Bnp, SIGNAL(triggered()), this, SLOT(save_model()));
    connect(ui->save_Jpeg, SIGNAL(triggered()), this, SLOT(save_model()));
    connect(ui->save_gif, SIGNAL(triggered()), this, SLOT(save_model()));


}

void MainWindow::on_action_open_file_triggered() {
  QString fileName;
  fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                          tr("3D model(*.obj)"));
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

void MainWindow::get_color() {
  color_window->show();
  if (sender() == ui->get_color_pick) {
    color_window->setWindowTitle("Цвет вершин");
    color_window->setCurrentColor(set-><QColor>getParam("dot_color"));
    if (color_window->exec() == QColorDialog::Accepted) {
      set->setParam("dot_color", color_window->selectedColor());
      emit updateSettings();
    }
  } else if (sender() == ui->get_color_line) {
    color_window->setWindowTitle("Цвет ребер");
    color_window->setCurrentColor(set-><QColor>getParam("line_color"));
    if (color_window->exec() == QColorDialog::Accepted) {
      set->setParam("line_color", color_window->selectedColor());
      emit updateSettings();
    }
  } else {
    color_window->setWindowTitle("Цвет фона");
    color_window->setCurrentColor(set-><QColor>getParam("background_color"));
    if (color_window->exec() == QColorDialog::Accepted) {
      background_color = color_window->selectedColor();
      emit updateSettings();
    }
  }
}

void MainWindow::get_size() {
  size_window->show();
  if (sender() == ui->get_size_pick) {
    size_window->setWindowTitle("Размер вершин");
    size_window->set_default(set->getParam("dots_size"), set-><QColor>getParam("dots_color"));
    if (size_window->exec() == QColorDialog::Accepted) {
      set->setParam("dots_size", size_window->get_value());
      emit updateSettings();
    }
  } else {
    size_window->setWindowTitle("Размер ребер");
    size_window->set_default(set->getParam("line_size"), set-><QColor>getParam("line_color"));
    if (size_window->exec() == QColorDialog::Accepted) {
      set->setParam("line_size",size_window->get_value());
      emit updateSettings();
    }
  }
}

void MainWindow::move(QAbstractButton* btn) {
  ui->open_GLWidget->change_position(btn->whatsThis());
}

void MainWindow::change_type_line() {
  if (sender() == ui->type_line) {
    ui->type_line->setChecked(true);
    ui->type_dot_line->setChecked(false);
  } else {
    ui->type_line->setChecked(false);
    ui->type_dot_line->setChecked(true);
  }
  emit updateSettings();
}

void MainWindow::reprint() {
//  save_conf();
//  ui->open_GLWidget->get_setting(QSettings("Ajhin_team", "3D_viewer"));
}

void MainWindow::change_center() {
  if (sender() == ui->center) {
    ui->center->setChecked(true);
    ui->center_parallel->setChecked(false);
  } else {
    ui->center->setChecked(false);
    ui->center_parallel->setChecked(true);
  }
  reprint();
}

void MainWindow::type_view() {
  if (sender() == ui->view_type_circle) {
    ui->view_type_circle->setChecked(true);
    ui->view_type_qadro->setChecked(false);
    ui->view_type_none->setChecked(false);
  } else if (sender() == ui->view_type_qadro) {
    ui->view_type_circle->setChecked(false);
    ui->view_type_qadro->setChecked(true);
    ui->view_type_none->setChecked(false);
  } else {
    ui->view_type_circle->setChecked(false);
    ui->view_type_qadro->setChecked(false);
    ui->view_type_none->setChecked(true);
  }
  emit updateSettings();
}

void MainWindow::save_conf() {
    set->saveSettings();
}

void MainWindow::load_conf() {
    set->loadSettting();
}

void MainWindow::save_model() {
  std::string file_type;
  std::string window_title = "Save File";
  if (sender() == ui->save_Bnp) {
    file_type = "Image (*.bmp)";
  } else if (sender() == ui->save_Jpeg) {
    file_type = "Image (*.jpeg)";
  } else if (sender() == ui->save_gif) {
    file_type = "GIF Image (*.gif)";
  }
  window_title += " " + file_type;
  QString fileName =
      QFileDialog::getSaveFileName(this, tr(window_title.c_str()),
                                   "/home/Users/home_*", tr(file_type.c_str()));
  ptr_save_file = new QFile(fileName);
  if (!ptr_save_file->open(QIODevice::WriteOnly)) {
    qDebug() << "cant open model file to save";
  } else {
    if (sender() == ui->save_gif) {
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
