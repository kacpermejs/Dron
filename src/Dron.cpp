#include "Dron.hh"
#include <memory>
/*
int Dron::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    Prostopadloscian P1;
    int numer=P1.Rysuj(api);
    return numer;
}*/

#define PredkoscX 0.1

#define PredkoscObrotu 5.0

void Dron::Sterowanie()
{
    if(Plynie)
    {
        Plyn(m_odleglosc, m_katY);
    }
    if(Skreca)
    {
        Skrec(m_katZ);
    }
}

void Dron::Rysuj()
{
    Prostopadloscian::Rysuj();
    L.Rysuj();
    P.Rysuj();
}

void Dron::Plyn(double & odleglosc, double & kat)
{
    if(Pochylanie==0)
    {
        obroc(kat, 'y');
        Pochylanie=1;
    }
    
    if(odleglosc > 0)
    {
        if(odleglosc > PredkoscX)
        {
            Wektor3D przesuniecie=Wektor3D{PredkoscX,0,0};

            if(!Kolizja)
            {
                przesun(m_MacOrientacji*przesuniecie);
                odleglosc-=PredkoscX;
                L.krec(-10);
                P.krec(10);
            }
            else
            {
                przesun(m_MacOrientacji*(-1*przesuniecie));
                obroc(-kat, 'y');
                Pochylanie=0;
                kat=0;
                odleglosc=0;
                Plynie=0;
            }
            
        }
        else if(odleglosc <= PredkoscX)
        {
            Wektor3D przesuniecie=Wektor3D{odleglosc,0,0};

            if(!Kolizja)
            {
                przesun(m_MacOrientacji*przesuniecie);
            
                L.krec(-10);
                P.krec(10);
            }
            else
            {
                przesun(m_MacOrientacji*(-1*przesuniecie));
            }

            obroc(-kat, 'y');
            Pochylanie=0;
            kat=0;
            odleglosc=0;
            Plynie=0;
        }
    }
    else if(odleglosc < 0)
    {
        if(odleglosc < -PredkoscX)
        {
            Wektor3D przesuniecie=Wektor3D{-PredkoscX,0,0};

            if(!Kolizja)
            {
                przesun(m_MacOrientacji*przesuniecie);
            
                odleglosc+=PredkoscX;
                L.krec(10);
                P.krec(-10);
            }
            else
            {
                przesun(m_MacOrientacji*(-1*przesuniecie));
                obroc(-kat, 'y');
                Pochylanie=0;
                kat=0;
                odleglosc=0;
                Plynie=0;
            }
            
        }
        else if(odleglosc >= -PredkoscX)
        {
            Wektor3D przesuniecie=Wektor3D{-odleglosc,0,0};            
            
            if(!Kolizja)
            {
                przesun(m_MacOrientacji*przesuniecie);
                L.krec(10);
                P.krec(-10);                
            }
            else
            {
                przesun(m_MacOrientacji*(-1*przesuniecie));
            }
            
            obroc(-kat, 'y');
            Pochylanie=0;
            kat=0;
            odleglosc=0;
            Plynie=0;
        }
    }
    L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    L.obroc_z_dronem(m_MacOrientacji);
    P.obroc_z_dronem(m_MacOrientacji);
    
}

void Dron::Skrec(double & kat)
{
    
    
    if(kat > 0)
    {
        if(kat > PredkoscObrotu)
        {
            obroc(PredkoscObrotu,'z');
            kat-=PredkoscObrotu;
        }
        else if(kat <= PredkoscObrotu)
        {
            obroc(kat,'z');
            kat=0;
            Skreca=0;
        }
        
    }
    else if(kat < 0)
    {
        if(kat < -PredkoscObrotu)
        {
            obroc(-PredkoscObrotu,'z');
            kat+=PredkoscObrotu;
        }
        else if(kat >= -PredkoscObrotu)
        {
            obroc(kat,'z');
            kat=0;
            Skreca=0;
        }
    }
    L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
    L.obroc_z_dronem(m_MacOrientacji);
    P.obroc_z_dronem(m_MacOrientacji);
}

void Dron::Usun()
{
    Prostopadloscian::Usun();
    L.Usun();
    P.Usun();
}

bool Dron::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if(    Wektor3D(D->zwrocSrodek() - this->zwrocSrodek()).dlugosc()  <=  ( D->zwrocPromien() + this->zwrocPromien() )    )
        return true;
    else
        return false;
}