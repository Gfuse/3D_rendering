/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *main;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *text;
    QPushButton *stl;
    QPushButton *ply;
    QPushButton *mesh;
    QPushButton *point_cloud;
    QLabel *picture;
    QVTKOpenGLWidget *qvtk;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(845, 637);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(MainWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        main = new QHBoxLayout(horizontalLayoutWidget);
        main->setSpacing(4);
        main->setContentsMargins(11, 11, 11, 11);
        main->setObjectName(QString::fromUtf8("main"));
        main->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        text = new QPushButton(horizontalLayoutWidget);
        text->setObjectName(QString::fromUtf8("text"));

        verticalLayout_2->addWidget(text);

        stl = new QPushButton(horizontalLayoutWidget);
        stl->setObjectName(QString::fromUtf8("stl"));

        verticalLayout_2->addWidget(stl);

        ply = new QPushButton(horizontalLayoutWidget);
        ply->setObjectName(QString::fromUtf8("ply"));

        verticalLayout_2->addWidget(ply);

        mesh = new QPushButton(horizontalLayoutWidget);
        mesh->setObjectName(QString::fromUtf8("mesh"));

        verticalLayout_2->addWidget(mesh);

        point_cloud = new QPushButton(horizontalLayoutWidget);
        point_cloud->setObjectName(QString::fromUtf8("point_cloud"));

        verticalLayout_2->addWidget(point_cloud);

        picture = new QLabel(horizontalLayoutWidget);
        picture->setObjectName(QString::fromUtf8("picture"));
        sizePolicy.setHeightForWidth(picture->sizePolicy().hasHeightForWidth());
        picture->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(picture);


        verticalLayout->addLayout(verticalLayout_2);


        main->addLayout(verticalLayout);

        qvtk = new QVTKOpenGLWidget(horizontalLayoutWidget);
        qvtk->setObjectName(QString::fromUtf8("qvtk"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(qvtk->sizePolicy().hasHeightForWidth());
        qvtk->setSizePolicy(sizePolicy1);
        qvtk->setMinimumSize(QSize(300, 300));

        main->addWidget(qvtk);

        MainWindow->setCentralWidget(horizontalLayoutWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        text->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        stl->setText(QCoreApplication::translate("MainWindow", "OPen STL", nullptr));
        ply->setText(QCoreApplication::translate("MainWindow", "OPen PLY", nullptr));
        mesh->setText(QCoreApplication::translate("MainWindow", "Mesh", nullptr));
        point_cloud->setText(QCoreApplication::translate("MainWindow", "Point Cloud", nullptr));
        picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
