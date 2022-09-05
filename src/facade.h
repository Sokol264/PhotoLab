#ifndef FACADE_H
#define FACADE_H

#include "filemanager.h"
#include "imagemanager.h"
#include <iostream>
#include <QPixmap>
#include <QLabel>

class Facade {
public:
    enum TypeImage { Input, Output };
    Facade();
    void OpenFile(QString filename);
    void UpdatePicture(TypeImage type, QLabel *picture);
    void InsertCommand(ImageManager::CommandType type, QLabel *picture);
    void RemoveCommand(ImageManager::CommandType type, QLabel *picture);
    void SetColor(QColor color);

private:
    QImage inputImage, outputImage;
    FileManager fileManager;
    ImageManager imageManager;
};

#endif // FACADE_H
