#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include <QSettings>
#include <QColor>

class settingController : public QObject
{
    Q_OBJECT
public:
    explicit settingController(QObject *parent = nullptr);
    void loadSettting();
    void saveSettings();

    QVariant getParam(QString);
    void setParam(QString, int data);
    void setParam(QString, QColor data);

signals:
    void getNewSetting();

private:
    QSettings settings { "Ajhin_team", "3D_viewer" };
    int line_size, dot_size;
    QColor dot_color, line_color, background_color;
    int type_line = 0;
    int center = 0;
    int dot_type = 0;
};

#endif // SETTINGCONTROLLER_H
