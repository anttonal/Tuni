/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSliderRed;
    QLabel *labelBlue;
    QLabel *labelRed;
    QSlider *horizontalSliderBlue;
    QSlider *horizontalSliderGreen;
    QLabel *labelGreen;
    QLabel *colorLabel;
    QSpinBox *spinBoxRed;
    QSpinBox *spinBoxGreen;
    QSpinBox *spinBoxBlue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(691, 407);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 80, 211, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSliderRed = new QSlider(gridLayoutWidget);
        horizontalSliderRed->setObjectName(QString::fromUtf8("horizontalSliderRed"));
        horizontalSliderRed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderRed, 1, 1, 1, 1);

        labelBlue = new QLabel(gridLayoutWidget);
        labelBlue->setObjectName(QString::fromUtf8("labelBlue"));

        gridLayout->addWidget(labelBlue, 3, 0, 1, 1);

        labelRed = new QLabel(gridLayoutWidget);
        labelRed->setObjectName(QString::fromUtf8("labelRed"));

        gridLayout->addWidget(labelRed, 1, 0, 1, 1);

        horizontalSliderBlue = new QSlider(gridLayoutWidget);
        horizontalSliderBlue->setObjectName(QString::fromUtf8("horizontalSliderBlue"));
        horizontalSliderBlue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderBlue, 3, 1, 1, 1);

        horizontalSliderGreen = new QSlider(gridLayoutWidget);
        horizontalSliderGreen->setObjectName(QString::fromUtf8("horizontalSliderGreen"));
        horizontalSliderGreen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderGreen, 2, 1, 1, 1);

        labelGreen = new QLabel(gridLayoutWidget);
        labelGreen->setObjectName(QString::fromUtf8("labelGreen"));

        gridLayout->addWidget(labelGreen, 2, 0, 1, 1);

        colorLabel = new QLabel(centralWidget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setGeometry(QRect(320, 100, 62, 51));
        spinBoxRed = new QSpinBox(centralWidget);
        spinBoxRed->setObjectName(QString::fromUtf8("spinBoxRed"));
        spinBoxRed->setGeometry(QRect(270, 80, 42, 25));
        spinBoxGreen = new QSpinBox(centralWidget);
        spinBoxGreen->setObjectName(QString::fromUtf8("spinBoxGreen"));
        spinBoxGreen->setGeometry(QRect(270, 120, 42, 25));
        spinBoxBlue = new QSpinBox(centralWidget);
        spinBoxBlue->setObjectName(QString::fromUtf8("spinBoxBlue"));
        spinBoxBlue->setGeometry(QRect(270, 150, 42, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 691, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderRed, &QSlider::valueChanged, spinBoxRed, &QSpinBox::setValue);
        QObject::connect(horizontalSliderGreen, &QSlider::valueChanged, spinBoxGreen, &QSpinBox::setValue);
        QObject::connect(horizontalSliderBlue, &QSlider::valueChanged, spinBoxBlue, &QSpinBox::setValue);
        QObject::connect(spinBoxBlue, &QSpinBox::valueChanged, horizontalSliderBlue, &QSlider::setValue);
        QObject::connect(spinBoxGreen, &QSpinBox::valueChanged, horizontalSliderGreen, &QSlider::setValue);
        QObject::connect(spinBoxRed, &QSpinBox::valueChanged, horizontalSliderRed, &QSlider::setValue);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelBlue->setText(QCoreApplication::translate("MainWindow", "blue:", nullptr));
        labelRed->setText(QCoreApplication::translate("MainWindow", "red:", nullptr));
        labelGreen->setText(QCoreApplication::translate("MainWindow", "green:", nullptr));
        colorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
