#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <QImage>
#include "command.h"
#include <vector>

class ImageManager
{
public:
    enum CommandType { Discoloration = 0, Negative };
    ImageManager();
    void SetImage(QImage *image);
    void InsertActiveCommand(CommandType type);
    void RemoveActiveCommand(CommandType type);
private:
    void ExecuteAllActiveCommands();

    std::vector<Command*> allCommands;
    std::vector<int> activeCommandIndex;
    QImage *image;
};

#endif // IMAGEMANAGER_H
