#include "customkerneldialog.h"
#include "ui_customkerneldialog.h"

CustomKernelDialog::CustomKernelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomKernelDialog) {
    ui->setupUi(this);
    connect(ui->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changedGridSize()));
    connect(ui->heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changedGridSize()));
    UpdateGrid();
}

CustomKernelDialog::~CustomKernelDialog() {
    delete ui;
}

void CustomKernelDialog::UpdateGrid() {
    while( ui->gridLayout->count() ) {
        QWidget* widget = ui->gridLayout->itemAt(0)->widget();
        if( widget ) {
            ui->gridLayout->removeWidget(widget);
            delete widget;
        }
    }
    for (int i = 0; i < ui->heightSpinBox->value(); ++i) {
        for (int j = 0; j < ui->widthSpinBox->value(); ++j) {
            QSpinBox *inputSpinBox = new QSpinBox();
            inputSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
            inputSpinBox->setMinimum(-100);
            inputSpinBox->setMaximum(100);
            ui->gridLayout->addWidget(inputSpinBox, i, j);
        }
    }
}

void CustomKernelDialog::changedGridSize() {
    UpdateGrid();
}

void CustomKernelDialog::on_buttonBox_accepted() {
    kernel.clear();
    for (int i = 0; i < ui->gridLayout->rowCount(); ++i) {
        std::vector<double> rowKernel;
        for (int j = 0; j < ui->gridLayout->columnCount(); ++j) {
            QWidget* widget = ui->gridLayout->itemAt(i * ui->gridLayout->columnCount() + j)->widget();
            auto spinBox = qobject_cast<QSpinBox*>(widget);
            rowKernel.push_back(static_cast<double>(spinBox->value()));
        }
        kernel.push_back(rowKernel);
    }
    emit GetKernel(kernel);
}


void CustomKernelDialog::on_buttonBox_rejected() {
    kernel.clear();
}

