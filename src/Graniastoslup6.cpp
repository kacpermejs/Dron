#include "Graniastoslup6.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Graniastoslup6::UstawWierzcholki()
    {
        Wektor<double,3> Przesuniecie;

        double kat=0;
        for(unsigned int i=0; i < 12; ++i)
        {
            if(i<6)
            {
                Przesuniecie=MacierzOb(kat, 'z')*Wektor<double,3>{m_promien,0,-1*(m_wysokosc)/2};
                kat+=60;
            }
            else
            {
                if(i==6)
                    kat=0;
                Przesuniecie=MacierzOb(kat, 'z')*Wektor<double,3>{m_promien,0,(m_wysokosc)/2};
                kat+=60;
            }
            
            m_Wierzcholki[i]=Przesuniecie;
        }
    }

void Graniastoslup6::Rysuj()
{
    std::vector < Wektor<double, 3> > Wierzcholki;
    Wierzcholki.reserve(12);

    for(unsigned int ind=0; ind < 12; ++ind)
    {
        Wierzcholki[ind]=m_MacOrientacji*m_Wierzcholki[ind]+m_WekPol;
        std::cout << Wierzcholki[ind] << "                        " <<ind << "\n";
    }
    
    m_Numer=this->api->draw_polyhedron(vector<vector<Point3D> >
    {
        {
            drawNS::Point3D(Wierzcholki[0][0], Wierzcholki[0][1], Wierzcholki[0][2]),
            drawNS::Point3D(Wierzcholki[1][0], Wierzcholki[1][1], Wierzcholki[1][2]),
            drawNS::Point3D(Wierzcholki[7][0], Wierzcholki[7][1], Wierzcholki[7][2]),
            drawNS::Point3D(Wierzcholki[6][0], Wierzcholki[6][1], Wierzcholki[6][2])
        },
        {
            drawNS::Point3D(Wierzcholki[1][0], Wierzcholki[1][1], Wierzcholki[1][2]),
            drawNS::Point3D(Wierzcholki[2][0], Wierzcholki[2][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[8][0], Wierzcholki[8][1], Wierzcholki[8][2]),
            drawNS::Point3D(Wierzcholki[7][0], Wierzcholki[7][1], Wierzcholki[7][2])
        },
        {
            drawNS::Point3D(Wierzcholki[2][0], Wierzcholki[2][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[3][0], Wierzcholki[3][1], Wierzcholki[2][2]),
            drawNS::Point3D(Wierzcholki[9][0], Wierzcholki[9][1], Wierzcholki[9][2]),
            drawNS::Point3D(Wierzcholki[8][0], Wierzcholki[8][1], Wierzcholki[8][2])
        },
        {
            drawNS::Point3D(Wierzcholki[3][0], Wierzcholki[3][1], Wierzcholki[2][2]),
            drawNS::Point3D(Wierzcholki[4][0], Wierzcholki[4][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[10][0], Wierzcholki[10][1], Wierzcholki[10][2]),
            drawNS::Point3D(Wierzcholki[9][0], Wierzcholki[9][1], Wierzcholki[9][2]) 
        },
        {
            drawNS::Point3D(Wierzcholki[4][0], Wierzcholki[4][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[5][0], Wierzcholki[5][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[11][0], Wierzcholki[11][1], Wierzcholki[11][2]),
            drawNS::Point3D(Wierzcholki[10][0], Wierzcholki[10][1], Wierzcholki[10][2])

        },
        {
            drawNS::Point3D(Wierzcholki[5][0], Wierzcholki[5][1], Wierzcholki[3][2]),
            drawNS::Point3D(Wierzcholki[0][0], Wierzcholki[0][1], Wierzcholki[0][2]),
            drawNS::Point3D(Wierzcholki[6][0], Wierzcholki[6][1], Wierzcholki[6][2]),
            drawNS::Point3D(Wierzcholki[11][0], Wierzcholki[11][1], Wierzcholki[11][2])
        }
      }, "red");//rysuje niebieski Prostopadloscian

    //return numer;

}

void Graniastoslup6::obroc(double kat, char kierunek)
{
    assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
    m_MacOrientacji*=MacierzOb(kat, kierunek);    
}

void Graniastoslup6::przesun(Wektor<double,3> V)
{
    m_WekPol+=V;
}