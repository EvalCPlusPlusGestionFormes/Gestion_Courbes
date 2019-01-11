#include "testergesdessin.h"


#define ECHELLETRIGO 5

#define ECHELLEMATH 10

#define RAYON 50
#define LARGEUR 50
#define HAUTEUR 100
#define ECHELLEFORME 0.5


static void AjouterDessinTrigo(gesdessin *gd)
{
    repere *r;
    sinus *ds;
    cosinus *dc;

    r = gd->AjouterRepere();
    r->EcrireDimensions(M_PI,1);
    gd->Ecrire(r,2,Qt::black,ECHELLETRIGO,ECHELLETRIGO,0,0);

    ds = gd->AjouterSinus();
    ds->EcrireNbPeriode(4);
    ds->EcrirePas(0.1);
    gd->Ecrire(ds,1,Qt::green,ECHELLETRIGO,ECHELLETRIGO,0,0);

    dc = gd->AjouterCosinus();
    dc->EcrireNbPeriode(4);
    dc->EcrirePas(0.1);
    gd->Ecrire(dc,1,Qt::blue,ECHELLETRIGO,ECHELLETRIGO,0,0);

    dc = gd->AjouterCosinus();
    dc->EcrireNbPeriode(2);
    dc->EcrirePas(0.8);
    gd->Ecrire(dc,1,Qt::yellow,ECHELLETRIGO,ECHELLETRIGO,0,1);
}

static void AjouterDessinMath(gesdessin *gd)
{
    repere *r;
    puissance2 *dp;
    racinecarre *dr;
    fonction *df;
    exponentiel *de;
    ligne *dl;

    r = gd->AjouterRepere();
    r->EcrireDimensions(1,1);
    gd->Ecrire(r,2,Qt::black,ECHELLEMATH,ECHELLEMATH,0,0);

    dp= gd->AjouterPuissance2();
    dp->EcrireBorneInf(-3);
    dp->EcrireBorneSup(2);
    dp->EcrirePas(0.1);
    gd->Ecrire(dp,1,Qt::cyan,ECHELLEMATH,ECHELLEMATH,0,0);

    dp= gd->AjouterPuissance2();
    dp->EcrireBorneInf(-2);
    dp->EcrireBorneSup(2);
    dp->EcrirePas(0.5);
    gd->Ecrire(dp,1,Qt::darkCyan,ECHELLEMATH,ECHELLEMATH,0,0);

    dr= gd->AjouterRacineCarre();
    dr->EcrireBorneInf(0);
    dr->EcrireBorneSup(2);
    dr->EcrirePas(0.1);
    gd->Ecrire(dr,1,Qt::darkBlue,ECHELLEMATH,ECHELLEMATH,0,0);

    df= gd->AjouterFonction();
    df->EcrireBorneInf(0);
    df->EcrireBorneSup(2);
    df->EcrirePas(0.1);
    gd->Ecrire(df,1,Qt::darkYellow,ECHELLEMATH,ECHELLEMATH,0,0);

    de= gd->AjouterExponentiel();
    de->EcrireBorneInf(-2);
    de->EcrireBorneSup(1);
    de->EcrirePas(0.1);
    gd->Ecrire(de,1,Qt::magenta,ECHELLEMATH,ECHELLEMATH,0,0);

    dl= gd->AjouterLigne();
    dl->EcrireCoordonnees(-2,-2,2,2);
    gd->Ecrire(dl,3,Qt::darkGray,ECHELLEMATH,ECHELLEMATH,0,0);
}

