#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QVTKOpenGLWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNew.h>
#include <vtkRenderer.h>
#include <vtkVectorText.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkPLYReader.h>
#include <vtkPolygon.h>
#include <vtkVertex.h>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
  Ui::MainWindow *ui;
  vtkNew<vtkRenderer> ren;
  int i=0;
private slots:
  void show_text();
  void show_mesh();
  void show_point_cloud();
  void show_stl_ply(int i=1);
};

#endif // MAINWINDOW_H
