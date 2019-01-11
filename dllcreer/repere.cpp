#include "repere.h"

repere::repere(
        const double dimensionx,
        const double dimensiony):
    dessin("REPERE")
{
    this->_x = new ligne();
    this->_y =new ligne();
    this->EcrireDimensions(dimensionx,dimensiony);
    this->EcrireType(TYPE);
}

void repere::EcrireDimensions(
        const double dimensionx,
        const double dimensiony)
{
    this->_x->EcrireCoordonnees(0,0,dimensionx,0);
    this->_y->EcrireCoordonnees(0,0,0,dimensiony);
}

void repere::LireDimensions(
        double &dimensionx,
        double &dimensiony)
{
    double x1,x2,y1,y2;
    this->_x->LireCoordonnees(x1,y1,x2,y2);
    dimensionx = x2-x1;
    this->_y->LireCoordonnees(x1,y1,x2,y2);
    dimensiony = y2-y1;
}

repere::~repere()
{
    delete this->_x;
    delete this->_y;
}

bool repere::GenererSansTransformation(void)
{
    if (this->_x->Generer() ==false) return (false);
    if (this->_y->Generer() ==false) return (false);
    if (this->_y->Inverser() ==false) return (false);

    return (true);
}

point* repere::Lire(int &nb)
{
    vector<dessin *> vd;

    vd.push_back(this->_y);
    vd.push_back(this->_x);
    return (dessin::Lire(&vd,nb));
}

void repere::Translater(
        const double tx,
        const double ty)
{
    this->_x->Translater(tx,ty);
    this->_y->Translater(tx,ty);
}

void repere::Dilater(const double ex, const double ey)
{
    this->_x->Dilater(ex,ey);
    this->_y->Dilater(ex,ey);
}
