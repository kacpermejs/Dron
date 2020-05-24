#ifndef INTERFEJS_DRONA

#define INTERFEJS_DRONA

#include "Dr3D_gnuplot_api.hh"
#include <sys/ioctl.h>
#include <termios.h>

bool kbhit();

class InterfejsDrona
{
protected:
    bool Plynie, Skreca, Pochylanie;

    double m_odleglosc;
    double m_katZ;
    double m_katY;
    
public:
    InterfejsDrona(): Plynie(0), Skreca(0), Pochylanie(0), m_odleglosc(0), m_katZ(0), m_katY(0) {}
    char Input();

    void UI();
    

};

#endif