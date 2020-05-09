#ifndef INTERFEJS_RYSOWANIA

#define INTERFEJS_RYSOWANIA

#include "Dr3D_gnuplot_api.hh"

class InterfejsRysowania
{
public:
    virtual int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) = 0;
};

#endif