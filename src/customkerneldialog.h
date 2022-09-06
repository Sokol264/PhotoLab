#ifndef CUSTOMKERNELDIALOG_H
#define CUSTOMKERNELDIALOG_H

#include <QDialog>

namespace Ui {
class CustomKernelDialog;
}

class CustomKernelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomKernelDialog(QWidget *parent = nullptr);
    ~CustomKernelDialog();
signals:
    void GetKernel(std::vector<std::vector<int>> &kernel);
private:
    void UpdateGrid();
    std::vector<std::vector<int>> kernel;
    Ui::CustomKernelDialog *ui;
private slots:
    void changedGridSize();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
};

#endif // CUSTOMKERNELDIALOG_H
