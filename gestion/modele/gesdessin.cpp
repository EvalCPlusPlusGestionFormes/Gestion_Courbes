#include "gesdessin.h"

void gesdessin::Ecrire(
        const int idessin,
        const int epaisseur,
        const QColor c
        )
{
    dessin *d;
    double* x;
    double* y;
    point *tp;
    int nbp;
    int i;
    point engmin,engmax;
    double engxmin,engxmax,engymin,engymax;

    d = this->_cd->LireDessin(idessin);
    if (d == NULL) return;

    tp = d->Lire(nbp);

    if (tp!=NULL)
    {
        x = new double[nbp+1];
        y = new double[nbp+1];
        if ((x!=NULL)||(y!=NULL))
        {
            for (i=0;i<nbp;i++)
                tp[i].LireXetY(x[i],y[i]);
            d->Englobant(engmin,engmax);
            engmin.LireXetY(engxmin,engymin);
            engmax.LireXetY(engxmax,engymax);
            this->_dp->Ecrire(
                        idessin,
                        nbp,
                        x,
                        y,
                        engxmin,
                        engxmax,
                        engymin,
                        engymax,
                        epaisseur,
                        c);
            delete[] x;
            delete[] y;
        }
        delete[] tp;
    }
}

void gesdessin::Ecrire(
        dessin *d,
        const int epaisseur,
        const QColor ct,
        const double ex,
        const double ey,
        const double tx,
        const double ty)
{
    //Pourquoi faire Christian ?
    class dessinp: public dessin
    {
    public:
        void EcrireEx(const double e)
        {this->EcrireExP(e);}
        void EcrireEy(const double e)
        {this->EcrireEyP(e);}
        void EcrireTx(const double t)
        {this->EcrireTxP(t);}
        void EcrireTy(const double t)
        {this->EcrireTyP(t);}
    };

    int idessin;
    point min,max;
    double xmin,ymin,xmax,ymax;

    idessin = this->_cd->Chercher(d);
    if (idessin == -1) return;

    ((dessinp *)d)->EcrireEx(ex);
    ((dessinp *)d)->EcrireEy(ey);
    ((dessinp *)d)->EcrireTx(tx);
    ((dessinp *)d)->EcrireTy(ty);
    d->Generer();

    this->_cd->Englobant(min,max);
    min.LireXetY(xmin,ymin);
    max.LireXetY(xmax,ymax);
    this->_dp->EcrireEnglobant(xmin,xmax,ymin,ymax);

    this->Ecrire(idessin,epaisseur,ct);
}

dessin *gesdessin::Lire(
        const int idessin)
{
    dessin *d;
    d = this->_cd->LireDessin(idessin);
    return (d);
}

dessin *gesdessin::Lire(
        const int idessin,
        int &epaisseur,
        QColor &ct)
{
    dessin *d;
    d = this->Lire(idessin);
    if (d !=NULL)
    {
        this->_dp->Lire(idessin,epaisseur,ct);
    }
    return (d);
}

gesdessin::gesdessin(
        const int largeur,
        const int hauteur,
        const QBrush fond_dessin,
        const string nom_coldessins)
{
    this->_dp = new dessinerpolygones(largeur,hauteur,fond_dessin);
    this->_cd = new coldessins(nom_coldessins);
}

gesdessin::~gesdessin()
{
    delete this->_dp;
    delete this->_cd;
}

