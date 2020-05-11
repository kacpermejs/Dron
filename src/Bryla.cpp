#include "Bryla.hh"

const MacierzKw<double, 3> Bryla::GetMacierzObrotu(char kierunek)
    {
        switch (kierunek)
        {
        case 'x':
            return this->MacObX;
            break;
        case 'y':
            return this->MacObY;
            break;
        case 'z':
            return this->MacObZ;
            break;
        default:
            return this->MacObZ;
            break;
        }
        
        
    }