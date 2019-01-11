#include "cercle.h"

cercle::cercle(
        const double rayon,
        const double pas):dessin("CERCLE")
{
    this->_haut =new demicercle();
    this->_bas  =new demicercle();
    this->EcrireRayon(rayon);
    this->EcrirePas(pas);
    this->EcrireType(TYPE);
}

cercle::~cercle()
{
    delete this->_haut;
    delete this->_bas;
}

void cercle::EcrireRayon(const double v)
{
    this->_haut->EcrireRayon(v);
    this->_bas->EcrireRayon(v);
}

double cercle::LireRayon(void)
{
    return (this->_haut->LireRayon());
}

void cercle::EcrirePas(const double v)
{
    this->_haut->EcrirePas(v);
    this->_bas->EcrirePas(v);
}

double cercle::LirePas(void)
{
    return (this->_haut->LirePas());
}

bool cercle::GenererSansTransformation(void)
{
    if (this->_haut->Generer() ==false) return (false);

    if (this->_bas->Generer() == false)return (false);
    this->_bas->MirroirY();
    if (this->_bas->Inverser()==false) return (false);

    return (true);
}

void cercle::Translater(const double tx, const double ty)
{
    this->_haut->Translater(tx,ty);
    this->_bas->Translater(tx,ty);
}

void cercle::Dilater(const double ex, const double ey)
{
    this->_haut->Dilater(ex,ey);
    this->_bas->Dilater(ex,ey);
}

point* cercle::Lire(int &nb)
{   
    vector<dessin *> vd;

    vd.push_back(this->_haut);
    vd.push_back(this->_bas);
    return (dessin::Lire(&vd,nb));
}
