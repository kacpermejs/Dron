#include "Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Prostopadloscian::UstawWierzcholki()
    {
        double mx,my,mz;
        Wektor3D Przesuniecie;
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
            m_Wierzcholki[i]=Przesuniecie;
        }
    }

void Prostopadloscian::Rysuj()
{
    std::vector < Wektor<double, 3> > WierzcholkiGlobalne;
    WierzcholkiGlobalne.reserve(8);
    
    for(unsigned int ind=0; ind < 8; ++ind)
    {
        WierzcholkiGlobalne[ind]=m_MacOrientacji*m_Wierzcholki[ind]+m_WekPol;
    }
    
    m_Numer=this->api->draw_polyhedron(vector<vector<Point3D> >
    {
        {
            drawNS::Point3D(WierzcholkiGlobalne[0][0], WierzcholkiGlobalne[0][1], WierzcholkiGlobalne[0][2]),
            drawNS::Point3D(WierzcholkiGlobalne[1][0], WierzcholkiGlobalne[1][1], WierzcholkiGlobalne[1][2]),
            drawNS::Point3D(WierzcholkiGlobalne[3][0], WierzcholkiGlobalne[3][1], WierzcholkiGlobalne[3][2]),
            drawNS::Point3D(WierzcholkiGlobalne[2][0], WierzcholkiGlobalne[2][1], WierzcholkiGlobalne[2][2])
        },
        {   
            drawNS::Point3D(WierzcholkiGlobalne[4][0], WierzcholkiGlobalne[4][1], WierzcholkiGlobalne[4][2]),
            drawNS::Point3D(WierzcholkiGlobalne[5][0], WierzcholkiGlobalne[5][1], WierzcholkiGlobalne[5][2]),
            drawNS::Point3D(WierzcholkiGlobalne[7][0], WierzcholkiGlobalne[7][1], WierzcholkiGlobalne[7][2]),
            drawNS::Point3D(WierzcholkiGlobalne[6][0], WierzcholkiGlobalne[6][1], WierzcholkiGlobalne[6][2])
	    }
      }, "blue");//rysuje niebieski Prostopadloscian

    //return numer;

}

void Prostopadloscian::obroc(double kat, char kierunek)
{
    assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
    m_MacOrientacji*=MacierzOb(kat, kierunek);    
}

void Prostopadloscian::przesun(Wektor3D V)
{
    m_WekPol+=V;
}