#include "MacierzOb.hh"

void MacierzOb::UstawMacierzOb()
{
    switch (this->m_kierunek)
        {
        case 'x':
            UstawMacierz(MacierzKw<double,3>
            {
                {1,0,0},
                {0,cos(m_kat*PI/180),sin(m_kat*PI/180)},
                {0,-sin(m_kat*PI/180),cos(m_kat*PI/180)}
            });
            break;
        case 'y':
            UstawMacierz(MacierzKw<double,3>
            {
                {cos(m_kat*PI/180),0,-sin(m_kat*PI/180)},
                {0,1,0},
                {sin(m_kat*PI/180),cos(m_kat*PI/180), 0}
            });
            break;
        case 'z':
            UstawMacierz(MacierzKw<double,3>
            {
                {cos(m_kat*PI/180),sin(m_kat*PI/180),0},
                {-sin(m_kat*PI/180),cos(m_kat*PI/180), 0},
                {0,0,1}
            });
            break;
        
        default:
            MacierzKw
            {
                {cos(m_kat*PI/180),sin(m_kat*PI/180),0},
                {-sin(m_kat*PI/180),cos(m_kat*PI/180), 0},
                {0,0,1}
            };
            break;
        }
}