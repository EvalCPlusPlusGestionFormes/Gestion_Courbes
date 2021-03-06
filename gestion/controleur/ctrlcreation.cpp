#include "ctrlcreation.h"
#include <QCoreApplication>

#define COLFOND Qt::white
#define NOMTRIGOS "COURBES TRIGONOMETRIQUES"
#define NOMMATHS  "COURBES MATHEMATIQUES"
#define NOMGEO "FORMES GEOMETRIQUES"
#define LARGEUR 300
#define HAUTEUR 300

#define DEMILARGEUR LARGEUR/2
#define DEMIHAUTEUR HAUTEUR/2

// ---------------------------------------
// La valeur en X du repere doit etre >=PI
#define REPERETRIGOX (double)M_PI
#define REPERETRIGOY (double)1

// -> REPERE EN X = 1/4 de la demi largeur
#define ECHELLETRIGOX  ((double)DEMILARGEUR/(double)4)/(REPERETRIGOX)
// -> REPERE EN Y = 1/4 de la demi hauteur
#define ECHELLETRIGOY  ((double)DEMIHAUTEUR/(double)4)/(REPERETRIGOY)

// Données pour les tracés mathématiques
// -------------------------------------
#define REPEREMATHX (double)1
#define REPEREMATHY (double)1

// -> REPERE EN X = 1/4 de la demi largeur
#define ECHELLEMATHX  ((double)DEMILARGEUR/(double)4)/(REPEREMATHX)
// -> REPERE EN Y = 1/4 de la demi hauteur
#define ECHELLEMATHY  ((double)DEMIHAUTEUR/(double)4)/(REPEREMATHY)

// Données pour les formes géométriques
// ------------------------------------
#define REPEREFORMEX (double)25
#define REPEREFORMEY (double)50

#define PERIODEMIN (int)1
// -> doit permettre d'occuper 3/4 de la  demi largeur
#define PERIODEMAX int ((((double)DEMILARGEUR*(double)3/(double)4))/((double)M_PI*ECHELLETRIGOX))
// -> 2 fois le repere en Y
#define TRANSLATIONTRIGOYMAX (double)1

//*******************************************
//      METHODES STATICS
//*******************************************

//********  Position fenetre ********
typedef enum{
    DROIT,
    GAUCHE,
    SANSX
}EPOSITION_X;

typedef enum{
    HAUT,
    BAS,
    SANSY
}EPOSITION_Y;

static void Positionner(
        QWidget *f,
        const int x,
        const int y)
{
    f->move(x,y);
}

//********  Ajout d'un rep�rere ********
static void AjouterRepere(
        const int t,
        gesdessin *gd)

{
    repere *r;
    double dimx,dimy;
    double echx,echy;
    bool ok;

    ok = false;
    if (t == 1)
    {
        ok = true;
        dimx = REPEREMATHX;
        dimy = REPEREMATHY;
        echx = ECHELLEMATHX;
        echy = ECHELLEMATHY;
    }
    if (t == 2)
    {
        ok = true;
        dimx = REPERETRIGOX;
        dimy = REPERETRIGOY;
        echx = ECHELLETRIGOX;
        echy = ECHELLETRIGOY;
    }
    if (t == 3)
    {
        ok = true;
        dimx = REPEREFORMEX;
        dimy = REPEREFORMEY;
        echx = 1;
        echy = 1;
    }
    if (ok == true)
    {
        r = gd->AjouterRepere();
        r->EcrireDimensions(dimx,dimy);
        gd->Ecrire(r,2,Qt::black,echx,echy);
    }
}

static void Reafficher(
        gesdessin *gd)
{
    gd->InitialiserSliders();
    gd->Rafraichir();
}

static void EffacerSelection(
            gesdessin *gd,
            int &sel)
    {
        if (sel != -1)
        {
            gd->Colorer(sel);
            gd->EcrireEpaisseur(sel);
            sel = -1;
        }
    }

static void EffacerSelection(gesdessin *gd,
                             int &sel,
                             const QColor color,
                             const int et)
{
    if (sel != -1)
    {
        gd->Colorer(sel, color);
        gd->EcrireEpaisseur(sel, et);
        sel = -1;
    }
}

