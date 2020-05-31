#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "InterfejsRysowania.hh"
#include "MacierzOb.hh"

/*!
 * \brief Klasa opisujaca plaszczyzne
 */
class Plaszczyzna: public InterfejsRysowania
{
protected:

/*!
 * \brief wymiar X plaszczyzny
 */
    double m_wymiarX;

/*!
 * \brief wymiar Y plaszczyzny
 */
    double m_wymiarY;

/*!
 * \brief Wektor polozenia srodka plaszczyzny
 */
    Wektor3D m_punktPodstawowy;

/*!
 * \brief Macierz obrotu plaszczyzny
 */
    MacierzOb m_MacierzOrientacji;

/*!
 * \brief tablica punktow globalnych plaszczyzny
 */
    std::vector<std::vector<drawNS::Point3D>> m_punkty;

//===========================================================================================

public:

/*!
 * \brief Konstruktor bezparametryczny przykladowej plaszczyzny
 */
    Plaszczyzna():
        m_wymiarX(10), m_wymiarY(10), m_punktPodstawowy({0,0,0}), m_MacierzOrientacji()
    {
        //m_punkty.reserve(m_wymiarX*m_wymiarY);
        UstawPunktyGlobalnie();
    }

/*!
 * \brief Konstruktor prostopadloscianu
 * \param WymX wymiar x,
 * \param WymY wymiar y,
 * \param X wspolrzedna x,
 * \param Y wspolrzedna y,
 * \param Z wspolrzedna z,
 */
    Plaszczyzna(double wymX, double wymY, double X, double Y, double Z):
        m_wymiarX(wymX), m_wymiarY(wymY), m_punktPodstawowy({X,Y,Z}), m_MacierzOrientacji()
    {
        //m_punkty.reserve(m_wymiarX*m_wymiarY);
        UstawPunktyGlobalnie();
    }

/*!
 * \brief Metoda rysowania dziedziczona wirtualnie z klasy InterfejsRysowania 
 */
    void Rysuj()override;


/*!
 * \brief Metoda Ustawiania punktow plaszczyzny
 */
    void UstawPunktyGlobalnie();

/*!
 * \brief Metoda obracania plaszczyzny
 * \param kat kat obrou
 * \param kierunek os obrotu ( 'x' || 'y' || 'z' )
 */
    void obroc(double kat, char kierunek)
    {
        assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
        m_MacierzOrientacji*=MacierzOb(kat, kierunek);    
    }



};


#endif