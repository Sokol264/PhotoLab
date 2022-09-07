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
    int newColor = (pixel.red() + pixel.green() + pixel.blue()) / 3;
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

void ToningCommand::Execute(QImage *image) {
    for (int i = 0; i < image->height(); ++i) {
        for (int j = 0; j < image->width(); ++j) {
            auto pixel = image->pixelColor(j, i);
            pixel = ToningColor(pixel);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor ToningCommand::ToningColor(QColor &pixel) {
    int red = (color.red() + pixel.red()) / 2;
    int green = (color.green() + pixel.green()) / 2;
    int blue = (color.blue() + pixel.blue()) / 2;
    return QColor(red, green, blue);
}

void ConvolutionFiltersCommand::Execute(QImage *image) {
    QImage temp(*image);
    int heightDiv2 = kernel.size() - 1 / 2;
    int widthDiv2 = kernel[0].size() - 1 / 2;
    for (int i = heightDiv2; i < image->height() - heightDiv2; ++i) {
        for (int j = widthDiv2; j < image->width() - widthDiv2; ++j) {
            auto pixel = image->pixelColor(j, i);
            pixel = ApplyFilter(temp, i, j);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor ConvolutionFiltersCommand::ApplyFilter(QImage &image, int index, int jndex) {
    double red = 0, green = 0, blue = 0;
    for (size_t i = 0; i < kernel.size(); ++i) {
        for (size_t j = 0; j < kernel[0].size(); ++j) {
            QColor pixel = image.pixelColor(jndex - (kernel.size() - 1) / 2 + i, index - (kernel[0].size() - 1) / 2 + j);
            red += (double)pixel.red() * kernel[j][i];
            green += (double)pixel.green() * kernel[j][i];
            blue += (double)pixel.blue() * kernel[j][i];
        }
    }
    red /= coefficient;
    if (red > 255) red = 255;
    if (red < 0) red = 0;
    green /= coefficient;
    if (green > 255) green = 255;
    if (green < 0) green = 0;
    blue /= coefficient;
    if (blue > 255) blue = 255;
    if (blue < 0) blue = 0;
    return QColor((int)red, (int)green, (int)blue);
}

void BrightnessChangeCommand::Execute(QImage *image) {
    for (int i = 0; i < originImage.height(); ++i) {
        for (int j = 0; j < originImage.width(); ++j) {
            auto pixel = originImage.pixelColor(j, i);
            pixel = CalcNewColor(pixel);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor BrightnessChangeCommand::CalcNewColor(QColor &pixel) {
    int r = pixel.red() + brightness;
    int g = pixel.green() + brightness;
    int b = pixel.blue() + brightness;
    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;

    return QColor(r, g, b);
}


void ContrastChangeCommand::Execute(QImage *image) {
    for (int i = 0; i < originImage.height(); ++i) {
        for (int j = 0; j < originImage.width(); ++j) {
            auto pixel = originImage.pixelColor(j, i);
            pixel = CalcNewColor(pixel);
            image->setPixelColor(j, i, pixel);
        }
    }
}

QColor ContrastChangeCommand::CalcNewColor(QColor &pixel) {
    double cont = (double)(contrast + 100) / 100.0;
    cont *= cont;
    double red = pixel.redF(), green = pixel.greenF(), blue = pixel.blueF();

    red -= 0.5;
    green -= 0.5;
    blue -= 0.5;

    red *= cont;
    green *= cont;
    blue *= cont;

    red += 0.5;
    green += 0.5;
    blue += 0.5;

    red *= 255;
    green *= 255;
    blue *= 255;
    if (red > 255) red = 255; else if (red < 0) red = 0;
    if (green > 255) green = 255; else if (green < 0) green = 0;
    if (blue > 255) blue = 255; else if (blue < 0) blue = 0;

    return QColor((int)red, (int)green, (int)blue);
}


