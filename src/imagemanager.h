#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <QImage>
#include "command.h"
#include <vector>

class ImageManager
{
public:
    enum CommandType {
        Discoloration = 0,
        Negative,
        Toning,
        Emboss,
        Sharpen,
        BoxBlur,
        GaussianBlur,
        LaplacianFilter,
        SobelFilter,
        CustomFilter,
        BrightnessChange,
        ContrastChange
    };
    ImageManager();
    void SetImage(QImage *image);
    void SetOriginImage(QImage *image);
    void SetColor(QColor color);
    void InsertActiveCommand(CommandType type);
    void RemoveActiveCommand(CommandType type);
    void SetKernelCommand(std::vector<std::vector<double>> &kernel);
    void SetBrightness(int value);
    void SetContrast(int value);
    void ExecCommand(ImageManager::CommandType type);
    ~ImageManager();
private:
    void ExecuteAllActiveCommands();

    std::vector<Command*> allCommands;
    std::vector<int> activeCommandIndex;
    QImage *image;
};

#endif // IMAGEMANAGER_H
