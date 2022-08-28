#ifndef SRC_INCLUDE_DIALOG_SIZE_H_
#define SRC_INCLUDE_DIALOG_SIZE_H_

#include <QDialog>

namespace Ui {
class Dialog_size;
}

class Dialog_size : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog_size(QWidget *parent = nullptr);
  ~Dialog_size();
  void set_default(int val, QColor color);
  int get_value();

 private slots:
  void on_spinBox_valueChanged(int arg1);

 private:
  Ui::Dialog_size *ui;
};

#endif  // SRC_INCLUDE_DIALOG_SIZE_H_
