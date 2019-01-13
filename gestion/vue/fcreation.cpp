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

//*******************************************
//              METHODES PUBLICS
//*******************************************

void fcreation::setCouleurCourbes(const QColor ccouleur)
{
    this->_couleurCourbes=ccouleur;
}

QColor fcreation::getCouleurCourbes(void)
{
    return(this->_couleurCourbes);
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

void fcreation::recupParamsCosSin(int &np, double &vp)
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

void fcreation::initialiserTabTrigo(void)
{
    this->ui->spinPeriodeTrigo->setRange(1,3);
    this->ui->spinPeriodeTrigo->setValue(1);
    this->ui->spinValeurPasTrigo->setRange(0.1,1.5);
    this->ui->spinValeurPasTrigo->setValue(0.1);
    this->ui->spinEchelleXTrigo->setRange(10,12);
    this->ui->spinEchelleXTrigo->setValue(10);
    this->ui->spinEchelleYTrigo->setRange(34,37);
    this->ui->spinEchelleYTrigo->setValue(34);
    this->ui->spinTransXTrigo->setRange(0,0);
    this->ui->spinTransXTrigo->setValue(0);
    this->ui->spinTransYTrigo->setRange(-1.0,1.0);
    this->ui->spinTransYTrigo->setValue(-1.0);
    this->ui->BtnCouleurTrigo->setStyleSheet("background-color: rgb(0, 0, 0);");
    this->setCouleurCourbes(Qt::black);

    //Parametrage ComboBox et positionnement sur la valeur=1 (0)
    this->ui->comboEpaisseurTrigo->setCurrentIndex(0);
}

void fcreation::initialiserTabMath(int index)
{
    switch (index) {
    //Puissance 2
    case 3:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(-1,-1.25);
        this->ui->spinXminMath->setValue(-1);
        this->ui->spinXmaxMath->setRange(1,1.25);
        this->ui->spinXmaxMath->setValue(1);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34,37);
        this->ui->spinEchelleXMath->setValue(34);
        this->ui->spinEchelleYMath->setRange(34,37);
        this->ui->spinEchelleYMath->setValue(34);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //Racine Carré
    case 4:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(0,1);
        this->ui->spinXminMath->setValue(0);
        this->ui->spinXmaxMath->setRange(2,3);
        this->ui->spinXmaxMath->setValue(2);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34,37);
        this->ui->spinEchelleXMath->setValue(34);
        this->ui->spinEchelleYMath->setRange(34,37);
        this->ui->spinEchelleYMath->setValue(37);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-2.0,2.0);
        this->ui->spinTransYMath->setValue(2.0);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

        //fonction
    case 5:
        //Parametrage des limites
        this->ui->spinXminMath->setRange(0,1);
        this->ui->spinXminMath->setValue(0);
        this->ui->spinXmaxMath->setRange(1,2);
        this->ui->spinXmaxMath->setValue(1);
        this->ui->spinValeurPasMath->setRange(0.1,1.0);
        this->ui->spinValeurPasMath->setValue(0.1);
        this->ui->spinEchelleXMath->setRange(34,37);
        this->ui->spinEchelleXMath->setValue(34);
        this->ui->spinEchelleYMath->setRange(34,37);
        this->ui->spinEchelleYMath->setValue(34);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);

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
        this->ui->spinEchelleXMath->setRange(34,37);
        this->ui->spinEchelleXMath->setValue(34);
        this->ui->spinEchelleYMath->setRange(34,37);
        this->ui->spinEchelleYMath->setValue(34);
        this->ui->spinTransXMath->setRange(0,0);
        this->ui->spinTransXMath->setValue(0);
        this->ui->spinTransYMath->setRange(-0.5,0.5);
        this->ui->spinTransYMath->setValue(-0.5);
        this->ui->BtnCouleurMath->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurMath->setCurrentIndex(0);
        break;

    }
}