static void recupParamCommunsSelection(const int sel,gesdessin *gd,
                                       double &ex, double &ey,
                                       double &tx, double &ty,
                                       QColor &ct, int &et)
{
        dessin *des;

        des = gd->Lire(sel,et, ct);
        ex = des->LireEx();
        ey = des->LireEy();
        tx = des->LireTx();
        ty = des->LireTy();
}

static void recupParamTrigoSelection(const int sel, gesdessin *gd,
                                     int &np, double &vp)
{
    dessin *des;
    trigo *trig;

    des = gd->Lire(sel);
    trig = (trigo*)des;

    np = trig->LireNbPeriode();
    vp = trig->LirePas();

}

static void recupParamMathSelection(const int sel, gesdessin *gd, double &xmi,
                                     double &xma, double &vp)
{
    dessin *des;
    maths *math;

    des = gd->Lire(sel);
    math = (maths*)des;

    xmi= math->LireBorneInf();
    xma= math->LireBorneSup();
    vp= math->LirePas();
}

static void recupParamGeoSelection(const int sel, gesdessin *gd,
                                   double &LarRay, double &HautPas)
{
    dessin *des;
    cercle *cer;
    rectangle *rect;
    int type;

    des = gd->Lire(sel);
    type = des->LireType();

    if(type == 1000)
    {
        cer = (cercle*)des;
        LarRay = cer->LireRayon();
        HautPas = cer->LirePas();
    }
    if(type == 2000)
    {
        rect = (rectangle*)des;
        rect->LireDimensions(LarRay, HautPas);
    }
}

static void recupParamSelection(gesdessin *gd,
                             fcreation *fc,
                             int sel)
{
    int type;
    double vp;
    //Communs
    double ex, ey, tx, ty;
    int et;
    QColor ct;
    //Trigo
    int np;
    //Maths
    double xmi, xma;
    //Geo
    double larRay, hautPas;

    //R�cup�ration de l'objet et du type
    dessin *des = gd->Lire(sel);
    type= des->LireType();

    if(type!=3000)
    {
        recupParamCommunsSelection(sel, gd, ex, ey, tx, ty, ct, et);
        fc->setParamCommuns(ex, ey, tx, ty, ct, et);
    }
    else
    {
        int index = fc->verifChecked();
        fc->initialiserTab(index);
    }

    if((type==100)||(type==200))
    {
        recupParamTrigoSelection(sel, gd, np, vp);
        fc->setParamTrigo(np, vp);
    }
    if((type==20)||(type==30)||(type==50)||(type==60))
    {
        recupParamMathSelection(sel, gd, xmi, xma, vp);
        fc->setParamMath(xmi, xma, vp);
    }
    if ((type==1000) || (type==2000))
    {
        recupParamGeoSelection(sel, gd, larRay, hautPas);
        fc->setParamGeo(larRay, hautPas);
    }

}

static void AfficherSelection(
            gesdessin *gd,
            fcreation *fc,
            int &sel,
            int l)
    {
        if (l!=-1)
        {
                EffacerSelection(gd, sel);
                sel = l;
                gd->EcrireEpaisseur(sel,3);

                if(l!=0)
                {
                    gd->Colorer(sel,Qt::red);
                }
                else
                    gd->EcrireEpaisseur(0);

                recupParamSelection(gd, fc, sel);
                Reafficher(gd);
        }
    }
static void toString(
        gesdessin *gd,
        string *&sm,
        string *&sr,
        int &nb)
{
    int i;

    nb = gd->LireNbDessins();
    sr = new string[nb+1];
    sm = new string[nb+1];
    for (i=0;i<nb;i++)
    {
        sm[i] = gd->toStringUnDessin(i,0);
        sr[i] = gd->toStringUnDessin(i,1);
    }
}

static void AfficherListe(
        const int t,
        gesdessin *gd,
        fcreation *fc,
        const int sel)
{
    string *sm;
    string *sr;
    int nb;

    toString(gd,sm,sr,nb);
    fc->Afficher(t,sm,sr,nb);
    fc->Selectionner(t,sel);
    delete[] sm;
    delete[] sr;
}

static void EffacerListe(
            const int t,
            fcreation *fc,
            const int index)
    {
        fc->Effacer(t);
        fc->Selectionner(t,index);
    }

