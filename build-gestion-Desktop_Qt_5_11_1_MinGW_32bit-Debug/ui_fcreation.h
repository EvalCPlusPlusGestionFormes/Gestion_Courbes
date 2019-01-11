/********************************************************************************
** Form generated from reading UI file 'fcreation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCREATION_H
#define UI_FCREATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fcreation
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidgetForme;
    QWidget *TabTrigo;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *radioCosinus;
    QRadioButton *radioSinus;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_19;
    QGroupBox *groupBoxParametreMath_2;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_21;
    QListWidget *LstTrigo;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_2;
    QLabel *lblPeriodeTrigo;
    QLabel *lblValeurPasTrigo;
    QDoubleSpinBox *spinValeurPasTrigo;
    QSpacerItem *verticalSpacer_8;
    QSpinBox *spinPeriodeTrigo;
    QLabel *lblEpaisseurTraitTrigo;
    QLabel *lblTransXTrigo;
    QLabel *lblEchelleXTrigo;
    QComboBox *comboEpaisseurTrigo;
    QDoubleSpinBox *spinEchelleXTrigo;
    QSpacerItem *verticalSpacer_9;
    QSpinBox *spinTransXTrigo;
    QLabel *lblTransYTrigo;
    QLabel *lblCouleurTrigo;
    QLabel *lblEchelleYTrigo;
    QPushButton *BtnCouleurTrigo;
    QDoubleSpinBox *spinTransYTrigo;
    QDoubleSpinBox *spinEchelleYTrigo;
    QLabel *label;
    QWidget *TabMath;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *radioPuissance2;
    QRadioButton *radioRacineCarree;
    QRadioButton *radioFonction;
    QRadioButton *radioExponentiel;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBoxParametreMath;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QListWidget *LstMath;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *spinEchelleXMath;
    QLabel *lblEpaisseurTraitMath;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QLabel *lblCouleurMath;
    QLabel *lblXmaxMath;
    QLabel *lblEchelleYMath;
    QDoubleSpinBox *spinValeurPasMath;
    QLabel *lblTransYMath;
    QDoubleSpinBox *spinTransYMath;
    QLabel *lblXminMath;
    QDoubleSpinBox *spinXmaxMath;
    QLabel *lblTransXMath;
    QPushButton *BtnCouleurMath;
    QSpacerItem *verticalSpacer_4;
    QDoubleSpinBox *spinXminMath;
    QLabel *lblValeurPasMath;
    QLabel *lblEchelleXMath;
    QDoubleSpinBox *spinEchelleYMath;
    QDoubleSpinBox *spinTransXMath;
    QComboBox *comboEpaisseurMath;
    QWidget *TabGeo;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioCercle;
    QRadioButton *radioRectangle;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBoxParametreGeo;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *LstGeo;
    QGridLayout *gridLayout_2;
    QLabel *lblLargeurRayonGeo;
    QDoubleSpinBox *spinLargeurRayonGeo;
    QSpacerItem *verticalSpacer;
    QLabel *lblHauteurPasGeo;
    QDoubleSpinBox *spinHauteurPasGeo;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblEpaisseurTraitGeo;
    QDoubleSpinBox *spinEchelleXGeo;
    QSpacerItem *verticalSpacer_3;
    QLabel *lblEchelleYGeo;
    QPushButton *BtnCouleurGeo;
    QLabel *lblTransXGeo;
    QDoubleSpinBox *spinEchelleYGeo;
    QLabel *lblCouleurGeo;
    QLabel *lblEchelleXGeo;
    QLabel *lblTransYGeo;
    QDoubleSpinBox *spinTransYGeo;
    QDoubleSpinBox *spinTransXGeo;
    QComboBox *comboEpaisseurGeo;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonAjouter;
    QPushButton *pushButtonRetirer;
    QPushButton *pushButtonModifier;
    QPushButton *pushButtonAfficher;
    QPushButton *pushButtonVider;

    void setupUi(QMainWindow *fcreation)
    {
        if (fcreation->objectName().isEmpty())
            fcreation->setObjectName(QStringLiteral("fcreation"));
        fcreation->resize(725, 450);
        fcreation->setMinimumSize(QSize(725, 450));
        fcreation->setMaximumSize(QSize(725, 450));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Logo_Eval.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        fcreation->setWindowIcon(icon);
        fcreation->setWindowOpacity(100);
        fcreation->setStyleSheet(QLatin1String("font: 11pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(214, 214, 214);"));
        centralWidget = new QWidget(fcreation);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidgetForme = new QTabWidget(centralWidget);
        tabWidgetForme->setObjectName(QStringLiteral("tabWidgetForme"));
        tabWidgetForme->setStyleSheet(QLatin1String(" font: 11pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(214, 214, 214);"));
        TabTrigo = new QWidget();
        TabTrigo->setObjectName(QStringLiteral("TabTrigo"));
        gridLayout_7 = new QGridLayout(TabTrigo);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        radioCosinus = new QRadioButton(TabTrigo);
        radioCosinus->setObjectName(QStringLiteral("radioCosinus"));
        radioCosinus->setChecked(true);

        horizontalLayout_18->addWidget(radioCosinus);

        radioSinus = new QRadioButton(TabTrigo);
        radioSinus->setObjectName(QStringLiteral("radioSinus"));

        horizontalLayout_18->addWidget(radioSinus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        horizontalLayout_18->setStretch(0, 25);
        horizontalLayout_18->setStretch(1, 25);
        horizontalLayout_18->setStretch(2, 50);

        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        groupBoxParametreMath_2 = new QGroupBox(TabTrigo);
        groupBoxParametreMath_2->setObjectName(QStringLiteral("groupBoxParametreMath_2"));
        horizontalLayout_20 = new QHBoxLayout(groupBoxParametreMath_2);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        LstTrigo = new QListWidget(groupBoxParametreMath_2);
        LstTrigo->setObjectName(QStringLiteral("LstTrigo"));
        LstTrigo->setMinimumSize(QSize(230, 270));
        LstTrigo->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_21->addWidget(LstTrigo);


        horizontalLayout_20->addLayout(horizontalLayout_21);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(20);
        gridLayout_5->setVerticalSpacing(5);
        gridLayout_5->setContentsMargins(-1, 4, -1, 0);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_7, 2, 0, 1, 1);

        label_2 = new QLabel(groupBoxParametreMath_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 26));
        label_2->setMaximumSize(QSize(16777215, 26));

        gridLayout_5->addWidget(label_2, 1, 1, 1, 1);

        lblPeriodeTrigo = new QLabel(groupBoxParametreMath_2);
        lblPeriodeTrigo->setObjectName(QStringLiteral("lblPeriodeTrigo"));
        lblPeriodeTrigo->setMaximumSize(QSize(126, 17));
        lblPeriodeTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblPeriodeTrigo, 3, 0, 1, 1);

        lblValeurPasTrigo = new QLabel(groupBoxParametreMath_2);
        lblValeurPasTrigo->setObjectName(QStringLiteral("lblValeurPasTrigo"));
        lblValeurPasTrigo->setMaximumSize(QSize(125, 17));
        lblValeurPasTrigo->setStyleSheet(QLatin1String("font: 11pt \"Arial\";\n"
""));

        gridLayout_5->addWidget(lblValeurPasTrigo, 3, 1, 1, 1);

        spinValeurPasTrigo = new QDoubleSpinBox(groupBoxParametreMath_2);
        spinValeurPasTrigo->setObjectName(QStringLiteral("spinValeurPasTrigo"));
        spinValeurPasTrigo->setMinimumSize(QSize(126, 26));
        spinValeurPasTrigo->setMaximumSize(QSize(126, 26));
        spinValeurPasTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinValeurPasTrigo->setLocale(QLocale(QLocale::French, QLocale::France));
        spinValeurPasTrigo->setMinimum(0.1);
        spinValeurPasTrigo->setMaximum(1.5);
        spinValeurPasTrigo->setSingleStep(0.01);

        gridLayout_5->addWidget(spinValeurPasTrigo, 4, 1, 1, 1, Qt::AlignVCenter);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_8, 5, 0, 1, 1);

        spinPeriodeTrigo = new QSpinBox(groupBoxParametreMath_2);
        spinPeriodeTrigo->setObjectName(QStringLiteral("spinPeriodeTrigo"));
        spinPeriodeTrigo->setMinimumSize(QSize(126, 26));
        spinPeriodeTrigo->setMaximumSize(QSize(126, 26));
        spinPeriodeTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinPeriodeTrigo->setMinimum(1);
        spinPeriodeTrigo->setMaximum(3);

        gridLayout_5->addWidget(spinPeriodeTrigo, 4, 0, 1, 1, Qt::AlignVCenter);

        lblEpaisseurTraitTrigo = new QLabel(groupBoxParametreMath_2);
        lblEpaisseurTraitTrigo->setObjectName(QStringLiteral("lblEpaisseurTraitTrigo"));
        lblEpaisseurTraitTrigo->setMaximumSize(QSize(126, 17));
        lblEpaisseurTraitTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblEpaisseurTraitTrigo, 6, 0, 1, 1);

        lblTransXTrigo = new QLabel(groupBoxParametreMath_2);
        lblTransXTrigo->setObjectName(QStringLiteral("lblTransXTrigo"));
        lblTransXTrigo->setMaximumSize(QSize(125, 17));
        lblTransXTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblTransXTrigo, 6, 1, 1, 1);

        lblEchelleXTrigo = new QLabel(groupBoxParametreMath_2);
        lblEchelleXTrigo->setObjectName(QStringLiteral("lblEchelleXTrigo"));
        lblEchelleXTrigo->setMaximumSize(QSize(126, 17));
        lblEchelleXTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblEchelleXTrigo, 6, 2, 1, 1);

        comboEpaisseurTrigo = new QComboBox(groupBoxParametreMath_2);
        comboEpaisseurTrigo->addItem(QString());
        comboEpaisseurTrigo->addItem(QString());
        comboEpaisseurTrigo->setObjectName(QStringLiteral("comboEpaisseurTrigo"));
        comboEpaisseurTrigo->setMinimumSize(QSize(126, 26));
        comboEpaisseurTrigo->setMaximumSize(QSize(126, 26));
        comboEpaisseurTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(comboEpaisseurTrigo, 7, 0, 1, 1, Qt::AlignVCenter);

        spinEchelleXTrigo = new QDoubleSpinBox(groupBoxParametreMath_2);
        spinEchelleXTrigo->setObjectName(QStringLiteral("spinEchelleXTrigo"));
        spinEchelleXTrigo->setMinimumSize(QSize(126, 26));
        spinEchelleXTrigo->setMaximumSize(QSize(126, 26));
        spinEchelleXTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleXTrigo->setMinimum(10);
        spinEchelleXTrigo->setMaximum(12);
        spinEchelleXTrigo->setSingleStep(0.01);

        gridLayout_5->addWidget(spinEchelleXTrigo, 7, 2, 1, 1, Qt::AlignVCenter);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_9, 8, 0, 1, 1);

        spinTransXTrigo = new QSpinBox(groupBoxParametreMath_2);
        spinTransXTrigo->setObjectName(QStringLiteral("spinTransXTrigo"));
        spinTransXTrigo->setMinimumSize(QSize(126, 26));
        spinTransXTrigo->setMaximumSize(QSize(126, 26));
        spinTransXTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransXTrigo->setMaximum(0);

        gridLayout_5->addWidget(spinTransXTrigo, 7, 1, 1, 1, Qt::AlignVCenter);

        lblTransYTrigo = new QLabel(groupBoxParametreMath_2);
        lblTransYTrigo->setObjectName(QStringLiteral("lblTransYTrigo"));
        lblTransYTrigo->setMaximumSize(QSize(125, 17));
        lblTransYTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblTransYTrigo, 9, 1, 1, 1);

        lblCouleurTrigo = new QLabel(groupBoxParametreMath_2);
        lblCouleurTrigo->setObjectName(QStringLiteral("lblCouleurTrigo"));
        lblCouleurTrigo->setMaximumSize(QSize(126, 17));
        lblCouleurTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblCouleurTrigo, 9, 0, 1, 1);

        lblEchelleYTrigo = new QLabel(groupBoxParametreMath_2);
        lblEchelleYTrigo->setObjectName(QStringLiteral("lblEchelleYTrigo"));
        lblEchelleYTrigo->setMaximumSize(QSize(126, 17));
        lblEchelleYTrigo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_5->addWidget(lblEchelleYTrigo, 9, 2, 1, 1);

        BtnCouleurTrigo = new QPushButton(groupBoxParametreMath_2);
        BtnCouleurTrigo->setObjectName(QStringLiteral("BtnCouleurTrigo"));
        BtnCouleurTrigo->setMinimumSize(QSize(126, 26));
        BtnCouleurTrigo->setMaximumSize(QSize(126, 26));
        BtnCouleurTrigo->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(BtnCouleurTrigo, 10, 0, 1, 1, Qt::AlignVCenter);

        spinTransYTrigo = new QDoubleSpinBox(groupBoxParametreMath_2);
        spinTransYTrigo->setObjectName(QStringLiteral("spinTransYTrigo"));
        spinTransYTrigo->setMinimumSize(QSize(126, 26));
        spinTransYTrigo->setMaximumSize(QSize(126, 26));
        spinTransYTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransYTrigo->setMinimum(-1);
        spinTransYTrigo->setMaximum(1);

        gridLayout_5->addWidget(spinTransYTrigo, 10, 1, 1, 1, Qt::AlignVCenter);

        spinEchelleYTrigo = new QDoubleSpinBox(groupBoxParametreMath_2);
        spinEchelleYTrigo->setObjectName(QStringLiteral("spinEchelleYTrigo"));
        spinEchelleYTrigo->setMinimumSize(QSize(126, 26));
        spinEchelleYTrigo->setMaximumSize(QSize(126, 26));
        spinEchelleYTrigo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleYTrigo->setMinimum(34);
        spinEchelleYTrigo->setMaximum(37);
        spinEchelleYTrigo->setSingleStep(0.01);

        gridLayout_5->addWidget(spinEchelleYTrigo, 10, 2, 1, 1, Qt::AlignVCenter);

        label = new QLabel(groupBoxParametreMath_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 17));
        label->setMaximumSize(QSize(16777215, 17));

        gridLayout_5->addWidget(label, 0, 1, 1, 1);

        gridLayout_5->setRowStretch(0, 10);

        horizontalLayout_20->addLayout(gridLayout_5);

        horizontalLayout_20->setStretch(0, 35);
        horizontalLayout_20->setStretch(1, 65);

        horizontalLayout_19->addWidget(groupBoxParametreMath_2);


        verticalLayout_3->addLayout(horizontalLayout_19);

        verticalLayout_3->setStretch(0, 15);
        verticalLayout_3->setStretch(1, 70);

        gridLayout_7->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidgetForme->addTab(TabTrigo, QString());
        TabMath = new QWidget();
        TabMath->setObjectName(QStringLiteral("TabMath"));
        gridLayout_4 = new QGridLayout(TabMath);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        radioPuissance2 = new QRadioButton(TabMath);
        radioPuissance2->setObjectName(QStringLiteral("radioPuissance2"));
        radioPuissance2->setChecked(true);

        horizontalLayout_13->addWidget(radioPuissance2);

        radioRacineCarree = new QRadioButton(TabMath);
        radioRacineCarree->setObjectName(QStringLiteral("radioRacineCarree"));

        horizontalLayout_13->addWidget(radioRacineCarree);

        radioFonction = new QRadioButton(TabMath);
        radioFonction->setObjectName(QStringLiteral("radioFonction"));

        horizontalLayout_13->addWidget(radioFonction);

        radioExponentiel = new QRadioButton(TabMath);
        radioExponentiel->setObjectName(QStringLiteral("radioExponentiel"));

        horizontalLayout_13->addWidget(radioExponentiel);

        horizontalLayout_13->setStretch(0, 25);
        horizontalLayout_13->setStretch(1, 25);
        horizontalLayout_13->setStretch(2, 25);
        horizontalLayout_13->setStretch(3, 25);

        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        groupBoxParametreMath = new QGroupBox(TabMath);
        groupBoxParametreMath->setObjectName(QStringLiteral("groupBoxParametreMath"));
        horizontalLayout_15 = new QHBoxLayout(groupBoxParametreMath);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        LstMath = new QListWidget(groupBoxParametreMath);
        LstMath->setObjectName(QStringLiteral("LstMath"));
        LstMath->setMinimumSize(QSize(230, 270));
        LstMath->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_16->addWidget(LstMath);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setHorizontalSpacing(20);
        gridLayout_3->setVerticalSpacing(5);
        gridLayout_3->setContentsMargins(-1, 4, -1, -1);
        spinEchelleXMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinEchelleXMath->setObjectName(QStringLiteral("spinEchelleXMath"));
        spinEchelleXMath->setMinimumSize(QSize(126, 26));
        spinEchelleXMath->setMaximumSize(QSize(126, 26));
        spinEchelleXMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleXMath->setMinimum(34);
        spinEchelleXMath->setMaximum(37);

        gridLayout_3->addWidget(spinEchelleXMath, 7, 2, 1, 1);

        lblEpaisseurTraitMath = new QLabel(groupBoxParametreMath);
        lblEpaisseurTraitMath->setObjectName(QStringLiteral("lblEpaisseurTraitMath"));
        lblEpaisseurTraitMath->setMaximumSize(QSize(126, 17));
        lblEpaisseurTraitMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblEpaisseurTraitMath, 6, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 8, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 5, 0, 1, 1);

        lblCouleurMath = new QLabel(groupBoxParametreMath);
        lblCouleurMath->setObjectName(QStringLiteral("lblCouleurMath"));
        lblCouleurMath->setMaximumSize(QSize(126, 17));
        lblCouleurMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblCouleurMath, 9, 0, 1, 1);

        lblXmaxMath = new QLabel(groupBoxParametreMath);
        lblXmaxMath->setObjectName(QStringLiteral("lblXmaxMath"));
        lblXmaxMath->setMaximumSize(QSize(126, 17));
        lblXmaxMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblXmaxMath, 3, 0, 1, 1);

        lblEchelleYMath = new QLabel(groupBoxParametreMath);
        lblEchelleYMath->setObjectName(QStringLiteral("lblEchelleYMath"));
        lblEchelleYMath->setMaximumSize(QSize(126, 17));
        lblEchelleYMath->setStyleSheet(QLatin1String("font: 11pt \"Arial\";\n"
""));

        gridLayout_3->addWidget(lblEchelleYMath, 9, 2, 1, 1);

        spinValeurPasMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinValeurPasMath->setObjectName(QStringLiteral("spinValeurPasMath"));
        spinValeurPasMath->setMinimumSize(QSize(126, 26));
        spinValeurPasMath->setMaximumSize(QSize(126, 26));
        spinValeurPasMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinValeurPasMath->setMinimum(0.1);
        spinValeurPasMath->setMaximum(1);
        spinValeurPasMath->setSingleStep(0.01);

        gridLayout_3->addWidget(spinValeurPasMath, 4, 1, 1, 1, Qt::AlignVCenter);

        lblTransYMath = new QLabel(groupBoxParametreMath);
        lblTransYMath->setObjectName(QStringLiteral("lblTransYMath"));
        lblTransYMath->setMaximumSize(QSize(126, 17));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lblTransYMath->setFont(font);
        lblTransYMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblTransYMath, 9, 1, 1, 1);

        spinTransYMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinTransYMath->setObjectName(QStringLiteral("spinTransYMath"));
        spinTransYMath->setMinimumSize(QSize(126, 26));
        spinTransYMath->setMaximumSize(QSize(126, 26));
        spinTransYMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransYMath->setMinimum(-0.5);
        spinTransYMath->setMaximum(0.5);
        spinTransYMath->setSingleStep(0.01);

        gridLayout_3->addWidget(spinTransYMath, 10, 1, 1, 1, Qt::AlignVCenter);

        lblXminMath = new QLabel(groupBoxParametreMath);
        lblXminMath->setObjectName(QStringLiteral("lblXminMath"));
        lblXminMath->setMinimumSize(QSize(126, 17));
        lblXminMath->setMaximumSize(QSize(126, 17));
        lblXminMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblXminMath, 0, 0, 1, 1);

        spinXmaxMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinXmaxMath->setObjectName(QStringLiteral("spinXmaxMath"));
        spinXmaxMath->setMinimumSize(QSize(126, 26));
        spinXmaxMath->setMaximumSize(QSize(126, 26));
        spinXmaxMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinXmaxMath->setMinimum(1);
        spinXmaxMath->setMaximum(1.25);
        spinXmaxMath->setSingleStep(0.01);

        gridLayout_3->addWidget(spinXmaxMath, 4, 0, 1, 1, Qt::AlignVCenter);

        lblTransXMath = new QLabel(groupBoxParametreMath);
        lblTransXMath->setObjectName(QStringLiteral("lblTransXMath"));
        lblTransXMath->setMaximumSize(QSize(126, 17));
        lblTransXMath->setFont(font);
        lblTransXMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblTransXMath, 6, 1, 1, 1);

        BtnCouleurMath = new QPushButton(groupBoxParametreMath);
        BtnCouleurMath->setObjectName(QStringLiteral("BtnCouleurMath"));
        BtnCouleurMath->setMinimumSize(QSize(126, 26));
        BtnCouleurMath->setMaximumSize(QSize(126, 26));
        BtnCouleurMath->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(BtnCouleurMath, 10, 0, 1, 1, Qt::AlignVCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 2, 0, 1, 1);

        spinXminMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinXminMath->setObjectName(QStringLiteral("spinXminMath"));
        spinXminMath->setMinimumSize(QSize(126, 26));
        spinXminMath->setMaximumSize(QSize(126, 26));
        spinXminMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinXminMath->setMinimum(-1.25);
        spinXminMath->setMaximum(-1.25);
        spinXminMath->setSingleStep(0.01);

        gridLayout_3->addWidget(spinXminMath, 1, 0, 1, 1, Qt::AlignVCenter);

        lblValeurPasMath = new QLabel(groupBoxParametreMath);
        lblValeurPasMath->setObjectName(QStringLiteral("lblValeurPasMath"));
        lblValeurPasMath->setMaximumSize(QSize(126, 17));
        lblValeurPasMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblValeurPasMath, 3, 1, 1, 1);

        lblEchelleXMath = new QLabel(groupBoxParametreMath);
        lblEchelleXMath->setObjectName(QStringLiteral("lblEchelleXMath"));
        lblEchelleXMath->setMaximumSize(QSize(126, 17));
        lblEchelleXMath->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(lblEchelleXMath, 6, 2, 1, 1);

        spinEchelleYMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinEchelleYMath->setObjectName(QStringLiteral("spinEchelleYMath"));
        spinEchelleYMath->setMinimumSize(QSize(126, 26));
        spinEchelleYMath->setMaximumSize(QSize(126, 26));
        spinEchelleYMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleYMath->setMinimum(34);
        spinEchelleYMath->setMaximum(37);

        gridLayout_3->addWidget(spinEchelleYMath, 10, 2, 1, 1);

        spinTransXMath = new QDoubleSpinBox(groupBoxParametreMath);
        spinTransXMath->setObjectName(QStringLiteral("spinTransXMath"));
        spinTransXMath->setMinimumSize(QSize(126, 26));
        spinTransXMath->setMaximumSize(QSize(126, 26));
        spinTransXMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransXMath->setMaximum(0);

        gridLayout_3->addWidget(spinTransXMath, 7, 1, 1, 1);

        comboEpaisseurMath = new QComboBox(groupBoxParametreMath);
        comboEpaisseurMath->addItem(QString());
        comboEpaisseurMath->addItem(QString());
        comboEpaisseurMath->setObjectName(QStringLiteral("comboEpaisseurMath"));
        comboEpaisseurMath->setMinimumSize(QSize(126, 26));
        comboEpaisseurMath->setMaximumSize(QSize(126, 26));
        comboEpaisseurMath->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));

        gridLayout_3->addWidget(comboEpaisseurMath, 7, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 10);
        gridLayout_3->setRowStretch(1, 10);
        gridLayout_3->setRowStretch(2, 10);
        gridLayout_3->setRowStretch(3, 10);
        gridLayout_3->setRowStretch(4, 10);
        gridLayout_3->setRowStretch(5, 10);
        gridLayout_3->setRowStretch(6, 10);
        gridLayout_3->setRowStretch(7, 10);
        gridLayout_3->setRowStretch(8, 10);
        gridLayout_3->setRowStretch(9, 10);
        gridLayout_3->setRowStretch(10, 10);

        horizontalLayout_15->addLayout(gridLayout_3);

        horizontalLayout_15->setStretch(0, 35);
        horizontalLayout_15->setStretch(1, 65);

        horizontalLayout_14->addWidget(groupBoxParametreMath);


        verticalLayout_2->addLayout(horizontalLayout_14);

        verticalLayout_2->setStretch(0, 15);
        verticalLayout_2->setStretch(1, 70);

        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidgetForme->addTab(TabMath, QString());
        TabGeo = new QWidget();
        TabGeo->setObjectName(QStringLiteral("TabGeo"));
        gridLayout = new QGridLayout(TabGeo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        radioCercle = new QRadioButton(TabGeo);
        radioCercle->setObjectName(QStringLiteral("radioCercle"));
        radioCercle->setChecked(true);

        horizontalLayout_4->addWidget(radioCercle);

        radioRectangle = new QRadioButton(TabGeo);
        radioRectangle->setObjectName(QStringLiteral("radioRectangle"));

        horizontalLayout_4->addWidget(radioRectangle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 25);
        horizontalLayout_4->setStretch(1, 25);
        horizontalLayout_4->setStretch(2, 50);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBoxParametreGeo = new QGroupBox(TabGeo);
        groupBoxParametreGeo->setObjectName(QStringLiteral("groupBoxParametreGeo"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxParametreGeo);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LstGeo = new QListWidget(groupBoxParametreGeo);
        LstGeo->setObjectName(QStringLiteral("LstGeo"));
        LstGeo->setMinimumSize(QSize(230, 270));
        LstGeo->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(LstGeo);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_2->setHorizontalSpacing(20);
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(-1, 4, -1, -1);
        lblLargeurRayonGeo = new QLabel(groupBoxParametreGeo);
        lblLargeurRayonGeo->setObjectName(QStringLiteral("lblLargeurRayonGeo"));
        lblLargeurRayonGeo->setMaximumSize(QSize(126, 17));
        lblLargeurRayonGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblLargeurRayonGeo, 0, 0, 1, 1);

        spinLargeurRayonGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinLargeurRayonGeo->setObjectName(QStringLiteral("spinLargeurRayonGeo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinLargeurRayonGeo->sizePolicy().hasHeightForWidth());
        spinLargeurRayonGeo->setSizePolicy(sizePolicy);
        spinLargeurRayonGeo->setMinimumSize(QSize(126, 26));
        spinLargeurRayonGeo->setMaximumSize(QSize(126, 26));
        spinLargeurRayonGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinLargeurRayonGeo->setMinimum(25);
        spinLargeurRayonGeo->setMaximum(50);
        spinLargeurRayonGeo->setSingleStep(0.01);

        gridLayout_2->addWidget(spinLargeurRayonGeo, 1, 0, 1, 1, Qt::AlignVCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        lblHauteurPasGeo = new QLabel(groupBoxParametreGeo);
        lblHauteurPasGeo->setObjectName(QStringLiteral("lblHauteurPasGeo"));
        lblHauteurPasGeo->setMaximumSize(QSize(126, 17));
        lblHauteurPasGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblHauteurPasGeo, 3, 0, 1, 1);

        spinHauteurPasGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinHauteurPasGeo->setObjectName(QStringLiteral("spinHauteurPasGeo"));
        spinHauteurPasGeo->setMinimumSize(QSize(126, 26));
        spinHauteurPasGeo->setMaximumSize(QSize(126, 26));
        spinHauteurPasGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinHauteurPasGeo->setMinimum(50);
        spinHauteurPasGeo->setMaximum(100);
        spinHauteurPasGeo->setSingleStep(0.01);

        gridLayout_2->addWidget(spinHauteurPasGeo, 4, 0, 1, 1, Qt::AlignVCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 0, 1, 1);

        lblEpaisseurTraitGeo = new QLabel(groupBoxParametreGeo);
        lblEpaisseurTraitGeo->setObjectName(QStringLiteral("lblEpaisseurTraitGeo"));
        lblEpaisseurTraitGeo->setMaximumSize(QSize(126, 17));
        lblEpaisseurTraitGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblEpaisseurTraitGeo, 6, 0, 1, 1);

        spinEchelleXGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinEchelleXGeo->setObjectName(QStringLiteral("spinEchelleXGeo"));
        spinEchelleXGeo->setMinimumSize(QSize(126, 26));
        spinEchelleXGeo->setMaximumSize(QSize(126, 26));
        spinEchelleXGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleXGeo->setMinimum(1);
        spinEchelleXGeo->setMaximum(1.5);
        spinEchelleXGeo->setSingleStep(0.01);

        gridLayout_2->addWidget(spinEchelleXGeo, 7, 2, 1, 1, Qt::AlignVCenter);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 8, 0, 1, 1);

        lblEchelleYGeo = new QLabel(groupBoxParametreGeo);
        lblEchelleYGeo->setObjectName(QStringLiteral("lblEchelleYGeo"));
        lblEchelleYGeo->setMaximumSize(QSize(126, 17));
        lblEchelleYGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblEchelleYGeo, 9, 2, 1, 1);

        BtnCouleurGeo = new QPushButton(groupBoxParametreGeo);
        BtnCouleurGeo->setObjectName(QStringLiteral("BtnCouleurGeo"));
        BtnCouleurGeo->setMinimumSize(QSize(126, 26));
        BtnCouleurGeo->setMaximumSize(QSize(126, 26));
        BtnCouleurGeo->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(BtnCouleurGeo, 10, 0, 1, 1, Qt::AlignVCenter);

        lblTransXGeo = new QLabel(groupBoxParametreGeo);
        lblTransXGeo->setObjectName(QStringLiteral("lblTransXGeo"));
        lblTransXGeo->setMaximumSize(QSize(126, 17));
        lblTransXGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblTransXGeo, 6, 1, 1, 1);

        spinEchelleYGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinEchelleYGeo->setObjectName(QStringLiteral("spinEchelleYGeo"));
        spinEchelleYGeo->setMinimumSize(QSize(126, 26));
        spinEchelleYGeo->setMaximumSize(QSize(126, 26));
        spinEchelleYGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinEchelleYGeo->setMinimum(0.75);
        spinEchelleYGeo->setMaximum(1.5);
        spinEchelleYGeo->setSingleStep(0.01);

        gridLayout_2->addWidget(spinEchelleYGeo, 10, 2, 1, 1, Qt::AlignVCenter);

        lblCouleurGeo = new QLabel(groupBoxParametreGeo);
        lblCouleurGeo->setObjectName(QStringLiteral("lblCouleurGeo"));
        lblCouleurGeo->setMaximumSize(QSize(126, 17));
        lblCouleurGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblCouleurGeo, 9, 0, 1, 1);

        lblEchelleXGeo = new QLabel(groupBoxParametreGeo);
        lblEchelleXGeo->setObjectName(QStringLiteral("lblEchelleXGeo"));
        lblEchelleXGeo->setMaximumSize(QSize(126, 17));
        lblEchelleXGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblEchelleXGeo, 6, 2, 1, 1);

        lblTransYGeo = new QLabel(groupBoxParametreGeo);
        lblTransYGeo->setObjectName(QStringLiteral("lblTransYGeo"));
        lblTransYGeo->setMaximumSize(QSize(126, 17));
        lblTransYGeo->setStyleSheet(QStringLiteral("font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(lblTransYGeo, 9, 1, 1, 1);

        spinTransYGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinTransYGeo->setObjectName(QStringLiteral("spinTransYGeo"));
        spinTransYGeo->setMinimumSize(QSize(126, 26));
        spinTransYGeo->setMaximumSize(QSize(126, 26));
        spinTransYGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransYGeo->setMinimum(-12);
        spinTransYGeo->setMaximum(12);
        spinTransYGeo->setSingleStep(0.01);

        gridLayout_2->addWidget(spinTransYGeo, 10, 1, 1, 1, Qt::AlignVCenter);

        spinTransXGeo = new QDoubleSpinBox(groupBoxParametreGeo);
        spinTransXGeo->setObjectName(QStringLiteral("spinTransXGeo"));
        spinTransXGeo->setMinimumSize(QSize(126, 26));
        spinTransXGeo->setMaximumSize(QSize(126, 26));
        spinTransXGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        spinTransXGeo->setMaximum(0);

        gridLayout_2->addWidget(spinTransXGeo, 7, 1, 1, 1);

        comboEpaisseurGeo = new QComboBox(groupBoxParametreGeo);
        comboEpaisseurGeo->addItem(QString());
        comboEpaisseurGeo->addItem(QString());
        comboEpaisseurGeo->setObjectName(QStringLiteral("comboEpaisseurGeo"));
        comboEpaisseurGeo->setMinimumSize(QSize(126, 26));
        comboEpaisseurGeo->setMaximumSize(QSize(126, 26));
        comboEpaisseurGeo->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));

        gridLayout_2->addWidget(comboEpaisseurGeo, 7, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 10);
        gridLayout_2->setRowStretch(1, 10);
        gridLayout_2->setRowStretch(2, 10);
        gridLayout_2->setRowStretch(3, 10);
        gridLayout_2->setRowStretch(4, 10);
        gridLayout_2->setRowStretch(5, 10);
        gridLayout_2->setRowStretch(6, 10);
        gridLayout_2->setRowStretch(7, 10);
        gridLayout_2->setRowStretch(8, 10);
        gridLayout_2->setRowStretch(9, 10);
        gridLayout_2->setRowStretch(10, 10);

        horizontalLayout_3->addLayout(gridLayout_2);

        horizontalLayout_3->setStretch(0, 35);
        horizontalLayout_3->setStretch(1, 65);

        horizontalLayout_5->addWidget(groupBoxParametreGeo);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 15);
        verticalLayout->setStretch(1, 70);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidgetForme->addTab(TabGeo, QString());

        gridLayout_6->addWidget(tabWidgetForme, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButtonAjouter = new QPushButton(centralWidget);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setMaximumSize(QSize(16777215, 35));
        pushButtonAjouter->setStyleSheet(QLatin1String("font: 75 18pt \"Arial\";\n"
"background-color: rgb(0, 170, 0);"));

        horizontalLayout_6->addWidget(pushButtonAjouter);

        pushButtonRetirer = new QPushButton(centralWidget);
        pushButtonRetirer->setObjectName(QStringLiteral("pushButtonRetirer"));
        pushButtonRetirer->setMaximumSize(QSize(16777215, 35));
        pushButtonRetirer->setStyleSheet(QLatin1String("font: 75 18pt \"Arial\";\n"
"background-color: rgb(221, 0, 0);"));

        horizontalLayout_6->addWidget(pushButtonRetirer);

        pushButtonModifier = new QPushButton(centralWidget);
        pushButtonModifier->setObjectName(QStringLiteral("pushButtonModifier"));
        pushButtonModifier->setMaximumSize(QSize(16777215, 35));
        pushButtonModifier->setStyleSheet(QStringLiteral("font: 75 11pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(pushButtonModifier);

        pushButtonAfficher = new QPushButton(centralWidget);
        pushButtonAfficher->setObjectName(QStringLiteral("pushButtonAfficher"));
        pushButtonAfficher->setMaximumSize(QSize(16777215, 35));
        pushButtonAfficher->setStyleSheet(QStringLiteral("font: 75 11pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(pushButtonAfficher);

        pushButtonVider = new QPushButton(centralWidget);
        pushButtonVider->setObjectName(QStringLiteral("pushButtonVider"));
        pushButtonVider->setMaximumSize(QSize(16777215, 35));
        pushButtonVider->setStyleSheet(QStringLiteral("font: 75 11pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(pushButtonVider);


        gridLayout_6->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_6->setRowMinimumHeight(0, 60);
        gridLayout_6->setRowMinimumHeight(1, 40);
        fcreation->setCentralWidget(centralWidget);

        retranslateUi(fcreation);

        tabWidgetForme->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fcreation);
    } // setupUi

    void retranslateUi(QMainWindow *fcreation)
    {
        fcreation->setWindowTitle(QApplication::translate("fcreation", "Gestion de Formes", nullptr));
        fcreation->setWindowFilePath(QString());
        radioCosinus->setText(QApplication::translate("fcreation", "Cosinus", nullptr));
        radioSinus->setText(QApplication::translate("fcreation", "Sinus", nullptr));
        groupBoxParametreMath_2->setTitle(QApplication::translate("fcreation", "Param\303\250tres", nullptr));
        label_2->setText(QString());
        lblPeriodeTrigo->setText(QApplication::translate("fcreation", "P\303\251riode", nullptr));
        lblValeurPasTrigo->setText(QApplication::translate("fcreation", "Valeur Pas", nullptr));
#ifndef QT_NO_TOOLTIP
        spinValeurPasTrigo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 0.1 et 1.5", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinPeriodeTrigo->setToolTip(QApplication::translate("fcreation", "entier compris entre 1 et 3", nullptr));
#endif // QT_NO_TOOLTIP
        lblEpaisseurTraitTrigo->setText(QApplication::translate("fcreation", "Epaisseur Trait", nullptr));
        lblTransXTrigo->setText(QApplication::translate("fcreation", "Translation en X", nullptr));
        lblEchelleXTrigo->setText(QApplication::translate("fcreation", "Echelle en X", nullptr));
        comboEpaisseurTrigo->setItemText(0, QApplication::translate("fcreation", "1", nullptr));
        comboEpaisseurTrigo->setItemText(1, QApplication::translate("fcreation", "2", nullptr));

#ifndef QT_NO_TOOLTIP
        comboEpaisseurTrigo->setToolTip(QApplication::translate("fcreation", "entier compris entre 1 et 2", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinEchelleXTrigo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 10 et 12", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinTransXTrigo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale toujours = 0", nullptr));
#endif // QT_NO_TOOLTIP
        lblTransYTrigo->setText(QApplication::translate("fcreation", "Translation en Y", nullptr));
        lblCouleurTrigo->setText(QApplication::translate("fcreation", "Couleur", nullptr));
        lblEchelleYTrigo->setText(QApplication::translate("fcreation", "Echelle en Y", nullptr));
#ifndef QT_NO_TOOLTIP
        BtnCouleurTrigo->setToolTip(QApplication::translate("fcreation", "couleur quelconque", nullptr));
#endif // QT_NO_TOOLTIP
        BtnCouleurTrigo->setText(QString());
#ifndef QT_NO_TOOLTIP
        spinTransYTrigo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre -1 et 1.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinEchelleYTrigo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 34 et 37", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QString());
        tabWidgetForme->setTabText(tabWidgetForme->indexOf(TabTrigo), QApplication::translate("fcreation", "Trigonom\303\251triques", nullptr));
        radioPuissance2->setText(QApplication::translate("fcreation", "Puissance de 2", nullptr));
        radioRacineCarree->setText(QApplication::translate("fcreation", "Racine Carr\303\251e", nullptr));
        radioFonction->setText(QApplication::translate("fcreation", "Fonction", nullptr));
        radioExponentiel->setText(QApplication::translate("fcreation", "Exponentiel", nullptr));
        groupBoxParametreMath->setTitle(QApplication::translate("fcreation", "Param\303\250tres", nullptr));
#ifndef QT_NO_TOOLTIP
        spinEchelleXMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 34 et 37", nullptr));
#endif // QT_NO_TOOLTIP
        lblEpaisseurTraitMath->setText(QApplication::translate("fcreation", "Epaisseur Trait", nullptr));
        lblCouleurMath->setText(QApplication::translate("fcreation", "Couleur", nullptr));
        lblXmaxMath->setText(QApplication::translate("fcreation", "Xmax", nullptr));
        lblEchelleYMath->setText(QApplication::translate("fcreation", "Echelle en Y", nullptr));
#ifndef QT_NO_TOOLTIP
        spinValeurPasMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 0.1 et 1.0", nullptr));
#endif // QT_NO_TOOLTIP
        lblTransYMath->setText(QApplication::translate("fcreation", "Translation en Y", nullptr));
#ifndef QT_NO_TOOLTIP
        spinTransYMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre -0.5 et 0.5", nullptr));
#endif // QT_NO_TOOLTIP
        lblXminMath->setText(QApplication::translate("fcreation", "Xmin", nullptr));
#ifndef QT_NO_TOOLTIP
        spinXmaxMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 1 et 1.25", nullptr));
#endif // QT_NO_TOOLTIP
        lblTransXMath->setText(QApplication::translate("fcreation", "Translation en X", nullptr));
#ifndef QT_NO_TOOLTIP
        BtnCouleurMath->setToolTip(QApplication::translate("fcreation", "couleur quelconque", nullptr));
#endif // QT_NO_TOOLTIP
        BtnCouleurMath->setText(QString());
#ifndef QT_NO_TOOLTIP
        spinXminMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre -1 et -1.25", nullptr));
#endif // QT_NO_TOOLTIP
        lblValeurPasMath->setText(QApplication::translate("fcreation", "Valeur Pas", nullptr));
        lblEchelleXMath->setText(QApplication::translate("fcreation", "Echelle en X", nullptr));
#ifndef QT_NO_TOOLTIP
        spinEchelleYMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 34 et 37", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinTransXMath->setToolTip(QApplication::translate("fcreation", "d\303\251cimale toujours = 0", nullptr));
#endif // QT_NO_TOOLTIP
        comboEpaisseurMath->setItemText(0, QApplication::translate("fcreation", "1", nullptr));
        comboEpaisseurMath->setItemText(1, QApplication::translate("fcreation", "2", nullptr));

#ifndef QT_NO_TOOLTIP
        comboEpaisseurMath->setToolTip(QApplication::translate("fcreation", "entier compris entre 1 et 2", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidgetForme->setTabText(tabWidgetForme->indexOf(TabMath), QApplication::translate("fcreation", "Math\303\251matiques", nullptr));
        radioCercle->setText(QApplication::translate("fcreation", "Cercle", nullptr));
        radioRectangle->setText(QApplication::translate("fcreation", "Rectangle", nullptr));
        groupBoxParametreGeo->setTitle(QApplication::translate("fcreation", "Param\303\250tres", nullptr));
        lblLargeurRayonGeo->setText(QApplication::translate("fcreation", "Largeur", nullptr));
#ifndef QT_NO_TOOLTIP
        spinLargeurRayonGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 25 et 50", nullptr));
#endif // QT_NO_TOOLTIP
        lblHauteurPasGeo->setText(QApplication::translate("fcreation", "Hauteur", nullptr));
#ifndef QT_NO_TOOLTIP
        spinHauteurPasGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 50 et 100", nullptr));
#endif // QT_NO_TOOLTIP
        lblEpaisseurTraitGeo->setText(QApplication::translate("fcreation", "Epaisseur Trait", nullptr));
#ifndef QT_NO_TOOLTIP
        spinEchelleXGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 1 et 1.5", nullptr));
#endif // QT_NO_TOOLTIP
        lblEchelleYGeo->setText(QApplication::translate("fcreation", "Echelle en Y", nullptr));
#ifndef QT_NO_TOOLTIP
        BtnCouleurGeo->setToolTip(QApplication::translate("fcreation", "couleur quelconque", nullptr));
#endif // QT_NO_TOOLTIP
        BtnCouleurGeo->setText(QString());
        lblTransXGeo->setText(QApplication::translate("fcreation", "Translation en X", nullptr));
#ifndef QT_NO_TOOLTIP
        spinEchelleYGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre 0.75 et 1.5", nullptr));
#endif // QT_NO_TOOLTIP
        lblCouleurGeo->setText(QApplication::translate("fcreation", "Couleur", nullptr));
        lblEchelleXGeo->setText(QApplication::translate("fcreation", "Echelle en X", nullptr));
        lblTransYGeo->setText(QApplication::translate("fcreation", "Translation en Y", nullptr));
#ifndef QT_NO_TOOLTIP
        spinTransYGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale comprise entre -12 et 12.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinTransXGeo->setToolTip(QApplication::translate("fcreation", "d\303\251cimale toujours = 0", nullptr));
#endif // QT_NO_TOOLTIP
        comboEpaisseurGeo->setItemText(0, QApplication::translate("fcreation", "1", nullptr));
        comboEpaisseurGeo->setItemText(1, QApplication::translate("fcreation", "2", nullptr));

#ifndef QT_NO_TOOLTIP
        comboEpaisseurGeo->setToolTip(QApplication::translate("fcreation", "entier compris entre 1 et 2", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidgetForme->setTabText(tabWidgetForme->indexOf(TabGeo), QApplication::translate("fcreation", "G\303\251om\303\251triques", nullptr));
        pushButtonAjouter->setText(QApplication::translate("fcreation", "+", nullptr));
        pushButtonRetirer->setText(QApplication::translate("fcreation", "-", nullptr));
        pushButtonModifier->setText(QApplication::translate("fcreation", "Modifier", nullptr));
        pushButtonAfficher->setText(QApplication::translate("fcreation", "Afficher", nullptr));
        pushButtonVider->setText(QApplication::translate("fcreation", "Vider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fcreation: public Ui_fcreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCREATION_H
