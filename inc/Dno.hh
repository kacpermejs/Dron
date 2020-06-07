#ifndef DNO_HH
#define DNO_HH

#define margines 1

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "InterfejsDrona.hh"
#include <cmath>

class Dno: public Plaszczyzna, public Przeszkoda
{
    double m_wysokosc;

public:
    Dno()=delete;

    Dno(double wymX, double wymY, double wysokosc):
        Plaszczyzna(wymX, wymY, 0, 0, wysokosc), m_wysokosc(wysokosc)
    {}

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)override;

    void Rysuj()override;

};

#endif