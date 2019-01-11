#include "dessin.h"

dessin::dessin(
        const string entete)
{
    this->EcrireTxP(0);
    this->EcrireTyP(0);
    this->EcrireExP(1);
    this->EcrireEyP(1);
    this->_entete = entete;
    this->EcrireType(0);
}

string dessin::toStringPoints(void)
{
    string s;
    int nb;
    point *t;
    t = this->Lire(nb);
    if (t != NULL)
    {
        s = toStringPoints(t,nb);
        delete[] t;
    }
    return (s);
}

void dessin::ChercherEnglobant(
        point &min,
        point &max)
{
    int nb;
    point *t;
    t = this->Lire(nb);
    if (t != NULL)
    {
        Englobant(t,nb,min,max);
        delete[] t;
    }
}

int dessin::LireNbPts(void)
{
    point *t;
    int nb;
    t = this->Lire(nb);
    delete[] t;
    return (nb);
}

void dessin::Englobant(
        point &min,
        point &max)
{
    point minl,maxl;
    double vmin,vmax;
    double xmax,ymax;

    this->ChercherEnglobant(minl,maxl);

    vmin = minl.LireX();
    vmax = maxl.LireX();
    if (vmin<0) vmin=-vmin;
    if (vmax<0) vmax=-vmax;
    if (vmin>vmax) xmax = vmin;
    else xmax=vmax;

    vmin = minl.LireY();
    vmax = maxl.LireY();
    if (vmin<0) vmin=-vmin;
    if (vmax<0) vmax=-vmax;
    if (vmin>vmax) ymax = vmin;
    else ymax=vmax;

    min.EcrireX(-xmax);
    max.EcrireX(xmax);
    min.EcrireY(-ymax);
    max.EcrireY(ymax);
}

bool dessin::Generer(void)
{
    bool ok;
    ok = this->GenererSansTransformation();
    if (ok == true)
    {
        this->Translater(this->_tx,this->_ty);
        this->Dilater(this->_ex,this->_ey);
    }
    return (ok);
}

string dessin::toString(
        const int mode)
{
    char nbpts[30];
    char transformation[256];
    string s;

    sprintf (nbpts,
             "%d",
             this->LireNbPts());
    sprintf (transformation,
             "Echelle (x-> %.2f; y-> %.2f); Translation (x-> %.2f; y-> %.2f)",
             this->LireEx(),
             this->LireEy(),
             this->LireTx(),
             this->LireTy());

    s = "";
    s += this->LireEntete();
    s+= " -> ";
    s+= "Nombre de points ";
    s+=nbpts;
    if ((mode==1)||(mode == 2))
    {
        s+=" : ";
        s+=this->LireCaracteristiques();
        s+=" : ";
        s+=transformation;
    }
    if (mode == 2)
    {
        s+="\n";
        s+="Coordonnees des points:";
        s+="\n";
        s+=this->toStringPoints();
    }
    return (s);
}

point *dessin::Lire(
        vector<dessin *> *vd,
        int &nb)
{
    bool ok;
    int i;
    int j;
    int n;
    int *nbl;
    point **tpl;
    point* t;
    int nbdessin;

    nbdessin = vd->size();

    tpl = new point*[nbdessin+1];
    nbl = new int[nbdessin+1];

    ok = true;
    for (i=0;i<nbdessin;i++)
    {
        tpl[i] = vd->at(i)->Lire(nbl[i]);
        if (tpl[i] == NULL) ok=false;
    }

    j=0;
    t=NULL;
    if (ok == true)
    {
        n = 0;
        for (i=0;i<nbdessin;i++) n+= nbl[i];

        t = new point[n+1];
        if (t!=NULL)
        {
            for (i=0;i<nbdessin-1;i++)
                Ajouter(tpl[i],nbl[i]-1,t,j);
            Ajouter(tpl[i],nbl[i],t,j);
        }
    }

    nb = j;
    for (i=0;i<nbdessin;i++)
        if (tpl[i] != NULL) delete[] tpl[i];

    delete[] tpl;
    delete[] nbl;

    return (t);
}

void dessin::Ajouter(
        point *ts,
        const int nbs,
        point *td,
        int &nbd)
{
    int i;
    int j;

    j = nbd;
    for (i=0;i<nbs;i++)
    {
        td[j].Copier(&(ts[i]));
        j++;
    }
    nbd = j;
}

string dessin::toStringPoints(
        point *t,
        const int nb)
{
    string s;
    char indice[10];
    char X[10];
    char Y[10];

    s = "";
    int i;
    for (i=0;i<nb;i++)
    {
        sprintf (indice,"%06d",i);
        sprintf (X,"%.2f",t[i].LireX());
        sprintf (Y,"%.2f",t[i].LireY());
        s+=
                string("Point ")+
                indice+
                " -> ";
        s+=
                string("X = ")+
                X+
                " ; "+
                "Y = "+
                Y+
                "\n";
    }
    return (s);
}

void dessin::Englobant(
        point *t,
        const int nb,
        point &min,
        point &max)
{
    double	minx,maxx,miny,maxy;
    int	i;

    minx= miny = 1E+100;
    maxx= maxy = -1E+100;

    for (i=0;i<nb;i++)
    {
        if (t[i].LireX() < minx) minx = t[i].LireX();
        if (t[i].LireY() < miny) miny = t[i].LireY();
        if (t[i].LireX() > maxx) maxx = t[i].LireX();
        if (t[i].LireY() > maxy) maxy = t[i].LireY();
    }
    min.EcrireX(minx);
    max.EcrireX(maxx);
    min.EcrireY(miny);
    max.EcrireY(maxy);
}
