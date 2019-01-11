#ifndef CTRLCREATION_H
#define CTRLCREATION_H

#include "fcreation.h"
#include "gesdessin.h"

class ctrlcreation
{

private:
   //*******************************************
   //                   ATTRIBUTS
   //*******************************************

  //Déclaration d'une fenetre principale (fc) en tant qu'attribut.
  fcreation *_fc;
  gesdessin *_fTrigo;
  gesdessin *_fMath;
  gesdessin *_fGeo;

  int _selectionTrigo;
  int _selectionMath;
  int _selectionGeo;

  //*******************************************
  //            METHODES PRIVATES
  //*******************************************
  void initialiser(void); //Vide pour le moment
  void cacherToutes(void);
  void positionDefaut(void);

public:
  //*******************************************
  //          CONSTRUCTEUR/DESTRUCTEUR
  //*******************************************
    ctrlcreation(void);
    ~ctrlcreation();

   //*******************************************
   //            METHODES PUBLICS
   //*******************************************
   void afficherFenetreGraphique(const int);
   void creerTrigos(const int);

};

#endif // CTRLCREATION_H
