#include "command.h"

void DiscolorationCommand::Execute(QImage *image) {
    for (int i = 0; i < image->height(); ++i) {
        for (int j = 0; j < image->width(); ++j) {
            auto pixel = image->pixelColor(j, i);
            pixel = MiddleGrey(pixel);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor DiscolorationCommand::MiddleGrey(QColor &pixel) {
    int newColor = (pixel.red() + pixel.green() + pixel.blue()) / 3.0;
    return QColor(newColor, newColor, newColor);
}

void NegativeCommand::Execute(QImage *image) {
    for (int i = 0; i < image->height(); ++i) {
        for (int j = 0; j < image->width(); ++j) {
            auto pixel = image->pixelColor(j, i);
            pixel = NegateColor(pixel);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor NegativeCommand::NegateColor(QColor &pixel) {
    int red = 255 - pixel.red();
    int green = 255 - pixel.green();
    int blue = 255 - pixel.blue();
    return QColor(red, green, blue);
}
