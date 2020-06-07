#include "Dno.hh"

bool Dno::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if( std::abs(D->zwrocSrodek()[2]-m_wysokosc) <= D->zwrocPromien() ||  D->zwrocSrodek()[2] < m_wysokosc)
        return 1;
    else
        return 0;
}

void Dno::Rysuj()
{
    Plaszczyzna::Rysuj();
}