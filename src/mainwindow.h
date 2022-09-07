#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller/controller.h"
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller *controller, QWidget *parent = nullptr);
    ~MainWindow();

private:
    void ConnectSlots();

private slots:
    void on_openFileButton_clicked();
    void checkBoxStateChanged(int state);

    void on_checkBox_3_stateChanged(int arg1);
    void on_checkBox_10_stateChanged(int arg1);

    void applyKernel(std::vector<std::vector<double>> &kernel);

    void on_brightnessSlider_valueChanged(int value);

    void on_constrastSlider_valueChanged(int value);

private:
    Controller *controller;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
