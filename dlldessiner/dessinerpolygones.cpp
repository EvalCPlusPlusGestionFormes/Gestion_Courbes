#include "dessinerpolygones.h"

static int HAUTEUR_DEF=500;
static int LARGEUR_DEF=500;
static QBrush FOND_DEF =Qt::lightGray;

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


static void PositionnerFenetres(
        dessinerpolygones *d,
        dessinerpolygones *s,
        EPOSITION_X posx,
        EPOSITION_Y posy)
{
    int x,y;
    int ls,hs;
    int ld,hd;

    s->LirePosition(x,y);
    s->LireDimension(ls,hs);
    d->LireDimension(ld,hd);

    switch (posx)
    {
    case GAUCHE:
        x = x-ls-ld-10;
    case DROIT:
        x = x+ls+10;
        break;
    default:
        break;
    }

    switch (posy)
    {
    case HAUT:
        y = y-hs-hd-30;
        break;
    case BAS:
        y = y+hs+30;
        break;
    default:
        break;
    }

    d->EcrirePosition(x,y);
}

static EPOSITION_X DecoderPosx(const int x)
{
    EPOSITION_X px;

    switch (x)
    {
    case 1:
        px = DROIT;
        break;
    case 2:
        px = GAUCHE;
        break;
    default:
        px=SANSX;
        break;
    }
    return (px);
}

static EPOSITION_Y DecoderPosy(const int y)
{
    EPOSITION_Y py;

    switch (y)
    {
    case 1:
        py = BAS;
        break;
    case 2:
        py = HAUT;
        break;
    default:
        py=SANSY;
        break;
    }
    return (py);
}


void dessinerpolygones::Positionner(
        dessinerpolygones *d,
        const int px,
        const int py)
{
    PositionnerFenetres(
                this,
                d,
                DecoderPosx(px),
                DecoderPosy(py));
}


void dessinerpolygones::Initialiser(
        const int hauteur,
        const int largeur,
        const QBrush fond)
{
    this->EcrireEx(1);
    this->EcrireEy(1);
    this->EcrireTx(0);
    this->EcrireTy(0);

    this->_modeaffichage=-1;
    this->EcrireEtatEffacement(true);

    this->_fd =new FDessinertrt(this);
    this->_fd->CreerScene(hauteur,largeur,fond,true);
    this->_vp = new VPOLYGONE();
    this->Montrer();
}

dessinerpolygones::dessinerpolygones(void)
{
    this->Initialiser(
                HAUTEUR_DEF,
                LARGEUR_DEF,
                FOND_DEF);
}

dessinerpolygones::dessinerpolygones(
        const int hauteur,
        const int largeur)
{
    this->Initialiser(
                hauteur,
                largeur,
                FOND_DEF);
}

dessinerpolygones::dessinerpolygones(
        const int hauteur,
        const int largeur,
        const QBrush fond)
{
    this->Initialiser(
                hauteur,
                largeur,
                fond);
}

dessinerpolygones::~dessinerpolygones()
{
    this->Supprimer();
    delete this->_vp;
    delete this->_fd;
}

bool dessinerpolygones::TesterExistence(
        const int i)
{
    bool ok;
    int nb;

    nb = this->LireNbDessins();

    ok = (i>=0)&&(i<nb);
    return (ok);
}

dessinerpolygones::spolygone *dessinerpolygones::LirePolygone(
        const int i)
{
    spolygone *sp;
    if (this->TesterExistence(i)==false)
        sp = NULL;
    else
        sp = this->_vp->at(i);
    return (sp);
}

bool dessinerpolygones::Ecrire(
        const int idessin,
        const int nbp,
        const double *ptx,
        const double *pty,
        const double engxmin,
        const double engxmax,
        const double engymin,
        const double engymax,
        const int epaisseur,
        const QColor ctrace)
{
    spolygone *sp;
    int i;

    sp = this->LirePolygone(idessin);
    if (sp == NULL) return (false);
    sp->nbp = nbp;
    sp->ctrace = ctrace;
    sp->epaisseur = epaisseur;
    sp->poly = FDessinertrt::AjouterPolygone();
    sp->tp = new spoint[nbp+1];
    for (i=0;i<nbp;i++)
    {
        sp->tp[i].x = ptx[i];
        sp->tp[i].y = pty[i];
    }
    sp->englobantmin.x = engxmin;
    sp->englobantmin.y = engymin;
    sp->englobantmax.x = engxmax;
    sp->englobantmax.y = engymax;
    return (true);
}

bool dessinerpolygones::Lire(
        const int idessin,
        int &epaisseur,
        QColor &ctrace)
{
    spolygone *sp;

    sp = this->LirePolygone(idessin);
    if (sp == NULL) return (false);

    epaisseur = sp->epaisseur_init;
    ctrace = sp->ctrace_init;
    return (true);
}

