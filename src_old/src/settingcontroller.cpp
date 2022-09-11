#include "settingcontroller.h"


settingController::settingController(QObject *parent)
    : QObject{parent}
{
    loadSettting();
}

void settingController::loadSettting() {
    type_line = settings.value("settings/line_type", 0).toInt();
    center = settings.value("settings/center", 0).toInt();
    dot_type = settings.value("settings/dots_type", 0).toInt();
    dot_color = settings.value("settings/dots_color", QColor(Qt::green)).value<QColor>();
    background_color = settings.value("settings/background_color", QColor(Qt::black)).value<QColor>();
    line_color = settings.value("settings/line_color", QColor(Qt::blue)).value<QColor>();
    line_size = settings.value("settings/line_size", 2).toInt();
    dot_size = settings.value("settings/dots_size", 2).toInt();
}

void settingController::saveSettings() {
    settings.clear();
    settings.setValue("settings/line_type", type_line);
    settings.setValue("settings/center", center);
    settings.setValue("settings/dots_type", dot_type);
    settings.setValue("settings/dots_size", dot_size);
    settings.setValue("settings/line_size", line_size);
    settings.setValue("settings/line_color", line_color);
    settings.setValue("settings/dots_color", dot_color);
    settings.setValue("settings/background_color", background_color);
    settings.sync();
}

QVariant settingController::getParam(QString param) {
    QVariant data;
    data.clear();
    if (param.contains("color")) {
        if (param.contains("line")) {
            data = line_color;
        } else if (param.contains("dots")) {
            data = dot_color;
        } else if (param.contains("background")) {
            data = background_color;
        }
    } else if (param.contains("size")) {
        if (param.contains("line")) {
            data = line_size;
        } else if (param.contains("dots")) {
            data = dot_size;
        }
    } else if (param.contains("type")) {
        if (param.contains("line")) {
            data = type_line;
        } else if (param.contains("dots"))  {
            data = dot_type;
        }
    } else {
        data = center;
    }
    emit getNewSetting();
    return data;
}

void settingController::setParam(QString param, QColor data) {
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
            dot_size = data;
        } else if (param.contains("line")) {
            line_size = data;
        }
    } else if (param.contains("type")){
        if (param.contains("dots")) {
            dot_type = data;
        } else if (param.contains("line")) {
            type_line = data;
        }
    } else {
        center = data;
    }
}
