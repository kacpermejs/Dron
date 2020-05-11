#include "Dron.hh"
/*
int Dron::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    Prostopadloscian P1;
    int numer=P1.Rysuj(api);
    return numer;
}*/

void Dron::Sterowanie(char input)
{
    switch (input)
    {
    case 'a':
        this->przesun(MacOrientacji*Wektor<double, 3>{-0.1,0,0});
        break;
    case 'd':
        this->przesun(MacOrientacji*Wektor<double, 3>{0.1,0,0});
        break;
    case 'w':
        this->przesun(MacOrientacji*Wektor<double, 3>{0,0.1,0});
        break;
    case 's':
        this->przesun(MacOrientacji*Wektor<double, 3>{0,-0.1,0});
        break;
    case 'q':
        this->obroc(5,'z');
        break;
    case 'e':
        this->obroc(-5,'z');
        break;
    case '+':
        this->przesun(MacOrientacji*Wektor<double, 3>{0,0,0.1});
        break;
    case '-':
        this->przesun(MacOrientacji*Wektor<double, 3>{0,0,-0.1});
        break;
    default:
        break;
    }
}