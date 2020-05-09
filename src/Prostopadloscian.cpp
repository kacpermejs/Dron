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
            m_Wierzcholki[i]=WekPol+Przesuniecie;
        }
    }

int Prostopadloscian::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    int numer=api->draw_polyhedron(vector<vector<Point3D> >
    {
        {
            drawNS::Point3D(m_Wierzcholki[0][0], m_Wierzcholki[0][1], m_Wierzcholki[0][2]),
            drawNS::Point3D(m_Wierzcholki[1][0], m_Wierzcholki[1][1], m_Wierzcholki[1][2]),
            drawNS::Point3D(m_Wierzcholki[3][0], m_Wierzcholki[3][1], m_Wierzcholki[3][2]),
            drawNS::Point3D(m_Wierzcholki[2][0], m_Wierzcholki[2][1], m_Wierzcholki[2][2])
        },
        {   
            drawNS::Point3D(m_Wierzcholki[4][0], m_Wierzcholki[4][1], m_Wierzcholki[4][2]),
            drawNS::Point3D(m_Wierzcholki[5][0], m_Wierzcholki[5][1], m_Wierzcholki[5][2]),
            
            drawNS::Point3D(m_Wierzcholki[7][0], m_Wierzcholki[7][1], m_Wierzcholki[7][2]),
            drawNS::Point3D(m_Wierzcholki[6][0], m_Wierzcholki[6][1], m_Wierzcholki[6][2])
	    }
      }, "blue");//rysuje niebieski Prostopadloscian

    return numer;

}

void Prostopadloscian::obroc(double kat, char kierunek)
{
    MacOb=MacierzOb{kat, kierunek};
    for(unsigned int ind=0; ind < 8; ++ind)
    {
        m_Wierzcholki[ind]=MacOb*(m_Wierzcholki[ind]-WekPol)+WekPol;
    }
}

void Prostopadloscian::przesun(Wektor<double,3> V)
{
    for(unsigned int ind=0; ind < 8; ++ind)
    {
        m_Wierzcholki[ind]+=V;
    }
    WekPol+=V;
}