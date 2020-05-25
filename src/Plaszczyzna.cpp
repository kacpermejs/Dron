#include "Plaszczyzna.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Plaszczyzna::UstawPunktyGlobalnie()
{
    double x=-0.5*m_wymiarX, y=-0.5*m_wymiarY;
    Wektor3D wek1;
    vector<Point3D> Temp; 

    for(int i=0; i<=m_wymiarX/5; ++i)
    {
        Temp.clear();
        for(int j=0; j<=m_wymiarY/5; ++j)
        {
            wek1=m_MacierzOrientacji*Wektor3D{x,y,0}+m_punktPodstawowy;
            //std::cout << wek1 << "|";
            Temp.push_back(Point3D(wek1[0],wek1[1],wek1[2]));
            y+=5;
            
        }
        //std::cout << i << "<- y \n";
        y=-0.5*m_wymiarX;
        x+=5;
        m_punkty.push_back(Temp);
    }
}

void Plaszczyzna::Rysuj()
{    
    api->draw_surface(m_punkty,"grey");
}