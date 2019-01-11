/*
  Fichier de définition de la classe "FDessiner"
  Cette classe permet de gérer un formulaire
  à l'intérieur duquel il est possible de dessiner
  des graphiques
*/

#ifndef FDESSINER_H
#define FDESSINER_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QAbstractGraphicsShapeItem>
#include <QPushButton>
#include <QRadioButton>

#include "dessiner_global.h"

namespace Ui {
class FDessiner;
}

class DESSINERSHARED_EXPORT FDessiner : public QMainWindow
{
    Q_OBJECT

private:
    Ui::FDessiner *_ui;
    QGraphicsView *_view;
    QGraphicsScene *_scene;
    int _hauteur_scene;
    int _largeur_scene;
    int _trt_close;

    // création des callbacks
    void InitialiserCB(void);

    // Méthodes de gestion mémoires
    // des elements graphiques
    void Ajouter(
            QGraphicsItem *gi
            );

    // Méthodes permettant de
    // dessiner un polygone de différentes
    // manière
    void DessinerPolygoneOuvertLignes(
            QGraphicsPolygonItem *poly);

    void DessinerPolygoneOuvert(
            QGraphicsPolygonItem *poly);

    void DessinerPolygoneFerme(
            QGraphicsPolygonItem *poly);


protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

    // méthodes virtuelles de traitement
    // des callbacks pouvant etre redéfinies dans
    // les classes filles
    virtual void TrtGererAffichage(
            const int type __attribute__((unused))){}

    virtual void TrtGererEffacement
    (const bool etat __attribute__((unused))){}

    virtual void TrtEchelleX(
            const int v __attribute__((unused)),
            const int vmini __attribute__((unused)),
            const int vmaxi __attribute__((unused))){}
    virtual void TrtEchelleY(
            const int v __attribute__((unused)),
            const int vmini __attribute__((unused)),
            const int vmaxi __attribute__((unused))){}

public:
    FDessiner(QWidget *parent = 0);
    virtual ~FDessiner();

    // Choix des modes affichage et effacement
    // Ils permettent d'agir sur les composants
    // graphiques et donc de générer les actions
    // de traitements des callbacks
    void ChoisirModeAffichage(
            const int modeaffichage);

    void ChoisirModeEffacement(
            const bool etat);

    // Gestion du checkbox permettant
    // de choisir si on souhaite
    // effacer la fenetre graphique ou non
    void CacherModeEffacement(void);
    void AfficherModeEffacement(void);

    // Initialisation des sliders de gestion
    // de l'echelle visuelle
    // Il permet d'agir sur les composants
    // graphiques et donc de générer les actions
    // de traitements des callbacks
    void InitialiserSliders(void);

    // création de la fenetre de dessin
    void CreerScene(
            int hauteur,
            int largeur,
            QBrush couleur_fond,
            bool avectrt=false);

    // lecture des dimensions de
    // la fenetre de dessin
    bool LireDimensionScene(
            int &h,
            int &l);

    // gestion de la position et de la taille du
    // formulaire
    void EcrireDimension(
            const int l,
            const int h)
    {this->resize(l,h);}

    void LireDimension(
            int &l,
            int &h)
    {
        l = this->frameGeometry().width();
        h = this->frameGeometry().height();
    }

    void EcrirePosition(
            const int x,
            const int y)
    {this->move(x,y);}

    void LirePosition(
            int &x,
            int &y)
    {
        x = this->frameGeometry().left();
        y = this->frameGeometry().top();
    }

    // définition de la maniere
    // de gerer la fermeture du formulaire
    // 1-> aucun traitement
    // 2-> fenetre cachée
    // 3-> fenetre detruite
    // 4-> arret de l'application
    void EcrireTraitementClose(
            const int t);

    // Méthodes de dessin
    void DessinerRectangle(
            int x,
            int y,
            int hauteur,
            int largeur,
            int epaisseur = 1,
            QColor couleur_trace = Qt::black,
            QColor couleur_fond = Qt::NoBrush);
    void DessinerEllipse(
            int x,
            int y,
            int hauteur,
            int largeur,
            int epaisseur = 1,
            QColor couleur_trace = Qt::black,
            QColor couleur_fond = Qt::NoBrush);
    void DessinerLigne(
            int xd,
            int yd,
            int xf,
            int yf,
            int epaisseur = 1,
            QColor couleur_trace = Qt::black);

    // le polygone ajouté doit etre
    // supprimé par l'application!!!
    static QGraphicsPolygonItem *AjouterPolygone(void);
    static void SupprimerLignesPolygone(
            QGraphicsPolygonItem *poly);
    static void AjouterLignePolygone(
            QGraphicsPolygonItem *poly,
            int xd,
            int yd,
            int xf,
            int yf);
    void DessinerPolygone(
            QGraphicsPolygonItem *poly,
            bool ferme=false,
            int epaisseur = 1,
            QColor couleur_trace = Qt::black,
            QColor couleur_fond = Qt::NoBrush);

    // Effacer la fenetre de dessin
    void Effacer(void);

    //Masque une fenetre.
    void MasquerFenetre(void){this->hide();}

    //Afficher une fenetre.
    void AfficherFenetre(void){this->show();}

    // Modification de la taille
    // de la zone de dessin
    static void DefinirRatioScene(
            const double rx,
            const double ry);

private slots:
    void CBGererAffichageNormal(void);
    void CBGererAffichageCadre(void);
    void CBGererEffacement(void);
    void CBVSliderChange(int v);
    void CBHSliderChange(int v);
};

#endif // FDESSINER_H
