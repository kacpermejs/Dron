#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"

class Dron: public InterfejsDrona, public Prostopadloscian
{
    
public:
    virtual int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)override;

};

#endif