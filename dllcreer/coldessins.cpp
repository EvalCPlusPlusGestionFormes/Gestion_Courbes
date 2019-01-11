#include "coldessins.h"

coldessins::coldessins(string nom)
{
    this->EcrireNom(nom);
    this->_vdessins = new VDESSINS();
}

coldessins::~coldessins()
{
    this->Supprimer();
    delete (this->_vdessins);
}

bool coldessins::TesterExistence(const int i)
{
    bool ok;
    ok = (i>=0)&&(i<this->LireNbDessins());
    return (ok);
}

int coldessins::Chercher(const dessin *d)
{
    int i;
    int trouve;
    dessin *dtmp;

    trouve = -1;
    for (
         i=0;
         (trouve == -1) && (i<this->LireNbDessins());
         i++)
    {
        dtmp = this->LireDessin(i);
        if (dtmp != NULL)
        {
            if (dtmp == d)
                trouve = i;
        }
    }
    return (trouve);
}

dessin *coldessins::LireDessin(const int i)
{
    dessin *d;
    if (this->TesterExistence(i)==false)
        d = NULL;
    else
        d = this->_vdessins->at(i);
    return (d);
}

bool coldessins::SupprimerDonnees(const int i)
{
    dessin *d;

    d = this->LireDessin(i);
    if (d == NULL) return (false);
    delete d;
    return (true);
}

bool coldessins::Supprimer(const int i)
{
    bool ok;

    ok = this->SupprimerDonnees(i);
    if (ok == true)
        this->_vdessins->erase(this->_vdessins->begin()+i);

    return (ok);
}

bool coldessins::Supprimer(const dessin *d)
{
    int i;

    i = this->Chercher(d);
    if (i == -1) return (false);
    return (this->Supprimer(i));
}

void coldessins::Supprimer(void)
{
    int i;
    int nbd;

    nbd = this->LireNbDessins();
    for (i=0;i<nbd;i++)
        this->SupprimerDonnees(i);
    this->_vdessins->clear();
}

string coldessins::toString(const int mode)
{
    string s;
    int i;
    dessin *d;

    s = "";
    s += "*** Collectionneur: "+this->LireNom();
    s += "\n";
    for(i=0;i<this->LireNbDessins();i++)
    {
        d = this->LireDessin(i);
        if (d != NULL)
            s += d->toString(mode)+"\n";
    }
    return (s);
}

bool coldessins::Generer(void)
{
    int i;
    dessin *d;
    bool ok;

    ok = true;
    for(
        i=0;
        (ok == true) && (i<this->LireNbDessins());
        i++)
    {
        d = this->LireDessin(i);
        if (d != NULL)
            ok = d->Generer();
    }
    return (ok);
}

void coldessins::Englobant(
        point &min,
        point &max)
{
    int nb,i,j;
    dessin *d;
    point *tsp;
    point mind,maxd;

    nb = this->LireNbDessins();
    tsp = new point[4*nb];
    j=0;
    for (i=0;i<nb;i++)
    {
        d = this->LireDessin(i);
        if (d!=NULL)
        {
            d->Englobant(mind,maxd);
        }
        tsp[j].Copier(&mind);
        j++;
        tsp[j].EcrireX(maxd.LireX());
        tsp[j].EcrireY(mind.LireY());
        j++;
        tsp[j].Copier(&maxd);
        j++;
        tsp[j].EcrireX(mind.LireX());
        tsp[j].EcrireY(maxd.LireY());
        j++;
    }
    dessin::Englobant(tsp,j,min,max);
    delete[] tsp;
}
