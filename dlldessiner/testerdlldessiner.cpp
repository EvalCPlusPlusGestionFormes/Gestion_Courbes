#include "testerdlldessiner.h"

FDessiner *TesterDlldessiner::TesterFenDessin(void)
{
    FDessiner *fd;
    QGraphicsPolygonItem *poly;

    fd = new FDessiner();

    fd->CreerScene(500,500,Qt::lightGray);

    fd->DessinerRectangle(-100,-100,200,200,3,Qt::green);
    fd->DessinerEllipse(-100,-100,300,200,2,Qt::blue);
    //fd->Effacer();

    fd->DessinerLigne(-200,-200,200,200,2,Qt::red);

    poly = fd->AjouterPolygone();
    fd->AjouterLignePolygone(poly,200,200,100,100);
    fd->AjouterLignePolygone(poly,100,100,200,0);
    fd->DessinerPolygone(poly,true,4,Qt::cyan,Qt::blue);
    delete poly;

    poly = fd->AjouterPolygone();
    fd->AjouterLignePolygone(poly,-200,200,150,200);
    fd->AjouterLignePolygone(poly,150,200,0,0);
    fd->AjouterLignePolygone(poly,0,0,-200,0);
    fd->DessinerPolygone(poly,false,3,Qt::blue);
    delete poly;

    return (fd);
}

dessinerpolygones *TesterDlldessiner::TesterDessin()
{
    dessinerpolygones *d;
    int idessin;
    double ptx[4] =
    {
        -100,
        -50,
        50,
        100
    };
    double pty[4] =
    {
        -100,
        50,
        50,
        -100
    };

    d = new dessinerpolygones(400,400,Qt::cyan);
    d->EcrireNom("TEST DESSINS");
    d->EcrireTraitementClose(3);

    d->Ajouter();
    idessin = d->LireNbDessins()-1;
    d->Ecrire(
                idessin,
                4,
                ptx,
                pty,
                -100,100,-100,50,
                2,Qt::blue);
    d->EcrireEnglobant(-100,100,-100,100);

    d->CacherModeEffacement();
    d->ChoisirModeEffacement(true);
    d->ChoisirModeAffichage(0);
    return (d);
}
