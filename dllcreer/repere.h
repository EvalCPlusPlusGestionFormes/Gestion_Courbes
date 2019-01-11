/*
Classe permettant de créer un repere orthonormé
Il est constitué de 2 lignes
*/
#ifndef REPERE_H
#define REPERE_H

#include "creer_global.h"

#include "dessin.h"
#include "ligne.h"

class CREERSHARED_EXPORT repere : public dessin
{
private:
    // axe x et y
    ligne *_x;
    ligne *_y;

    static const int TYPE = 3000;

protected:
    string LireCaracteristiques(void)
    {
        double l,h;
        char s[256];

        this->LireDimensions(l,h);
        sprintf (s,
                 "Largeur -> %.2f; Hauteur-> %.2f",
                 l,h
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
    // constructeurs
    // dimensionx = dimension de l'axe x
    // dimensiony = dimension de l'axe y

    repere(
            const double dimensionx=1,
            const double dimensiony=1);
    ~repere();

    // les accesseurs
    // --------------

    void EcrireDimensions(
            const double dimensionx=1,
            const double dimensiony=1);

    void LireDimensions(
            double &dimensionx,
            double &dimensiony);

    // les traitements
    // ---------------

    point* Lire(int &nb);

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};

#endif // REPERE_H
