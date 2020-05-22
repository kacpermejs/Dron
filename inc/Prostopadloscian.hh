#ifndef PROSTOPADLOSCIAN

#define PROSTOPADLOSCIAN

#include "Bryla.hh"


class Prostopadloscian:
    public Bryla
{
protected:
    Wektor<double, 3> m_Wymiary; //(x,y,z)
    std::vector < Wektor<double, 3> > m_Wierzcholki=std::vector < Wektor<double, 3> >(8);
public:
    Prostopadloscian(): m_Wymiary{1,2,3}
    {
        
        UstawWierzcholki();
    }
    
    Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
    Bryla{WspX, WspY, WspZ}, m_Wymiary{WymX,WymY,WymZ}
    {
        
        UstawWierzcholki();
    }

    Prostopadloscian(Wektor3D wek, double WymX, double WymY, double WymZ):
    Bryla(wek), m_Wymiary{WymX,WymY,WymZ}
    {
        
        UstawWierzcholki();
    }

    void UstawWierzcholki();

    void Rysuj() override;


    virtual void obroc(double kat, char kierunek)override;
    virtual void przesun(Wektor3D V)override;

    const Wektor3D & operator[] (int index) const { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }
    Wektor3D & operator[] (int index) { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

};

#endif