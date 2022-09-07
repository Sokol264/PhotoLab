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
    void SetKernelCommand(std::vector<std::vector<double>> &kernel);
    void ExecCommand(ImageManager::CommandType type, QLabel *picture);
    void SetBrightness(int value);
    void SetContrast(int value);
private:
    QImage inputImage, outputImage;
    FileManager fileManager;
    ImageManager imageManager;
};

#endif // FACADE_H
