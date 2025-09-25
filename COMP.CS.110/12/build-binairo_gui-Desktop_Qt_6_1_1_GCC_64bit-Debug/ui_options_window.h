/********************************************************************************
** Form generated from reading UI file 'options_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_WINDOW_H
#define UI_OPTIONS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_options_window
{
public:

    void setupUi(QWidget *options_window)
    {
        if (options_window->objectName().isEmpty())
            options_window->setObjectName(QString::fromUtf8("options_window"));
        options_window->resize(400, 300);

        retranslateUi(options_window);

        QMetaObject::connectSlotsByName(options_window);
    } // setupUi

    void retranslateUi(QWidget *options_window)
    {
        options_window->setWindowTitle(QCoreApplication::translate("options_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class options_window: public Ui_options_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_WINDOW_H
