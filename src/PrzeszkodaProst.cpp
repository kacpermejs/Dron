#include "PrzeszkodaProst.hh"

bool PrzeszkodaProst::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    double odlX, odlY, odlZ;

    odlX=std::abs(D->zwrocSrodek()[0]-m_WekPol[0]);
    odlY=std::abs(D->zwrocSrodek()[1]-m_WekPol[1]);
    odlZ=std::abs(D->zwrocSrodek()[2]-m_WekPol[2]);


    if( odlX    <=   D->zwrocPromien()+(m_Wymiary[0]/2)+MarginesPrzeszkodyProst)//X
    {
        if( odlY    <=   D->zwrocPromien()+(m_Wymiary[1]/2)+MarginesPrzeszkodyProst)//Y
        {
            if( odlZ    <=   D->zwrocPromien()+(m_Wymiary[2]/2)+MarginesPrzeszkodyProst)//Z
            {
                std::cout << "tutaj jestem\n";
                return 1;
            }
                
        }
    }
    return 0;

}

void PrzeszkodaProst::Rysuj()
{
    Prostopadloscian::Rysuj();
}