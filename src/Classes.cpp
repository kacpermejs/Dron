#include "Classes.hh"

void MacierzOb::UstawMacierzOb()
{
    switch (this->m_kierunek)
        {
        case 'x':
            MacierzKw
            {
                {1,0,0},
                {0,cos(m_kat),sin(m_kat)},
                {0,-sin(m_kat),cos(m_kat)}
            };
            break;
        case 'y':
            MacierzKw
            {
                {cos(m_kat),0,-sin(m_kat)},
                {0,1,0},
                {sin(m_kat),cos(m_kat), 0}
            };
            break;
        case 'z':
            MacierzKw
            {
                {cos(m_kat),sin(m_kat),0},
                {-sin(m_kat),cos(m_kat), 0},
                {0,0,1}
            };
            break;
        
        default:
            MacierzKw
            {
                {cos(m_kat),sin(m_kat),0},
                {-sin(m_kat),cos(m_kat), 0},
                {0,0,1}
            };
            break;
        }
}

void Prostopadloscian::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    api->draw_polyhedron(vector<vector<Point3D> >
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
      },
      "blue");//rysuje niebieski graniastosłup


}



void InterfejsDrona::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    Prostopadloscian P1;
    P1.Rysuj(api);
}