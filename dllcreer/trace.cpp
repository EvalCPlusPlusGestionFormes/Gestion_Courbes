#include "trace.h"

// Define associé aux valeurs qui ne sont pas definies
#define VALEUR_INDEFINI -1E+100


void trace::InitialiserDonnees(
        const double binf,
        const double bsup,
        const double pas,
        const int type
        )
{
    this->_nbpts = 0;
    this->_tabpts.clear();

    this->EcrireLaBorneInf(binf);
    this->EcrireLaBorneSup(bsup);
    this->EcrireLePas(pas);
    this->EcrireType(type);
}

trace::trace(
        const string entete,
        const int type):
    dessin(entete)
{
    this->InitialiserDonnees(
                VALEUR_INDEFINI,
                VALEUR_INDEFINI,
                VALEUR_INDEFINI,
                type);
}

trace::trace(
        const double xmin,
        const double xmax,
        const string entete,
        const int type):
    dessin(entete)
{
    this->InitialiserDonnees(
                xmin,
                xmax,
                VALEUR_INDEFINI,
                type);
}

trace::trace(
        const double xmin,
        const double xmax,
        const double pas,
        const string entete,
        const int type):
    dessin(entete)
{
    this->InitialiserDonnees(
                xmin,
                xmax,
                pas,
                type);
}

trace::~trace()
{
    this->_tabpts.clear();
}

bool trace::GenererSansTransformation(void)
{
    double	pas;
    double	binf;
    double	bsup;
    int		i;
    double x,y;
    point pt;

    pas = this->LireLePas();
    binf = this->LireLaBorneInf();
    bsup = this->LireLaBorneSup();

    // Controle de la definition des donnees necessaires
    if (binf == VALEUR_INDEFINI) return (false);

    if (bsup == VALEUR_INDEFINI) return (false);

    if (pas == VALEUR_INDEFINI) return (false);

    // Allocation du tableau des points
    this->_nbpts = (int)(((bsup-binf)/pas)+1);
    this->_tabpts.clear();
    this->_tabpts.resize(this->_nbpts);

    // Boucle de generation des points
    for (i=0;i<this->_nbpts;i++)
    {
        x = (binf + i*pas);
        if (x>= bsup)
            x = bsup;

        // Appel de la methode virtuelle de calcul !!!
        y = this->Calculer(x);

        // ecriture des coordonnees calculees
        pt.EcrireX(x);
        pt.EcrireY(y);
        this->_tabpts[i].Copier(&pt);
    }
    return (true);
}

void trace::Translater(
        const double tx,
        const double ty)
{
    int nb;
    int i;

    nb = this->_nbpts;
    for (i=0;i<nb;i++)
        this->_tabpts[i].Translater(tx,ty);
}

void trace::Dilater(const double ex, const double ey)
{
    int nb;
    int i;

    nb = this->_nbpts;
    for (i=0;i<nb;i++)
        this->_tabpts[i].Dilater(ex,ey);
}

// Recuperation des points générés
point* trace::Lire(int &nb)
{
    point *t;
    int i;

    nb = this->_nbpts;
    t= new point [nb+1];
    if (t == NULL) return (NULL);

    for (i=0;i<nb;i++)
    {
        t[i].Copier(&(this->_tabpts[i]));
    }

    return (t);
}

// Inversion du tableau des points generes
bool trace::Inverser(void)
{
    int nb;
    int i;
    point *pt;

    nb = this->_nbpts;
    if (nb ==0) return (true);

    pt = new point[nb+1];
    if (pt == NULL) return (false);

    for (i=0;i<nb;i++)
        pt[i].Copier(&(this->_tabpts[i]));

    for (i=0;i<nb;i++)
        this->_tabpts[i].Copier(&(pt[nb-1-i]));

    delete [] pt;

    return (true);
}

// Symetrie selon l'axe X
void trace::MirroirX(void)
{
    int nb;
    int i;

    nb = this->_nbpts;
    for (i=0;i<nb;i++)
    {
        this->_tabpts[i].EcrireX(
                    -this->_tabpts[i].LireX());
    }
}

// Symetrie selon l'axe Y
void trace::MirroirY(void)
{
    int nb;
    int i;

    nb = this->_nbpts;
    for (i=0;i<nb;i++)
    {
        this->_tabpts[i].EcrireY(
                    -this->_tabpts[i].LireY());
    }
}
