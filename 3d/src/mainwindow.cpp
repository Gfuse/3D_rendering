#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this); //
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    this->ui->qvtk->SetRenderWindow(renderWindow);
    this->ui->qvtk->GetRenderWindow()->AddRenderer(ren);
    connect(this->ui->text,SIGNAL(clicked()),this,SLOT(show_text()));
    connect(this->ui->mesh,SIGNAL(clicked()),this,SLOT(show_mesh()));
    connect(this->ui->stl,&QPushButton::clicked,this,[=](){this->show_stl_ply(1);});
    connect(this->ui->ply,&QPushButton::clicked,this,[=](){this->show_stl_ply(-1);});
    connect(this->ui->point_cloud,SIGNAL(clicked()),this,SLOT(show_point_cloud()));
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::show_text(){
    // Geometry
    vtkNew<vtkVectorText> text;
    text->SetText(("Majid Geravant Number "+std::to_string(i)).c_str());
    vtkNew<vtkElevationFilter> elevation;
    elevation->SetInputConnection(text->GetOutputPort());
    elevation->SetLowPoint(0,0,0);
    elevation->SetHighPoint(10,0,0);
    ++i;
    // Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(elevation->GetOutputPort());

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // Add Actor to renderer
    ren->RemoveActor(ren->GetActors()->GetLastActor());
    ren->AddActor(actor);
    ren->ResetCamera();
    this->ui->qvtk->GetRenderWindow()->Render();

}
void MainWindow::show_mesh(){
    // Point
    vtkNew<vtkSphereSource> sphere;
    // Cell
    vtkNew<vtkCellArray> cell;
    // Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(sphere->GetOutputPort());

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // Add Actor to renderer
    ren->RemoveActor(ren->GetActors()->GetLastActor());
    ren->AddActor(actor);
    ren->ResetCamera();
    this->ui->qvtk->GetRenderWindow()->Render();

}
void MainWindow::show_point_cloud(){
    // Geometry
    vtkNew<vtkVectorText> text;
    text->SetText(("Majid Geravant Number "+std::to_string(i)).c_str());
    vtkNew<vtkElevationFilter> elevation;
    elevation->SetInputConnection(text->GetOutputPort());
    elevation->SetLowPoint(0,0,0);
    elevation->SetHighPoint(10,0,0);
    ++i;
    // Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(elevation->GetOutputPort());

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // Add Actor to renderer
    ren->RemoveActor(ren->GetActors()->GetLastActor());
    ren->AddActor(actor);
    ren->ResetCamera();
    this->ui->qvtk->GetRenderWindow()->Render();

}
void MainWindow::show_stl_ply(int i){
    std::string name=(QFileDialog::getOpenFileName(this,tr("Choose a name"),QDir::homePath(),tr("*.stl *.ply"),nullptr,QFileDialog::DontResolveSymlinks|QFileDialog::DontUseNativeDialog|QFileDialog::DontConfirmOverwrite)).toStdString();
    if(!name.empty()){
        vtkNew<vtkPolyDataMapper> mapper;
        if(i>0){
            vtkNew<vtkSTLReader> stl_file;
            stl_file->SetFileName(name.c_str());
            // Mapper
            mapper->SetInputConnection(stl_file->GetOutputPort());
        }else{
            vtkNew<vtkPLYReader> ply_file;
            ply_file->SetFileName(name.c_str());
            // Mapper
            mapper->SetInputConnection(ply_file->GetOutputPort());
        }

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // Add Actor to renderer
    ren->RemoveActor(ren->GetActors()->GetLastActor());
    ren->AddActor(actor);
    ren->ResetCamera();
    this->ui->qvtk->GetRenderWindow()->Render();
    }
}
