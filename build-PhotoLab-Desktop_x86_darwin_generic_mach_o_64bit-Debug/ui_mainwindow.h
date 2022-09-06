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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openFileButton;
    QPushButton *saveFileButton;
    QFrame *frame;
    QLabel *inputImage;
    QFrame *frame_2;
    QLabel *outputImage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(681, 258);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openFileButton = new QPushButton(centralwidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(80, 180, 100, 32));
        saveFileButton = new QPushButton(centralwidget);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));
        saveFileButton->setGeometry(QRect(490, 180, 100, 32));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 20, 250, 150));
        frame->setStyleSheet(QString::fromUtf8("QFrame {background:rgb(255, 255, 255);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        inputImage = new QLabel(frame);
        inputImage->setObjectName(QString::fromUtf8("inputImage"));
        inputImage->setGeometry(QRect(1, 1, 246, 147));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputImage->sizePolicy().hasHeightForWidth());
        inputImage->setSizePolicy(sizePolicy);
        inputImage->setScaledContents(false);
        inputImage->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(420, 20, 250, 150));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {background:rgb(255, 255, 255);}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        outputImage = new QLabel(frame_2);
        outputImage->setObjectName(QString::fromUtf8("outputImage"));
        outputImage->setGeometry(QRect(1, 1, 246, 147));
        sizePolicy.setHeightForWidth(outputImage->sizePolicy().hasHeightForWidth());
        outputImage->setSizePolicy(sizePolicy);
        outputImage->setStyleSheet(QString::fromUtf8("QFrame {background:rgb(255, 255, 255);}"));
        outputImage->setScaledContents(false);
        outputImage->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 20, 116, 209));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_1 = new QCheckBox(layoutWidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));

        verticalLayout->addWidget(checkBox_1);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        verticalLayout->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(layoutWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        verticalLayout->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(layoutWidget);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        verticalLayout->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(layoutWidget);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        verticalLayout->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(layoutWidget);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        verticalLayout->addWidget(checkBox_9);

        checkBox_10 = new QCheckBox(layoutWidget);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        verticalLayout->addWidget(checkBox_10);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        saveFileButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        inputImage->setText(QString());
        outputImage->setText(QString());
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "Discoloration", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Negative", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Toning", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Emboss", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Sharpen", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Box Blur", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Gaussian Blur", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "Laplacian Filter", nullptr));
        checkBox_9->setText(QCoreApplication::translate("MainWindow", "Sobel Filter", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", "Custom Kernel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
