#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customkerneldialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include "command.h"

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , controller(controller)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectSlots();
}

void MainWindow::ConnectSlots() {
    for (int i = 0; i < ui->verticalLayout->count() - 1; ++i) {
        auto checkBox = qobject_cast<QCheckBox*>(ui->verticalLayout->itemAt(i)->widget());
        connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChanged(int)));
    }
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

void MainWindow::checkBoxStateChanged(int state) {
    auto checkBox = static_cast<QCheckBox*>(sender());
    auto name = checkBox->objectName().remove("checkBox_");
    int number = name.toInt() - 1;
    if (state) {
        controller->InsertCommand(static_cast<ImageManager::CommandType>(number), ui->outputImage);
    } else {
        controller->RemoveCommand(static_cast<ImageManager::CommandType>(number), ui->outputImage);
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

void MainWindow::on_checkBox_10_stateChanged(int arg1) {
    if (arg1) {
        CustomKernelDialog *window = new CustomKernelDialog();
        connect(window, SIGNAL(GetKernel(std::vector<std::vector<int>> &)), this, SLOT(applyKernel(std::vector<std::vector<int>> &)));

        window->show();
        std::vector<std::vector<int>> kernel;
    }
}

void MainWindow::applyKernel(std::vector<std::vector<int>> &kernel) {
    controller->InsertCommand(ImageManager::CustomFilter, ui->outputImage);
}
