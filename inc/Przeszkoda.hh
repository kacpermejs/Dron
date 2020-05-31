#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDrona.hh"

class Przeszkoda
{
public:
    virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)=0;
    
};

#endif