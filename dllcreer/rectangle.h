/*
Classe permettant de créer un rectangle
Il est constitué de 4 lignes
*/
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "creer_global.h"

#include "dessin.h"
#include "ligne.h"

class CREERSHARED_EXPORT rectangle: public dessin
{			
private:   
    // lignes gauche, haute, droite et basse
    ligne *_gauche;
    ligne *_haute;
    ligne *_droite;
    ligne *_bas;

    static const int TYPE = 2000;

    void Initialiser(
            const double largeur,
            const double hauteur);

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
    rectangle(
            const double largeur=1,
            const double hauteur=1
            );

    ~rectangle();

    // les accesseurs
    // --------------

    void EcrireDimensions(
            const double largeur,
            const double hauteur
            );

    void LireDimensions(
            double &largeur,
            double &hauteur
            );

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
