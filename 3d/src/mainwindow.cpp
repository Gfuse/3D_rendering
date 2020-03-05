#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this); //
/*
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
    viewer->addPointCloud (cloud, "cloud");
    viewer->resetCamera ();
    */
    // Qt Table View
    //this->TableView = vtkSmartPointer<vtkQtTableView>::New();

    // Place the table view in the designer form
    //this->ui->tableFrame->layout()->addWidget(this->TableView->GetWidget());

    // Geometry
    vtkNew<vtkVectorText> text;
    text->SetText("VTK and Qt!");
    vtkNew<vtkElevationFilter> elevation;
    elevation->SetInputConnection(text->GetOutputPort());
    elevation->SetLowPoint(0,0,0);
    elevation->SetHighPoint(10,0,0);

    // Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(elevation->GetOutputPort());

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // VTK Renderer
    vtkNew<vtkRenderer> ren;

    // Add Actor to renderer
    //ren->AddActor(actor);
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    this->ui->qvtk->SetRenderWindow(renderWindow);
    this->ui->qvtk->GetRenderWindow()->AddRenderer(ren);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