static void AjouterMaths(
           gesdessin *gd,
           fcreation *fc,
           const int index)
   {
       puissance2 *dp;
       racinecarre *dr;
       fonction *df;
       exponentiel *de;
       double ex, ey, tx, ty, xmi, xma, vp;
       QColor ct;
       int et;

       fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
       fc->recupParamsMaths(xmi, xma, vp);

       switch(index)
       {
       case 3:
           dp = gd->AjouterPuissance2();
           //Xmin
           dp->EcrireBorneInf(xmi);
           //Xmax
           dp->EcrireBorneSup(xma);
           //Valeur du pas
           dp->EcrirePas(vp);
           gd->Ecrire(
                       dp,
                       //Epaisseur du trac�
                       et,
                       //Couleur
                       ct,
                       //Echelle en x
                       ex,
                       //Echelle en y
                       ey,
                       //Translation en x
                       tx,
                       //Translation en y
                       ty
                       );
           break;

       case 4:
           dr = gd->AjouterRacineCarre();
           dr->EcrireBorneInf(xmi);
           dr->EcrireBorneSup(xma);
           dr->EcrirePas(vp);
           gd->Ecrire(
                       dr,
                       //Epaisseur du trac�
                       et,
                       //Couleur
                       ct,
                       //Echelle en x
                       ex,
                       //Echelle en y
                       ey,
                       //Translation en x
                       tx,
                       //Translation en y
                       ty
                       );
           break;

       case 5 :
           df = gd->AjouterFonction();
           df->EcrireBorneInf(xmi);
           df->EcrireBorneSup(xma);
           df->EcrirePas(vp);
           gd->Ecrire(
                       df,
                       //Epaisseur du trac�
                       et,
                       //Couleur
                       ct,
                       //Echelle en x
                       ex,
                       //Echelle en y
                       ey,
                       //Translation en x
                       tx,
                       //Translation en y
                       ty
                       );
           break;

       case 6:
           de = gd->AjouterExponentiel();
           de->EcrireBorneInf(xmi);
           de->EcrireBorneSup(xma);
           de->EcrirePas(vp);
           gd->Ecrire(
                       de,
                       //Epaisseur du trac�
                       et,
                       //Couleur
                       ct,
                       //Echelle en x
                       ex,
                       //Echelle en y
                       ey,
                       //Translation en x
                       tx,
                       //Translation en y
                       ty
                       );
           break;       
       }
}

static void AjouterTrigos(
        gesdessin *gd,
        fcreation *fc,
        const int index)
{
    cosinus *dc;
    sinus *ds;
    double ex, ey, tx, ty, vp;
    QColor ct;
    int et, np;

    fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);

    switch(index)
    {
    case 1 : 
        fc->recupParamsTrigo(np, vp);
        dc = gd->AjouterCosinus();

        dc->EcrireNbPeriode(np);
        dc->EcrirePas(vp);
        gd->Ecrire(
                    dc,
                    //Epaisseur
                    et,
                    //Couleur
                    ct,
                    //Echelle en x
                    ex,
                    //Echelle en y
                    ey,
                    //Translation en x
                    tx,
                    //Translation en y
                    ty
                    );
        break;

    case 2:
        fc->recupParamsTrigo(np, vp);
        ds = gd->AjouterSinus();

        ds->EcrireNbPeriode(np);
        ds->EcrirePas(vp);
        gd->Ecrire(
                    ds,
                    et,
                    ct,
                    ex,
                    ey,
                    tx,
                    ty
                    );
        break;
    }
}

static void AjouterGeo(
        gesdessin *gd,
        fcreation *fc,
        const int index)
{
    cercle *dc;
    rectangle *dr;
    double ex, ey, tx, ty, LarRay, HautPas;
    QColor ct;
    int et;

    fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
    fc->recupParamsGeo(LarRay, HautPas);

    switch(index)
    {
    case 7:
        dc = gd->AjouterCercle();
        dc->EcrireRayon(LarRay);
        dc->EcrirePas(HautPas);
        gd->Ecrire(
                    dc,
                    //Epaisseur
                    et,
                    //Couleur
                    ct,
                    //Echelle en x
                    ex,
                    //Echelle en y
                    ey,
                    //Translation en x
                    tx,
                    //Translation en y
                    ty
                    );
        break;

    case 8:
        dr = gd->AjouterRectangle();
        dr->EcrireDimensions(LarRay, HautPas);
        gd->Ecrire(
                    dr,
                    //Epaisseur
                    et,
                    //Couleur
                    ct,
                    //Echelle en x
                    ex,
                    //Echelle en y
                    ey,
                    //Translation en x
                    tx,
                    //Translation en y
                    ty
                    );
        break;
    }
}

