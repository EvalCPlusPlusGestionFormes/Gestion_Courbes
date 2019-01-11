#include <QCloseEvent>
#include "fdessiner.h"
#include "ui_fdessiner.h"

static double ratiox = 0.98;
static double ratioy = 0.98;
static bool transformerenligne=false;

static void EcrireEpaisseur(
        QAbstractGraphicsShapeItem *poly,
        int epaisseur)
{
    QPen contour;

    contour = poly->pen();
    contour.setWidth(epaisseur);
    poly->setPen(contour);
}


static void EcrireCouleurTrace(
        QAbstractGraphicsShapeItem *poly,
        QColor couleur_trace)
{
    QPen contour;

    contour = poly->pen();
    contour.setColor(couleur_trace);
    poly->setPen(contour);
}

static void EcrireCouleurFond(
        QAbstractGraphicsShapeItem *poly,
        QColor couleur_fond)
{
    QBrush remplissage;

    remplissage= poly->brush();
    if (couleur_fond==Qt::NoBrush)
        remplissage.setStyle(Qt::NoBrush);
    else
    {
        remplissage.setStyle(Qt::SolidPattern);
        remplissage.setColor(couleur_fond);
    }
    poly->setBrush(remplissage);
}


static void Definir(
        QAbstractGraphicsShapeItem *gi,
        int epaisseur,
        QColor couleur_trace,
        QColor couleur_fond
        )
{
    QPen contour;
    QBrush remplissage;

    gi->setBrush(remplissage);
    gi->setPen(contour);
    EcrireEpaisseur(gi,epaisseur);
    EcrireCouleurTrace(gi,couleur_trace);
    EcrireCouleurFond(gi,couleur_fond);
}

static void Definir(
        QGraphicsLineItem *gi,
        int epaisseur,
        QColor couleur_trace)
{
    QPen contour(couleur_trace);
    contour.setWidth(epaisseur);
    gi->setPen(contour);
}


void FDessiner::InitialiserCB(void)
{
    QObject::connect(
                this->_ui->ChkEffacer,
                SIGNAL(toggled(bool)),
                this,
                SLOT(CBGererEffacement())
                );

    QObject::connect(
                this->_ui->RadNormal,
                SIGNAL(toggled(bool)),
                this,
                SLOT(CBGererAffichageNormal())
                );
    QObject::connect(
                this->_ui->RadCadre,
                SIGNAL(toggled(bool)),
                this,
                SLOT(CBGererAffichageCadre())
                );
    QObject::connect(
                this->_ui->verticalSlider,
                SIGNAL(valueChanged(int)),
                this,
                SLOT(CBVSliderChange(int))
                );
    QObject::connect(
                this->_ui->horizontalSlider,
                SIGNAL(valueChanged(int)),
                this,
                SLOT(CBHSliderChange(int))
                );
}

void FDessiner::CBGererEffacement(void)
{
    bool b;
    b = this->_ui->ChkEffacer->isChecked();
    this->_ui->RadAucun->setChecked(true);
    this->TrtGererEffacement(b);
}

void FDessiner::CBVSliderChange(int v)
{
    this->TrtEchelleY(
                v,
                this->_ui->verticalSlider->minimum(),
                this->_ui->verticalSlider->maximum()
                );
}

void FDessiner::CBHSliderChange(int v)
{
    this->TrtEchelleX(
                v,
                this->_ui->horizontalSlider->minimum(),
                this->_ui->horizontalSlider->maximum()
                );
}

void FDessiner::CBGererAffichageNormal(void)
{
    if (this->_ui->RadNormal->isChecked())
        this->TrtGererAffichage(0);
    this->InitialiserSliders();
}

void FDessiner::CBGererAffichageCadre(void)
{
    if (this->_ui->RadCadre->isChecked())
        this->TrtGererAffichage(1);
    this->InitialiserSliders();
}

void FDessiner::ChoisirModeAffichage(
        const int modeaffichage)
{
    if (modeaffichage ==0)
        this->_ui->RadNormal->setChecked(true);
    if (modeaffichage ==1)
        this->_ui->RadCadre->setChecked(true);
    if (modeaffichage ==3)
        this->_ui->RadAucun->setChecked(true);
}

