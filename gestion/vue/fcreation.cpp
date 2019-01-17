#include <QMessageBox>
#include <QCloseEvent>
#include <QTabWidget>
#include <qcolordialog.h>
#include <QColor>
#include <QPalette>
#include <QComboBox>

#include "fcreation.h"
#include "ui_fcreation.h"
#include "ctrlcreation.h"

//*******************************************
//              CONSTRUCTEUR
//*******************************************
fcreation::fcreation(ctrlcreation *creation, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fcreation)
{
    this->_ctrlCreate = creation;
    ui->setupUi(this);
    this->initialiserCB();
    this->initialiserTab(1);
}

//*******************************************
//              DESTRUCTEUR
//*******************************************
fcreation::~fcreation()
{
    delete ui;
}

//*******************************************
//          METHODES STATICS
//*******************************************
static void EffacerListe(
        QListWidget *l)
{
    int i;
    int nb;
    QListWidgetItem *it;
    nb = l->count();
    l->setCurrentRow(-1);
    for (i=0;i<nb;i++)
    {
        it = l->item(0);
        delete it;
    }
    l->clear();
}

static void AfficherListe(
        QListWidget *l,
        string *sm,
        string *sr,
        const int nbs
        )
{
    int i;
    QListWidgetItem *it;
    QString im;
    QString ir;

    EffacerListe(l);
    for (i=0;i<nbs;i++)
    {
        it = new QListWidgetItem();
        im = QString(sm[i].data());
        ir = QString(sr[i].data());
        it->setText(im);
        it->setToolTip(ir);
        l->addItem(it);
    }
}

static void SelectionnerListe(
        QListWidget *l,
        const int sel
        )
{
    if ((sel >=0)&&(sel<l->count()))
        l->setCurrentRow(sel);
}

//Méthode confirmer qui permet d'avoir le messageBox de confirmation
//Avant de quitter l'application.
bool fcreation::confirmer(const char *q)
{
    bool r;

    r = QMessageBox::question(
                0,
                "Confirmation",
                q,
                QMessageBox::Yes,
                QMessageBox::No
                )==QMessageBox::Yes;
    return (r);
}

void fcreation::informer(const char *s)
{
    QMessageBox::information(
                0,
                "Confirmation",
                s);
}
//*******************************************
//              ACCESSEURS
//*******************************************

void fcreation::setCouleurCourbes(const QColor ccouleur)
{
    this->_couleurCourbes=ccouleur;
}

QColor fcreation::getCouleurCourbes(void)
{
    return(this->_couleurCourbes);
}

//*******************************************
//              METHODES PUBLIC
//*******************************************
int fcreation::recupLigneSelect(const int index)
{
    int ligne;
    if((index>=1) && (index<=2))
    {
        ligne = this->ui->LstTrigo->currentRow();
    }
    if((index>=3) && (index<=6))
    {
       ligne = this->ui->LstMath->currentRow();
    }
    if((index>=7) && (index<=8))
    {
       ligne = this->ui->LstGeo->currentRow();
    }
    return(ligne);
}



QListWidget* fcreation::Chercher(
        const int type)
{
    QListWidget *l;
    l = NULL;
    if (type == 1)
        l = this->ui->LstMath;
    if (type == 2)
        l = this->ui->LstTrigo;
    if (type == 3)
        l = this->ui->LstGeo;
    return (l);
}


void fcreation::Afficher(
        const int type,
        string *sm,
        string *sr,
        const int nbs)
{
    QListWidget *l;
    l = this->Chercher(type);
    if (l != NULL)
        AfficherListe(l,sm,sr,nbs);
}


void fcreation::Effacer(
        const int type)
{
    QListWidget *l;
    l = this->Chercher(type);
    if (l != NULL)
        EffacerListe(l);
}

void fcreation::Selectionner(
        const int type,
        const int sel)
{
    QListWidget *l;
    l = this->Chercher(type);
    if (l != NULL)
        SelectionnerListe(l,sel);
}

