#include "Plaszczyzna.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Plaszczyzna::UstawPunktyGlobalnie()
{
    double x=-1*m_wymiarX,y=m_wymiarY;
    Wektor<double,3> Temp;
    for(int i=0; i<m_wymiarX; ++i)
    {
        for(int j=0; j<m_wymiarY; ++j)
        {
            Temp=m_MacierzOrientacji*Wektor<double,3>{x,y,0}+m_punktPodstawowy;
            m_punkty[i].push_back(Point3D(Temp[0], Temp[1], Temp[2]));
        }
    }
}

void Plaszczyzna::Rysuj()
{
    
    api->draw_surface(m_punkty,"grey");
}