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

//********  Ajout d'un repère ********
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

// min<=n<=max
static int TirerAuSort(
        const int min,
        const int max)
{
    int n;
    n =
            min+
            (rand()%(max-min+1));
    return (n);
}

/*
// min<=f<=max
static double TirerAuSort(
        const double min,
        const double max)
{
    double f;
    f =
            (rand()/(double)RAND_MAX)*
            (max-min) + min;

    return (f);
}

static QColor TirerCouleurAuSort(void)
{
    int r,v,b;
    r = TirerAuSort(0,255);
    v = TirerAuSort(0,255);
    b = TirerAuSort(0,255);

    QColor c(r,v,b);
    return c;
}
*/
static void Reafficher(
        gesdessin *gd)
{
    gd->InitialiserSliders();
    gd->Rafraichir();
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


    switch(index)
    {
    case 1 :
        fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
        fc->recupParamsCosSin(np, vp);
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
        fc->recupParamsCommuns(ex, ey, tx, ty, ct, et);
        fc->recupParamsCosSin(np, vp);
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

static void ajouter(
        const int t,
        gesdessin *gd,
        fcreation *fc,
        const int index)
{
   // if (t == 1)
        //AjouterMaths(gd);
    if (t == 2)
        AjouterTrigos(gd,fc,index);
    //if (t == 3)
        //AjouterFormes(gd);
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

    //Ajout du Logo pour la fenetre
    this->_fc->setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/Logo_Eval.jpg"));

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


    //Ajouter le repère.
    AjouterRepere(2, this->_fTrigo);
    AjouterRepere(1, this->_fMath);
    AjouterRepere(3, this->_fGeo);

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

void ctrlcreation::creerTrigos(const int index)
{
    creerTraces(2, this->_fTrigo, this->_fc, this->_selectionTrigo, index);
}
