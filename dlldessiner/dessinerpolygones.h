/*
 Classe de gestion de traces polygonaux.
 Cette classe permet de:
    Afficher des polygones
    Gerer des actions sus la fenetre d'affichage
 Pour cela, elle dialogue avec la classe FDessinertrt
*/

#ifndef DESSINER_H
#define DESSINER_H

#include <vector>

#include "dessiner_global.h"
#include "fdessinertrt.h"

using namespace std;

class DESSINERSHARED_EXPORT dessinerpolygones
{
    // définition des structures internes utilisees
    // pour les traitements
    typedef struct struct_point
    {
        double x;
        double y;
    }spoint;

    typedef struct struct_polygone
    {
        QGraphicsPolygonItem *poly;
        spoint englobantmin;
        spoint englobantmax;
        spoint *tp;
        int nbp;
        QColor ctrace;
        QColor ctrace_init;
        int epaisseur_init;
        int epaisseur;
    }spolygone;

    typedef vector<spolygone *> VPOLYGONE;

private:
    // fenetre de dessin
    FDessinertrt *_fd;

    // données de transformation géometriques
    // pour la visualisation
    // (agit sur les doonées affichées)
    double _ex;
    double _ey;
    double _tx;
    double _ty;

    // englobant des données affichées
    spoint _englobantmin;
    spoint _englobantmax;

    // données de définition des polygones
    VPOLYGONE *_vp;

    // mémorisation du mode d'affichage
    int _modeaffichage;

    // boolean peremttant de valider ou non
    // le traitement d'effacement
    bool _effacer;

    void Initialiser(
            const int hauteur,
            const int largeur,
            const QBrush fond);


    void Afficher(
            const spolygone *sp,
            const double ex,
            const double ey,
            const double tx,
            const double ty);


    bool TesterExistence(const int i);
    spolygone *LirePolygone(const int i);
    bool SupprimerDonnees(const int i);

    static void CopierEnglobant(
            spoint *es,
            spoint *ed)
    {
        ed->x = es->x;
        ed->y = es->y;
    }

public:
    dessinerpolygones(void);
    dessinerpolygones(
            const int hauteur,
            const int largeur);
    dessinerpolygones(
            const int hauteur,
            const int largeur,
            const QBrush fond);
    ~dessinerpolygones();

    // definition des donnees
    // pour transformation géométrique
    // (translations et echalle visuelles).
    void EcrireEx(const double e)
    {this->_ex=e;}

    void EcrireEy(const double e)
    {this->_ey=e;}

    void EcrireTx(const double t)
    {this->_tx=t;}

    void EcrireTy(const double t)
    {this->_ty=t;}

    // gestion de la fenetre graphique
    void EcrireDimension(
            const int l,
            const int h)
    {this->_fd->EcrireDimension(l,h);}

    void LireDimension(
            int &l,
            int &h)
    {this->_fd->LireDimension(l,h);}

    void EcrirePosition(
            const int x,
            const int y)
    {this->_fd->EcrirePosition(x,y);}

    void LirePosition(
            int &x,
            int &y)
    {this->_fd->LirePosition(x,y);}

    void Positionner(
            const int posx,
            const int posy)
    {this->EcrirePosition(posx,posy);}

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
            dessinerpolygones *d,
            const int px,
            const int py);

    // définition de la maniere
    // de gerer la fermeture du formulaire
    // 1-> aucun traitement
    // 2-> fenetre cachée
    // 3-> fenetre detruite
    // 4-> arret de l'application
    void EcrireTraitementClose(const int t)
    {this->_fd->EcrireTraitementClose(t);}

    void EcrireNom(const char *nom)
    {this->_fd->setWindowTitle(QString(nom));}

    void MasquerFenetre(void){this->_fd->MasquerFenetre();}
    void AfficherFenetre(void){this->_fd->AfficherFenetre();}

    void Montrer(void)
    {this->_fd->show();}

    void Cacher(void)
    {this->_fd->hide();}

    void EcrireEnglobant(
            const double engxmin,
            const double engxmax,
            const double engymin,
            const double engymax
            )
    {
        this->_englobantmin.x = engxmin;
        this->_englobantmin.y = engymin;
        this->_englobantmax.x = engxmax;
        this->_englobantmax.y = engymax;
    }

    int LireNbDessins(void)
    {return(this->_vp->size());}

    // gestion mémoire ->

    // ajout d'un nouveau polygone
    void Ajouter(void)
    {
        spolygone *sp;

        sp = new spolygone;
        this->_vp->push_back(sp);
    }

    // suppression de polygones
    bool Supprimer(
            const int i);
    void Supprimer(
            void);

    // ecriture des données pour un polygone
    bool Ecrire(
            const int idessin,
            const int nbp,
            const double *ptx,
            const double *pty,
            const double engxmin,
            const double engxmax,
            const double engymin,
            const double engymax,
            const int epaisseur,
            const QColor ctrace);

    bool EcrireEpaisseur(
            const int i,
            const int epaisseur);

    bool EcrireEpaisseur(
            const int i);

    bool Colorer(
            const int i,
            const QColor trace);

    bool Colorer(
            const int i);

    // Lecture des données graphiques pour un polygone
    bool Lire(
            const int idessin,
            int &epaisseur,
            QColor &ctrace);


    void CalculerEchelleMax(double &ex, double &ey);

    // affichage des données
    // cadrage = 0 -> aucun recadrage
    // cadrage = 1 -> recadrage avec conservation des echelles
    // cadrage = 2 -> recadrage sans conservation des echelles
    void Afficher(
            const int modeaffichage=1);
    void Rafraichir(void);

    void EcrireEtatEffacement(bool b)
    {this->_effacer=b;}

    int LireModeAffichage()
    {return (this->_modeaffichage);}

    void ChoisirModeAffichage(
            const int modeaffichage=1)
    {this->_fd->ChoisirModeAffichage(modeaffichage);}

    void Effacer(void);

    void ChoisirModeEffacement(
            const bool etat)
    {this->_fd->ChoisirModeEffacement(etat);}

    void CacherModeEffacement(void)
    {this->_fd->CacherModeEffacement();}

    void AfficherModeEffacement(void)
    {this->_fd->AfficherModeEffacement();}

    void InitialiserSliders(void)
    {this->_fd->InitialiserSliders();}
};

#endif // DESSINER_H
