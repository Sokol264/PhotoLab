#ifndef COMMAND_H
#define COMMAND_H

#include "QtCore/qdebug.h"
#include <QImage>
#include <QColor>

class Command {
public:
    virtual ~Command() {}
    explicit Command() : image(nullptr) {}
    virtual void Execute(QImage *image) = 0;
protected:
    QImage *image;
};

class DiscolorationCommand : public Command {
public:
    void Execute(QImage *image);
private:
    QColor MiddleGrey(QColor &pixel);
};

class NegativeCommand : public Command {
public:
    void Execute(QImage *image);
private:
    QColor NegateColor(QColor &pixel);
};

class ToningCommand : public Command {
public:
    void Execute(QImage *image);
    void SetColor(QColor color)  { this->color = color; }
private:
    QColor color;
    QColor ToningColor(QColor &pixel);
};

class ConvolutionFiltersCommand : public Command {
public:
    void Execute(QImage *image);
protected:
    std::vector<std::vector<double>> kernel;
    double coefficient = 1;
    QColor ApplyFilter(QImage &image, int index, int jndex);
};

class EmbossFilterCommand : public ConvolutionFiltersCommand {
public:
    EmbossFilterCommand() { kernel = std::vector<std::vector<double>>({{ -2, -1, 0 },
                                                                        { -1, 1, 1 },
                                                                        { 0, 1, 2 }});
                          }
};

class SharpenFilterCommand : public ConvolutionFiltersCommand {
public:
    SharpenFilterCommand() { kernel = std::vector<std::vector<double>>({{ -1, -1, -1 },
                                                                        { -1, 10, -1 },
                                                                        { -1, -1, -1 }});
                             coefficient = 2;
                           }
};

class BoxBlurFilterCommand : public ConvolutionFiltersCommand {
public:
    BoxBlurFilterCommand() { kernel = std::vector<std::vector<double>>({{ 1, 1, 1 },
                                                                        { 1, 1, 1 },
                                                                        { 1, 1, 1 }});
                             coefficient = 9;
                          }
};

class GaussianBlurFilterCommand : public ConvolutionFiltersCommand {
public:
    GaussianBlurFilterCommand() { kernel = std::vector<std::vector<double>>({{ 1, 2, 1 },
                                                                            { 2, 4, 2 },
                                                                            { 1, 2, 1 }});
                             coefficient = 16;
                          }
};

class LaplacianFilterCommand : public ConvolutionFiltersCommand {
public:
    LaplacianFilterCommand() { kernel = std::vector<std::vector<double>>({{ -1, -1, -1 },
                                                                          { -1, 8, -1 },
                                                                          { -1, -1, -1 }});
                          }
};

class SobelFilterCommand : public ConvolutionFiltersCommand {
public:
    SobelFilterCommand() { kernel = std::vector<std::vector<double>>({{ 1, 0, -1 },
                                                                    { 2, 0, -2 },
                                                                    { 1, 0, -1 }});
                          }

};

class CustomFilterCommand : public ConvolutionFiltersCommand {
public:
    void SetKernel(std::vector<std::vector<double>> kernel)  { this->kernel = kernel; }
};

class BrightnessChangeCommand : public Command {
public:
    void Execute(QImage *image);
    void SetBrightness(int value) { this->brightness = value; }
    void SetOriginImage(QImage *image) { this->originImage = *image; }
private:
    QImage originImage;
    QColor CalcNewColor(QColor &pixel);
    int brightness;
};

class ContrastChangeCommand : public Command {
public:
    void Execute(QImage *image);
    void SetContrast(int value) { this->contrast = value; }
    void SetOriginImage(QImage *image) { this->originImage = *image; }
private:
    QImage originImage;
    QColor CalcNewColor(QColor &pixel);
    int contrast;
};




#endif // COMMAND_H
