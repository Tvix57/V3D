#include "dialog_size.h"

#include "ui_dialog_size.h"

Dialog_size::Dialog_size(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog_size) {
    ui->setupUi(this);
}

Dialog_size::~Dialog_size() { delete ui; }

void Dialog_size::on_spinBox_valueChanged(int arg1) {
    ui->line->setLineWidth(arg1);
}

void Dialog_size::set_default(int val, QColor color) {
    ui->spinBox->setValue(val);
    ui->line->setPalette(color);
    ui->line->setLineWidth(val);
}

int Dialog_size::get_value() { return ui->spinBox->value(); }
