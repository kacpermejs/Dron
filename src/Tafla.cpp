#include "Tafla.hh"

bool Tafla::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if( std::abs(D->zwrocSrodek()[2]-m_wysokosc) == 0 ||  D->zwrocSrodek()[2] > m_wysokosc)
        return 1;
    else
        return 0;
}

void Tafla::Rysuj()
{
    Plaszczyzna::Rysuj();
}