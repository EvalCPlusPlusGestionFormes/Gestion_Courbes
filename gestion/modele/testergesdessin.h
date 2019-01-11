#ifndef TESTERCTRLDESSIN_H
#define TESTERCTRLDESSIN_H

#include "gesdessin.h"

class testergesdessin
{
private:
    gesdessin *_gdformes;
    gesdessin *_gdtrigos;
    gesdessin *_gdmaths;
    gesdessin *_gdtout;

public:
    testergesdessin(void);
    ~testergesdessin();
};

#endif // TESTERCTRLDESSIN_H
