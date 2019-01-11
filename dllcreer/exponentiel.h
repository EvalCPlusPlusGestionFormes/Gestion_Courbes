/*
Classe permettant de créer une courbe exponentielle
*/

#ifndef __EXPONENTIEL_H__
#define __EXPONENTIEL_H__

#include <math.h>

#include "creer_global.h"
#include "maths.h"

class CREERSHARED_EXPORT exponentiel:public maths
{
private:
    static const int TYPE = 20;

protected: 
    double Calculer(const double x)
    { return (exp(x));}

public:
    exponentiel(
            const double xmin=0,
            const double xmax=1,
            const double pas=0.1):
        maths(xmin,xmax,pas,"EXPONENTIEL",TYPE){}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}

};

#endif
