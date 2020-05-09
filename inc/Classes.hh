#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "Macierz.hh"
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include <cmath>
#include <vector>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::sin;
using std::cos;

class InterfejsRysowania
{
public:
    virtual void Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;
};

class MacierzOb: public MacierzKw<double, 3>
{
protected:
    double m_kat;
    char m_kierunek;
public:
    MacierzOb():
        m_kat(0), m_kierunek('z')
    {
        UstawMacierzOb();
    }

    MacierzOb(double kat, char kierunek):
        m_kat(kat), m_kierunek(kierunek)
    {
        UstawMacierzOb();
    }

    void UstawMacierzOb();

    void Set(double kat, char kierunek) {(*this)=MacierzOb(kat, kierunek);}
    const MacierzOb Get() const {return *this;}
    
};

class Bryla
{
protected:
    MacierzOb MacOb;
    Wektor<double,3> WekPol; //wektor wspolrzednych srodka obiektu
public:
    Bryla(): WekPol{0,0,0} {}
    Bryla(double WspX, double WspY, double WspZ): WekPol{WspX, WspY, WspZ} {}

    void SetX(double x){this->WekPol[0]=x;}
    void SetY(double y){this->WekPol[1]=y;}
    void SetZ(double z){this->WekPol[2]=z;}

    const double GetX(){return this->WekPol[0];}
    const double GetY(){return this->WekPol[1];}
    const double GetZ(){return this->WekPol[2];}

    virtual void obroc(double kat, char kierunek)=0;

};

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

    void Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) override;

    virtual void obroc(double kat, char kierunek)override
    {
        MacOb=MacierzOb{kat, kierunek};
        for(unsigned int ind=0; ind < 8; ++ind)
        {
            m_Wierzcholki[ind]=MacOb*m_Wierzcholki[ind];
        }
    }
    const Wektor<double,3> & operator[] (int index) const { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }
    Wektor<double,3> & operator[] (int index) { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

};

class InterfejsDrona
{
protected:
    
public:
    void Sterowanie();
    void Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
};

class Dron: public InterfejsDrona, public Prostopadloscian
{
    
public:


};


#endif