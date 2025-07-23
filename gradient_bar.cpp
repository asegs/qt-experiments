#include "gradient_bar.h"
#include <iostream>
#include <string>
#include <format>

int LOW_HUE = 120;
int HIGH_HUE = 0;
int SATURATION = 128;
int LIGHTNESS = 128;

double FIRST_STOP = 0.6;
double SECOND_STOP = 0.8;

GradientBar::GradientBar(QWidget *parent): QProgressBar(parent) {}

QString getHslForVal(int val) {
    double percent = 1 - (double)val/100.0;
    double realHue = percent * (double)(LOW_HUE - HIGH_HUE);
    int wholeRealHue = (int) realHue;
    std::string style = std::format(
            "QProgressBar::chunk {{background: hsl({},{},{})}}",
            wholeRealHue,
            SATURATION,
            LIGHTNESS);

    return QString::fromStdString(style);
}

double min(double a, double b) {
    if (a < b) {
        return a;
    }
    return b;
}

QString getGradientSliderForVal(int val) {
    double percent = ((double) val) / 100.0;
    double firstStop = min(0.9999, FIRST_STOP/percent);
    double secondStop = min(0.99999, SECOND_STOP/percent);
    std::string style = std::format(
            "QProgressBar::chunk {{background: qlineargradient(x0: 0, x2: 1, stop: 0 green, stop: {} green, stop: {} orange, stop: 1 red)}}",
            firstStop,
            secondStop
                );
    return QString::fromStdString(style);
}


void GradientBar::setValue(int val)
   {
    this->setStyleSheet(
       getGradientSliderForVal(val)
    );
    QProgressBar::setValue(val);
   }

