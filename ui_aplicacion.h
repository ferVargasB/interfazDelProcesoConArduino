/********************************************************************************
** Form generated from reading UI file 'aplicacion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APLICACION_H
#define UI_APLICACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Aplicacion
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDistancia;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTanqueA;
    QLabel *labelTanqueB;

    void setupUi(QDialog *Aplicacion)
    {
        if (Aplicacion->objectName().isEmpty())
            Aplicacion->setObjectName(QStringLiteral("Aplicacion"));
        Aplicacion->resize(348, 470);
        gridLayout = new QGridLayout(Aplicacion);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelDistancia = new QLabel(Aplicacion);
        labelDistancia->setObjectName(QStringLiteral("labelDistancia"));
        labelDistancia->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelDistancia);

        lcdNumber = new QLCDNumber(Aplicacion);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setDigitCount(2);

        horizontalLayout_2->addWidget(lcdNumber);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelTanqueA = new QLabel(Aplicacion);
        labelTanqueA->setObjectName(QStringLiteral("labelTanqueA"));
        labelTanqueA->setMinimumSize(QSize(100, 250));
        labelTanqueA->setMaximumSize(QSize(100, 250));
        labelTanqueA->setFrameShape(QFrame::Box);
        labelTanqueA->setFrameShadow(QFrame::Plain);
        labelTanqueA->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTanqueA);

        labelTanqueB = new QLabel(Aplicacion);
        labelTanqueB->setObjectName(QStringLiteral("labelTanqueB"));
        labelTanqueB->setMinimumSize(QSize(100, 250));
        labelTanqueB->setMaximumSize(QSize(100, 250));
        labelTanqueB->setFrameShape(QFrame::Box);
        labelTanqueB->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTanqueB);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(Aplicacion);

        QMetaObject::connectSlotsByName(Aplicacion);
    } // setupUi

    void retranslateUi(QDialog *Aplicacion)
    {
        Aplicacion->setWindowTitle(QApplication::translate("Aplicacion", "Aplicacion", 0));
        labelDistancia->setText(QApplication::translate("Aplicacion", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600;\">Distancia</span><br/></p></body></html>", 0));
        labelTanqueA->setText(QApplication::translate("Aplicacion", "Tanque A", 0));
        labelTanqueB->setText(QApplication::translate("Aplicacion", "Tanque B", 0));
    } // retranslateUi

};

namespace Ui {
    class Aplicacion: public Ui_Aplicacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APLICACION_H
