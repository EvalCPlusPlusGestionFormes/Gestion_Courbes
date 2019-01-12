#include "fcreation.h"
#include <QApplication>

#include "ctrlcreation.h"

int main(int argc, char *argv[])
{
    int r;

    //On déclare un controleur "creation"
    ctrlcreation *creation;

    QApplication a(argc, argv);

    //Création d'un controleur.
    creation = new ctrlcreation();

    //Ajout du logo pour l'application
    QApplication::setWindowIcon(QIcon(":/vue/Logo_Eval.jpg"));


   r = a.exec();

    //Destruction du controleur.
	//Ajout une commentaire
    delete creation;

    return(r);
}
