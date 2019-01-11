/*
Classe permettant de cr�er la focntion trigonom�trique
(y = sin(x))
*/

#ifndef __SINUS_H__
#define  __SINUS_H__

#include <math.h>

#include "creer_global.h"
#include "trigo.h"

class CREERSHARED_EXPORT sinus:public trigo
{
private:
    static const int TYPE = 200;

protected:
    double Calculer(const double x)
    {return (sin(x));}

    // M�thodes publiques
    //--------------------

public:
    sinus(
            const int nb_periode=1,
            const double pas=0.1):
        trigo(nb_periode,pas,"SINUS",TYPE){}

    // ----------------------
    // M�thodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}

};

#endif
