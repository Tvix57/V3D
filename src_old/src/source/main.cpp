#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    setlocale(LC_NUMERIC, "C");
    QCoreApplication::setOrganizationName("Ajhin_team");
    QCoreApplication::setOrganizationDomain("s21_.com");
    QCoreApplication::setApplicationName("3D_viewer");
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "3DViewer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
