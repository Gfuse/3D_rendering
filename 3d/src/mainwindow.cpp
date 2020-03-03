#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <FlowLayout>
#include <QScrollArea>
#include <QImage>
#include "qimage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <QIcon>
#include <QToolButton>
#include <QPixmap>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //

    qvtkWidget=new QVTKWidget; //
    piclabel=new QLabel; //

	cv::Mat img; // make the same cv::Mat
	img= cv::imread("../picture/nn.png", CV_LOAD_IMAGE_COLOR);
	cv::Size size(300,150);
	cv::Mat temp;//src image
	cv::resize(img,temp,size);//resize image

    cvtColor(temp, temp,CV_BGR2RGB); // cvtColor, change the image format from BGR2RGB
	QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    dest.bits(); //
    piclabel->setPixmap(QPixmap::fromImage(dest));//
    piclabel->resize(piclabel->pixmap()->size());//

	// Setup the cloud pointer
	cloud.reset (new PointCloudT);
	// The number of points in the cloud
	cloud->points.resize (8000);

	// The default color
	red   = 128;
	green = 128;
	blue  = 128;

	// Fill the cloud with some points
	for (size_t i = 0; i < cloud->points.size (); ++i)
		{
	        cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
	        cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
	        cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);

	        cloud->points[i].r = red;
	        cloud->points[i].g = green;
	        cloud->points[i].b = blue;
		}
      // Set up the QVTK window
      viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
      qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
      viewer->setupInteractor (qvtkWidget->GetInteractor (), qvtkWidget->GetRenderWindow ());
      qvtkWidget->update ();

      // Connect "random" button and the function
      pushButton_random=new QPushButton;
      horizontalSlider_R=new QSlider;
      horizontalSlider_G=new QSlider;
      horizontalSlider_B=new QSlider;
      // Connect R,G,B sliders and their functions
      connect (horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
      connect (horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
      connect (horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
      connect (horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
      connect (horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
      connect (horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

      // Connect point size slider
      //connect (horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));
    createGridGroupBox();
    connect(playbutton,SIGNAL(released()),this,SLOT(play_pressed()));
    connect(stopbutton,SIGNAL(released()),this,SLOT(stop_pressed()));
    connect(dumpbutton,SIGNAL(released()),this,SLOT(dump_pressed()));
    connect(framebutton,SIGNAL(released()),this,SLOT(frame_pressed()));
    connect(dump2mapbutton,SIGNAL(released()),this,SLOT(dump2map_pressed()));
    connect(topviewcheck, SIGNAL(clicked()), this, SLOT(view_check()));
    connect(d3viewcheck, SIGNAL(clicked()), this, SLOT(()));
    connect(indoorradio, SIGNAL(clicked()), this, SLOT(mode_radio()));
    connect(mobileradio, SIGNAL(clicked()), this, SLOT(mode_radio()));
    connect(aerialradio, SIGNAL(clicked()), this, SLOT(mode_radio()));
    connect(fastradio, SIGNAL(clicked()), this, SLOT(quality_radio()));
    connect(mediumradio, SIGNAL(clicked()), this, SLOT(quality_radio()));
    connect(hdmapsradio, SIGNAL(clicked()), this, SLOT(quality_radio()));
    connect(browsebutton,SIGNAL(released()),this,SLOT(browse_pressed()));
    connect(geobutton,SIGNAL(released()),this,SLOT(geobutton_pressed()));
    connect(timespin, SIGNAL(valueChanged(double)), this, SLOT(on_spinBox_valueChanged(double)));//this is for connection to ros
    viewer->addPointCloud (cloud, "cloud");
    viewer->resetCamera ();
    qvtkWidget->update ();

}


void MainWindow::randomButtonPressed ()
{
  printf ("Random button was pressed\n");


  // Set the new color
  for (size_t i = 0; i < cloud->size(); i++)
  {
    cloud->points[i].r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  }

  viewer->updatePointCloud (cloud, "cloud");
  qvtkWidget->update ();
}
void MainWindow::RGBsliderReleased ()
{
  // Set the new color
  for (size_t i = 0; i < cloud->size (); i++)
  {
    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }
  viewer->updatePointCloud (cloud, "cloud");
  qvtkWidget->update ();
}
void MainWindow::redSliderValueChanged (int value)
{
  red = value;
  printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void MainWindow::greenSliderValueChanged (int value)
{
  green = value;
  printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void MainWindow::blueSliderValueChanged (int value)
{
  blue = value;
  printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}


void MainWindow::createGridGroupBox()
{
    gridGroupBox = new QGroupBox;
//    gridGroupBox = new QGroupBox(tr("Map3D"));
    layout = new QGridLayout;

                topviewcheck= new QCheckBox(tr("Top View"));
		//QCheckBox::indicator {width: 10px;height: 10px;};
              topviewcheck->setStyleSheet("color: rgb(255, 255, 255);");
topviewcheck->setStyleSheet("QCheckBox::indicator:checked{  image: url(../picture/check.png);} QCheckBox::indicator:unchecked{  image: url(../picture/uncheck.png);} QCheckBox { color: white}");

                d3viewcheck= new QCheckBox(tr("3D View"));
                d3viewcheck->setStyleSheet("QCheckBox::indicator:checked{  image: url(../picture/check.png);} QCheckBox::indicator:unchecked{  image: url(../picture/uncheck.png);} QCheckBox { color: white}");
                combobag= new QComboBox;
                combobag->setStyleSheet("border: 1px solid gray;border-radius: 3px;padding: 1px 18px 1px 3px;min-width: 6em;");
                /*QDir path("../log");
                QStringList files=path.entryList(QDir::Files);
                combobag= new QComboBox;
                combobag->addItems(files);*/

                connect(combobag, SIGNAL(currentTextChanged()), this, SLOT(comboboxItemChanged()));
		browsebutton = new QPushButton;
browsebutton->setStyleSheet("background-color: rgb(64,64,64);border-style:outset;border-width:2px;border-radius:17px;border-color:black;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
		browselabel=new QLabel(tr("Browse"));
browselabel->setStyleSheet("color: rgb(255, 255, 255);");

                playbutton= new QPushButton;
                playbutton->setStyleSheet("background-color: rgb(186, 189, 182);border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");

                stopbutton= new QPushButton;
                stopbutton->setStyleSheet("background-color: rgb(186, 189, 182);border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
                playlabel= new QLabel(tr("Play"));
                playlabel->setStyleSheet("color: rgb(255, 255, 255);");
                stoplabel= new QLabel(tr("Stop"));
                stoplabel->setStyleSheet("color: rgb(255, 255, 255);");
                timespin= new  QDoubleSpinBox;
		timespin->setMaximum(1000);
                timespinlabel=new QLabel(tr("Skip Time  .sec"));
                timespinlabel->setStyleSheet("color: rgb(255, 255, 255);");

                progressbar=new QProgressBar;
                progressbar->setStyleSheet("QProgressBar { text-align: center;border: 2px solid black;border-radius: 5px;}QProgressBar::chunk {background-color: #05B8CC;width: 20px;}");



                         combogrid=new QGridLayout;
                         combogroup=new QGroupBox;
                         combogrid->addWidget(combobag,0,0,1,3);
			 combogrid->addWidget(browsebutton,0,4);
			 combogrid->addWidget(browselabel,0,5);
                        /* combogrid->addWidget(playbutton,0,3);
                         combogrid->addWidget(stopbutton,0,4);
                         combogrid->addWidget(playlabel,2,3);
                         combogrid->addWidget(stoplabel,2,4);*/
                         combogroup->setLayout(combogrid);


                modegroup=new QGroupBox;
                modegroup->setTitle("Mode");
               modegroup->setStyleSheet("color: rgb(255, 255, 255);");

                modelayout = new QGridLayout;
//background-color: rgb(252,254,252);color: black;

                         indoorradio=new QRadioButton("Indoor");
indoorradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                         mobileradio=new QRadioButton("Mobile");
mobileradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                         aerialradio=new QRadioButton("Aerial");
aerialradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");


                         modelayout->addWidget(indoorradio,1,1);
                         modelayout->addWidget(mobileradio,2,1);
                         modelayout->addWidget(aerialradio,3,1);
                         modegroup->setLayout(modelayout);

                qualitygroup=new QGroupBox;
                qualitygroup->setStyleSheet("color: rgb(255, 255, 255);");
                qualitygroup->setTitle("Quality");
                QVBoxLayout *qualitylayout = new QVBoxLayout;

                         fastradio=new QRadioButton("Fast");
fastradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                         mediumradio=new QRadioButton("Medium");
mediumradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                         hdmapsradio=new QRadioButton("HD Maps");
hdmapsradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                         //qualitylayout->tr("Quality");
                         qualitylayout->addWidget(fastradio);
                         qualitylayout->addWidget(mediumradio);
                         qualitylayout->addWidget(hdmapsradio);
                         qualitygroup->setLayout(qualitylayout);

                 outputgroup=new QGroupBox;
                 outputgroup->setTitle("Output");
                 outputgroup->setStyleSheet("color: rgb(255, 255, 255);");
                 QGridLayout *outputlayout = new QGridLayout;


                                  //dumpbutton= new QPushButton(tr("Dump"));
dumpbutton= new QPushButton;
dumpbutton->setStyleSheet("background-color:rgb(125, 6, 6);height:24px;width:40px;border-style:outset;");

//                                  dumpbutton->setStyleSheet("color:black;");


    QIcon *ic = new QIcon();
    ic->addPixmap(QPixmap("/home/taha/projects/Demo pcl/ui/picture/onS.png"),QIcon::Normal,QIcon::On);
    ic->addPixmap(QPixmap("/home/taha/projects/Demo pcl/ui/picture/offS.png"),QIcon::Normal,QIcon::Off);
    dumpbutton->setIcon(*ic);
    //dumpbutton->setIconSize(QSize(75,45));
dumpbutton->setIconSize(QSize(80,40));
dumpbutton->setCheckable(true);


                                  //framebutton=new QPushButton(tr("Frame2UTM"));
framebutton=new QPushButton;
                                  framebutton->setStyleSheet("background-color:rgb(125, 6, 6);height:24px;width:40px;border-style:outset;");

    framebutton->setIcon(*ic);
    framebutton->setIconSize(QSize(80,40));
    framebutton->setCheckable(true);



                                  dump2mapbutton=new QPushButton;
                                  dump2mapbutton->setStyleSheet("background-color:rgb(125, 6, 6);height:24px;width:40px;border-style:outset;");

    dump2mapbutton->setIcon(*ic);
    dump2mapbutton->setIconSize(QSize(80,40));
    dump2mapbutton->setCheckable(true);





                                  dumplabel=new QLabel("Dump");
                                  framelabel=new QLabel("Frame2UTM");
                                  dump2maplabel=new QLabel("Dump2Map");

                                  outputlayout->addWidget(dumpbutton,0,0);
                                  outputlayout->addWidget(framebutton,1,0);
                                  outputlayout->addWidget(dump2mapbutton,2,0);
                                  outputlayout->addWidget(dumplabel,0,1);
                                  outputlayout->addWidget(framelabel,1,1);
                                  outputlayout->addWidget(dump2maplabel,2,1);

                                  outputgroup->setLayout(outputlayout);


                Egeo=new QLineEdit;
                Egeo->setText("RGB: r=125");
                Egeo->setStyleSheet("background-color:rgb(125, 6, 6);color:white;width:100px;");
		Ngeo=new QLineEdit;
                Ngeo->setText("RGB: g=102");
                Ngeo->setStyleSheet("background-color:rgb(125, 6, 6);color:white;");
                Zgeo=new QLineEdit;
                Zgeo->setText("RGB: b=121");
                Zgeo->setStyleSheet("background-color:rgb(125, 6, 6);color:white;");
                geogroup=new QGroupBox;
geogroup->setTitle("RGB");
geogroup->setStyleSheet("color: rgb(255, 255, 255);");
 std::cout<<"22222"<<std::endl;
                geolayout = new QGridLayout;

 std::cout<<"1"<<std::endl;
                outputcombo=new QComboBox;
outputcombo->setStyleSheet("min-height:16;");
		geobutton=new QPushButton(tr("Dir"));
geobutton->setStyleSheet("max-width:34px;max-height:30px;");

geolayout->setSpacing(0);

//                                  geolayout->addWidget(outputcombo,0,0);
//		    		  geolayout->addWidget(geobutton,0,1);
                                  geolayout->addWidget(Egeo,2,0,1,2);
                                  geolayout->addWidget(Ngeo,3,0,1,2);
                                  geolayout->addWidget(Zgeo,4,0,1,2);
                                  geogroup->setLayout(geolayout);
                                  //geogroup->setMinimumWidth(130);
 std::cout<<"2"<<std::endl;

                                  qvtkgroup=new QGroupBox;

                                  QVBoxLayout *qvtklayout = new QVBoxLayout;

                                  qvtklayout->addWidget(qvtkWidget);
                                  //qvtklayout->addWidget(horizontalSlider_R, 0,0);
                                  //qvtklayout->addWidget(horizontalSlider_G, 0, 1);
                                  //qvtklayout->addWidget(horizontalSlider_B, 0, 2);
                                  //qvtklayout->addWidget(pushButton_random, 0,3);
                                  qvtkgroup->setLayout(qvtklayout);


                                 /* FlowLayout *flowLayout = new FlowLayout;

                                  QWidget* scrollAreaContent = new QWidget;
                                  scrollAreaContent->setLayout (flowLayout);

                                  QScrollArea* scrollArea = new QScrollArea;
                                  scrollArea->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
                                  scrollArea->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);
                                  scrollArea->setWidgetResizable (true);
                                  scrollArea->setWidget (scrollAreaContent);

                                  flowLayout->addWidget (qvtkWidget);*/



                                  qvtkgroup->resize(QSize(1000,1000));   // optional: make it big enough
                                  //piclabel->resize(10,10);

                                  QScrollArea *qvtScrollArea = new QScrollArea;
                                  qvtScrollArea->setWidget(qvtkgroup);

				  ///maplayout=new QVBoxLayout;
				  ///mapgroup=new QGroupBox;
QLabel *maponlabel=new QLabel(tr("Turn on map"));
QLabel *mapofflabel=new QLabel(tr("Turn off map"));
//maponlabel->setStyleSheet("background: transparent;");
//maponlabel->setAutoFillBackground(false);
maponlabel->setStyleSheet("color: rgb(255, 255, 255);");
mapofflabel->setStyleSheet("color: rgb(255, 255, 255);");
mapofflabel->setAutoFillBackground(false);

                                  turnonmapradio=new QRadioButton;
turnonmapradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

                                  turnoffmapradio=new QRadioButton;
turnoffmapradio->setStyleSheet("QRadioButton::indicator{width: 18px;height: 18px;} QRadioButton::indicator:checked{image: url(../picture/radiobutton.png);}QRadioButton::indicator:unchecked{image: url(../picture/uncheckradio.png);}");

				  /*mapgroup->setStyleSheet("color: rgb(255, 255, 255);");
                                  maplayout->addWidget(turnonmapradio);
                                  maplayout->addWidget(turnoffmapradio);
				  mapgroup->setLayout(maplayout);*/

				  viewgroup=new QGroupBox;
				  viewlayout=new QVBoxLayout;

				  viewlayout->addWidget(topviewcheck);
				  viewlayout->addWidget(d3viewcheck);
				  viewgroup->setLayout(viewlayout);



//layout->setSpacing(0);

//                layout->addWidget(viewgroup, 0 , 0);

                layout->addWidget(combogroup,1,0,1,2);
//                layout->addWidget(timespinlabel, 3,0);
//                layout->addWidget(timespin,3,1);
                layout->addWidget(progressbar,4,0,1,2);
//                layout->addWidget(modegroup,5,0);
//                layout->addWidget(qualitygroup,5,1);
                layout->addWidget(outputgroup,7,0);

                layout->addWidget(geogroup,7,1);
                //layout->addWidget(outputcombo,8,1);
                //layout->addWidget(mapgroup, 0, 1);
                //layout->addWidget(mapgroup,0,6);
//layout->addWidget(b,3,1);

//                layout->addWidget(piclabel,7,0,1,2);

laygroup=new QGroupBox;

laygroup->setLayout(layout);
//laygroup->setMinimumWidth(1);
laygroup->setMaximumSize(340,1050);

    vlayout =new QGridLayout;
   vlayout->addWidget(laygroup,0,0,63,20);
/*vlayout->addWidget(viewgroup, 0 , 0);
vlayout->addWidget(combogroup,1,0);
vlayout->addWidget(timespinlabel, 3,0);
vlayout->addWidget(timespin,4,1);
vlayout->addWidget(progressbar,4,0);
vlayout->addWidget(modegroup,5,0);
vlayout->addWidget(qualitygroup,5,1);
vlayout->addWidget(outputgroup,6,0);
vlayout->addWidget(geogroup,6,1);*/



//    vlayout->addWidget(piclabel,63,0,37,30);




                vlayout->addWidget(qvtkWidget,0,21,100,100);
		vlayout->addWidget(turnonmapradio,1,102,4,3);	//change add
		vlayout->addWidget(turnoffmapradio,6,102,4,3);	//change add
		vlayout->addWidget(maponlabel,1,105,4,6);	//change add
		vlayout->addWidget(mapofflabel,6,105,4,6);	//change add
//vlayout->addWidget(qvtScrollArea,0,1,2,2);



               QPalette pal = palette();

                // set black background
                pal.setColor(QPalette::Background, QColor(125, 6, 6));
                gridGroupBox->setAutoFillBackground(true);
                gridGroupBox->setPalette(pal);

       gridGroupBox->setLayout(vlayout);
gridGroupBox->setMinimumSize(1,1);

       gridGroupBox->show();
//vlayout->show();
}
void MainWindow::dump_pressed()
{
 qDebug()<<"dumppressed";
  for (size_t i = 0; i < cloud->size(); i++)
  {
    cloud->points[i].r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
//Egeo->setText();
    cloud->points[i].g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  }

  viewer->updatePointCloud (cloud, "cloud");
  qvtkWidget->update ();
}
void MainWindow::frame_pressed()
{
 qDebug()<<"framepressed";
}
void MainWindow::dump2map_pressed()
{
 qDebug()<<"dump2mappressed";
}
void MainWindow::play_pressed()
{
        playbutton->setStyleSheet("background-color:red ;border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
        stopbutton->setStyleSheet("background-color: rgb(186, 189, 182);border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
        qDebug()<<"playpressed";
}

void MainWindow::stop_pressed()
{
    stopbutton->setStyleSheet("background-color:red ;border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
    playbutton->setStyleSheet("background-color: rgb(186, 189, 182);border-style:outset;border-width:2px;border-radius:17px;border-color:white;max-width:34px;max-height:34px;min-width:34px;min-height:34px;");
    qDebug()<<"stoppressed";

}

void MainWindow::view_check()
{

    if (topviewcheck->isChecked()) {
            qDebug()<<"topview is checked";
        } else if (d3viewcheck->isChecked()) {
            qDebug()<<"3dview is checked";
        }
}
void MainWindow::mode_radio()
{

      if (indoorradio->isChecked()) {
            qDebug()<<"indoorradio is checked";
        } else if (mobileradio->isChecked()) {
            qDebug()<<"mobileradio is checked";
        }else if (aerialradio->isChecked()) {
        qDebug()<<"mobileradio is checked";
    }

}
void MainWindow::quality_radio()
{

    if (fastradio->isChecked()) {
            qDebug()<<"fastradio is checked";
        } else if (mediumradio->isChecked()) {
            qDebug()<<"mediumradio is checked";
        }else if (hdmapsradio->isChecked()) {
        qDebug()<<"hdmapsradio is checked";
    }

}
void MainWindow::on_progressbar_valueChanged(int value)
{

}
void MainWindow::comboboxItemChanged()
{
qDebug()<<"comboboxxxxxxx";

}
void MainWindow::browse_pressed()
{
        QDir directory(QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath())));

            //combobag->addItems(files);
            //combobag->setCurrentIndex(combobag->findText(directory));
//QDir path("../log");
                QStringList files=directory.entryList(QDir::Files);
//                combobag= new QComboBox;
                combobag->addItems(files);
}
/*void MainWindow::browse_pressed()
{
    StringList files;
       QDirIterator it(source , QDir::Files , QDirIterator::Subdirectories); //QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot
combobag->addItems(files);

        while (it.hasNext())
        {

            files.append(it.next());
        }
}*/



void MainWindow::geobutton_pressed()   //change
{
        //QString director =QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
	//outputcombo->setCurrentIndex(combobag->findText(directory));

/*	outputcombo->clear();
	const QString directory = QFileDialog::getExistingDirectory(this, tr("Open  Directory"),QDir::Path(), QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
                outputcombo->addItem(directory);*/
outputcombo->clear();
const QString path="/home/taha";
const QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),path, QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks|QFileDialog::DontUseNativeDialog);
outputcombo->addItem(directory);


}
void MainWindow::on_spinBox_valueChanged(double)
{
    spinvalue =timespin->value();
qDebug()<<spinvalue;


}
MainWindow::~MainWindow()
{
    delete ui;
}