int fcreation::verifChecked(void)
{
    int curTab = this->ui->tabWidgetForme->currentIndex();
    int numRadio;

    switch(curTab)
    {
    case 0:
            if (this->ui->radioCosinus->isChecked())
                numRadio = 1;
            if (this->ui->radioSinus->isChecked())
                numRadio = 2;
        break;

    case 1:
            if (this->ui->radioPuissance2->isChecked())
                numRadio = 3;
            if (this->ui->radioRacineCarree->isChecked())
                numRadio = 4;
            if (this->ui->radioFonction->isChecked())
                numRadio = 5;
            if (this->ui->radioExponentiel->isChecked())
                numRadio = 6;
        break;

    case 2:
            if (this->ui->radioCercle->isChecked())
                numRadio = 7;
            if (this->ui->radioRectangle->isChecked())
                numRadio = 8;
        break;
    }
    return(numRadio);
}

void fcreation::recupParamsTrigo(int &np, double &vp)
{
    np = this->ui->spinPeriodeTrigo->value();
    vp = this->ui->spinValeurPasTrigo->value();
}

void fcreation::recupParamsMaths(double &xmi, double &xma, double &vp)
{
    xmi = this->ui->spinXminMath->value();
    xma = this->ui->spinXmaxMath->value();
    vp = this->ui->spinValeurPasMath->value();
}

void fcreation::recupParamsGeo(double &LarRay, double &HautPas)
{
    LarRay = this->ui->spinLargeurRayonGeo->value();
    HautPas = this->ui->spinHauteurPasGeo->value();
}

void fcreation::recupParamsCommuns(double &ex, double &ey,
                                   double &tx, double &ty, QColor &ct, int &et)
{
    int index = this->verifChecked();
    QString stret;

    if((index>=1) && (index<=2))
    {
        ex = this->ui->spinEchelleXTrigo->value();
        ey = this->ui->spinEchelleYTrigo->value();
        tx = this->ui->spinTransXTrigo->value();
        ty = this->ui->spinTransYTrigo->value();
        ct = this->getCouleurCourbes();
        stret = this->ui->comboEpaisseurTrigo->currentText();
        et=stret.toInt();
    }
    if((index>=3) && (index<=6))
    {
        ex = this->ui->spinEchelleXMath->value();
        ey = this->ui->spinEchelleYMath->value();
        tx = this->ui->spinTransXMath->value();
        ty = this->ui->spinTransYMath->value();
        ct = this->getCouleurCourbes();
        stret = this->ui->comboEpaisseurMath->currentText();
        et=stret.toInt();
    }
    if((index>=7) && (index<=8))
    {
        ex = this->ui->spinEchelleXGeo->value();
        ey = this->ui->spinEchelleYGeo->value();
        tx = this->ui->spinTransXGeo->value();
        ty = this->ui->spinTransYGeo->value();
        ct = this->getCouleurCourbes();
        stret = this->ui->comboEpaisseurGeo->currentText();
        et=stret.toInt();
    }
}

void fcreation::setParamTrigo(const int np, double vp)
{
    this->ui->spinPeriodeTrigo->setValue(np);
    this->ui->spinValeurPasTrigo->setValue(vp);
}

void fcreation::setParamMath(const double xmin, const double xmax, const double vp)
{
    this->ui->spinXminMath->setValue(xmin);
    this->ui->spinXmaxMath->setValue(xmax);
    this->ui->spinValeurPasMath->setValue(vp);
}

void fcreation::setParamGeo(const double larRay, const double hautPas)
{
    this->ui->spinLargeurRayonGeo->setValue(larRay);
    this->ui->spinHauteurPasGeo->setValue(hautPas);
}

