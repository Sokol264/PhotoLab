#include "imagemanager.h"

ImageManager::ImageManager() : image(nullptr), allCommands(2) {
    allCommands[0] = new DiscolorationCommand();
    allCommands[1] = new NegativeCommand();
}

void ImageManager::SetImage(QImage *image) { this->image = image; }

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

