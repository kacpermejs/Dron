#ifndef PRZESZKODA_PROST_HH
#define PRZESZKODA_PROST_HH

#define MarginesPrzeszkodyProst 0.1

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"

class PrzeszkodaProst: public Prostopadloscian, Przeszkoda
{

public:
    PrzeszkodaProst(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
        Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ)
    {}




    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)override;
};


#endif