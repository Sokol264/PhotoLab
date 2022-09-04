#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <QPixmap>

class FileManager
{
public:
    FileManager();
    QImage ReadPixmapFromFile(QString filename);
};

#endif // FILEMANAGER_H
