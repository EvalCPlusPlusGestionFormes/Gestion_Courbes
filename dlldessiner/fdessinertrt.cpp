#include "fdessinertrt.h"
#include "dessinerpolygones.h"

void FDessinertrt::TrtGererAffichage(const int type)
{
    this->_dessin->Effacer();
    this->_dessin->Afficher(type);
}

void FDessinertrt::TrtGererEffacement(const bool etat)
{
    this->_dessin->EcrireEtatEffacement(etat);
    this->_dessin->Effacer();
}

void FDessinertrt::TrtEchelleY(
        const int v,
        const int vmini,
        const int vmaxi)
{
    double exmax,eymax;
    double ey;
    if (this->_dessin->LireModeAffichage()==0)
    {
        this->_dessin->CalculerEchelleMax(exmax,eymax);
        ey = (eymax-1)*(v-vmini)/(vmaxi-vmini);
        ey = ey+1;
        this->_dessin->EcrireEy(ey);
        this->_dessin->Rafraichir();
    }
}

void FDessinertrt::TrtEchelleX(
        const int v,
        const int vmini,
        const int vmaxi)
{
    double exmax,eymax;
    double ex;
    if (this->_dessin->LireModeAffichage()==0)
    {
        this->_dessin->CalculerEchelleMax(exmax,eymax);
        ex = (exmax-1)*(v-vmini)/(vmaxi-vmini);
        ex = ex+1;
        this->_dessin->EcrireEx(ex);
        this->_dessin->Rafraichir();
    }
}

