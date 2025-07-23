#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <adjustor.h>

class QPushButton;
class Window:public QWidget
{
  Q_OBJECT
  public:
    explicit Window(QWidget *parent = 0);
   private:
    Adjustor *adjustor;
    QPushButton *m_button;
   signals:
   public slots:
     void sliderValue(int level);
};

#endif // WINDOW_H
