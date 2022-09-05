#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include "command.h"

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , controller(controller)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_openFileButton_clicked() {
    auto filename = QFileDialog::getOpenFileName(this, tr("Open Image file"), "/", tr("Image Files (*.bmp)"));
    if (!filename.isEmpty()) {
        controller->ReadFile(filename);
        controller->UpdatePicture(Facade::Input, ui->inputImage);
        controller->UpdatePicture(Facade::Output, ui->outputImage);
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::Discoloration, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::Discoloration, ui->outputImage);
    }
}


void MainWindow::on_checkBox_2_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::Negative, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::Negative, ui->outputImage);
    }
}

void MainWindow::on_checkBox_3_stateChanged(int arg1) {
    if (arg1) {
        QPalette palette = ui->checkBox_3->palette();
        QColor color = palette.color(QPalette::WindowText);
        color = QColorDialog::getColor(color);
        if (color.isValid()) {
            palette.setColor(QPalette::WindowText, color);
        } else {
            color = palette.color(QPalette::WindowText);
        }
        ui->checkBox_3->setPalette(palette);
        controller->SetColorCommand(color);
        controller->InsertCommand(ImageManager::Toning, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::Toning, ui->outputImage);
    }
}

void MainWindow::on_checkBox_4_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::Emboss, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::Emboss, ui->outputImage);
    }
}


void MainWindow::on_checkBox_5_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::Sharpen, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::Sharpen, ui->outputImage);
    }
}


void MainWindow::on_checkBox_6_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::BoxBlur, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::BoxBlur, ui->outputImage);
    }
}

void MainWindow::on_checkBox_7_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::GaussianBlur, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::GaussianBlur, ui->outputImage);
    }
}

void MainWindow::on_checkBox_8_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::LaplacianFilter, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::LaplacianFilter, ui->outputImage);
    }
}

void MainWindow::on_checkBox_9_stateChanged(int arg1) {
    if (arg1) {
        controller->InsertCommand(ImageManager::SobelFilter, ui->outputImage);
    } else {
        controller->RemoveCommand(ImageManager::SobelFilter, ui->outputImage);
    }
}


void MainWindow::on_checkBox_10_stateChanged(int arg1) {
    if (arg1) {
        QDialog *customKernelReader = new QDialog(this);
//        customKernelReader
        customKernelReader->show();
    }
}
