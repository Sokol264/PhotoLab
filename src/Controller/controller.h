#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "facade.h"

class Controller
{
public:
    Controller(Facade *facade);

    void ReadFile(QString filename);
    void UpdatePicture(Facade::TypeImage type, QLabel *picture);
    void InsertCommand(ImageManager::CommandType type, QLabel *picture);
    void RemoveCommand(ImageManager::CommandType type, QLabel *picture);
    void SetColorCommand(QColor color);
    void SetKernelCommand(std::vector<std::vector<double>> &kernel);
    void ExecCommand(ImageManager::CommandType type, QLabel *picture);
    void SetBrightness(int value);
    void SetContrast(int value);
private:
    Facade *facade;
};

#endif // CONTROLLER_H
