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

    decltype(auto) getParam(QString);
    void setParam();

signals:
    void getNewSetting();

private:
    QSettings settings { "Ajhin_team", "3D_viewer" };
    int line_size, dot_size;
    QColor dot_color, line_color, background_color;
};

#endif // SETTINGCONTROLLER_H
