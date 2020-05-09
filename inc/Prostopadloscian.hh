#ifndef PROSTOPADLOSCIAN

#define PROSTOPADLOSCIAN

#include "Bryla.hh"
#include "InterfejsRysowania.hh"


class Prostopadloscian:
    public Bryla, InterfejsRysowania
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

    void UstawWierzcholki()
    {
        double mx,my,mz;
        Wektor<double,3> Przesuniecie;
        for(unsigned int i=0; i<8; ++i)
        {
            if((i+1)%2==1)
                mx=-1;
            else
                mx=1;
            if((i+1)%4==3 || (i+1)%4==0)
                my=-1;
            else
                my=1;
            if(i<4)
                mz=-1;
            else
                mz=1;
            Przesuniecie={mx*m_Wymiary[0]/2, my*m_Wymiary[1]/2, mz*m_Wymiary[2]/2};
            m_Wierzcholki[i]=WekPol+Przesuniecie;
        }
    }

    int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;

    virtual void obroc(double kat, char kierunek)override
    {
        MacOb=MacierzOb{kat, kierunek};
        for(unsigned int ind=0; ind < 8; ++ind)
        {
            m_Wierzcholki[ind]=MacOb*(m_Wierzcholki[ind]-WekPol)+WekPol;
        }
    }
    const Wektor<double,3> & operator[] (int index) const { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }
    Wektor<double,3> & operator[] (int index) { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

};

#endif