#include "Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

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
      }, "blue");//rysuje niebieski graniastosłup

    return numer;

}