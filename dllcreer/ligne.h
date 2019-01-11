/*
Classe permettant de créer une ligne
(y = ax+b)
*/
#ifndef __LIGNE_H__
#define  __LIGNE_H__

#include "creer_global.h"
#include "trace.h"

class CREERSHARED_EXPORT ligne : public trace
{ 
private:
    double _a;
    double _b;
    double _x1;
    double _y1;
    double _x2;
    double _y2;
    static const int TYPE = 40;

protected:
    string LireCaracteristiques(void)
    {
        char s[256];
        double x1,x2,y1,y2;
        this->LireCoordonnees(x1,y1,x2,y2);
        sprintf (s,
                 "x1 -> %.2f; x2-> %.2f; y1-> %.2f; y2-> %.2f",
                 x1,x2,y1,y2
                 );
        return (string(s));
    }

    double Calculer (const double x)
    {return((this->_a*x)+this->_b);}

public:
    ligne (
            const double x1=0,
            const double y1=0,
            const double x2=1,
            const double y2=1);

    // les accesseurs
    // --------------

    void EcrireCoordonnees(
            const double x1,
            const double y1,
            const double x2,
            const double y2);

    void LireCoordonnees(
            double &x1,
            double &y1,
            double &x2,
            double &y2)
    {
        x1= this->_x1;
        y1= this->_y1;
        x2= this->_x2;
        y2= this->_y2;
    }

    // ----------------------
    // Méthodes de classe
    // ----------------------

    static int LireTypeClass(void)
    {return (TYPE);}
};


#endif

