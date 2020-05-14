#ifndef GRANIASTOSLUP6
#define GRANIASTOSLUP6

#include "Bryla.hh"

class Graniastoslup6: public Bryla
{
protected:
    double m_wysokosc;
    double m_promien;
    std::vector < Wektor<double, 3> > m_Wierzcholki;
public:
    Graniastoslup6(): m_wysokosc(1), m_promien(1)
    {
        m_Wierzcholki.reserve(12);
        UstawWierzcholki();
    }
    
    Graniastoslup6(double WspX, double WspY, double WspZ, double Wysokosc, double Promien):
    Bryla{WspX, WspY, WspZ}, m_wysokosc(Wysokosc), m_promien(Promien)
    {
        m_Wierzcholki.reserve(12);
        UstawWierzcholki();
    }

    void UstawWierzcholki();

    void Rysuj() override;

    virtual void obroc(double kat, char kierunek)override;
    virtual void przesun(Wektor<double,3> V)override;

    const Wektor<double,3> & operator[] (int index) const { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }
    Wektor<double,3> & operator[] (int index) { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }

};

#endif