static void modifierTrigos(gesdessin *gd, fcreation *fc, int &sel)
{
    dessin *des;
    trigo *trig;
    double ex, ey, tx, ty, vp;
    QColor ct;
    int et, np;

    des = gd->Lire(sel);
    trig = (trigo*)des;

    fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
    fc->recupParamsTrigo(np, vp);


    trig->EcrireNbPeriode(np);
    trig->EcrirePas(vp);
    gd->Ecrire(
                trig,
                //Epaisseur
                et,
                //Couleur
                ct,
                //Echelle en x
                ex,
                //Echelle en y
                ey,
                //Translation en x
                tx,
                //Translation en y
                ty
                );

    EffacerSelection(gd, sel, ct, et);
}

static void modifierMaths(gesdessin *gd, fcreation *fc, int &sel)
{
    dessin *des;
    maths *math;
    double ex, ey, tx, ty, xmi, xma, vp;
    QColor ct;
    int et;

    des = gd->Lire(sel);
    math = (maths*)des;

    fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
    fc->recupParamsMaths(xmi, xma, vp);

    math->EcrireBorneInf(xmi);
    math->EcrireBorneSup(xma);
    math->EcrirePas(vp);
    gd->Ecrire(
                math,
                //Epaisseur
                et,
                //Couleur
                ct,
                //Echelle en x
                ex,
                //Echelle en y
                ey,
                //Translation en x
                tx,
                //Translation en y
                ty
                );
    EffacerSelection(gd, sel, ct, et);
}

static void modifierGeo(gesdessin *gd, fcreation *fc, int &sel)
{
    int type;
    dessin *des;
    cercle *cer;
    rectangle *rect;
    double ex, ey, tx, ty, LarRay, HautPas;
    QColor ct;
    int et;

    des = gd->Lire(sel);
    type = des->LireType();

    fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
    fc->recupParamsGeo(LarRay, HautPas);

    if (type==1000)
    {
        cer = (cercle*)des;
        cer->EcrireRayon(LarRay);
        cer->EcrirePas(HautPas);
        gd->Ecrire(
                    cer,
                    //Epaisseur
                    et,
                    //Couleur
                    ct,
                    //Echelle en x
                    ex,
                    //Echelle en y
                    ey,
                    //Translation en x
                    tx,
                    //Translation en y
                    ty
                    );
    }

    if (type==2000)
    {
        rect = (rectangle*)des;
        rect->EcrireDimensions(LarRay, HautPas);
        gd->Ecrire(
                    rect,
                    //Epaisseur
                    et,
                    //Couleur
                    ct,
                    //Echelle en x
                    ex,
                    //Echelle en y
                    ey,
                    //Translation en x
                    tx,
                    //Translation en y
                    ty
                    );
    }
    EffacerSelection(gd, sel, ct, et);
}

static void ajouter(
        const int t,
        gesdessin *gd,
        fcreation *fc,
        const int index)
{
    if (t == 1)
        AjouterMaths(gd, fc, index);
    if (t == 2)
        AjouterTrigos(gd,fc,index);
    if (t == 3)
        AjouterGeo(gd,fc,index);
}

static void modifier(const int t, gesdessin *gd,fcreation *fc, int &sel)
{
    if (t == 1)
        modifierMaths(gd, fc, sel);
    if (t == 2)
        modifierTrigos(gd,fc, sel);
    if (t == 3)
        modifierGeo(gd,fc, sel);
}

static void creerTraces(
        const int t,
        gesdessin *gd,
        fcreation *fc,
        const int sel,
        const int index)
{
    ajouter(t,gd,fc,index);
    AfficherListe(t,gd,fc,sel);
    Reafficher(gd);
}

static void modifierTraces(const int t, gesdessin *gd, fcreation *fc, int sel)
{
    modifier(t, gd, fc, sel);
    AfficherListe(t, gd, fc, sel);
    Reafficher(gd);
}

static bool supprimerTrace(
            const int t,
            gesdessin *gd,
            fcreation *fc,
            int &sel)
    {
        char q[256];
        int isupp;
        bool ok;

        sprintf (q,
                 "Voulez vous detruire la courbe [%s]",
                 gd->toStringUnDessin(sel).data()
                 );
        ok = fc->confirmer(q);
        if (ok==true)
        {
            isupp = sel;
            EffacerSelection(gd,sel);
            gd->Supprimer(isupp);
            AfficherListe(t,gd,fc,sel);
            Reafficher(gd);
        }
        else
            EffacerSelection(gd,sel);
            AfficherListe(t,gd,fc,sel);
            Reafficher(gd);

        return (ok);
    }

