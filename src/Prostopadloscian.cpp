#include "Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Prostopadloscian::UstawWierzcholki()
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
            m_Wierzcholki[i]=Przesuniecie;
        }
    }

void Prostopadloscian::UstawGlobalne()
{
    
    for(unsigned int ind=0; ind < 8; ++ind)
    {
        m_WierzcholkiGlobalne[ind]=m_MacOrientacji*m_Wierzcholki[ind]+m_WekPol;
    }
}

void Prostopadloscian::Rysuj()
{
    
    UstawGlobalne();
    m_Numer=this->api->draw_polyhedron(vector<vector<Point3D> >
    {
        {
            drawNS::Point3D(m_WierzcholkiGlobalne[0][0], m_WierzcholkiGlobalne[0][1], m_WierzcholkiGlobalne[0][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[1][0], m_WierzcholkiGlobalne[1][1], m_WierzcholkiGlobalne[1][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[3][0], m_WierzcholkiGlobalne[3][1], m_WierzcholkiGlobalne[3][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[2][0], m_WierzcholkiGlobalne[2][1], m_WierzcholkiGlobalne[2][2])
        },
        {   
            drawNS::Point3D(m_WierzcholkiGlobalne[4][0], m_WierzcholkiGlobalne[4][1], m_WierzcholkiGlobalne[4][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[5][0], m_WierzcholkiGlobalne[5][1], m_WierzcholkiGlobalne[5][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[7][0], m_WierzcholkiGlobalne[7][1], m_WierzcholkiGlobalne[7][2]),
            drawNS::Point3D(m_WierzcholkiGlobalne[6][0], m_WierzcholkiGlobalne[6][1], m_WierzcholkiGlobalne[6][2])
	    }
      }, "blue");//rysuje niebieski Prostopadloscian

    //return numer;

}

void Prostopadloscian::obroc(double kat, char kierunek)
{
    assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
    m_MacOrientacji*=MacierzOb(kat, kierunek);    
}

void Prostopadloscian::przesun(Wektor<double,3> V)
{
    m_WekPol+=V;
}