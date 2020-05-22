#include "Dron.hh"
/*
int Dron::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    Prostopadloscian P1;
    int numer=P1.Rysuj(api);
    return numer;
}*/

void Dron::Sterowanie()
{
    if(Przod)
    {
        PlynPrzod();
    }
    if(Tyl)
    {
        PlynTyl();
    }
    if(Lewo)
    {
        SkrecLewo();
    }
    if(Prawo)
    {
        SkrecPrawo();
    }
    if(Wynurz)
    {
        AnimacjaWynurzania();
    }
    if(Zanurz)
    {
        AnimacjaZanurzania();
    }
}

void Dron::RysowaieDrona()
{
    this->Rysuj();
    L.Rysuj();
    P.Rysuj();
    L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    L.obroc_z_dronem(m_MacOrientacji);
    P.obroc_z_dronem(m_MacOrientacji);
    
}

void Dron::AnimacjaWynurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,0.1});
}

void Dron::AnimacjaZanurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,-0.1});
    
    
}

void Dron::PlynPrzod()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0.1,0,0});
    L.krec(10);
    P.krec(-10);
    Przod=0;
}

void Dron::PlynTyl()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{-0.1,0,0});
    L.krec(-10);
    P.krec(10);
    Tyl=0;
}

void Dron::SkrecLewo()
{
    obroc(2,'z');
    Lewo=0;
}

void Dron::SkrecPrawo()
{
    obroc(-2,'z');
    Prawo=0;
}

void Dron::WymazDrona()
{
    InterfejsRysowania::Usun(this->GetNumer());
    InterfejsRysowania::Usun(L.GetNumer());
    InterfejsRysowania::Usun(P.GetNumer());
}