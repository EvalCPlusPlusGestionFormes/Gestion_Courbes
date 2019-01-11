#include "ligne.h"

ligne::ligne (
        const double x1,
        const double y1,
        const double x2,
        const double y2):
    trace("LIGNE",TYPE)
{
    this->EcrireCoordonnees(x1,y1,x2,y2);
}

void ligne::EcrireCoordonnees(
        const double x1,
        const double y1,
        const double x2,
        const double y2)
{
    this->_x1 = x1;
    this->_y1 = y1;
    this->_x2 = x2;
    this->_y2 = y2;
    double pas, binf,bsup;
    double x1L,x2L;

    x1L = x1;
    x2L = x2;

    if (x1L == x2L)
    {
        x2L = x2L+0.000001;
    }

    this->_a = (y2-y1)/(x2L-x1L);
    this->_b = y1 - _a*x1L;

    binf = x1L;
    bsup = x2L;
    pas = x2L-x1L;

    this->EcrireLaBorneInf(binf);
    this->EcrireLaBorneSup(bsup);
    this->EcrireLePas(pas);
}


