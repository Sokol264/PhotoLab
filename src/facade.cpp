#include "facade.h"
#include <QGraphicsPixmapItem>

Facade::Facade() {}

void Facade::OpenFile(QString filename) {
    outputImage = inputImage = fileManager.ReadPixmapFromFile(filename);
}

void Facade::UpdatePicture(TypeImage type, QLabel *picture) {
    int width = picture->width();
    int height = picture->height();
    QImage image = (type == Input) ? inputImage : outputImage;
    QPixmap pixmap = QPixmap::fromImage(image);
    picture->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Facade::InsertCommand(ImageManager::CommandType type, QLabel *picture) {
    imageManager.SetImage(&outputImage);
    imageManager.InsertActiveCommand(type);
    UpdatePicture(Output, picture);
}

void Facade::RemoveCommand(ImageManager::CommandType type, QLabel *picture) {
    outputImage = inputImage;
    imageManager.SetImage(&outputImage);
    imageManager.RemoveActiveCommand(type);
    UpdatePicture(Output, picture);
}

void Facade::SetColor(QColor color) {
    imageManager.SetColor(color);
}

