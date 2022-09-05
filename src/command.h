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
    void SetColor(QColor color)  { this->color = color; }
    void SetKernel(std::vector<std::vector<double>> kernel)  { this->kernel = kernel; }
protected:
    QImage *image;
    QColor color;
    std::vector<std::vector<double>> kernel;
    double coefficient;
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
private:
    QColor ToningColor(QColor &pixel);
};

class ConvolutionFiltersCommand : public Command {
public:
    void Execute(QImage *image);
protected:
    QColor ApplyFilter(QImage &image, int index, int jndex);
};

class EmbossFilterCommand : public ConvolutionFiltersCommand {
public:
    EmbossFilterCommand() { kernel = std::vector<std::vector<double>>({{ -2, -1, 0 },
                                                                        { -1, 1, 1 },
                                                                        { 0, 1, 2 }});
                            coefficient = 1;
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
                               coefficient = 1;
                          }
};

class SobelFilterCommand : public ConvolutionFiltersCommand {
public:
    SobelFilterCommand() { kernel = std::vector<std::vector<double>>({{ 1, 0, -1 },
                                                                    { 2, 0, -2 },
                                                                    { 1, 0, -1 }});
                           coefficient = 1;
                          }

};

#endif // COMMAND_H
