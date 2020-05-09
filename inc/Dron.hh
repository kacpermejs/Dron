#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"

class Dron: public InterfejsDrona, public Prostopadloscian
{
    
public:
    Dron(): Prostopadloscian() {}
    Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ): Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ) {}

    
    void Sterowanie(char input);

};

#endif