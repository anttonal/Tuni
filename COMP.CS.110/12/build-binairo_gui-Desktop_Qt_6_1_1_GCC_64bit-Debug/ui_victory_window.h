/********************************************************************************
** Form generated from reading UI file 'victory_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORY_WINDOW_H
#define UI_VICTORY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_victory_window
{
public:

    void setupUi(QWidget *victory_window)
    {
        if (victory_window->objectName().isEmpty())
            victory_window->setObjectName(QString::fromUtf8("victory_window"));
        victory_window->resize(400, 300);

        retranslateUi(victory_window);

        QMetaObject::connectSlotsByName(victory_window);
    } // setupUi

    void retranslateUi(QWidget *victory_window)
    {
        victory_window->setWindowTitle(QCoreApplication::translate("victory_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class victory_window: public Ui_victory_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_WINDOW_H
