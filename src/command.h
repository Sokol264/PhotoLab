#ifndef COMMAND_H
#define COMMAND_H

#include <QImage>
#include <QColor>

class Command {
public:
    ~Command();
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

class NegativeCommand : public Command{
public:
    void Execute(QImage *image);
private:
    QColor NegateColor(QColor &pixel);
};

#endif // COMMAND_H
