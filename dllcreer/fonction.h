/*
Classe permettant de créer une courbe
y = log(10x +1)
*/

#ifndef __FONCTION_H__
#define __FONCTION_H__

#include <math.h>

#include "creer_global.h"
#include "maths.h"

class CREERSHARED_EXPORT fonction:public maths
{
private:
    static const int TYPE = 30;

protected:
    double Calculer(const double x)
    {return(log(10*x+1));}


public:
    fonction(
            const double xmin=0,
            const double xmax=1,
            const double pas=0.1):
        maths (xmin,xmax,pas,"FONCTION",TYPE){}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif
