#include "settingcontroller.h"


settingController::settingController(QObject *parent)
    : QObject{parent}
{

}

void settingController::loadSettting() {
//    ui->type_line->setChecked(
//        settings.value("settings/type_line", false).toBool());
//    ui->type_dot_line->setChecked(
//        settings.value("settings/type_dot_line", false).toBool());
//    if (!ui->type_line->isChecked() && !ui->type_dot_line->isChecked()) {
//      ui->type_line->setChecked(true);
//    }
//    ui->center->setChecked(settings.value("settings/center", false).toBool());
//    ui->center_parallel->setChecked(
//        settings.value("settings/center_parallel", false).toBool());
//    if (!ui->center->isChecked() && !ui->center_parallel->isChecked()) {
//      ui->center->setChecked(true);
//    }
//    ui->view_type_circle->setChecked(
//        settings.value("settings/view_type_circle", false).toBool());
//    ui->view_type_qadro->setChecked(
//        settings.value("settings/view_type_qadro", false).toBool());
//    ui->view_type_none->setChecked(
//        settings.value("settings/view_type_none", false).toBool());
//    if (!ui->view_type_none->isChecked() && !ui->view_type_qadro->isChecked() &&
//        !ui->view_type_circle->isChecked()) {
//      ui->view_type_none->setChecked(true);
//    }

    dot_color = settings.value("settings/dot_color", QColor(Qt::green)).value<QColor>();
    background_color = settings.value("settings/background_color", QColor(Qt::black)).value<QColor>();
    line_color = settings.value("settings/line_color", QColor(Qt::blue)).value<QColor>();
    line_size = settings.value("settings/dot_size", 2).toInt();
    dot_size = settings.value("settings/line_size", 2).toInt();
}

void settingController::saveSettings() {
    settings.clear();
    settings.setValue("settings/type_line", type_line);
    settings.setValue("settings/center", center);
    settings.setValue("settings/dot_type", dot_type);
    settings.setValue("settings/dot_size", dot_size);
    settings.setValue("settings/line_size", line_size);
    settings.setValue("settings/line_color", line_color);
    settings.setValue("settings/dots_color", dot_color);
    settings.setValue("settings/background_color", background_color);
    settings.sync();
}

QVariant settingController::getParam(QString param) {
    if (param.contains("color")) {
        if (param.contains("line")) {
            return line_color;
        } else if (param.contains("dots")) {
            return dot_color;
        } else if (param.contains("background")) {
            return background_color;
        }
    } else if (param.contains("size")) {
        if (param.contains("line")) {
            return line_size;
        } else if (param.contains("dots")) {
            return dot_size;
        }
    }
    emit getNewSetting();
}

void settingController::setParam(QString param, QColor data) {
    QString write("settings/");
     write.append(param);
    if (param.contains("line")) {
        line_color = data;
    } else if (param.contains("dots")) {
        dot_color = data;
    } else if (param.contains("background")) {
        background_color = data;
    }
}

void settingController::setParam(QString param,  int data) {
    if (param.contains("size")) {
        if (param.contains("dots")) {
            line_size = data;
        } else if (param.contains("line")) {
            dot_size = data;
        }
    }

}
