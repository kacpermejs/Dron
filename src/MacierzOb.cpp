#include "MacierzOb.hh"

void MacierzOb::UstawMacierzOb(double kat, char kierunek)
{
    switch (kierunek)
        {
        case 'x':
            UstawMacierz(Macierz3D
            {
                {1,0,0},
                {0,cos(kat*PI/180),sin(kat*PI/180)},
                {0,-sin(kat*PI/180),cos(kat*PI/180)}
            });
            break;
        case 'y':
            UstawMacierz(Macierz3D
            {
                {cos(kat*PI/180),0,-sin(kat*PI/180)},
                {0,1,0},
                {sin(kat*PI/180),0, cos(kat*PI/180)}
            });
            break;
        case 'z':
            UstawMacierz(Macierz3D
            {
                {cos(kat*PI/180),sin(kat*PI/180),0},
                {-sin(kat*PI/180),cos(kat*PI/180), 0},
                {0,0,1}
            });
            break;
        
        default:
            Macierz3D
            {
                {cos(kat*PI/180),sin(kat*PI/180),0},
                {-sin(kat*PI/180),cos(kat*PI/180), 0},
                {0,0,1}
            };
            break;
        }
}