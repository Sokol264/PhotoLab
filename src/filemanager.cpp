#include "filemanager.h"

FileManager::FileManager() {}

QImage FileManager::ReadPixmapFromFile(QString filename) {
    QImage image = QImage(filename);
    image.convertTo(QImage::Format_RGB32);
    return image;
}
