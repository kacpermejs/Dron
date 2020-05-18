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
    InterfejsRysowania::Usun(this->GetNumer());
    InterfejsRysowania::Usun(m_WirnikLewy.GetNumer());
    InterfejsRysowania::Usun(m_WirnikPrawy.GetNumer());
    this->Rysuj();
    m_WirnikLewy.Rysuj();
    m_WirnikPrawy.Rysuj();
}

void Dron::AnimacjaWynurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,0.1});
    //obroc(20,'x');
    this->m_WirnikLewy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0,0.1});
    this->m_WirnikPrawy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0,0.1});
}

void Dron::AnimacjaZanurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,-0.1});
    //obroc(-20,'x');
    this->m_WirnikLewy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0,-0.1});
    this->m_WirnikPrawy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0,-0.1});
}

void Dron::PlynPrzod()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0.1,0});
    this->m_WirnikLewy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0.1,0});
    this->m_WirnikPrawy.przesun(m_MacOrientacji*Wektor<double, 3>{0,0.1,0});
    m_WirnikLewy.obroc(30,'y');
    m_WirnikPrawy.obroc(-30,'y');
    Przod=0;
}

void Dron::PlynTyl()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,-0.1,0});
    this->m_WirnikLewy.przesun(m_MacOrientacji*Wektor<double, 3>{0,-0.1,0});
    this->m_WirnikPrawy.przesun(m_MacOrientacji*Wektor<double, 3>{0,-0.1,0});
    m_WirnikLewy.obroc(-30,'y');
    m_WirnikPrawy.obroc(30,'y');
    Tyl=0;
}

void Dron::SkrecLewo()
{
    obroc(2,'z');
    m_WirnikLewy.SetWekPol(MacierzOb(2,'z')*m_WirnikLewy.GetWekPol());
    m_WirnikPrawy.SetWekPol(MacierzOb(2,'z')*m_WirnikPrawy.GetWekPol());
    Lewo=0;
}

void Dron::SkrecPrawo()
{
    obroc(-2,'z');
    m_WirnikLewy.SetWekPol(MacierzOb(-2,'z')*m_WirnikLewy.GetWekPol());
    m_WirnikPrawy.SetWekPol(MacierzOb(-2,'z')*m_WirnikPrawy.GetWekPol());
    Prawo=0;
}