void FDessiner::ChoisirModeEffacement(
        const bool etat)
{
    this->_ui->ChkEffacer->setChecked(etat);
}

void FDessiner::CacherModeEffacement(void)
{
    this->_ui->ChkEffacer->hide();
}

void FDessiner::AfficherModeEffacement(void)
{
    this->_ui->ChkEffacer->show();
}

void FDessiner::InitialiserSliders()
{
    this->CBHSliderChange(
                this->_ui->horizontalSlider->value());
    this->CBVSliderChange(
                this->_ui->verticalSlider->value());
}

FDessiner::FDessiner(QWidget *parent):
    QMainWindow(
        parent,
        Qt::MSWindowsFixedSizeDialogHint|Qt::WindowCloseButtonHint)
{
    this->_ui = new Ui::FDessiner();
    this->_ui->setupUi(this);

    this->_scene = NULL;
    this->_view = NULL;
    this->EcrireTraitementClose(3);
    this->_ui->RadAucun->hide();

    this->ChoisirModeAffichage(3);
    this->ChoisirModeEffacement(false);
    this->CacherModeEffacement();

    this->InitialiserCB();
}

FDessiner::~FDessiner()
{
    if (this->_scene!=NULL)
    {
        this->Effacer();
        delete this->_scene;
    }
    if (this->_view != NULL)
    {
        delete this->_view;
    }
    delete this->_ui;
}

bool FDessiner::LireDimensionScene(
        int &h,
        int &l)
{
    if (this->_scene == NULL) return (false);
    h = this->_hauteur_scene;
    l = this->_largeur_scene;
    return (true);
}

void FDessiner::EcrireTraitementClose(const int t)
{
    QString s;
    this->_trt_close=t;
    switch (t)
    {
    case 1:
        s = "Affichage permanent";
        break;
    case 2:
        s = "Close -> fenetre cachee";
        break;
    case 3:
        s = "Close -> fenetre detruite";
        break;
    case 4:
        s = "Close -> arret de l'application";
        break;
    default:
        s = "";
    }
    this->statusBar()->showMessage(s);
    this->setWindowTitle(this->windowTitle()+" ("+s+")");
}

void FDessiner::CreerScene(
        int hauteur,
        int largeur,
        QBrush couleur_fond,
        bool avectrt)
{
    QWidget *w;

    if (avectrt==false)
        w = this;
    else
        w = this->_ui->LabDessin;

    this->_largeur_scene = largeur*ratiox;
    this->_hauteur_scene = hauteur*ratioy;

    w->setFixedSize(largeur,hauteur);

    this->_scene = new QGraphicsScene(w);
    this->_scene->setBackgroundBrush(couleur_fond);

    this->_view = new QGraphicsView(_scene,w);
    this->_view->setGeometry(0,0,largeur,hauteur);

    // definition du rectangle
    // englobant la scene
    // centré au centre de la view
    // et dimension de la view
    this->_scene->setSceneRect(
                -this->_largeur_scene/2,
                -this->_hauteur_scene/2,
                this->_largeur_scene,
                this->_hauteur_scene);

    this->_view->show();
}

void FDessiner::Ajouter(
        QGraphicsItem *gi)
{
    if (this->_scene != NULL)
        this->_scene->addItem(gi);
}


void FDessiner::DessinerRectangle(
        int x,
        int y,
        int hauteur,
        int largeur,
        int epaisseur,
        QColor couleur_trace,
        QColor couleur_fond)
{
    if (this->_scene ==NULL) return;

    QGraphicsRectItem *gi;
    gi = new QGraphicsRectItem(x, y,largeur,hauteur);
    Definir(gi,epaisseur,couleur_trace,couleur_fond);
    this->Ajouter(gi);
}

void FDessiner::DessinerEllipse(
        int x,
        int y,
        int hauteur,
        int largeur,
        int epaisseur,
        QColor couleur_trace,
        QColor couleur_fond)
{
    if (this->_scene ==NULL) return;

    QGraphicsEllipseItem *gi;
    gi = new QGraphicsEllipseItem(x, y,largeur,hauteur);
    Definir(gi,epaisseur,couleur_trace,couleur_fond);
    this->Ajouter(gi);
}

