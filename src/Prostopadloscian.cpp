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

int Prostopadloscian::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    std::vector < Wektor<double, 3> > Wierzcholki;
    Wierzcholki.reserve(8);
    for(unsigned int ind=0; ind < 8; ++ind)
    {
        Wierzcholki[ind]=MacOrientacji*m_Wierzcholki[ind]+WekPol;
    }
    int numer=api->draw_polyhedron(vector<vector<Point3D> >
    {
        {
            drawNS::Point3D(Wierzcholki[0][0], Wierzcholki[0][1], Wierzcholki[0][2]),
            drawNS::Point3D(Wierzcholki[1][0], Wierzcholki[1][1], Wierzcholki[1][2]),
            drawNS::Point3D(Wierzcholki[3][0], Wierzcholki[3][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[2][0], Wierzcholki[2][1], Wierzcholki[2][2])
        },
        {   
            drawNS::Point3D(Wierzcholki[4][0], Wierzcholki[4][1], Wierzcholki[4][2]),
            drawNS::Point3D(Wierzcholki[5][0], Wierzcholki[5][1], Wierzcholki[5][2]),
            drawNS::Point3D(Wierzcholki[7][0], Wierzcholki[7][1], Wierzcholki[7][2]),
            drawNS::Point3D(Wierzcholki[6][0], Wierzcholki[6][1], Wierzcholki[6][2])
	    }
      }, "blue");//rysuje niebieski Prostopadloscian

    return numer;

}

void Prostopadloscian::obroc(double kat, char kierunek)
{
    assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
    MacOrientacji*=MacierzOb(kat, kierunek);    
}

void Prostopadloscian::przesun(Wektor<double,3> V)
{
    WekPol+=V;
}