/*
Classe permettant de créer une courbe
y = x*x
*/

#ifndef __PUISSANCE2_H__
#define __PUISSANCE2_H__

#include "creer_global.h"
#include "maths.h"

class CREERSHARED_EXPORT puissance2:public maths
{
private:
    static const int TYPE = 50;

protected:   
    double Calculer(const double x){
        return (x*x);}

public:
    puissance2(
            const double xmin=0,
            const double xmax=1,
            const double pas=0.1):
        maths (xmin,xmax,pas,"PUISSANCE DE 2",TYPE){}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif
