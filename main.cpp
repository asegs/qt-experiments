#include <QApplication>
#include <QPushButton>
#include <filesystem>
#include <iostream>
#include <window.h>

int main (int argc, char **argv)
{
    std::cout << __cplusplus << std::endl;
    QApplication app (argc, argv);
    Window window;
    window.show();
    return app.exec();
}
