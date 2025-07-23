#ifndef ADJUSTOR_H
#define ADJUSTOR_H


#include <QWidget>

class QSlider;
class QProgressBar;
class Adjustor:public QWidget
{
  Q_OBJECT
  public:
    explicit Adjustor(QWidget *parent);
   private:
    QSlider *slider;
    QProgressBar *bar;
   signals:
   public slots:
};

#endif // ADJUSTOR_H
