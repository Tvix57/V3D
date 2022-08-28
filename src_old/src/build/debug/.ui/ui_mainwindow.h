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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    GLWidget *open_GLWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *record_label;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QSlider *slider_x;
    QSlider *slider_y;
    QSlider *slider_z;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSlider *slider_scale;
    QGridLayout *gridLayout;
    QPushButton *btn_up;
    QPushButton *btn_down;
    QPushButton *btn_right;
    QPushButton *btn_left;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_forward;
    QPushButton *btn_back;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_5;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_9;
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        open_GLWidget = new GLWidget(centralwidget);
        open_GLWidget->setObjectName(QString::fromUtf8("open_GLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(open_GLWidget->sizePolicy().hasHeightForWidth());
        open_GLWidget->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(open_GLWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(0);

        horizontalLayout_3->addWidget(label_4);

        record_label = new QLabel(centralwidget);
        record_label->setObjectName(QString::fromUtf8("record_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(record_label->sizePolicy().hasHeightForWidth());
        record_label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(29);
        record_label->setFont(font);
        record_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        record_label->setMargin(0);

        horizontalLayout_3->addWidget(record_label);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        slider_x = new QSlider(centralwidget);
        slider_x->setObjectName(QString::fromUtf8("slider_x"));
        slider_x->setMaximum(360);
        slider_x->setValue(180);
        slider_x->setOrientation(Qt::Horizontal);
        slider_x->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(slider_x);

        slider_y = new QSlider(centralwidget);
        slider_y->setObjectName(QString::fromUtf8("slider_y"));
        slider_y->setMaximum(360);
        slider_y->setValue(180);
        slider_y->setTracking(true);
        slider_y->setOrientation(Qt::Horizontal);
        slider_y->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(slider_y);

        slider_z = new QSlider(centralwidget);
        slider_z->setObjectName(QString::fromUtf8("slider_z"));
        slider_z->setMaximum(360);
        slider_z->setValue(180);
        slider_z->setOrientation(Qt::Horizontal);
        slider_z->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(slider_z);


        horizontalLayout->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        slider_scale = new QSlider(centralwidget);
        slider_scale->setObjectName(QString::fromUtf8("slider_scale"));
        sizePolicy1.setHeightForWidth(slider_scale->sizePolicy().hasHeightForWidth());
        slider_scale->setSizePolicy(sizePolicy1);
        slider_scale->setMinimumSize(QSize(0, 120));
        slider_scale->setLayoutDirection(Qt::LeftToRight);
        slider_scale->setMinimum(1);
        slider_scale->setMaximum(51);
        slider_scale->setPageStep(5);
        slider_scale->setValue(1);
        slider_scale->setSliderPosition(1);
        slider_scale->setOrientation(Qt::Vertical);
        slider_scale->setInvertedAppearance(false);
        slider_scale->setInvertedControls(false);
        slider_scale->setTickPosition(QSlider::TicksBothSides);

        verticalLayout->addWidget(slider_scale);


        horizontalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        btn_up = new QPushButton(centralwidget);
        Group_btn_move = new QButtonGroup(MainWindow);
        Group_btn_move->setObjectName(QString::fromUtf8("Group_btn_move"));
        Group_btn_move->addButton(btn_up);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        sizePolicy3.setHeightForWidth(btn_up->sizePolicy().hasHeightForWidth());
        btn_up->setSizePolicy(sizePolicy3);
        btn_up->setMinimumSize(QSize(50, 50));
        btn_up->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/icons8-\321\202\320\276\320\273\321\201\321\202\320\260\321\217-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-\320\262\320\262\320\265\321\200\321\205-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_up->setIcon(icon);

        gridLayout->addWidget(btn_up, 0, 1, 1, 1);

        btn_down = new QPushButton(centralwidget);
        Group_btn_move->addButton(btn_down);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        sizePolicy3.setHeightForWidth(btn_down->sizePolicy().hasHeightForWidth());
        btn_down->setSizePolicy(sizePolicy3);
        btn_down->setMinimumSize(QSize(50, 50));
        btn_down->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/icons8-\321\202\320\276\320\273\321\201\321\202\320\260\321\217-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-\320\262\320\275\320\270\320\267-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_down->setIcon(icon1);

        gridLayout->addWidget(btn_down, 2, 1, 1, 1);

        btn_right = new QPushButton(centralwidget);
        Group_btn_move->addButton(btn_right);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        sizePolicy3.setHeightForWidth(btn_right->sizePolicy().hasHeightForWidth());
        btn_right->setSizePolicy(sizePolicy3);
        btn_right->setMinimumSize(QSize(50, 50));
        btn_right->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/icons8-\321\201\321\202\321\200\320\265\320\273\320\272\320\260,-\321\203\320\272\320\260\320\267\321\213\320\262\320\260\321\216\321\211\320\260\321\217-\320\262\320\273\320\265\320\262\320\276-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_right->setIcon(icon2);

        gridLayout->addWidget(btn_right, 1, 0, 1, 1);

        btn_left = new QPushButton(centralwidget);
        Group_btn_move->addButton(btn_left);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        sizePolicy3.setHeightForWidth(btn_left->sizePolicy().hasHeightForWidth());
        btn_left->setSizePolicy(sizePolicy3);
        btn_left->setMinimumSize(QSize(50, 50));
        btn_left->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/icons8-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_left->setIcon(icon3);

        gridLayout->addWidget(btn_left, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(-1);
#endif
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_forward = new QPushButton(centralwidget);
        Group_btn_move->addButton(btn_forward);
        btn_forward->setObjectName(QString::fromUtf8("btn_forward"));
        sizePolicy3.setHeightForWidth(btn_forward->sizePolicy().hasHeightForWidth());
        btn_forward->setSizePolicy(sizePolicy3);
        btn_forward->setMinimumSize(QSize(50, 25));
        btn_forward->setMaximumSize(QSize(50, 25));
        btn_forward->setLayoutDirection(Qt::LeftToRight);
        btn_forward->setIcon(icon);
        btn_forward->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(btn_forward);

        btn_back = new QPushButton(centralwidget);
        Group_btn_move->addButton(btn_back);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        sizePolicy3.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy3);
        btn_back->setMinimumSize(QSize(50, 25));
        btn_back->setMaximumSize(QSize(50, 25));
        btn_back->setIcon(icon1);
        btn_back->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(btn_back);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout_5->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
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
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action_open_file);
        menu->addAction(menu_5->menuAction());
        menu_5->addAction(save_Jpeg);
        menu_5->addAction(save_Bnp);
        menu_5->addAction(save_gif);
        menu_2->addAction(menu_4->menuAction());
        menu_2->addAction(menu_3->menuAction());
        menu_2->addAction(menu_7->menuAction());
        menu_2->addAction(get_back_color);
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D_Viewer", nullptr));
        action_open_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        record_label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\264\320\265\321\202 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 Z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
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
#if QT_CONFIG(whatsthis)
        btn_left->setWhatsThis(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_left->setText(QString());
#if QT_CONFIG(shortcut)
        btn_left->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
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
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\320\265\320\261\320\265\321\200", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        menu_9->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
