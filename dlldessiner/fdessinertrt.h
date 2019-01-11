/*
  Fichier de définition de la classe "FDessinertrt"
  Cette classe hérite de la classe FDessiner et peremt
  de définit les actions associées au callbacks
  des composants graphiques
  Cette classe est liée à la classe dessin
  afin de gérer les actions
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
