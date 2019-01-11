/*
  Fichier de définition de la classe "dessin"
  Cette classe est abstraite et permet
  de définir tous les traitements communs
  a l'ensemble des tracés
*/

#ifndef DESSIN_H
#define DESSIN_H

#include <iostream>
#include <vector>

#include "creer_global.h"
#include "point.h"

using namespace std;

class CREERSHARED_EXPORT dessin
{
private:
    // permet de définir une entete pour
    // l'affichage des tracés
    string _entete;

    // données pour les transformations géométriques
    // (translation et echelle)
    double _tx;
    double _ty;
    double _ex;
    double _ey;

    // permet de définir un type différent
    // pour chaque tracé
    int _type;

    // cherche le point minimum
    // et maximum englobant le tracé
    void ChercherEnglobant(
            point &min,
            point &max);

    // lecture du nombre de points
    // du tracé
    int LireNbPts(void);

    // lecture de l'entete
    // (pour afficher les informations)
    string LireEntete(void)
    {return (this->_entete);}

protected:
    // permet aux classes filles
    // de définir un type particulier
    void EcrireType(const int type)
    {this->_type = type;}

    // méthode virtuelle permettant
    // de connaitre les caractéristiques d'un tracé
    virtual string LireCaracteristiques(void)
    {return ("");}

    // méthode virtuelle pure:
    // Generation des points
    // Retourne false si Erreur et true si OK
    virtual bool GenererSansTransformation(void)=0;

    // méthode virtuelle pure:
    // translation de tous les points du tracé
    virtual void Translater(
            const double tx,
            const double ty)=0;

    // méthode virtuelle pure:
    // echelle sur tous les points du tracé
    virtual void Dilater(
            const double ex,
            const double ey)=0;


    void EcrireExP(const double e)
    {this->_ex=e;}
    void EcrireEyP(const double e)
    {this->_ey=e;}
    void EcrireTxP(const double t)
    {this->_tx=t;}
    void EcrireTyP(const double t)
    {this->_ty=t;}

public:
    dessin(
            const string entete = "DESSIN"
            );

    virtual ~dessin(){}

    // les accesseurs
    // --------------

    double LireEx(void)
    {return this->_ex;}
    double LireEy(void)
    {return this->_ey;}
    double LireTx(void)
    {return this->_tx;}
    double LireTy(void)
    {return this->_ty;}

    int LireType(void)
    {return (this->_type);}

    // les traitements
    // ---------------

    // Generation des points
    // Retourne false si Erreur et true si OK
    bool Generer(void);

    // Méthode virtuelle pure
    // permettant de recuperer un tableau de points
    // Retourne NULL si Erreur et le pointeur vers le tableau des points si OK
    // LE TABLEAU DES POINTS DEVRA ETRE LIBERE LORSQU'IL NE SERA PLUS
    // UTILISE!!!!
    // le paramètre de sortie permet de connaitre le nombre de points
    virtual point* Lire(
            int &nb)=0;

    // méthode de conversion d'un trace en string
    // mode= 0 -> informations minimales
    // mode= 1 -> informations reduites
    // mode= 2 -> informations completes
    string toString(
            const int mode=0);

    // Méthode permettant d'afficher à l'ecran
    // les coordonnees de tous les points generes
    string toStringPoints(void);

    // Méthode permettant de déterminer l'englobant
    // du dessin
    void Englobant(
            point &min,
            point &max);

    // ----------------------
    // Méthodes de classe
    // ----------------------

    // ajout d'un tableau de points(ts) à un tableau de points(td)
    // nbs = nombre de points a ajouter
    // nbd = nombre de points de td avant ajout et aprés ajouts
    static void Ajouter(
            point *ts,
            const int nbs,
            point *td,
            int &nbd);

    // Affichage a l'ecran d'un tableau de points
    static string toStringPoints(
            point *t,
            const int nb);

    // determine le rectangle englobant
    // un ensemble de points
    static void Englobant(
            point *t,
            const int nb,
            point &min,
            point &max);

    // Permet de récupérer un ensemble de points
    // contenus dans plusieurs dessins
    // Le paralmètre de sortie peremt de connaitre
    // le nombre de points
    static point* Lire(
            vector<dessin *> *vd,
            int &nb);
};

#endif // DESSIN_H
