#include "testerdllcreer.h"

void TesterDllcreer::TesterCreation(void)
{
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

    coldessins *c;

    repere *r;
    racinecarre *dr;
    puissance2 *dp;
    fonction *df;
    exponentiel *de;
    cosinus *dc;
    sinus *ds;
    cercle *dfc;
    demicercle *dfdc;
    ligne *dl;
    rectangle *dfr;

    int modeaffichage;

    modeaffichage = 1;

    c = new coldessins();
    c->EcrireNom("TEST COLLECTION");

    c->Ajouter(r);
    r->EcrireDimensions(10,10);

    c->Ajouter(dr);
    dr->EcrireBorneInf(0);
    dr->EcrireBorneSup(4);
    dr->EcrirePas(0.1);
    ((dessinp *)dr)->EcrireEx(2);
    ((dessinp *)dr)->EcrireTx(10);
    ((dessinp *)dr)->EcrireEy(2);
    ((dessinp *)dr)->EcrireTy(-10);

    c->Ajouter(dp);
    dp->EcrireBorneInf(-2);
    dp->EcrireBorneSup(4);
    dp->EcrirePas(0.1);

    c->Ajouter(df);
    df->EcrireBorneInf(-2);
    df->EcrireBorneSup(10);
    df->EcrirePas(1);

    c->Ajouter(de);
    de->EcrireBorneInf(0);
    de->EcrireBorneSup(2);
    de->EcrirePas(0.2);

    c->Ajouter(dc);
    dc->EcrireNbPeriode(3);
    dc->EcrirePas(0.1);


    c->Ajouter(ds);
    ds->EcrireNbPeriode(2);
    ds->EcrirePas(0.5);

    c->Ajouter(dfc);
    dfc->EcrireRayon(3);
    dfc->EcrirePas(0.1);

    c->Ajouter(dfdc);
    dfdc->EcrireRayon(3);
    dfdc->EcrirePas(0.1);

    c->Ajouter(dl);
    dl->EcrireCoordonnees(-2,-2,2,2);

    c->Ajouter(dfr);
    dfr->EcrireDimensions(12,20);

    if (c->Generer()==false)
        cout << "Erreur de generation des traces" << endl;

    cout << c->toString(modeaffichage) << endl;
    delete c;
}
