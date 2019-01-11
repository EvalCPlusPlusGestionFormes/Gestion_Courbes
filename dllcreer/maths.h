/*
  Fichier de définition de la classe de base "maths"
  Cette classe est abstraite et permet de gérer un ensemble
  de données permettant de  représenter des fonctions mathématiques
*/

#ifndef MATHS_H
#define MATHS_H

#include "creer_global.h"
#include "trace.h"

class CREERSHARED_EXPORT maths:public trace
{
public:
    maths(
            const double xmin=0,
            const double xmax=1,
            const double pas=0.1,
            const string entete="MATHS",
            const int type=0):
        trace (xmin,xmax,pas,entete,type){}

    // les accesseurs
    // --------------

    void EcrirePas(const double val)
    {this->EcrireLePas(val);}

    double LirePas(void)
    {return (this->LireLePas());}

    void EcrireBorneInf(const double val)
    {this->EcrireLaBorneInf(val);}

    double LireBorneInf(void)
    {return (this->LireLaBorneInf());}

    void EcrireBorneSup(const double val)
    {this->EcrireLaBorneSup(val);}

    double LireBorneSup(void)
    {return (this->LireLaBorneSup());}
};

#endif // MATHS_H
