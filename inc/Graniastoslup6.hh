#ifndef GRANIASTOSLUP6
#define GRANIASTOSLUP6

#include "Bryla.hh"

class Graniastoslup6: public Bryla
{
protected:
    double m_wysokosc;
    double m_promien;
    std::vector < Wektor<double, 3> > m_Wierzcholki=std::vector < Wektor<double, 3> >(12);
public:
    Graniastoslup6(): m_wysokosc(1), m_promien(1)
    {
        UstawWierzcholki();
    }
    
    Graniastoslup6(double WspX, double WspY, double WspZ, double Wysokosc, double Promien):
    Bryla{WspX, WspY, WspZ}, m_wysokosc(Wysokosc), m_promien(Promien)
    {
        UstawWierzcholki();
    }

    Graniastoslup6(Wektor3D wspolrzedne_sr, double Wysokosc, double Promien):
    Bryla(wspolrzedne_sr), m_wysokosc(Wysokosc), m_promien(Promien)
    {
        UstawWierzcholki();
    }

    void UstawWierzcholki();

    void Rysuj() override;

    virtual void obroc(double kat, char kierunek)override;
    virtual void przesun(Wektor3D V)override;

    const Wektor3D & operator[] (int index) const { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }
    Wektor3D & operator[] (int index) { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }

};

#endif