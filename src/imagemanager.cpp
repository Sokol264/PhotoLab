#include "imagemanager.h"

ImageManager::ImageManager() : allCommands(9), image(nullptr) {
    allCommands[0] = new DiscolorationCommand();
    allCommands[1] = new NegativeCommand();
    allCommands[2] = new ToningCommand();
    allCommands[3] = new EmbossFilterCommand();
    allCommands[4] = new SharpenFilterCommand();
    allCommands[5] = new BoxBlurFilterCommand();
    allCommands[6] = new GaussianBlurFilterCommand();
    allCommands[7] = new LaplacianFilterCommand();
    allCommands[8] = new SobelFilterCommand();
}

void ImageManager::SetImage(QImage *image) { this->image = image; }

void ImageManager::SetColor(QColor color) { allCommands[Toning]->SetColor(color); }

void ImageManager::InsertActiveCommand(CommandType type) {
    activeCommandIndex.push_back(type);
    allCommands[type]->Execute(image);
}

void ImageManager::ExecuteAllActiveCommands() {
    for (auto i = activeCommandIndex.begin(); i < activeCommandIndex.end(); ++i) {
        allCommands[*i]->Execute(image);
    }
}

void ImageManager::RemoveActiveCommand(CommandType type) {
    for (auto i = activeCommandIndex.begin(); i < activeCommandIndex.end(); ++i) {
        if (*i == type) {
            activeCommandIndex.erase(i);
            break;
        }
    }
    ExecuteAllActiveCommands();
}

ImageManager::~ImageManager() {
    delete allCommands[0];
    delete allCommands[1];
    delete allCommands[2];
}