void dessinerpolygones::Afficher(
        const spolygone *sp,
        const double ex,
        const double ey,
        const double tx,
        const double ty)
{
    int i;
    QGraphicsPolygonItem *poly;
    spoint *tp;
    int nbp;
    double xd,yd,xg,yg;

    poly = sp->poly;
    tp = sp->tp;
    nbp = sp->nbp;

    FDessinertrt::SupprimerLignesPolygone(poly);

    for (i=0; i<nbp-1; i++) {
        xd = tp[i].x;
        xd =  (xd+tx)*ex;

        yd = tp[i].y;
        yd =  (yd+ty)*ey;
        yd = -yd;

        xg = tp[i+1].x;
        xg =  (xg+tx)*ex;

        yg = tp[i+1].y;
        yg =  (yg+ty)*ey;
        yg = -yg;

        FDessinertrt::AjouterLignePolygone(
                    poly,
                    xd,yd,xg,yg);
    }
    this->_fd->DessinerPolygone(poly,false,sp->epaisseur,sp->ctrace);
}

static void CalculerEchelle(
        const double minx,
        const double maxx,
        const double miny,
        const double maxy,
        const double largeur,
        const double hauteur,
        double &ex,
        double &ey)
{
    double bornex,borney;

    bornex = maxx-minx;
    borney = maxy-miny;
    if (bornex > borney) borney=bornex;
    else bornex=borney;

    ex = largeur/bornex;
    ey = hauteur/borney;
}

void dessinerpolygones::CalculerEchelleMax(
        double &ex,
        double &ey)
{
    int largeur;
    int hauteur;
    double bornex,borney;

    ex=ey=1;

    if (this->_fd->LireDimensionScene(
                hauteur,
                largeur)==true)
    {
        bornex = this->_englobantmax.x-this->_englobantmin.x;
        borney = this->_englobantmax.y-this->_englobantmin.y;

        ex = largeur/bornex;
        ey = hauteur/borney;
    }
}

void dessinerpolygones::Rafraichir(void)
{
    if (this->_modeaffichage>=0)
    {
        this->Effacer();
        this->Afficher(this->_modeaffichage);
    }
}

void dessinerpolygones::Afficher(
        const int modeaffichage)
{
    spolygone *sp;
    int nb;
    int i;
    int largeur, hauteur;
    spoint min,max;
    double ex,ey,tx,ty;

    this->_modeaffichage = modeaffichage;

    if (this->_fd->LireDimensionScene(hauteur,largeur)==false) return;
    CopierEnglobant(
                &this->_englobantmin,
                &min);
    CopierEnglobant(
                &this->_englobantmax,
                &max);

    nb = this->LireNbDessins();
    for (i=0;i<nb;i++)
    {
        sp = this->LirePolygone(i);

        if (sp != NULL)
        {
            if (modeaffichage == 2)
            {
                CopierEnglobant(
                            &sp->englobantmin,
                            &min);
                CopierEnglobant(
                            &sp->englobantmax,
                            &max);
            }
            if (modeaffichage == 0)
            {
                ex = this->_ex;
                ey = this->_ey;
                tx = this->_tx;
                ty = this->_ty;
            }
            else
            {
                CalculerEchelle(
                            min.x,
                            max.x,
                            min.y,
                            max.y,
                            largeur,
                            hauteur,
                            ex,
                            ey);
                tx=0;
                ty=0;
            }
            this->Afficher(sp,ex,ey,tx,ty);
        }
    }
}

void dessinerpolygones::Effacer(void)
{
    if (this->_effacer==true)
        this->_fd->Effacer();
}

bool dessinerpolygones::Colorer(
        const int i,
        const QColor ctrace)
{
    spolygone *sp;

    sp = this->LirePolygone(i);
    if (sp == NULL) return (false);
    sp->ctrace_init = sp->ctrace;
    sp->ctrace = ctrace;

    return (true);
}

bool dessinerpolygones::Colorer(
        const int i)
{
    spolygone *sp;

    sp = this->LirePolygone(i);
    if (sp == NULL) return (false);
    sp->ctrace = sp->ctrace_init;

    return (true);
}

bool dessinerpolygones::EcrireEpaisseur(
        const int i,
        const int epaisseur)
{
    spolygone *sp;

    sp = this->LirePolygone(i);
    if (sp == NULL) return (false);
    sp->epaisseur_init = sp->epaisseur;
    sp->epaisseur = epaisseur;

    return (true);
}

bool dessinerpolygones::EcrireEpaisseur(
        const int i)
{
    spolygone *sp;

    sp = this->LirePolygone(i);
    if (sp == NULL) return (false);
    sp->epaisseur = sp->epaisseur_init;

    return (true);
}

bool dessinerpolygones::SupprimerDonnees(
        const int i)
{
    spolygone *sp;

    sp = this->LirePolygone(i);
    if (sp == NULL) return (false);
    delete[] sp->tp;
    delete sp->poly;
    delete (sp);
    return(true);
}

bool dessinerpolygones::Supprimer(
        const int i)
{
    bool ok;

    ok = this->SupprimerDonnees(i);
    if (ok == true)
        this->_vp->erase(this->_vp->begin()+i);

    return (ok);
}

void dessinerpolygones::Supprimer(void)
{
    int nb;

    nb = this->LireNbDessins();
    for (int i=0;i<nb;i++)
        this->SupprimerDonnees(i);
    this->_vp->clear();
    this->Effacer();
}

