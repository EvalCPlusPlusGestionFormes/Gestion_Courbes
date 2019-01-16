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
    static void informer(const char *s);
    static bool confirmer(const char *q);

    void setCouleurCourbes(const QColor);
    QColor getCouleurCourbes(void);
    int recupLigneSelect(const int);
    void supprimerLigneList(const int, const int);
    QListWidget *Chercher(const int type);
    void Afficher(const int type,string *sm,string *sr,const int nbs);
    void Effacer(const int type);
    void Selectionner(const int type,const int sel);
    int verifChecked(void);
    void recupParamsTrigo(int&, double&);
    void recupParamsMaths(double&, double&, double&);
    void recupParamsGeo(double&, double&);
    void recupParamsCommuns(double&, double&, double&, double&,
                            QColor&, int&);
    void setParamCommuns(const double, const double, const double, const double,
                         const QColor, const int);
    void initialiserTab(int);
    void initialiserTips(int);
    void AfficherFenetreGraphique(void);
    void initialiserCerRect(int);
    void setParamTrigo(const int, const double);
    void setParamMath(const double, const double, const double);
    void setParamGeo(const double, const double);
    void selectLastRow(void);

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
    void CBCreer(void);
    void CBSupprimerLigne(void);
    void CBVider(void);
    void CBModifLigne(void);
    void CBChoisirCouleur (void);
    void CBParametrerLimites (void);
    void CBLigneSelectionnee(int);
};

#endif // FCREATION_H
