/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open_file;
    QAction *center_parallel;
    QAction *center;
    QAction *save_Jpeg;
    QAction *save_Bnp;
    QAction *get_back_color;
    QAction *save_gif;
    QAction *type_line;
    QAction *type_dot_line;
    QAction *get_size_line;
    QAction *get_color_line;
    QAction *get_size_pick;
    QAction *get_color_pick;
    QAction *view_type_circle;
    QAction *view_type_qadro;
    QAction *view_type_none;
    QAction *action;
    QAction *actionAbout;
    QAction *actiontest_2;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QWidget *tabWidgetPage2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QDial *dial_4;
    QDial *dial;
    QDial *dial_2;
    QWidget *tabWidgetPage1;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_forward;
    QPushButton *btn_back;
    QPushButton *btn_left;
    QPushButton *btn_up;
    QPushButton *btn_down;
    QPushButton *btn_right;
    GLWidget *open_GLWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_5;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_9;
    QMenu *menu_8;
    QMenu *menuHelp;
    QMenu *menutest;
    QStatusBar *statusbar;
    QButtonGroup *Group_btn_move;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1081, 876);
        action_open_file = new QAction(MainWindow);
        action_open_file->setObjectName(QString::fromUtf8("action_open_file"));
        center_parallel = new QAction(MainWindow);
        center_parallel->setObjectName(QString::fromUtf8("center_parallel"));
        center_parallel->setCheckable(true);
        center_parallel->setChecked(false);
        center = new QAction(MainWindow);
        center->setObjectName(QString::fromUtf8("center"));
        center->setCheckable(true);
        save_Jpeg = new QAction(MainWindow);
        save_Jpeg->setObjectName(QString::fromUtf8("save_Jpeg"));
        save_Bnp = new QAction(MainWindow);
        save_Bnp->setObjectName(QString::fromUtf8("save_Bnp"));
        get_back_color = new QAction(MainWindow);
        get_back_color->setObjectName(QString::fromUtf8("get_back_color"));
        save_gif = new QAction(MainWindow);
        save_gif->setObjectName(QString::fromUtf8("save_gif"));
        type_line = new QAction(MainWindow);
        type_line->setObjectName(QString::fromUtf8("type_line"));
        type_line->setCheckable(true);
        type_dot_line = new QAction(MainWindow);
        type_dot_line->setObjectName(QString::fromUtf8("type_dot_line"));
        type_dot_line->setCheckable(true);
        get_size_line = new QAction(MainWindow);
        get_size_line->setObjectName(QString::fromUtf8("get_size_line"));
        get_color_line = new QAction(MainWindow);
        get_color_line->setObjectName(QString::fromUtf8("get_color_line"));
        get_size_pick = new QAction(MainWindow);
        get_size_pick->setObjectName(QString::fromUtf8("get_size_pick"));
        get_color_pick = new QAction(MainWindow);
        get_color_pick->setObjectName(QString::fromUtf8("get_color_pick"));
        view_type_circle = new QAction(MainWindow);
        view_type_circle->setObjectName(QString::fromUtf8("view_type_circle"));
        view_type_circle->setCheckable(true);
        view_type_qadro = new QAction(MainWindow);
        view_type_qadro->setObjectName(QString::fromUtf8("view_type_qadro"));
        view_type_qadro->setCheckable(true);
        view_type_none = new QAction(MainWindow);
        view_type_none->setObjectName(QString::fromUtf8("view_type_none"));
        view_type_none->setCheckable(true);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actiontest_2 = new QAction(MainWindow);
        actiontest_2->setObjectName(QString::fromUtf8("actiontest_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(true);
        tabWidgetPage3 = new QWidget();
        tabWidgetPage3->setObjectName(QString::fromUtf8("tabWidgetPage3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidgetPage3->sizePolicy().hasHeightForWidth());
        tabWidgetPage3->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(tabWidgetPage3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_3 = new QLabel(tabWidgetPage3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalSlider = new QSlider(tabWidgetPage3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy3);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout_5->addLayout(verticalLayout);

        tabWidget->addTab(tabWidgetPage3, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        sizePolicy1.setHeightForWidth(tabWidgetPage2->sizePolicy().hasHeightForWidth());
        tabWidgetPage2->setSizePolicy(sizePolicy1);
        tabWidgetPage2->setMinimumSize(QSize(0, 0));
        tabWidgetPage2->setMaximumSize(QSize(16777215, 16777215));
        tabWidgetPage2->setAutoFillBackground(false);
        horizontalLayout_3 = new QHBoxLayout(tabWidgetPage2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(tabWidgetPage2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(label_6);

        label_5 = new QLabel(tabWidgetPage2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(label_5);

        label_2 = new QLabel(tabWidgetPage2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(label_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dial_4 = new QDial(tabWidgetPage2);
        dial_4->setObjectName(QString::fromUtf8("dial_4"));

        horizontalLayout_2->addWidget(dial_4);

        dial = new QDial(tabWidgetPage2);
        dial->setObjectName(QString::fromUtf8("dial"));

        horizontalLayout_2->addWidget(dial);

        dial_2 = new QDial(tabWidgetPage2);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));

        horizontalLayout_2->addWidget(dial_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tabWidget->addTab(tabWidgetPage2, QString());
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        sizePolicy1.setHeightForWidth(tabWidgetPage1->sizePolicy().hasHeightForWidth());
        tabWidgetPage1->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(tabWidgetPage1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(-1);
#endif
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_forward = new QPushButton(tabWidgetPage1);
        Group_btn_move = new QButtonGroup(MainWindow);
        Group_btn_move->setObjectName(QString::fromUtf8("Group_btn_move"));
        Group_btn_move->addButton(btn_forward);
        btn_forward->setObjectName(QString::fromUtf8("btn_forward"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_forward->sizePolicy().hasHeightForWidth());
        btn_forward->setSizePolicy(sizePolicy5);
        btn_forward->setMinimumSize(QSize(50, 25));
        btn_forward->setMaximumSize(QSize(50, 25));
        btn_forward->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/icons8-\321\202\320\276\320\273\321\201\321\202\320\260\321\217-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-\320\262\320\262\320\265\321\200\321\205-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_forward->setIcon(icon);
        btn_forward->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(btn_forward);

        btn_back = new QPushButton(tabWidgetPage1);
        Group_btn_move->addButton(btn_back);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        sizePolicy5.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy5);
        btn_back->setMinimumSize(QSize(50, 25));
        btn_back->setMaximumSize(QSize(50, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/icons8-\321\202\320\276\320\273\321\201\321\202\320\260\321\217-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-\320\262\320\275\320\270\320\267-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_back->setIcon(icon1);
        btn_back->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(btn_back);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        btn_left = new QPushButton(tabWidgetPage1);
        Group_btn_move->addButton(btn_left);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        sizePolicy5.setHeightForWidth(btn_left->sizePolicy().hasHeightForWidth());
        btn_left->setSizePolicy(sizePolicy5);
        btn_left->setMinimumSize(QSize(50, 50));
        btn_left->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/icons8-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_left->setIcon(icon2);

        gridLayout->addWidget(btn_left, 1, 2, 1, 1);

        btn_up = new QPushButton(tabWidgetPage1);
        Group_btn_move->addButton(btn_up);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        sizePolicy5.setHeightForWidth(btn_up->sizePolicy().hasHeightForWidth());
        btn_up->setSizePolicy(sizePolicy5);
        btn_up->setMinimumSize(QSize(50, 50));
        btn_up->setMaximumSize(QSize(50, 50));
        btn_up->setIcon(icon);

        gridLayout->addWidget(btn_up, 0, 1, 1, 1);

        btn_down = new QPushButton(tabWidgetPage1);
        Group_btn_move->addButton(btn_down);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        sizePolicy5.setHeightForWidth(btn_down->sizePolicy().hasHeightForWidth());
        btn_down->setSizePolicy(sizePolicy5);
        btn_down->setMinimumSize(QSize(50, 50));
        btn_down->setMaximumSize(QSize(50, 50));
        btn_down->setIcon(icon1);

        gridLayout->addWidget(btn_down, 2, 1, 1, 1);

        btn_right = new QPushButton(tabWidgetPage1);
        Group_btn_move->addButton(btn_right);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        sizePolicy5.setHeightForWidth(btn_right->sizePolicy().hasHeightForWidth());
        btn_right->setSizePolicy(sizePolicy5);
        btn_right->setMinimumSize(QSize(50, 50));
        btn_right->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/icons8-\321\201\321\202\321\200\320\265\320\273\320\272\320\260,-\321\203\320\272\320\260\320\267\321\213\320\262\320\260\321\216\321\211\320\260\321\217-\320\262\320\273\320\265\320\262\320\276-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_right->setIcon(icon3);

        gridLayout->addWidget(btn_right, 1, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        tabWidget->addTab(tabWidgetPage1, QString());

        gridLayout_2->addWidget(tabWidget, 5, 6, 1, 1);

        open_GLWidget = new GLWidget(centralwidget);
        open_GLWidget->setObjectName(QString::fromUtf8("open_GLWidget"));
        sizePolicy.setHeightForWidth(open_GLWidget->sizePolicy().hasHeightForWidth());
        open_GLWidget->setSizePolicy(sizePolicy);
        open_GLWidget->setStyleSheet(QString::fromUtf8("width: 100%;\n"
"height: 100%;"));

        gridLayout_2->addWidget(open_GLWidget, 0, 0, 6, 7);

        MainWindow->setCentralWidget(centralwidget);
        open_GLWidget->raise();
        tabWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1081, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_5 = new QMenu(menu);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_6 = new QMenu(menu_3);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        menu_7 = new QMenu(menu_2);
        menu_7->setObjectName(QString::fromUtf8("menu_7"));
        menu_9 = new QMenu(menu_7);
        menu_9->setObjectName(QString::fromUtf8("menu_9"));
        menu_8 = new QMenu(menubar);
        menu_8->setObjectName(QString::fromUtf8("menu_8"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menutest = new QMenu(menuHelp);
        menutest->setObjectName(QString::fromUtf8("menutest"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_8->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menu->addAction(action_open_file);
        menu->addAction(menu_5->menuAction());
        menu_5->addAction(save_Jpeg);
        menu_5->addAction(save_Bnp);
        menu_5->addAction(save_gif);
        menu_2->addAction(menu_4->menuAction());
        menu_2->addAction(menu_3->menuAction());
        menu_2->addAction(menu_7->menuAction());
        menu_2->addAction(get_back_color);
        menu_2->addAction(action);
        menu_4->addAction(center_parallel);
        menu_4->addAction(center);
        menu_3->addAction(menu_6->menuAction());
        menu_3->addAction(get_size_line);
        menu_3->addAction(get_color_line);
        menu_6->addAction(type_line);
        menu_6->addAction(type_dot_line);
        menu_7->addAction(get_size_pick);
        menu_7->addAction(get_color_pick);
        menu_7->addAction(menu_9->menuAction());
        menu_9->addAction(view_type_none);
        menu_9->addAction(view_type_qadro);
        menu_9->addAction(view_type_circle);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(menutest->menuAction());
        menutest->addAction(actiontest_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D_Viewer", nullptr));
        action_open_file->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        center_parallel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        center->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        save_Jpeg->setText(QCoreApplication::translate("MainWindow", "Jpeg", nullptr));
        save_Bnp->setText(QCoreApplication::translate("MainWindow", "Bmp", nullptr));
        get_back_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        save_gif->setText(QCoreApplication::translate("MainWindow", "Gif", nullptr));
        type_line->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270", nullptr));
        type_dot_line->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200", nullptr));
        get_size_line->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        get_color_line->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        get_size_pick->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        get_color_pick->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        view_type_circle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        view_type_qadro->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        view_type_none->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\321\203\321\200\321\213", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actiontest_2->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage3), QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QString());
#if QT_CONFIG(whatsthis)
        btn_forward->setWhatsThis(QCoreApplication::translate("MainWindow", "Forward", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_forward->setText(QString());
#if QT_CONFIG(shortcut)
        btn_forward->setShortcut(QCoreApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        btn_back->setWhatsThis(QCoreApplication::translate("MainWindow", "Back", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_back->setText(QString());
#if QT_CONFIG(shortcut)
        btn_back->setShortcut(QCoreApplication::translate("MainWindow", "C", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        btn_left->setWhatsThis(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_left->setText(QString());
#if QT_CONFIG(shortcut)
        btn_left->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        btn_up->setWhatsThis(QCoreApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_up->setText(QString());
#if QT_CONFIG(shortcut)
        btn_up->setShortcut(QCoreApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        btn_down->setWhatsThis(QCoreApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_down->setText(QString());
#if QT_CONFIG(shortcut)
        btn_down->setShortcut(QCoreApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        btn_right->setWhatsThis(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_right->setText(QString());
#if QT_CONFIG(shortcut)
        btn_right->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\320\265\320\261\320\265\321\200", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        menu_9->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        menu_8->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\276\320\275", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menutest->setTitle(QCoreApplication::translate("MainWindow", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
