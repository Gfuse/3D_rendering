#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
//#include < QDoubleSpinBox>
#include <QRadioButton>
#include <iostream>
#include <QDebug>
#include <QLayout>
#include <QMessageBox>
#include <QSpacerItem>
#include <QVTKWidget.h>
#include <QDir>
#include <QSlider>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QTextEdit>
#pragma once
#include <iostream>
// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
#include <QScrollArea>
#include <QImage>
#include "qimage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <QToolButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
public Q_SLOTS:
  void
  randomButtonPressed ();

  void
  RGBsliderReleased ();

/*  void
  pSliderValueChanged (int value);*/

  void
  redSliderValueChanged (int value);

  void greenSliderValueChanged (int value);

  void
  blueSliderValueChanged (int value);
  
protected:
  pcl::visualization::PCLVisualizer::Ptr viewer;
  PointCloudT::Ptr cloud;


  unsigned int red;
  unsigned int green;
  unsigned int blue;  

private:
double spinvalue; //change add

    Ui::MainWindow *ui;
    QVTKWidget *qvtkWidget;
    QProgressBar *progressbar;
    QSlider *horizontalSlider_R, *horizontalSlider_G, *horizontalSlider_B, *horizontalSlider_p;
    QPushButton *pushButton_random;
    QPushButton *dumpbutton;
    QGridLayout *layout, *combogrid, *modelayout, *geolayout, *vlayout;
    void createGridGroupBox();
    QGroupBox *gridGroupBox, *combogroup, *modegroup, *qualitygroup, *outputgroup, *geogroup, *qvtkgroup, *mapgroup, *viewgroup, *laygroup;
    QCheckBox *topviewcheck, *d3viewcheck;
    QLabel *topviewlabel,*d3viewlabel, *timespinlabel, *stoplabel, *playlabel, *dumplabel, *framelabel, *dump2maplabel, *indoorlabel, *mobilelabel, *aeriallabel, *piclabel, *browselabel;
    QComboBox *combobag, *outputcombo;
    QDoubleSpinBox *timespin;
    QLineEdit *Egeo, *Ngeo, *Zgeo;
    QPushButton *playbutton, *stopbutton, *framebutton, *dump2mapbutton, *browsebutton, *geobutton;
    QRadioButton *indoorradio, *mobileradio, *aerialradio, *fastradio, *mediumradio, *hdmapsradio, *turnonmapradio, *turnoffmapradio;
    QVBoxLayout *maplayout, *viewlayout;
    //QHBoxLayout *vlayout;
    QToolButton *b ;
private slots:
void on_spinBox_valueChanged(double); //change add
    void comboboxItemChanged();
    void play_pressed();
    void stop_pressed();
    void browse_pressed();
    void dump_pressed();
    void frame_pressed();
    void dump2map_pressed();
    void view_check();
    void mode_radio();
    void quality_radio();
    void geobutton_pressed();


    void on_progressbar_valueChanged(int value);
};

#endif // MAINWINDOW_H
