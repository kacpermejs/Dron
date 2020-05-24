#include "Dron.hh"
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

void Dron::RysowaieDrona()
{
    this->Rysuj();
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
            przesun(m_MacOrientacji*Wektor3D{PredkoscX,0,0});
            odleglosc-=PredkoscX;
            L.krec(-10);
            P.krec(10);
        }
        else if(odleglosc <= PredkoscX)
        {
            przesun(m_MacOrientacji*Wektor3D{odleglosc,0,0});
            L.krec(-10);
            P.krec(10);
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
            przesun(m_MacOrientacji*Wektor3D{-PredkoscX,0,0});
            odleglosc+=PredkoscX;
            L.krec(10);
            P.krec(-10);
        }
        else if(odleglosc >= -PredkoscX)
        {
            przesun(m_MacOrientacji*Wektor3D{odleglosc,0,0});
            L.krec(10);
            P.krec(-10);
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


/*
void Dron::AnimacjaWynurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,0.1});
}

void Dron::AnimacjaZanurzania()
{
    przesun(m_MacOrientacji*Wektor<double, 3>{0,0,-0.1});
    
    
}*/

/*
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
*/

/*
void Dron::SkrecLewo()
{
    obroc(2,'z');
    Lewo=0;
}

void Dron::SkrecPrawo()
{
    obroc(-2,'z');
    Prawo=0;
}*/

void Dron::WymazDrona()
{
    InterfejsRysowania::Usun(this->GetNumer());
    InterfejsRysowania::Usun(L.GetNumer());
    InterfejsRysowania::Usun(P.GetNumer());
}