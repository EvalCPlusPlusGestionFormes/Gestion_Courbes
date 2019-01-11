/* Classe de tests unitaires
des classes de dessin
*/

#ifndef TESTERDESSINER_H
#define TESTERDESSINER_H

#include "dessiner_global.h"

#include "dessinerpolygones.h"
#include "fdessiner.h"

class DESSINERSHARED_EXPORT TesterDlldessiner
{
public:
    static FDessiner *TesterFenDessin(void);
    static dessinerpolygones *TesterDessin(void);
};

#endif // TESTERDESSINER_H
