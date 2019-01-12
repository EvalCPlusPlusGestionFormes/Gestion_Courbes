#ifndef FCREATION_H
#define FCREATION_H

#include <iostream>
#include <QMainWindow>


using namespace std;

//Permet à la la classe fcreation de connaitre le controleur
class ctrlcreation;
class QListWidget;

namespace Ui {
class fcreation;
}

class fcreation : public QMainWindow
{
    Q_OBJECT

public:
    //*******************************************
    //          CONSTRUCTEUR/DESTRUCTEUR
    //*******************************************
    //Modification du constructeur pour avoir en paramètre
    //le controleur (ctrlcreation *creation)
    fcreation(ctrlcreation *creation, QWidget *parent = 0);
    ~fcreation();

    //*******************************************
    //          METHODES PUBLICS
    //*******************************************
    void setCouleurCourbes(const QColor);
    QColor getCouleurCourbes(void);
    QListWidget *Chercher(const int type);
    static bool confirmer(const char *q);
    void Afficher(const int type,string *sm,string *sr,const int nbs);
    void Effacer(const int type);
    void Selectionner(const int type,const int sel);

    static void Informer(const char *s);

    int verifChecked(void);
    void recupParamsCosSin(int&, double&);
    void recupParamsCommuns(double&, double&, double&, double&,
                            QColor&, int&);
    void initialiserTabTrigo(void);
    void initialiserTabMath(int);
    void initialiserTabGeo(int);
    void initialiserTips(int);

private:
    //*******************************************
    //                   ATTRIBUTS
    //*******************************************
    Ui::fcreation *ui;
    //Déclaration d'un attribut de type ctrlcreation.
    ctrlcreation *_ctrlCreate;
    QColor _couleurCourbes;

    //*******************************************
    //              METHODES PRIVATES
    //*******************************************
    void initialiserCB(void);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void CBAfficherFenetreGraphique(void);
    void CBCreer(void);
    void CBVider(void);
    void CBChoisirCouleur (void);
    void CBParametrerLimites (void);
};

#endif // FCREATION_H
