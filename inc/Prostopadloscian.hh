#ifndef PROSTOPADLOSCIAN

#define PROSTOPADLOSCIAN

#include "Bryla.hh"


class Prostopadloscian:
    public Bryla
{
protected:
    Wektor<double, 3> m_Wymiary; //(x,y,z)
    std::vector < Wektor<double, 3> > m_Wierzcholki;
public:
    Prostopadloscian(): m_Wymiary{1,2,3}
    {
        m_Wierzcholki.reserve(8);
        UstawWierzcholki();
    }
    
    Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
    Bryla{WspX, WspY, WspZ}, m_Wymiary{WymX,WymY,WymZ}
    {
        m_Wierzcholki.reserve(8);
        UstawWierzcholki();
    }

    void UstawWierzcholki();

    void Rysuj() override;

    virtual void obroc(double kat, char kierunek)override;
    virtual void przesun(Wektor<double,3> V)override;

    const Wektor<double,3> & operator[] (int index) const { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }
    Wektor<double,3> & operator[] (int index) { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

};

#endif