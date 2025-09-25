/********************************************************************************
** Form generated from reading UI file 'gameboard_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_WINDOW_H
#define UI_GAMEBOARD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameboard_window
{
public:

    void setupUi(QWidget *gameboard_window)
    {
        if (gameboard_window->objectName().isEmpty())
            gameboard_window->setObjectName(QString::fromUtf8("gameboard_window"));
        gameboard_window->resize(400, 300);

        retranslateUi(gameboard_window);

        QMetaObject::connectSlotsByName(gameboard_window);
    } // setupUi

    void retranslateUi(QWidget *gameboard_window)
    {
        gameboard_window->setWindowTitle(QCoreApplication::translate("gameboard_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameboard_window: public Ui_gameboard_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_WINDOW_H
