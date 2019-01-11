/*
Classe permettant de créer une courbe
y = sqrt(x)
*/

#ifndef __RACINECARRE_H__
#define __RACINECARRE_H__

#include <math.h>

#include "creer_global.h"
#include "maths.h"

class CREERSHARED_EXPORT racinecarre : public maths
{
private:
    static const int TYPE = 60;

protected:
    double Calculer(const double x)
    {return (sqrt(x));}

public:
    racinecarre(
            const double xmin=0,
            const double xmax=1,
            const double pas=0.1):
        maths (xmin,xmax,pas,"RACINE CARREE",TYPE){}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif
