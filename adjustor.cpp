#include "adjustor.h"
#include <QSlider>
#include <gradient_bar.h>
Adjustor::Adjustor(QWidget *parent):
    QWidget(parent) {
        slider = new QSlider(this);
        slider->setOrientation(Qt::Horizontal);
        slider->setRange(0, 100);
        slider->setValue(0);
        slider->setGeometry(10, 60, 180, 30);

        bar = new GradientBar(this);
        bar->setRange(0, 100);
        bar->setValue(0);
        bar->setGeometry(10, 10, 180, 50);
        bar->setStyleSheet(
                "QProgressBar::chunk {"
                "background: red"
                "}"
            );

        connect(slider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
        connect(slider, SIGNAL(valueChanged(int)), parent, SLOT(sliderValue(int)));

}

