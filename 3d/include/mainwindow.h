#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
// Point Cloud Library
//#include <pcl/point_cloud.h>
//#include <pcl/point_types.h>
//#include <pcl/visualization/pcl_visualizer.h>
// Visualization Toolkit (VTK)
#include <QVTKOpenGLWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNew.h>
#include <vtkRenderer.h>
#include <vtkVectorText.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkSphereSource.h>
//#include <vtkPNGReader.h>
//#include <vtkVersion.h>
//#include <vtkSmartPointer.h>
//#include <vtkCellArray.h>
//#include <vtkCellData.h>
//#include <vtkUnsignedCharArray.h>
//#include <vtkRenderWindow.h>
//#include <vtkPoints.h>
//#include <vtkLine.h>
//#include <vtkPolyData.h>
//typedef pcl::PointXYZRGBA PointT;
//typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  
//protected:
 // pcl::visualization::PCLVisualizer::Ptr viewer;
  //PointCloudT::Ptr cloud;

private:
  Ui::MainWindow *ui;
  vtkNew<vtkRenderer> ren;
  int i=0;
private slots:
  void show_text();
  void show_mesh();
  void show_point_cloud();
};

#endif // MAINWINDOW_H
