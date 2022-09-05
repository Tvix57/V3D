/********************************************************************************
** Form generated from reading UI file 'dialog_size.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SIZE_H
#define UI_DIALOG_SIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_size
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_size)
    {
        if (Dialog_size->objectName().isEmpty())
            Dialog_size->setObjectName(QString::fromUtf8("Dialog_size"));
        Dialog_size->resize(400, 84);
        horizontalLayout_3 = new QHBoxLayout(Dialog_size);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(Dialog_size);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(25);

        horizontalLayout->addWidget(spinBox);

        label = new QLabel(Dialog_size);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line = new QFrame(Dialog_size);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        horizontalLayout_2->addWidget(line);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(Dialog_size);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        retranslateUi(Dialog_size);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_size, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_size, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_size);
    } // setupUi

    void retranslateUi(QDialog *Dialog_size)
    {
        Dialog_size->setWindowTitle(QCoreApplication::translate("Dialog_size", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_size", " pxc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_size: public Ui_Dialog_size {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SIZE_H
