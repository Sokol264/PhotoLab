#include "controller.h"

Controller::Controller(Facade *facade) : facade(facade) {}

void Controller::ReadFile(QString filename) {
    facade->OpenFile(filename);
}

void Controller::UpdatePicture(Facade::TypeImage type, QLabel *picture) {
    facade->UpdatePicture(type, picture);
}

void Controller::InsertCommand(ImageManager::CommandType type, QLabel *picture) {
    facade->InsertCommand(type, picture);
}

void Controller::RemoveCommand(ImageManager::CommandType type, QLabel *picture) {
    facade->RemoveCommand(type, picture);
}

void Controller::SetColorCommand(QColor color) {
    facade->SetColor(color);
}

void Controller::SetKernelCommand(std::vector<std::vector<double> > &kernel) {
    facade->SetKernelCommand(kernel);
}

void Controller::ExecCommand(ImageManager::CommandType type, QLabel *picture) {
    facade->ExecCommand(type, picture);
}

void Controller::SetBrightness(int value) {
    facade->SetBrightness(value);
}

void Controller::SetContrast(int value) {
    facade->SetContrast(value);
}

