/*
Classe permettant de créer la focntion trigonométrique
(y = cos(x))
*/

#ifndef __COSINUS_H__
#define  __COSINUS_H__

#include <math.h>

#include "creer_global.h"
#include "trigo.h"

class CREERSHARED_EXPORT cosinus:public trigo
{
    // Méthodes publiques
    //--------------------
private:
    static const int TYPE = 100;

protected:
    double Calculer(const double x)
    {return (cos(x));}

public:
    cosinus(
            const int nb_periode=1,
            const double pas=0.1):
        trigo(nb_periode,pas,"COSINUS",TYPE){}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif
