#include "rectangle.h"

void rectangle::Initialiser(
        const double largeur,
        const double hauteur)
{
    this->_gauche = new ligne();
    this->_haute = new ligne();
    this->_droite = new ligne();
    this->_bas = new ligne();

    this->EcrireDimensions(largeur,hauteur);
    this->EcrireType(TYPE);
}

rectangle::rectangle(
        const double largeur,
        const double hauteur):dessin("RECTANGLE")
{
    this->Initialiser(
                largeur,
                hauteur);
}

void rectangle::EcrireDimensions(
        const double largeur,
        const double hauteur)
{
    double xbg;
    double ybg;
    double xhd;
    double yhd;

    xbg = -largeur/2;
    ybg = -hauteur/2;
    xhd = largeur/2;
    yhd = hauteur/2;

    this->_gauche->EcrireCoordonnees(xbg,ybg,xbg,yhd);
    this->_haute->EcrireCoordonnees(xbg,yhd,xhd,yhd);
    this->_droite->EcrireCoordonnees(xhd,ybg,xhd,yhd);
    this->_bas->EcrireCoordonnees(xbg,ybg,xhd,ybg);
}

void rectangle::LireDimensions(
        double &largeur,
        double &hauteur)
{
    double x1;
    double y1;
    double x2;
    double y2;
    this->_gauche->LireCoordonnees(x1,y1,x2,y2);
    hauteur = y2-y1;
    this->_haute->LireCoordonnees(x1,y1,x2,y2);
    largeur = x2-x1;
}

rectangle::~rectangle()
{
    delete this->_gauche;
    delete this->_haute;
    delete this->_droite;
    delete this->_bas;
}

bool rectangle::GenererSansTransformation(void)
{
    if (this->_gauche->Generer() ==false) return (false);
    if (this->_haute->Generer() ==false) return (false);

    if (this->_droite->Generer() == false) return (false);
    if (this->_droite->Inverser() == false) return (false);

    if (this->_bas->Generer() == false)return (false);
    if (this->_bas->Inverser() == false)return (false);

    return (true);
}

void rectangle::Translater(
        const double tx,
        const double ty)
{
    this->_gauche->Translater(tx,ty);
    this->_haute->Translater(tx,ty);
    this->_droite->Translater(tx,ty);
    this->_bas->Translater(tx,ty);
}

void rectangle::Dilater(
        const double ex,
        const double ey)
{
    this->_gauche->Dilater(ex,ey);
    this->_haute->Dilater(ex,ey);
    this->_droite->Dilater(ex,ey);
    this->_bas->Dilater(ex,ey);
}

point* rectangle::Lire(int &nb)
{
    vector<dessin *> vd;

    vd.push_back(this->_gauche);
    vd.push_back(this->_haute);
    vd.push_back(this->_droite);
    vd.push_back(this->_bas);
    return (dessin::Lire(&vd,nb));
}