static void AjouterDessinForme(gesdessin *gd)
{
    repere *r;
    rectangle *dr;
    cercle *dc;
    demicercle *ddc;

    r = gd->AjouterRepere();
    r->EcrireDimensions(RAYON,RAYON);
    gd->Ecrire(r,2,Qt::black,ECHELLEFORME,ECHELLEFORME,0,0);

    dr = gd->AjouterRectangle();
    dr->EcrireDimensions(LARGEUR,HAUTEUR);
    gd->Ecrire(dr,3,Qt::red,ECHELLEFORME,ECHELLEFORME,LARGEUR/2-10,HAUTEUR/2+10);

    dr = gd->AjouterRectangle();
    dr->EcrireDimensions(LARGEUR/2,HAUTEUR);
    gd->Ecrire(dr,1,Qt::darkRed,ECHELLEFORME,ECHELLEFORME,0,0);

    dc = gd->AjouterCercle();
    dc->EcrireRayon(RAYON);
    dc->EcrirePas(1);
    gd->Ecrire(dc,3,Qt::green,ECHELLEFORME,ECHELLEFORME,RAYON+10,RAYON+10);

    dc = gd->AjouterCercle();
    dc->EcrireRayon(RAYON);
    dc->EcrirePas(RAYON/5);
    gd->Ecrire(dc,1,Qt::green,ECHELLEFORME,ECHELLEFORME,RAYON,RAYON);

    dc = gd->AjouterCercle();
    dc->EcrireRayon(2*RAYON);
    dc->EcrirePas(1);
    gd->Ecrire(dc,1,Qt::darkGreen,ECHELLEFORME,ECHELLEFORME,0,0);

    ddc = gd->AjouterDemicercle();
    ddc->EcrireRayon(RAYON/2);
    ddc->EcrirePas(1);
    gd->Ecrire(ddc,3,Qt::darkCyan,ECHELLEFORME,ECHELLEFORME,RAYON,0);
}

testergesdessin::testergesdessin(void)
{
    int px,py,largeur,hauteur;

    px=20;
    py=20;

    largeur=250;
    hauteur=250;

    this->_gdformes = new gesdessin(
                largeur,
                hauteur,
                Qt::lightGray,
                "FORMES");
    this->_gdtrigos = new gesdessin(
                largeur,
                hauteur,
                Qt::gray,
                "TRIGO");
    this->_gdmaths = new gesdessin(
                largeur,
                hauteur,
                Qt::lightGray,
                "MATH");
    this->_gdtout = new gesdessin(
                largeur,
                hauteur,
                Qt::white,
                "TOUT");

    this->_gdformes->AfficherModeEffacement();
    this->_gdtrigos->AfficherModeEffacement();
    this->_gdmaths->AfficherModeEffacement();
    this->_gdtout->CacherModeEffacement();

    this->_gdformes->Positionner(px,py);
    this->_gdtrigos->Positionner(this->_gdformes,1,3);
    this->_gdmaths->Positionner(this->_gdtrigos,1,3);
    this->_gdtout->Positionner(this->_gdformes,3,1);

    this->_gdtrigos->EcrireNom("DESSINS TRIGO");
    this->_gdtrigos->EcrireTraitementClose(1);

    this->_gdmaths->EcrireNom("DESSINS MATHEMATIQUES");
    this->_gdmaths->EcrireTraitementClose(2);

    this->_gdformes->EcrireNom("DESSINS FORMES");
    this->_gdformes->EcrireTraitementClose(4);

    this->_gdtout->EcrireNom("TOUS LES DESSINS");
    this->_gdtout->EcrireTraitementClose(1);

    AjouterDessinTrigo(this->_gdtrigos);
    AjouterDessinMath(this->_gdmaths);
    AjouterDessinForme(this->_gdformes);

    AjouterDessinTrigo(this->_gdtout);
    AjouterDessinMath(this->_gdtout);
    AjouterDessinForme(this->_gdtout);

    this->_gdformes->ChoisirModeEffacement(true);
    this->_gdmaths->ChoisirModeEffacement(true);
    this->_gdtrigos->ChoisirModeEffacement(true);
    this->_gdtout->ChoisirModeEffacement(true);

    this->_gdformes->ChoisirModeAffichage(0);
    this->_gdmaths->ChoisirModeAffichage(0);
    this->_gdtrigos->ChoisirModeAffichage(0);
    this->_gdtout->ChoisirModeAffichage(0);
}

testergesdessin::~testergesdessin()
{
    delete this->_gdformes;
    delete this->_gdmaths;
    delete this->_gdtrigos;
    delete this->_gdtout;
}

