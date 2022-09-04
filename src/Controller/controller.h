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

private:
    Facade *facade;
};

#endif // CONTROLLER_H
