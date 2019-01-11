#include <math.h>
#include "demicercle.h"

demicercle::demicercle (
        const double rayon,
        const double pas):
    trace("DEMI-CERCLE",TYPE)
{
    this->EcrireRayon(rayon);
    this->EcrirePas(pas);
}

void demicercle::EcrireRayon(const double v)
{
    this->_rayon=v;
    this->EcrireLaBorneInf(-v);
    this->EcrireLaBorneSup(v);
}

double demicercle::Calculer(const double x)
{
    double xcarre;
    double rcarre;
    double ycarre;
    double y;

    xcarre = x*x;
    rcarre = (this->_rayon*this->_rayon);
    ycarre = rcarre-xcarre;
    y = sqrt(ycarre);
    return (y);
}