void FDessiner::DessinerLigne(
        int xd,
        int yd,
        int xf,
        int yf,
        int epaisseur ,
        QColor couleur_trace)
{
    if (this->_scene ==NULL) return;

    QGraphicsLineItem *gi;
    gi  = new QGraphicsLineItem(xd,yd,xf,yf);
    Definir(gi,epaisseur,couleur_trace);
    this->Ajouter(gi);
}

QGraphicsPolygonItem *FDessiner::AjouterPolygone()
{
    QGraphicsPolygonItem *poly;
    QPolygonF polygon;

    poly = new QGraphicsPolygonItem();

    poly->setPolygon(polygon);
    return (poly);
}


void FDessiner::SupprimerLignesPolygone(
        QGraphicsPolygonItem *poly)
{
    QPolygonF polygon;
    polygon = poly->polygon();
    polygon.clear();
    poly->setPolygon(polygon);
}

void FDessiner::AjouterLignePolygone(
        QGraphicsPolygonItem *poly,
        int xd,
        int yd,
        int xf,
        int yf)
{ 
    QPolygonF polygon;
    QPointF debut(xd,yd);
    QPointF final(xf,yf);
    polygon = poly->polygon();
    polygon<<debut;
    polygon<<final;
    poly->setPolygon(polygon);
}

void FDessiner::DessinerPolygoneOuvertLignes(
        QGraphicsPolygonItem *poly)
{
    QColor couleur_trace;
    QPolygonF polygon;
    int epaisseur;

    couleur_trace = poly->pen().color();
    epaisseur = poly->pen().width();
    polygon = poly->polygon();
    for (int i=0;i<polygon.length();i+=2)
    {
        this->DessinerLigne(
                    polygon[i].x(),
                    polygon[i].y(),
                    polygon[i+1].x(),
                polygon[i+1].y(),
                epaisseur,
                couleur_trace);
    }
}

void FDessiner::DessinerPolygoneOuvert(
        QGraphicsPolygonItem *poly)
{
    QPainterPath op;
    op.addPolygon(poly->polygon());
    if (this->_scene != NULL)
        this->_scene->addPath(
                op,
                poly->pen(),
                poly->brush());
}

void FDessiner::DessinerPolygoneFerme(
        QGraphicsPolygonItem *poly)
{
    QGraphicsPolygonItem *ogi;

    ogi = new QGraphicsPolygonItem();
    ogi->setBrush(poly->brush());
    ogi->setPen(poly->pen());
    ogi->setPolygon(poly->polygon());
    this->Ajouter(ogi);
}

void FDessiner::DessinerPolygone(
        QGraphicsPolygonItem *poly,
        bool ferme,
        int epaisseur,
        QColor couleur_trace,
        QColor couleur_fond)
{     
    if (this->_scene ==NULL) return;

    Definir(poly,epaisseur,couleur_trace,couleur_fond);

    if (ferme == false)
        if (transformerenligne)
            this->DessinerPolygoneOuvertLignes(poly);
        else
            this->DessinerPolygoneOuvert(poly);
    else
        this->DessinerPolygoneFerme(poly);
}

void FDessiner::Effacer(void)
{
    QList<QGraphicsItem *> litems;
    int nbitems;

    if (this->_scene!=NULL)
    {
        litems = this->_scene->items();
        nbitems = litems.length();
        for (int i=0;i<nbitems;i++)
            delete (litems[i]);
        this->_scene->clear();
    }
}

void FDessiner::DefinirRatioScene(
        const double rx,
        const double ry)
{
    ratiox = rx;
    ratioy = ry;
}

void FDessiner::closeEvent(QCloseEvent *event)
{
    switch (this->_trt_close)
    {
    case 1:
        event->ignore();
        break;
    case 2:
        this->hide();
        event->ignore();
        break;
    case 3:
        break;
    case 4:
        qApp->quit();
        break;
    }
}
