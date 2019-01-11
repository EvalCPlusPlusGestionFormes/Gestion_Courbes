/********************************************************************************
** Form generated from reading UI file 'fdessiner.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDESSINER_H
#define UI_FDESSINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FDessiner
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSlider *verticalSlider;
    QLabel *LabDessin;
    QHBoxLayout *HLayActions;
    QGroupBox *GrpVisu;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RadCadre;
    QRadioButton *RadNormal;
    QRadioButton *RadAucun;
    QCheckBox *ChkEffacer;
    QSlider *horizontalSlider;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FDessiner)
    {
        if (FDessiner->objectName().isEmpty())
            FDessiner->setObjectName(QLatin1String("FDessiner"));
        FDessiner->resize(305, 190);
        centralwidget = new QWidget(FDessiner);
        centralwidget->setObjectName(QLatin1String("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QLatin1String("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 1, 1, 1);

        LabDessin = new QLabel(centralwidget);
        LabDessin->setObjectName(QLatin1String("LabDessin"));

        gridLayout->addWidget(LabDessin, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        HLayActions = new QHBoxLayout();
        HLayActions->setObjectName(QLatin1String("HLayActions"));
        GrpVisu = new QGroupBox(centralwidget);
        GrpVisu->setObjectName(QLatin1String("GrpVisu"));
        horizontalLayout_2 = new QHBoxLayout(GrpVisu);
        horizontalLayout_2->setObjectName(QLatin1String("horizontalLayout_2"));
        RadCadre = new QRadioButton(GrpVisu);
        RadCadre->setObjectName(QLatin1String("RadCadre"));

        horizontalLayout_2->addWidget(RadCadre);

        RadNormal = new QRadioButton(GrpVisu);
        RadNormal->setObjectName(QLatin1String("RadNormal"));

        horizontalLayout_2->addWidget(RadNormal);

        RadAucun = new QRadioButton(GrpVisu);
        RadAucun->setObjectName(QLatin1String("RadAucun"));

        horizontalLayout_2->addWidget(RadAucun);


        HLayActions->addWidget(GrpVisu);

        ChkEffacer = new QCheckBox(centralwidget);
        ChkEffacer->setObjectName(QLatin1String("ChkEffacer"));

        HLayActions->addWidget(ChkEffacer);

        HLayActions->setStretch(0, 80);
        HLayActions->setStretch(1, 20);

        gridLayout->addLayout(HLayActions, 2, 0, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QLatin1String("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 80);
        gridLayout->setRowStretch(1, 5);
        gridLayout->setRowStretch(2, 15);
        FDessiner->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(FDessiner);
        statusBar->setObjectName(QLatin1String("statusBar"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusBar->setFont(font);
        statusBar->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 0, 255);"));
        FDessiner->setStatusBar(statusBar);

        retranslateUi(FDessiner);

        QMetaObject::connectSlotsByName(FDessiner);
    } // setupUi

    void retranslateUi(QMainWindow *FDessiner)
    {
        FDessiner->setWindowTitle(QApplication::translate("FDessiner", "Dessins", nullptr));
#ifndef QT_NO_TOOLTIP
        verticalSlider->setToolTip(QApplication::translate("FDessiner", "<html><head/><body><p>Permet de zoomer selon l'axe Y : <span style=\" font-weight:600; font-style:italic;\">operation visible lorsque le mode &quot;Normal&quot; est selectionne.</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        LabDessin->setText(QApplication::translate("FDessiner", "TextLabel", nullptr));
        GrpVisu->setTitle(QApplication::translate("FDessiner", "Mode de visualisation", nullptr));
#ifndef QT_NO_TOOLTIP
        RadCadre->setToolTip(QApplication::translate("FDessiner", "<html><head/><body><p>Permet d'afficher l'ensemble des courbes de maniere a occuper toutes la zone graphique.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        RadCadre->setText(QApplication::translate("FDessiner", "Cadre", nullptr));
#ifndef QT_NO_TOOLTIP
        RadNormal->setToolTip(QApplication::translate("FDessiner", "<html><head/><body><p>Permet d'afficher l'ensemble des courbes en conservant leurs dimensions initiales.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        RadNormal->setText(QApplication::translate("FDessiner", "Normal", nullptr));
        RadAucun->setText(QApplication::translate("FDessiner", "Aucun", nullptr));
#ifndef QT_NO_TOOLTIP
        ChkEffacer->setToolTip(QApplication::translate("FDessiner", "<html><head/><body><p>Peremt de valider ou devalider l'affacement de la zone graphique lors de chaque action de dessin.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        ChkEffacer->setText(QApplication::translate("FDessiner", "Effacer", nullptr));
#ifndef QT_NO_TOOLTIP
        horizontalSlider->setToolTip(QApplication::translate("FDessiner", "<html><head/><body><p>Permet de zoomer selon l'axe X : <span style=\" font-weight:600; font-style:italic;\">operation visible lorsque le mode &quot;Normal&quot; est selectionne.</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class FDessiner: public Ui_FDessiner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDESSINER_H