static void DetruireTraces(
            const int t,
            gesdessin *gd,
            fcreation *fc,
            int &sel)
    {
        EffacerSelection(gd,sel);
        gd->Supprimer();
        EffacerListe(t,fc,sel);
        AjouterRepere(t,gd);
        AfficherListe(t,gd,fc,sel);
        Reafficher(gd);
    }

//*******************************************
//           METHODE INITIALISER
//*******************************************
void ctrlcreation::initialiser(void)
{
    //Création d'une fenetre principale avec le controleur en paramètre (this)
    this->_fc = new fcreation(this);
    this->_fTrigo = new gesdessin(LARGEUR,HAUTEUR,COLFOND);
    this->_fMath = new gesdessin(LARGEUR,HAUTEUR,COLFOND);
    this->_fGeo = new gesdessin(LARGEUR,HAUTEUR,COLFOND);

    //Postion de la fenetre principale.
    Positionner(this->_fc,0,0);

    //Paramétrage des fenetres graphiques
    this->_fTrigo->EcrireNom(NOMTRIGOS);
    this->_fMath->EcrireNom(NOMMATHS);
    this->_fGeo->EcrireNom(NOMGEO);

    //Masque toutes les fenetres graphiques
    this->cacherToutes();
    //Affichage de la fenetre principale.
    this->_fc->show();
    //Affiche la fenetre graphique du premier onglet.
    this->_fTrigo->AfficherFenetre();
    //Positionne les fenetres graphiques par defaut
    this->positionDefaut();
    //Empeche de fermer la fenetre graphique.
    this->_fTrigo->EcrireTraitementClose(1);


    //Ajouter le rep�rere.
    AjouterRepere(2, this->_fTrigo);
    AfficherListe(2, _fTrigo,_fc,_selectionTrigo);
    AjouterRepere(1, this->_fMath);
    AfficherListe(1, _fMath,_fc,_selectionMath);
    AjouterRepere(3, this->_fGeo);

    AfficherListe(2,this->_fTrigo,this->_fc,1);
    AfficherListe(1,this->_fMath,this->_fc,3);
    AfficherListe(3,this->_fGeo,this->_fc,5);


    //Affiche le repère.
    this->_fTrigo->ChoisirModeAffichage(0);
    this->_fMath->ChoisirModeAffichage(0);
    this->_fGeo->ChoisirModeAffichage(0);

    this->_selectionTrigo = -1;
    this->_selectionMath = -1;
    this->_selectionGeo = -1;
}


//*******************************************
//              CONSTRUCTEUR
//*******************************************
ctrlcreation::ctrlcreation(void)
{
    this->initialiser();
}

//*******************************************
//              DESTRUCTEUR
//*******************************************
ctrlcreation::~ctrlcreation()
{
    delete this->_fc;
    delete this->_fTrigo;
    delete this->_fMath;
    delete this->_fGeo;
}

//*******************************************
//           METHODES PRIVATES
//*******************************************
void ctrlcreation::cacherToutes(void)
{
    this->_fTrigo->MasquerFenetre();
    this->_fMath->MasquerFenetre();
    this->_fGeo->MasquerFenetre();
}

void ctrlcreation::positionDefaut(void)
{
    this->_fTrigo->Positionner(this->_fc->frameGeometry().right()-8,
                               this->_fc->frameGeometry().top());
    this->_fMath->Positionner(this->_fc->frameGeometry().right()-8,
                               this->_fc->frameGeometry().top());
    this->_fGeo->Positionner(this->_fc->frameGeometry().right()-8,
                                this->_fc->frameGeometry().top());
}

//*******************************************
//           METHODES PUBLICS
//*******************************************
void ctrlcreation::afficherFenetreGraphique(const int index)
{
    switch(index){
    case 0:
            this->cacherToutes();
            this->_fTrigo->AfficherFenetre();
            this->_fTrigo->EcrireTraitementClose(1);
            this->positionDefaut();
            break;
    case 1:
            this->cacherToutes();
            this->_fMath->AfficherFenetre();
            this->_fMath->EcrireTraitementClose(1);
            this->positionDefaut();
            break;
    case 2:
            this->cacherToutes();
            this->_fGeo->AfficherFenetre();
            this->_fGeo->EcrireTraitementClose(1);
            this->positionDefaut();
            break;
    }
}

