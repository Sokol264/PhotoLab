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
    allCommands[9] = new CustomFilterCommand();
    allCommands[10] = new BrightnessChangeCommand();
    allCommands[11] = new ContrastChangeCommand();
}

void ImageManager::SetColor(QColor color) {
    static_cast<ToningCommand*>(allCommands[Toning])->SetColor(color);
}

void ImageManager::InsertActiveCommand(CommandType type) {
    activeCommandIndex.push_back(type);
    allCommands[type]->Execute(image);
}

void ImageManager::ExecuteAllActiveCommands() {
    for (auto i = activeCommandIndex.begin(); i < activeCommandIndex.end(); ++i) {
        allCommands[*i]->Execute(image);
    }
    static_cast<BrightnessChangeCommand*>(allCommands[BrightnessChange])->SetOriginImage(image);
    static_cast<ContrastChangeCommand*>(allCommands[ContrastChange])->SetOriginImage(image);
    allCommands[BrightnessChange]->Execute(image);
    allCommands[ContrastChange]->Execute(image);
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

void ImageManager::SetImage(QImage *image) { this->image = image; }

void ImageManager::SetOriginImage(QImage *image) {
    static_cast<BrightnessChangeCommand*>(allCommands[BrightnessChange])->SetOriginImage(image);
    static_cast<ContrastChangeCommand*>(allCommands[ContrastChange])->SetOriginImage(image);
}

void ImageManager::SetKernelCommand(std::vector<std::vector<double> > &kernel) {
    static_cast<CustomFilterCommand*>(allCommands[CustomFilter])->SetKernel(kernel);
}

void ImageManager::SetBrightness(int value) {
    static_cast<BrightnessChangeCommand*>(allCommands[BrightnessChange])->SetBrightness(value);
}

void ImageManager::SetContrast(int value) {
    static_cast<ContrastChangeCommand*>(allCommands[ContrastChange])->SetContrast(value);
}

void ImageManager::ExecCommand(CommandType type) {
    allCommands[type]->Execute(image);
}

ImageManager::~ImageManager() {
    for (size_t i = 0; i < allCommands.size(); ++i) {
        delete allCommands[i];
    }
}