void fcreation::setParamCommuns(const double ex, const double ey,
                            const double tx, const double ty,
                            const QColor ct, int et)
{
    int index = this->verifChecked();
    QString stret;
    QString scoul;

    this->setCouleurCourbes(ct);

    if((index>=1) && (index<=2))
    {
        this->ui->spinEchelleXTrigo->setValue(ex);
        this->ui->spinEchelleYTrigo->setValue(ey);
        this->ui->spinTransXTrigo->setValue(tx);
        this->ui->spinTransYTrigo->setValue(ty);
        scoul = QString("background-color: ")+ct.name()+";";
        this->ui->BtnCouleurTrigo->setStyleSheet(scoul);
        stret.setNum(et);
        this->ui->comboEpaisseurTrigo->setCurrentText(stret);
    }
    if((index>=3) && (index<=6))
    {
        this->ui->spinEchelleXMath->setValue(ex);
        this->ui->spinEchelleYMath->setValue(ey);
        this->ui->spinTransXMath->setValue(tx);
        this->ui->spinTransYMath->setValue(ty);
        scoul = QString("background-color: ")+ct.name()+";";
        this->ui->BtnCouleurMath->setStyleSheet(scoul);
        stret.setNum(et);
        this->ui->comboEpaisseurMath->setCurrentText(stret);
    }
    if((index>=7) && (index<=8))
    {
        this->ui->spinEchelleXGeo->setValue(ex);
        this->ui->spinEchelleYGeo->setValue(ey);
        this->ui->spinTransXGeo->setValue(tx);
        this->ui->spinTransYGeo->setValue(ty);
        scoul = QString("background-color: ")+ct.name()+";";
        this->ui->BtnCouleurGeo->setStyleSheet(scoul);
        stret.setNum(et);
        this->ui->comboEpaisseurGeo->setCurrentText(stret);
    }
}

