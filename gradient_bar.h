#ifndef GRADIENT_BAR_H
#define GRADIENT_BAR_H

#include <QProgressBar>

class GradientBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit GradientBar(QWidget *parent);


// So you need to create a slot, not just override the method??
public slots:
       void setValue(int val);

};

#endif // GRADIENT_BAR_H
