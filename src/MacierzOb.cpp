#include "MacierzOb.hh"

void MacierzOb::UstawMacierzOb(double kat, char kierunek)
{
    switch (kierunek)
        {
        case 'x':
            UstawMacierz(MacierzKw<double,3>
            {
                {1,0,0},
                {0,cos(kat*PI/180),sin(kat*PI/180)},
                {0,-sin(kat*PI/180),cos(kat*PI/180)}
            });
            break;
        case 'y':
            UstawMacierz(MacierzKw<double,3>
            {
                {cos(kat*PI/180),0,-sin(kat*PI/180)},
                {0,1,0},
                {sin(kat*PI/180),cos(kat*PI/180), 0}
            });
            break;
        case 'z':
            UstawMacierz(MacierzKw<double,3>
            {
                {cos(kat*PI/180),sin(kat*PI/180),0},
                {-sin(kat*PI/180),cos(kat*PI/180), 0},
                {0,0,1}
            });
            break;
        
        default:
            MacierzKw
            {
                {cos(kat*PI/180),sin(kat*PI/180),0},
                {-sin(kat*PI/180),cos(kat*PI/180), 0},
                {0,0,1}
            };
            break;
        }
}