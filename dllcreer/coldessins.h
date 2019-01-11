/*
Classe permettant de gérer un ensemble de tracés
*/

#ifndef COLDESSINS_H
#define COLDESSINS_H

#include <iostream>
#include <vector>

#include "creer_global.h"
#include "dessin.h"
#include "cercle.h"
#include "demicercle.h"
#include "ligne.h"
#include "rectangle.h"
#include "repere.h"
#include "cosinus.h"
#include "exponentiel.h"
#include "fonction.h"
#include "puissance2.h"
#include "racinecarre.h"
#include "sinus.h"

using namespace std;

class CREERSHARED_EXPORT coldessins
{
    typedef vector<dessin *> VDESSINS;

private:
    VDESSINS *_vdessins;
    string _nom;

    bool TesterExistence(const int i);
    bool SupprimerDonnees(const int i);

    void AjouterVecteur(dessin *d)
    {this->_vdessins->push_back(d);}

public:
    coldessins(string nom="LES DESSINS");
    ~coldessins();

    // Les accesseurs
    // --------------
    void EcrireNom(const string nom)
    {this->_nom =nom;}

    string LireNom(void)
    {return (this->_nom);}

    // les méthodes de gestion mémoire
    // -------------------------------
    void Ajouter(racinecarre *&d)
    {
        d = new racinecarre();
        this->AjouterVecteur(d);
    }

    void Ajouter(puissance2 *&d)
    {
        d = new puissance2();
        this->AjouterVecteur(d);
    }

    void Ajouter(fonction *&d)
    {
        d = new fonction();
        this->AjouterVecteur(d);
    }

    void Ajouter(exponentiel *&d)
    {
        d = new exponentiel();
        this->AjouterVecteur(d);
    }

    void Ajouter(cosinus *&d)
    {
        d = new cosinus();
        this->AjouterVecteur(d);
    }

    void Ajouter(sinus *&d)
    {
        d = new sinus();
        this->AjouterVecteur(d);
    }

    void Ajouter(cercle *&d)
    {
        d = new cercle();
        this->AjouterVecteur(d);
    }

    void Ajouter(demicercle *&d)
    {
        d = new demicercle();
        this->AjouterVecteur(d);
    }

    void Ajouter(ligne *&d)
    {
        d = new ligne();
        this->AjouterVecteur(d);
    }

    void Ajouter(rectangle *&d)
    {
        d = new rectangle();
        this->AjouterVecteur(d);
    }

    void Ajouter(repere *&d)
    {
        d = new repere();
        this->AjouterVecteur(d);
    }

    int  Chercher(const dessin *d);

    bool Supprimer(const dessin *d);
    bool Supprimer(const int i);
    void Supprimer(void);

    int LireNbDessins(void)
    {
        return (this->_vdessins->size());
    }

    dessin *LireDessin(const int i);

    // les traitements
    // ---------------

    // méthode de conversion d'un collectionneur en string
    // mode= 0 -> informations minimales
    // mode= 1 -> informations reduites
    // mode= 2 -> informations completes
    string toString(
            const int mode=0);

    // Generation des points
    // Retourne false si Erreur et true si OK
    bool Generer(void);

    // Méthode permettant de déterminer l'englobant
    // du collectionneur
    void Englobant(
            point &min,
            point &max);
};

#endif // COLDESSINS_H
