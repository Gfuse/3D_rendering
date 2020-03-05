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
#include <QtWidgets/QSlider>
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
    QLabel *picture;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *rotate;
    QHBoxLayout *horizontalLayout_7;
    QSlider *rotate_slider;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *r;
    QHBoxLayout *horizontalLayout_9;
    QSlider *r_slider;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *g;
    QHBoxLayout *horizontalLayout_11;
    QSlider *g_slider;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *b;
    QHBoxLayout *horizontalLayout_13;
    QSlider *b_slider;
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
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 831, 621));
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
        picture = new QLabel(horizontalLayoutWidget);
        picture->setObjectName(QString::fromUtf8("picture"));
        sizePolicy.setHeightForWidth(picture->sizePolicy().hasHeightForWidth());
        picture->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(picture);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rotate = new QLabel(horizontalLayoutWidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rotate->sizePolicy().hasHeightForWidth());
        rotate->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(rotate);


        horizontalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rotate_slider = new QSlider(horizontalLayoutWidget);
        rotate_slider->setObjectName(QString::fromUtf8("rotate_slider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rotate_slider->sizePolicy().hasHeightForWidth());
        rotate_slider->setSizePolicy(sizePolicy2);
        rotate_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(rotate_slider);


        horizontalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        r = new QLabel(horizontalLayoutWidget);
        r->setObjectName(QString::fromUtf8("r"));
        sizePolicy1.setHeightForWidth(r->sizePolicy().hasHeightForWidth());
        r->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(r);


        horizontalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        r_slider = new QSlider(horizontalLayoutWidget);
        r_slider->setObjectName(QString::fromUtf8("r_slider"));
        sizePolicy2.setHeightForWidth(r_slider->sizePolicy().hasHeightForWidth());
        r_slider->setSizePolicy(sizePolicy2);
        r_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(r_slider);


        horizontalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        g = new QLabel(horizontalLayoutWidget);
        g->setObjectName(QString::fromUtf8("g"));
        sizePolicy1.setHeightForWidth(g->sizePolicy().hasHeightForWidth());
        g->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(g);


        horizontalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        g_slider = new QSlider(horizontalLayoutWidget);
        g_slider->setObjectName(QString::fromUtf8("g_slider"));
        sizePolicy2.setHeightForWidth(g_slider->sizePolicy().hasHeightForWidth());
        g_slider->setSizePolicy(sizePolicy2);
        g_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(g_slider);


        horizontalLayout_5->addLayout(horizontalLayout_11);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        b = new QLabel(horizontalLayoutWidget);
        b->setObjectName(QString::fromUtf8("b"));
        sizePolicy1.setHeightForWidth(b->sizePolicy().hasHeightForWidth());
        b->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(b);


        horizontalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        b_slider = new QSlider(horizontalLayoutWidget);
        b_slider->setObjectName(QString::fromUtf8("b_slider"));
        sizePolicy2.setHeightForWidth(b_slider->sizePolicy().hasHeightForWidth());
        b_slider->setSizePolicy(sizePolicy2);
        b_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(b_slider);


        horizontalLayout_4->addLayout(horizontalLayout_13);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_3);


        main->addLayout(verticalLayout);

        qvtk = new QVTKOpenGLWidget(horizontalLayoutWidget);
        qvtk->setObjectName(QString::fromUtf8("qvtk"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(qvtk->sizePolicy().hasHeightForWidth());
        qvtk->setSizePolicy(sizePolicy3);
        qvtk->setMinimumSize(QSize(300, 300));

        main->addWidget(qvtk);

        MainWindow->setCentralWidget(horizontalLayoutWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        picture->setText(QString());
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        r->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        g->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        b->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
