/********************************************************************************
** Form generated from reading UI file 'customkerneldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMKERNELDIALOG_H
#define UI_CUSTOMKERNELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomKernelDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *heightLabel;
    QSpinBox *heightSpinBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *CustomKernelDialog)
    {
        if (CustomKernelDialog->objectName().isEmpty())
            CustomKernelDialog->setObjectName(QString::fromUtf8("CustomKernelDialog"));
        CustomKernelDialog->resize(249, 275);
        buttonBox = new QDialogButtonBox(CustomKernelDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 240, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(CustomKernelDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 231, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        heightLabel = new QLabel(horizontalLayoutWidget);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));

        horizontalLayout->addWidget(heightLabel);

        heightSpinBox = new QSpinBox(horizontalLayoutWidget);
        heightSpinBox->setObjectName(QString::fromUtf8("heightSpinBox"));
        heightSpinBox->setMinimum(1);
        heightSpinBox->setMaximum(16);
        heightSpinBox->setSingleStep(1);
        heightSpinBox->setValue(3);

        horizontalLayout->addWidget(heightSpinBox);

        widthLabel = new QLabel(horizontalLayoutWidget);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));

        horizontalLayout->addWidget(widthLabel);

        widthSpinBox = new QSpinBox(horizontalLayoutWidget);
        widthSpinBox->setObjectName(QString::fromUtf8("widthSpinBox"));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(16);
        widthSpinBox->setValue(3);

        horizontalLayout->addWidget(widthSpinBox);

        gridLayoutWidget = new QWidget(CustomKernelDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 231, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(CustomKernelDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CustomKernelDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CustomKernelDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CustomKernelDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomKernelDialog)
    {
        CustomKernelDialog->setWindowTitle(QCoreApplication::translate("CustomKernelDialog", "Dialog", nullptr));
        heightLabel->setText(QCoreApplication::translate("CustomKernelDialog", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        widthLabel->setText(QCoreApplication::translate("CustomKernelDialog", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomKernelDialog: public Ui_CustomKernelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMKERNELDIALOG_H
