#ifndef INTERFEJS_DRONA

#define INTERFEJS_DRONA

#include "Dr3D_gnuplot_api.hh"
#include <sys/ioctl.h>
#include <termios.h>
#include "Wektor.hh"

bool kbhit();

class InterfejsDrona
{
protected:
    bool Plynie, Skreca, Pochylanie ,Kolizja;

    double m_odleglosc;
    double m_katZ;
    double m_katY;
    
public:
    InterfejsDrona(): Plynie(0), Skreca(0), Pochylanie(0), m_odleglosc(0), m_katZ(0), m_katY(0) {}

    char Input();
    void UI();

    void RejestrujKolizje() {   Kolizja=1;   }
    void RejestrujBrakKolizji() {   Kolizja=0;   }

    virtual const double zwrocPromien()const=0;
    virtual const Wektor<double,3> zwrocSrodek()const=0;
    

};

#endif