void fcreation::initialiserTab(int index)
{
    switch (index) {

    case 1:
        this->ui->spinPeriodeTrigo->setRange(1,3);
        this->ui->spinPeriodeTrigo->setValue(1);
        this->ui->spinValeurPasTrigo->setRange(0.1,1.5);
        this->ui->spinValeurPasTrigo->setValue(0.1);
        this->ui->spinEchelleXTrigo->setRange(10.0,12.0);
        this->ui->spinEchelleXTrigo->setValue(10.0);
        this->ui->spinEchelleYTrigo->setRange(34.0,37.0);
        this->ui->spinEchelleYTrigo->setValue(34.0);
        this->ui->spinTransXTrigo->setRange(0,0);
        this->ui->spinTransXTrigo->setValue(0);
        this->ui->spinTransYTrigo->setRange(-1.0,1.0);
        this->ui->spinTransYTrigo->setValue(-1.0);
        this->ui->BtnCouleurTrigo->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
		this->ui->comboEpaisseurTrigo->setCurrentIndex(0);
        this->ui->LstTrigo->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();
		
        break;

    case 2:
        this->ui->spinPeriodeTrigo->setRange(1,3);
        this->ui->spinPeriodeTrigo->setValue(1);
        this->ui->spinValeurPasTrigo->setRange(0.1,1.5);
        this->ui->spinValeurPasTrigo->setValue(0.1);
        this->ui->spinEchelleXTrigo->setRange(10.0,12.0);
        this->ui->spinEchelleXTrigo->setValue(10.0);
        this->ui->spinEchelleYTrigo->setRange(34.0,37.0);
        this->ui->spinEchelleYTrigo->setValue(34.0);
        this->ui->spinTransXTrigo->setRange(0,0);
        this->ui->spinTransXTrigo->setValue(0);
        this->ui->spinTransYTrigo->setRange(-1.0,1.0);
        this->ui->spinTransYTrigo->setValue(-1.0);
        this->ui->BtnCouleurTrigo->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
		this->ui->comboEpaisseurTrigo->setCurrentIndex(0);
        this->ui->LstTrigo->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();

		break;

    //Puissance 2
    case 3:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(-1.25,-1.00);
        this->ui->spinXminMath->setValue(-1.25);
        this->ui->spinXmaxMath->setRange(1.0,1.25);
        this->ui->spinXmaxMath->setValue(1.0);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34.0,37.0);
        this->ui->spinEchelleXMath->setValue(34.0);
        this->ui->spinEchelleYMath->setRange(34.0,37.0);
        this->ui->spinEchelleYMath->setValue(34.0);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstMath->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();


        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //Racine Carré
    case 4:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(0.0,1.0);
        this->ui->spinXminMath->setValue(0.0);
        this->ui->spinXmaxMath->setRange(2.0,3.0);
        this->ui->spinXmaxMath->setValue(2.0);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34.0,37.0);
        this->ui->spinEchelleXMath->setValue(34.0);
        this->ui->spinEchelleYMath->setRange(34.0,37.0);
        this->ui->spinEchelleYMath->setValue(37.0);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-2.0,2.0);
        this->ui->spinTransYMath->setValue(-2.0);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstMath->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();


        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //fonction
    case 5:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(0.0,1.0);
        this->ui->spinXminMath->setValue(0.0);
        this->ui->spinXmaxMath->setRange(1.0,2.0);
        this->ui->spinXmaxMath->setValue(1.0);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34.0,37.0);
        this->ui->spinEchelleXMath->setValue(34.0);
        this->ui->spinEchelleYMath->setRange(34.0,37.0);
        this->ui->spinEchelleYMath->setValue(34.0);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstMath->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();


        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //Exponentiel
    case 6:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(-2.0,-1.0);
        this->ui->spinXminMath->setValue(-2.0);
        this->ui->spinXmaxMath->setRange(0.1,1.0);
        this->ui->spinXmaxMath->setValue(0.1);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34.0,37.0);
        this->ui->spinEchelleXMath->setValue(34.0);
        this->ui->spinEchelleYMath->setRange(34.0,37.0);
        this->ui->spinEchelleYMath->setValue(34.0);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstMath->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //Cercle
     case 7:

        //modification des label communs
        initialiserCerRect(index);

        //Parametrage des limites
        this->ui->spinLargeurRayonGeo->setRange(25.0,37.5);
        this->ui->spinLargeurRayonGeo->setValue(25.0);
        this->ui->spinHauteurPasGeo->setRange(0.1,1.0);
        this->ui->spinHauteurPasGeo->setValue(0.1);
        this->ui->spinEchelleXGeo->setRange(1.0,1.5);
        this->ui->spinEchelleXGeo->setValue(1.0);
        this->ui->spinEchelleYGeo->setRange(0.75,1.5);
        this->ui->spinEchelleYGeo->setValue(0.75);
        this->ui->spinTransXGeo->setRange(0,0);
        this->ui->spinTransXGeo->setValue(0);
        this->ui->spinTransYGeo->setRange(-12.0,12.0);
        this->ui->spinTransYGeo->setValue(-12.0);
        this->ui->BtnCouleurGeo->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstGeo->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurGeo->setCurrentIndex(0);
        break;

        //Rectangle
    case 8:

        //modification des label communs
        initialiserCerRect(index);

        //Parametrage des limites
        this->ui->spinLargeurRayonGeo->setRange(25.0,50.0);
        this->ui->spinLargeurRayonGeo->setValue(25.0);
        this->ui->spinHauteurPasGeo->setRange(50.0,100.0);
        this->ui->spinHauteurPasGeo->setValue(50.0);
        this->ui->spinEchelleXGeo->setRange(1.0,1.5);
        this->ui->spinEchelleXGeo->setValue(1.0);
        this->ui->spinEchelleYGeo->setRange(0.75,1.5);
        this->ui->spinEchelleYGeo->setValue(0.75);
        this->ui->spinTransXGeo->setRange(0,0);
        this->ui->spinTransXGeo->setValue(0);
        this->ui->spinTransYGeo->setRange(-12.0,12.0);
        this->ui->spinTransYGeo->setValue(-12.0);
        this->ui->BtnCouleurGeo->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);
        this->ui->LstGeo->setCurrentRow(0);
        this->ui->LstTrigo->setFocus();

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurGeo->setCurrentIndex(0);
        break;

    }
}
void fcreation::initialiserCerRect (int index)
{
    switch (index)
    {
    case 7:
        {
        //Changement du Nom des Label Communs (Rayon/Hauteur et Largeur/Pas )
        this->ui->lblHauteurPasGeo->setText("Valeur du pas");
        this->ui->lblLargeurRayonGeo->setText("Rayon");
        }
        break;

    case 8:
        {
        //Changement du Nom des Label Communs (Rayon/Hauteur et Largeur/Pas )
        this->ui->lblHauteurPasGeo->setText("Hauteur");
        this->ui->lblLargeurRayonGeo->setText("Largeur");
        }
        break;
    }
}

