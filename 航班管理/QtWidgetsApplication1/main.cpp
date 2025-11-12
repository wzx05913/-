#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("Windows"));
    QtWidgetsApplication1 window;
    window.show();
    return app.exec();
}
