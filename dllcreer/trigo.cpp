#include <math.h>
#include "trigo.h"

trigo::trigo(
        const int nb_periode,
        const double pas,
        const string entete,
        const int type):
    trace(entete)
{
    this->EcrireNbPeriode(nb_periode);
    this->EcrirePas(pas);
    this->EcrireType(type);
}

void trigo::EcrireNbPeriode(
        const int nb_periode)
{
    double binf,bsup;

    this->_nb_periode = nb_periode;
    binf = -M_PI*nb_periode;
    bsup = M_PI*nb_periode;

    this->EcrireLaBorneInf(binf);
    this->EcrireLaBorneSup(bsup);
}


