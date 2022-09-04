#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
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

