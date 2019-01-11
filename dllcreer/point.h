/*
  Fichier de définition de la classe "point"
  Cette classe permet de gérer un point 2D
*/

#ifndef __POINT__H__
#define __POINT__H__

#include "creer_global.h"

class CREERSHARED_EXPORT point
{
private:
    double _x;
    double _y;

public:
    point(void)
    {
        this->EcrireX(0);
        this->EcrireY(0);
    }
    ~point()
    {}

    // les accesseurs
    // --------------

    double LireX(void)
    {return this->_x;}

    void EcrireX(const double x)
    {this->_x=x;}

    double LireY(void)
    {return this->_y;}

    void EcrireY(const double y)
    {this->_y=y;}

    void LireXetY(double &x, double &y)
    {
        x = this->LireX();
        y = this->LireY();
    }

    // les traitements
    // ---------------

    // copie d'un point dans l'objet courant
    void Copier(point *ps)
    {
        this->EcrireX(ps->LireX());
        this->EcrireY(ps->LireY());
    }

    // translation du point
    void Translater(
            const double tx,
            const double ty)
    {
        this->EcrireX(this->LireX()+tx);
        this->EcrireY(this->LireY()+ty);
    }

    // echelle sur le point
    void Dilater(
            const double ex,
            const double ey)
    {
        this->EcrireX(this->LireX()*ex);
        this->EcrireY(this->LireY()*ey);
    }
};

#endif
