/*
Cette classe permet de gérer l'affichage de polygones
créés avec les classes de génération des tracés.
Il s'agit d'un controleur de gestion des services
des 2 dll
*/

#ifndef CTRL_H
#define CTRL_H

#include "coldessins.h"
#include "dessinerpolygones.h"

class gesdessin
{
#define HAUTEUR_DEF 500
#define LARGEUR_DEF 500
#define FOND_DEF Qt::lightGray
#define NOM_DEF "Dessins"

private:
    // collectionneur de dessin -> gestion des traces
    coldessins *_cd;
    // dessiner polygones -> affichage des tracés
    dessinerpolygones *_dp;

    // transformation d'un tracé en polygone
    void Ecrire(
            const int idessin,
            const int epaisseur,
            const QColor c
            );

public:
    gesdessin(
            const int largeur_dessin=LARGEUR_DEF,
            const int hauteur_dessin=HAUTEUR_DEF,
            const QBrush fond_dessin=FOND_DEF,
            const string nom_coldessins=NOM_DEF);
    ~gesdessin();

    // gestion de la position
    // et de la dimension de la fenetre de dessin
    void EcrireDimension(
            const int l,
            const int h)
    {this->_dp->EcrireDimension(l,h);}

    void LireDimension(
            int &l,
            int &h)
    { this->_dp->LireDimension(l,h);}

    void EcrirePosition(
            const int x,
            const int y)
    {this->_dp->EcrirePosition(x,y);}

    void LirePosition(
            int &x,
            int &y)
    {this->_dp->LirePosition(x,y);}

    void Positionner(
            const int px,
            const int py)
    {this->_dp->Positionner(px,py);}

    // position par rapport à une autre fenetre de dessin
    //px:
    //  1 à droite
    //  2 à gauche
    //  3 au meme endroit
    //py:
    //  1 en bas
    //  2 en haut
    //  3 au meme endroit
    void Positionner(
            const gesdessin *c,
            const int px,
            const int py
            )
    { this->_dp->Positionner(c->_dp,px,py);}

    // accesseurs pour le nom et
    // les données de transformation
    // visuelles (translation et echelle)
    void EcrireNom(
            const char *nom
            )
    {this->_dp->EcrireNom(nom);}

    void MasquerFenetre(void){this->_dp->Cacher();}
    void AfficherFenetre(void){this->_dp->Montrer();}

    void EcrireEchelle(
            const double ex,
            const double ey)
    {
        this->_dp->EcrireEx(ex);
        this->_dp->EcrireEy(ey);
    }

    void EcrireTranslation(
            const double tx,
            const double ty)
    {
        this->_dp->EcrireTx(tx);
        this->_dp->EcrireTy(ty);
    }

    // gestion affichage
    void Rafraichir(void)
    {this->_dp->Rafraichir();}

    void ChoisirModeAffichage(
            const int mode
            )
    {this->_dp->ChoisirModeAffichage(mode);}

    void ChoisirModeEffacement(
            const bool etat
            )
    {this->_dp->ChoisirModeEffacement(etat);}

    void Effacer(void)
    { this->_dp->Effacer();}

    void InitialiserSliders(void)
    {this->_dp->InitialiserSliders();}

    void CacherModeEffacement(void)
    {this->_dp->CacherModeEffacement();}

    void AfficherModeEffacement(void)
    {this->_dp->AfficherModeEffacement();}

    // définition de la maniere
    // de gerer la fermeture du formulaire
    // 1-> aucun traitement
    // 2-> fenetre cachée
    // 3-> fenetre detruite
    // 4-> arret de l'application
    void EcrireTraitementClose(
            const int t
            )
    {this->_dp->EcrireTraitementClose(t);}

    // ecriture des données polygonales
    // pour le dessin
    void Ecrire(
            dessin *d,
            const int epaisseur,
            const QColor ct,
            const double ex=1,
            const double ey=1,
            const double tx=0,
            const double ty=0
            );

    // lecture du ieme tracé
    dessin *Lire( const int i);

    // lecture du ieme tracé et recupération
    // de l'epaisseur et de la couleur
    dessin *Lire(
            const int i,
            int &epaisseur,
            QColor &ct);

    // méthodes d'ajouts de traces
    // (permet également de générer le polygone
    // associé)
    exponentiel *AjouterExponentiel(void)
    {
        exponentiel *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    fonction *AjouterFonction(void)
    {
        fonction *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    puissance2 *AjouterPuissance2(void)
    {
        puissance2 *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    racinecarre *AjouterRacineCarre(void)
    {
        racinecarre *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    cosinus *AjouterCosinus(void)
    {
        cosinus *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    sinus *AjouterSinus(void)
    {
        sinus *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    demicercle *AjouterDemicercle(void)
    {
        demicercle *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    ligne *AjouterLigne(void)
    {
        ligne *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    cercle *AjouterCercle(void)
    {
        cercle *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    rectangle *AjouterRectangle(void)
    {
        rectangle *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    repere *AjouterRepere(void)
    {
        repere *d;
        this->_cd->Ajouter(d);
        this->_dp->Ajouter();
        this->Ecrire(d,1,Qt::black);
        return (d);
    }

    bool Supprimer(
            const int i)
    {
        bool okcd;
        bool okfd;
        okcd = this->_cd->Supprimer(i);
        okfd = this->_dp->Supprimer(i);
        return (okcd&&okfd);
    }

    void Supprimer(void)
    {
        this->_cd->Supprimer();
        this->_dp->Supprimer();
    }

    int LireNbDessins(void)
    {return (this->_cd->LireNbDessins());}

    // gestion de la coloration
    // du ieme trace
    bool Colorer(
            const int i,
            const QColor c)
    {return (this->_dp->Colorer(i,c));}

    bool Colorer(
            const int i)
    {return (this->_dp->Colorer(i));}

    // gestion de l'epaisseur
    // du ieme trace
    bool EcrireEpaisseur(
            const int i,
            const int epaisseur)
    {return (this->_dp->EcrireEpaisseur(i,epaisseur));}

    bool EcrireEpaisseur(
            const int i)
    {return (this->_dp->EcrireEpaisseur(i));}


    // méthode de conversion du ieme trace en string
    // mode= 0 -> informations minimales
    // mode= 1 -> informations reduites
    // mode= 2 -> informations completes
    string toStringUnDessin(
            const int i,
            const int mode=0)
    {
        string s;
        dessin *d;
        s = "";
        d = this->_cd->LireDessin(i);
        if (d!=NULL)
            s = d->toString(mode);
        return (s);
    }

    // méthode de conversion de tous les tracés en string
    // mode= 0 -> informations minimales
    // mode= 1 -> informations reduites
    // mode= 2 -> informations completes
    string toString(
            const int mode=0)
    {return (this->_cd->toString(mode));}
};

#endif // CTRL_H
