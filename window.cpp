#include "window.h"
#include <adjustor.h>
#include <QPushButton>
#include <QApplication>
Window::Window(QWidget *parent) :
 QWidget(parent) {
    setFixedSize(500, 250);
    adjustor = new Adjustor(this);
    m_button = new QPushButton("Hello there.", this);
    m_button->setGeometry(200, 20, 150, 200);
    m_button->setToolTip("What are you looking at?");
    QFont font ("Helvetica");
    QIcon icon(":/mouse.jpeg");
    m_button->setFont(font);
    m_button->setIcon(icon);
    connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT (quit()));
}

void Window::sliderValue(int level) {
    if (level > 75) {
        m_button->setText("It's getting too damn hot!");
        m_button->setStyleSheet("background-color: red");
        m_button->setGeometry(200, 20, 275, 200);
    } else {
        m_button->setText("Phew...thanks.");
        m_button->setStyleSheet("");
        m_button->setGeometry(200, 20, 150, 200);

    }
}
