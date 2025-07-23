#include "gradient_bar.h"
#include <iostream>
#include <string>
#include <format>

int LOW_HUE = 120;
int HIGH_HUE = 0;
int SATURATION = 128;
int LIGHTNESS = 128;

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


void GradientBar::setValue(int val)
   {
    this->setStyleSheet(
       getHslForVal(val)
    );
    QProgressBar::setValue(val);
   }

