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

    r = a.exec();

    //Destruction du controleur.
	//Ajout une commentaire
    delete creation;

    return(r);
}