void fcreation::initialiserTabGeo(int index)
{
    switch (index) {

    //Cercle
    case 7:
        //Changement du Nom des Label Communs (Rayon/Hauteur et Largeur/Pas )
        this->ui->lblHauteurPasGeo->setText("Valeur du pas");
        this->ui->lblLargeurRayonGeo->setText("Rayon");

        //Parametrage des limites

        this->ui->spinLargeurRayonGeo->setRange(25.00,37.5);
        this->ui->spinLargeurRayonGeo->setValue(25.00);
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

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurGeo->setCurrentIndex(0);
        break;

        //Rectangle
    case 8:
        //Changement du Nom des Label Communs (Rayon/Hauteur et Largeur/Pas )
        this->ui->lblHauteurPasGeo->setText("Hauteur");
        this->ui->lblLargeurRayonGeo->setText("Largeur");

        //Parametrage des limites
        this->ui->spinLargeurRayonGeo->setRange(25.00,50.00);
        this->ui->spinLargeurRayonGeo->setValue(25.00);
        this->ui->spinHauteurPasGeo->setRange(50.00,100.00);
        this->ui->spinHauteurPasGeo->setValue(50.00);
        this->ui->spinEchelleXGeo->setRange(1.0,1.5);
        this->ui->spinEchelleXGeo->setValue(1.0);
        this->ui->spinEchelleYGeo->setRange(0.75,1.5);
        this->ui->spinEchelleYGeo->setValue(1.5);
        this->ui->spinTransXGeo->setRange(0,0);
        this->ui->spinTransXGeo->setValue(0);
        this->ui->spinTransYGeo->setRange(-12.0,12.0);
        this->ui->spinTransYGeo->setValue(-12.0);
        this->ui->BtnCouleurGeo->setStyleSheet("background-color: rgb(0, 0, 0);");
        this->setCouleurCourbes(Qt::black);

        //Parametrage ComboBox et positionnement sur la valeur=1 (0)
        this->ui->comboEpaisseurGeo->setCurrentIndex(0);
        break;
}
}

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
    this->initialiserTabTrigo();
}

//*******************************************
//              DESTRUCTEUR
//*******************************************
fcreation::~fcreation()
{
    delete ui;
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
                    SLOT(CBAfficherFenetreGraphique())
                    );
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

    //Evenement sur bouton "Vider"
    QObject::connect(
                    this->ui->pushButtonVider,
                    SIGNAL(clicked()),
                    this,
                    SLOT(CBVider())
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
}


//*******************************************
//              SLOTS PRIVATES
//*******************************************
void fcreation::CBAfficherFenetreGraphique(void)
{
    this->_ctrlCreate->afficherFenetreGraphique(
                    this->ui->tabWidgetForme->currentIndex());
}

void fcreation::CBChoisirCouleur(void)
{
      QString scouleur;
      QColor couleur = QColorDialog::getColor(Qt::white,this);
      scouleur=QString("background-color: ")+couleur.name()+";";
      int i=this->ui->tabWidgetForme->currentIndex();

      //this->ui->ComboCouleurTrigo->setStyleSheet(scouleur);

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
    int index;
    index = this->verifChecked();

    if((index>=1) && (index<=2))
       this->_ctrlCreate->creerTrigos(index);
    if((index>=3) && (index<=6))
       this->_ctrlCreate->creerMaths(index);
    if((index>=7) && (index<=8))
       this->_ctrlCreate->creerGeo(index);
}

void fcreation::CBParametrerLimites (void)
{
    int index = this->verifChecked();
    //********************************************
    //Parametrage des valeurs Mini et Maxi pour la Trigo
    //********************************************
if ((index>=1) && (index<=2))
  {
            this->initialiserTabTrigo();
  }

    //********************************************
    //Parametrage des valeurs Mini et Maxi pour les Math
    //********************************************
if ((index>=3) && (index<=6))
 {
    this->initialiserTabMath(index);

  }


    //********************************************
    //Parametrage des valeurs Mini et Maxi pour les Forme Geo
    //********************************************
if ((index>=7) && (index<=8))
{
    this->initialiserTabGeo(index);
}

}

void fcreation::CBVider(void)
{
    int i=this->ui->tabWidgetForme->currentIndex();

    if (i==0){
        int reponse = QMessageBox::question(this, "Confirmation vider Trigo", "Attention, vous allez vider <strong>Trigo</strong>", QMessageBox::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
            {
                this->_ctrlCreate->detruireTrigos();
                QMessageBox::information(this, "Commande effectuée", "La liste a bien été vidé");
            }
        else if (reponse == QMessageBox::No)
            {
                // Ferme la QMessageBox
            }
    }

    if (i==1){
        int reponse = QMessageBox::question(this, "Confirmation vider Math", "Attention, vous allez vider <strong>Math</strong>", QMessageBox::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
            {
                this->_ctrlCreate->detruireMaths();
                QMessageBox::information(this, "Commande effectuée", "La liste a bien été vidé");
            }
        else if (reponse == QMessageBox::No)
            {
                // Ferme la QMessageBox
            }
    }

    if (i==2){
        int reponse = QMessageBox::question(this, "Confirmation vider Géo", "Attention, vous allez vider <strong>Géo</strong>", QMessageBox::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
            {
                this->_ctrlCreate->detruireGeo();
                QMessageBox::information(this, "Commande effectuée", "La liste a bien été vidé");
            }
        else if (reponse == QMessageBox::No)
            {
                // Ferme la QMessageBox
            }
    }
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
