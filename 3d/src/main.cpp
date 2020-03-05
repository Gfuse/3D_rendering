#include "mainwindow.h"
#include <QSurfaceFormat>

#include "QVTKOpenGLWidget.h"

int main(int argc, char *argv[])
{
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
    MainWindow w;
    if(a.exec()==0)return 0;
}
