/*
  Fichier de d�finition de la classe "FDessinertrt"
  Cette classe h�rite de la classe FDessiner et peremt
  de d�finit les actions associ�es au callbacks
  des composants graphiques
  Cette classe est li�e � la classe dessin
  afin de g�rer les actions
*/

#ifndef FDESSINERCTRL_H
#define FDESSINERCTRL_H

#include "dessiner_global.h"
#include "fdessiner.h"

class dessinerpolygones;

class DESSINERSHARED_EXPORT FDessinertrt:public FDessiner
{
    Q_OBJECT

private:
    dessinerpolygones *_dessin;

protected:
    void TrtGererAffichage(const int type);
    void TrtGererEffacement(const bool etat);
    void TrtEchelleX(
            const int v,
            const int vmini,
            const int vmaxi);
    void TrtEchelleY(
            const int v,
            const int vmini,
            const int vmaxi);

public:
    FDessinertrt(
            dessinerpolygones *ctrld,
            QWidget *parent = 0):
        FDessiner(parent)
    {this->_dessin = ctrld;}

    ~FDessinertrt(){}
};

#endif // FDESSINERCTRL_H
