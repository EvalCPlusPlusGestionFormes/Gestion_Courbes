/*
  Fichier de d�finition de la classe de base "trigo"
  Cette classe est abstraite et permet de g�rer un ensemble
  de donn�es permettant de  repr�senter des fonctions trigonom�triques
*/

#ifndef __TRIGO_H__
#define __TRIGO_H__

#include "creer_global.h"
#include "trace.h"

class CREERSHARED_EXPORT trigo:public trace
{  
private:  
    // nombre de p�riodes de la fonction
    // 1 periode correspond � x variant de -PI � PI
    int _nb_periode;

protected:
    string LireCaracteristiques(void)  
    {
        char s[256];
        sprintf (s,
                 "Nb periodes -> %d; Pas-> %.2f",
                 this->LireNbPeriode(),
                 this->LirePas()
                 );
        return (string(s));
    }

public:
    trigo(
            const int nb_periode=1,
            const double pas=0.1,
            const string entete="TRIGO",
            const int type=0);

    virtual ~trigo(){}

    // les accesseurs
    // --------------

    void EcrireNbPeriode(const int nb_periode);
    int LireNbPeriode(void)
    {return (this->_nb_periode);}

    void EcrirePas(const double val)
    {this->EcrireLePas(val);}

    double LirePas(void)
    {return (this->LireLePas());}
};

#endif
