#ifndef TAFLA_HH
#define TAFLA_HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "InterfejsDrona.hh"

class Tafla: public Plaszczyzna, public Przeszkoda
{
    double m_wysokosc;

public:
    Tafla()=delete;

    Tafla(double wymX, double wymY, double wysokosc):
        Plaszczyzna(wymX, wymY, 0, 0, wysokosc), m_wysokosc(wysokosc)
    {}

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)override;

    void Rysuj()override;

};

#endif