void ctrlcreation::modifLigne(void)
{
    int index = this->_fc->verifChecked();

    if((index>=1) && (index<=2) && (_selectionTrigo != 0) && (_selectionTrigo != -1))
        modifierTraces(2,this->_fTrigo,this->_fc,this->_selectionTrigo);
    else if((index>=3) && (index<=6) && (_selectionMath != 0) && (_selectionMath != -1))
        modifierTraces(1,this->_fMath,this->_fc,this->_selectionMath);
    else if((index>=7) && (index<=8) && (_selectionGeo !=0) && (_selectionGeo != -1))
        modifierTraces(3,this->_fGeo,this->_fc,this->_selectionGeo);
    else
        this->_fc->informer("Le repere ne peut etre modifie");

}

void ctrlcreation::creerForme(void)
{
    int index = this->_fc->verifChecked();

    if((index>=1) && (index<=2))
        creerTraces(2, this->_fTrigo, this->_fc, this->_selectionTrigo, index);
    if((index>=3) && (index<=6))
        creerTraces(1, this->_fMath, this->_fc, this->_selectionMath, index);
    if((index>=7) && (index<=8))
        creerTraces(3, this->_fGeo, this->_fc, this->_selectionGeo, index);
}

void ctrlcreation::detruireFormes(void)
{
    int index = this->_fc->verifChecked();
    if((index>=1) && (index<=2))
        if (this->_fc->confirmer("Voulez vous vider la liste TRIGO ?"))
            DetruireTraces(2,this->_fTrigo,this->_fc,this->_selectionTrigo);
    if((index>=3) && (index<=6))
        if (this->_fc->confirmer("Voulez vous vider la liste MATHS ?"))
            DetruireTraces(1,this->_fMath,this->_fc,this->_selectionMath);
    if((index>=7) && (index<=8))
        if (this->_fc->confirmer("Voulez vous vider la liste GEO ?"))
            DetruireTraces(3,this->_fGeo,this->_fc,this->_selectionGeo);

}

void ctrlcreation::supprimerForme(void)
{
    dessin *des;
    int index = this->_fc->verifChecked();

    if((index>=1) && (index<=2))
    {
        if (this->_selectionTrigo== -1)
                this->_fc->informer("Aucune forme n'est selectionnee");
        if (this->_selectionTrigo== 0)
                this->_fc->informer("Le repere ne peut etre supprime");
        else
        {
            des = this->_fTrigo->Lire(this->_selectionTrigo);
            if (des != NULL)
                supprimerTrace(2,this->_fTrigo,this->_fc,this->_selectionTrigo);
        }
    }

    if((index>=3) && (index<=6))
    {
        if (this->_selectionMath== -1)
                this->_fc->informer("Aucune forme n'est selectionnee");
        if (this->_selectionMath== 0)
                this->_fc->informer("Le repere ne peut etre supprime");
        else
        {
            des = this->_fMath->Lire(this->_selectionMath);
            if (des != NULL)
                supprimerTrace(1,this->_fMath,this->_fc,this->_selectionMath);
        }
    }

    if((index>=7) && (index<=8))
    {
        if (this->_selectionGeo== -1)
                this->_fc->informer("Aucune forme n'est selectionnee");
        if (this->_selectionGeo== 0)
                this->_fc->informer("Le repere ne peut etre supprime");
        else
        {
            des = this->_fGeo->Lire(this->_selectionGeo);
            if (des != NULL)
                supprimerTrace(3,this->_fGeo,this->_fc,this->_selectionGeo);
        }
    }

}

void ctrlcreation::afficherSelectionLigne(const int l)
{
    int index = this->_fc->verifChecked();
    if((index>=1) && (index<=2))
        AfficherSelection(this->_fTrigo,this->_fc,this->_selectionTrigo,l);
    if((index>=3) && (index<=6))
        AfficherSelection(this->_fMath,this->_fc,this->_selectionMath,l);
    if((index>=7) && (index<=8))
        AfficherSelection(this->_fGeo,this->_fc,this->_selectionGeo,l);
}
