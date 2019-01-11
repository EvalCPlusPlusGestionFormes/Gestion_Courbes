/*
  Fichier de d�finition de la classe de base "trace"
  Cette classe est abstraite et permet de g�rer un ensemble
  de donn�es permettant de  repr�senter des formes g�om�triques
  ou des fonctions trigonom�triques ou des fonctions math�matiques.
*/

#ifndef __TRACE_H__
#define __TRACE_H__

#include <vector>

#include "creer_global.h"
#include "point.h"
#include "dessin.h"

using namespace std;

class CREERSHARED_EXPORT trace: public dessin
{
private:
    // borne inferieure pour la generation des points
    double	_xmin;

    // borne sup�rieure pour la generation des points
    double	_xmax;

    // pas d'echantillonnage pour la generation des points
    double	_pas;

    // nombre de points constituant la courbe generee
    // (depend des bornes inferieure et superieure et du pas)
    int _nbpts;

    // tableau des points constituant la courbe a generer
    vector<point> _tabpts;

    // Initialisation generale des donnees pour les constructeurs
    void InitialiserDonnees(
            const double binf,
            const double bsup,
            const double _pas,
            const int type);

protected:
    // les accesseurs
    // --------------

    void EcrireLaBorneInf(const double val)
    {this->_xmin = val;}

    double LireLaBorneInf(void)
    {return (this->_xmin);}

    void EcrireLaBorneSup(const double val)
    {this->_xmax = val;}

    double LireLaBorneSup(void)
    {return (this->_xmax);}

    void EcrireLePas(const double val)
    {this->_pas = val;}

    double LireLePas(void)
    {return (this->_pas);}

    // les traitements
    // ---------------

    string LireCaracteristiques(void)
    {
        char s[256];
        sprintf (s,
                 "Borne (inf-> %.2f; sup-> %.2f); Pas-> %.2f",
                 this->LireLaBorneInf(),
                 this->LireLaBorneSup(),
                 this->LireLePas()
                 );
        return (string(s));
    }

    bool GenererSansTransformation(void);

    // M�thode virtuelle pure permettant
    // de definir le calcul � effectuer
    // lors de la g�n�ration des points
    virtual double Calculer(
            const double x)=0;

public:	
    trace(
            const string entete = "TRACE",
            const int type=0);
    trace (
            const double _xmin,
            const double _xmax,
            const string entete = "TRACE",
            const int type=0);
    trace (
            const double _xmin,
            const double _xmax,
            const double _pas,
            const string entete = "TRACE",
            const int type=0);

    virtual ~trace();

    // les traitements
    // ---------------

    // les m�thodes de la classe dessin sont red�finies
    // en public pour les rendre accessibles depuis
    // d'autres classes
    void Translater(
            const double tx,
            const double ty);
    void Dilater(
            const double ex,
            const double ey);


    // M�thode permettant d'inverser le contenu du tableau
    // des points (le dernier devient le premier, etc ...)
    // Retourne false si Erreur et true si OK
    bool Inverser(void);

    // M�thode permettant d'effectuer une symetrie selon l'axe X
    // de l'ensemble des points generes (X = -X)
    void MirroirX(void);

    // M�thode permettant d'effectuer une symetrie selon l'axe Y
    // de l'ensemble des points generes (Y = -Y)
    void MirroirY(void);

    point* Lire(int &nb);
};
#endif
