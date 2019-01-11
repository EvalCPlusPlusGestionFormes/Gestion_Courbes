/*
Classe permettant de créer un demi cercle
*/

#ifndef __DEMICERCLE_H__
#define  __DEMICERCLE_H__

#include "creer_global.h"
#include "trace.h"

class CREERSHARED_EXPORT demicercle : public trace
{

private:
    double _rayon;
    static const int TYPE = 10;

protected:
    double Calculer (const double x);

    string LireCaracteristiques(void)
    {
        char s[256];
        sprintf (s,
                 "Rayon -> %.2f; Pas-> %.2f",
                 this->LireRayon(),
                 this->LirePas()
                 );
        return (string(s));
    }


public:
    demicercle (
            const double rayon=1,
            const double pas=0.1);

    // les accesseurs
    // --------------

    void EcrireRayon(const double v);
    double LireRayon(void)
    {return (this->_rayon);}

    void EcrirePas(const double val)
    {this->EcrireLePas(val);}

    double LirePas(void)
    {return (this->LireLePas());}

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};


#endif
