#ifndef INTERFEJS_DRONA

#define INTERFEJS_DRONA

#include "Dr3D_gnuplot_api.hh"
#include <sys/ioctl.h>
#include <termios.h>

bool kbhit();

class InterfejsDrona
{
protected:
    bool Przod=0, Tyl=0, Lewo=0, Prawo=0, Wynurz=0, Zanurz=0;
    
public:
    char Input();

    void UI();
    

};

#endif