/********************************************************************************
** Form generated from reading UI file 'calculadora_funtras.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_FUNTRAS_H
#define UI_CALCULADORA_FUNTRAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculadora_funtras
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calculadora_funtras)
    {
        if (calculadora_funtras->objectName().isEmpty())
            calculadora_funtras->setObjectName("calculadora_funtras");
        calculadora_funtras->resize(800, 600);
        centralwidget = new QWidget(calculadora_funtras);
        centralwidget->setObjectName("centralwidget");
        calculadora_funtras->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calculadora_funtras);
        menubar->setObjectName("menubar");
        calculadora_funtras->setMenuBar(menubar);
        statusbar = new QStatusBar(calculadora_funtras);
        statusbar->setObjectName("statusbar");
        calculadora_funtras->setStatusBar(statusbar);

        retranslateUi(calculadora_funtras);

        QMetaObject::connectSlotsByName(calculadora_funtras);
    } // setupUi

    void retranslateUi(QMainWindow *calculadora_funtras)
    {
        calculadora_funtras->setWindowTitle(QCoreApplication::translate("calculadora_funtras", "calculadora_funtras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculadora_funtras: public Ui_calculadora_funtras {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_FUNTRAS_H