void fcreation::initialiserTips(int index)
{
    switch (index)
    {
    case 1&2://Cosinus et Sinus
        {
        this->ui->spinPeriodeTrigo->setToolTip("Nombre de périodes : entier compris entre 1 et 3");
        this->ui->spinValeurPasTrigo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.5");
        this->ui->spinEchelleXTrigo->setToolTip("Échelle en X: décimale comprise entre 10 et 12");
        this->ui->spinEchelleYTrigo->setToolTip("Échelle en Y: décimale comprise entre 34 et 37");
        this->ui->spinTransXTrigo->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYTrigo->setToolTip("Translation en Y: décimale comprise entre -1 et 1.");
        this->ui->BtnCouleurTrigo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurTrigo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 3://Puissance de 2
        {
        this->ui->spinXminMath->setToolTip("xmin (valeur x de départ de la génération): décimale comprise entre -1 et -1.25");
        this->ui->spinXmaxMath->setToolTip("xmax (valeur x de fin de la génération): décimale comprise entre 1 et 1.25");
        this->ui->spinValeurPasTrigo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.0");
        this->ui->spinEchelleXMath->setToolTip("Échelle en X: décimale comprise entre 34 et 37");
        this->ui->spinEchelleYMath->setToolTip("Échelle en Y: décimale comprise entre 34 et 37");
        this->ui->spinTransXMath->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYMath->setToolTip("Translation en Y: décimale comprise entre -0.5 et 0.5");
        this->ui->BtnCouleurTrigo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurTrigo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 4://Racine Carree
        {
        this->ui->spinXminMath->setToolTip("xmin (valeur x de départ de la génération): décimale comprise entre 0 et 1");
        this->ui->spinXmaxMath->setToolTip("xmax (valeur x de fin de la génération): décimale comprise entre 2 et 3");
        this->ui->spinValeurPasTrigo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.0");
        this->ui->spinEchelleXMath->setToolTip("Échelle en X: décimale comprise entre 34 et 37");
        this->ui->spinEchelleYMath->setToolTip("Échelle en Y: décimale comprise entre 34 et 37");
        this->ui->spinTransXMath->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYMath->setToolTip("Translation en Y: décimale comprise entre -2 et 2");
        this->ui->BtnCouleurTrigo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurTrigo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 5://Fonction
        {
        this->ui->spinXminMath->setToolTip("xmin (valeur x de départ de la génération): décimale comprise entre 0 et 1");
        this->ui->spinXmaxMath->setToolTip("xmax (valeur x de fin de la génération): décimale comprise entre 1 et 2");
        this->ui->spinValeurPasTrigo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.0");
        this->ui->spinEchelleXMath->setToolTip("Échelle en X: décimale comprise entre 34 et 37");
        this->ui->spinEchelleYMath->setToolTip("Échelle en Y: décimale comprise entre 34 et 37");
        this->ui->spinTransXMath->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYMath->setToolTip("Translation en Y: décimale comprise entre -0.5 et 0.5");
        this->ui->BtnCouleurTrigo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurTrigo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 6://Exponentiel
        {
        this->ui->spinXminMath->setToolTip("xmin (valeur x de départ de la génération): décimale comprise entre -2 et -1");
        this->ui->spinXmaxMath->setToolTip("xmax (valeur x de fin de la génération): décimale comprise entre 0.1 et 1");
        this->ui->spinValeurPasTrigo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.0");
        this->ui->spinEchelleXMath->setToolTip("Échelle en X: décimale comprise entre 34 et 37");
        this->ui->spinEchelleYMath->setToolTip("Échelle en Y: décimale comprise entre 34 et 37");
        this->ui->spinTransXMath->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYMath->setToolTip("Translation en Y: décimale comprise entre -0.5 et 0.5");
        this->ui->BtnCouleurTrigo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurTrigo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 7://Cercle
        {
        this->ui->spinLargeurRayonGeo->setToolTip("Rayon : décimale comprise entre 25 et 37.5");
        this->ui->spinHauteurPasGeo->setToolTip("Valeur du pas: décimale comprise entre 0.1 et 1.0");
        this->ui->spinEchelleXGeo->setToolTip("Échelle en X: décimale comprise entre 1 et 1.5");
        this->ui->spinEchelleYGeo->setToolTip("Échelle en Y: décimale comprise entre 0.75 et 1.5");
        this->ui->spinTransXGeo->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYGeo->setToolTip("Translation en Y: décimale comprise entre -12 et 12.");
        this->ui->BtnCouleurGeo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurGeo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    case 8://Rectangle
        {
        this->ui->spinLargeurRayonGeo->setToolTip("Largeur : décimale comprise entre 25 et 50");
        this->ui->spinHauteurPasGeo->setToolTip("Hauteur : décimale comprise entre 50 et 100");
        this->ui->spinEchelleXGeo->setToolTip("Échelle en X: décimale comprise entre 1 et 1.5");
        this->ui->spinEchelleYGeo->setToolTip("Échelle en Y: décimale comprise entre 0.75 et 1.5");
        this->ui->spinTransXGeo->setToolTip("Translation en X: décimale toujours = 0");
        this->ui->spinTransYGeo->setToolTip("Translation en Y: décimale comprise entre -12 et 12.");
        this->ui->BtnCouleurGeo->setToolTip("Couleur de tracé: couleur quelconque");
        this->ui->comboEpaisseurGeo->setToolTip("Épaisseur de tracé: entier compris entre 1 et 2");
        }

        break;

    }
}

//Affichage des fentres graphique
void fcreation::AfficherFenetreGraphique(void)
{
    this->_ctrlCreate->afficherFenetreGraphique(
    this->ui->tabWidgetForme->currentIndex());
}

void fcreation::selectLastRow(void)
{
    int index = this->verifChecked();
    int nbElem;

    if ((index>=1) && (index<=2))
      {
        nbElem = this->ui->LstTrigo->count();
        this->ui->LstTrigo->setCurrentRow(nbElem-1);
      }

    if ((index>=3) && (index<=6))
     {
        nbElem = this->ui->LstMath->count();
        this->ui->LstMath->setCurrentRow(nbElem-1);
     }
    if ((index>=7) && (index<=8))
    {
        nbElem = this->ui->LstGeo->count();
        this->ui->LstGeo->setCurrentRow(nbElem-1);
    }
}

//*******************************************
//              METHDOES PRIVATES
//*******************************************
void fcreation::initialiserCB(void)
{
    //Evenement sur les onglets.

    QObject::connect(
                    this->ui->tabWidgetForme,
                    SIGNAL(currentChanged(int)),
                    this,
                    SLOT(CBParametrerLimites())
                    );

    //Evenement sur le bouton "+"
    QObject::connect(
                    this->ui->pushButtonAjouter,
                    SIGNAL(clicked()),
                    this,
                    SLOT(CBCreer())
                    );

    //Evenement sur le bouton "-"
    QObject::connect(
                    this->ui->pushButtonRetirer,
                    SIGNAL(clicked()),
                    this,
                    SLOT(CBSupprimerLigne())
                    );


    //Evenement sur bouton "Vider"
    QObject::connect(
                    this->ui->pushButtonVider,
                    SIGNAL(clicked()),
                    this,
                    SLOT(CBVider())
                    );
    //Evenement sur bouton "Modifier"
    QObject::connect(
                    this->ui->pushButtonModifier,
                    SIGNAL(clicked()),
                    this,
                    SLOT(CBModifLigne())
                    );

    //Evenement sur bouton "choisir Couleur"
    QObject::connect(
                this->ui->BtnCouleurTrigo,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBChoisirCouleur())
                );
    QObject::connect(
                this->ui->BtnCouleurGeo,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBChoisirCouleur())
                );
    QObject::connect(
                this->ui->BtnCouleurMath,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBChoisirCouleur())
                );
    //Evenement sur Radio bouton
    QObject::connect(
                this->ui->radioCosinus,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioSinus,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioPuissance2,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioRacineCarree,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioFonction,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioExponentiel,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioCercle,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->radioRectangle,
                SIGNAL(clicked(bool)),
                this,
                SLOT (CBParametrerLimites())
                );
    QObject::connect(
                this->ui->LstTrigo,
                SIGNAL(currentRowChanged(int)),
                this,
                SLOT(CBLigneSelectionnee(int))
                );
    QObject::connect(
                this->ui->LstMath,
                SIGNAL(currentRowChanged(int)),
                this,
                SLOT(CBLigneSelectionnee(int))
                );
    QObject::connect(
                this->ui->LstGeo,
                SIGNAL(currentRowChanged(int)),
                this,
                SLOT(CBLigneSelectionnee(int))
                );
}


//*******************************************
//              SLOTS PRIVATES
//*******************************************


void fcreation::CBChoisirCouleur(void)
{
  QString scouleur;
  QColor couleur = QColorDialog::getColor(Qt::white,this);
  scouleur=QString("background-color: ")+couleur.name()+";";
  int i=this->ui->tabWidgetForme->currentIndex();

    if (i==0)
       {
            this->ui->BtnCouleurTrigo->setStyleSheet(scouleur);
            this->setCouleurCourbes(couleur);
        }
   if (i==1)
        {
            this->ui->BtnCouleurMath->setStyleSheet(scouleur);
            this->setCouleurCourbes(couleur);
        }
    if (i==2)
        {
            this->ui->BtnCouleurGeo->setStyleSheet(scouleur);
            this->setCouleurCourbes(couleur);
        }
}


void fcreation::CBCreer(void)
{
    this->_ctrlCreate->creerForme();
    this->selectLastRow();
}

void fcreation::CBSupprimerLigne(void)
{
    this->_ctrlCreate->supprimerForme();
}

void fcreation::CBLigneSelectionnee(int l)
{

    this->_ctrlCreate->afficherSelectionLigne(l);
}

void fcreation::CBParametrerLimites (void)
{
    int index = this->verifChecked();
    this->AfficherFenetreGraphique();

    //********************************************
    //Parametrage des valeurs Mini et Maxi pour la Trigo
    //********************************************
    if ((index>=1) && (index<=2))
      {
        this->initialiserTab(index);
        this->initialiserTips(index);

      }

        //********************************************
        //Parametrage des valeurs Mini et Maxi pour les Math
        //********************************************
    if ((index>=3) && (index<=6))
     {
        this->initialiserTab(index);
        this->initialiserTips(index);

      }

        //********************************************
        //Parametrage des valeurs Mini et Maxi pour les Forme Geo
        //********************************************
    if ((index>=7) && (index<=8))
    {
        this->initialiserTab(index);
        this->initialiserTips(index);
    }

}

void fcreation::CBModifLigne(void)
{
    this->_ctrlCreate->modifLigne();
    this->selectLastRow();
}

void fcreation::CBVider(void)
{
    this->_ctrlCreate->detruireFormes();
    this->selectLastRow();
}

//*******************************************
//              METHDOES PROTECTED
//*******************************************
//Redefinition de la methode closeEvent pour avoir un message
//De confirmation lors de la fermeture de la fenetre principale
void fcreation::closeEvent(QCloseEvent *event)
{
    if (confirmer("Voulez vous quitter l'application")==false)
        event->ignore();
    else
        qApp->quit();
}


