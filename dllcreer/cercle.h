/*
Classe permettant de créer un cercle
Il est constitué de 2 demi cercles
*/

#ifndef __CERCLE_H__
#define  __CERCLE_H__

#include "creer_global.h"

#include "dessin.h"
#include "demicercle.h"

class CREERSHARED_EXPORT cercle: public dessin
{			
private:
    // demi cercles haut et bas
    demicercle *_haut;
    demicercle *_bas;

    static const int TYPE = 1000;

protected:
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

    bool GenererSansTransformation(void);
    void Translater(
            const double tx,
            const double ty);
    void Dilater(
            const double ex,
            const double ey);

public:
    cercle(
            const double rayon=1,
            const double pas=0.1);

    ~cercle();

    // les accesseurs
    // --------------

    void EcrireRayon(const double v);
    void EcrirePas(const double v);

    double LireRayon(void);
    double LirePas(void);

    // les traitements
    // ---------------

    point* Lire(int &nb);

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif
