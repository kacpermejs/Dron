#ifndef PROSTOPADLOSCIAN

#define PROSTOPADLOSCIAN

#include "Bryla.hh"

/*!
 * \brief Klasa opisujaca prostopadloscian
 * Dziedziczy z klasy Bryla.
 */
class Prostopadloscian:
    public Bryla
{
protected:

/*!
 * \brief Wektor3D wymiarow prostopadloscianu (x,y,z)
 */
    Wektor3D m_Wymiary; //(x,y,z)

/*!
 * \brief tablica std::vector obiektow Wektor3D zawierajaca lokalne wierzcholki
 */
    std::vector < Wektor3D > m_Wierzcholki=std::vector < Wektor<double, 3> >(8);

/*!
 * \brief Metoda ustawiania wierzcholkow w lokalnym ukladzie wspolrzednych
 * Tylko do konstruktora
 */
    void UstawWierzcholki();
//=================================================================================================================
public:

/*!
 * \brief Konstruktor bezparametryczny tworzacy przykladowy prostopadloscian
 */
    Prostopadloscian(): m_Wymiary{1,2,3}
    {
        UstawWierzcholki();
    }

/*!
 * \brief Konstruktor prostopadloscianu
 * \param WspX wspolrzedna x,
 * \param WspY wspolrzedna y,
 * \param WspZ wspolrzedna z,
 * \param WymX wymiar x,
 * \param WymY wymiar y,
 * \param WymZ wymiar z,
 */
    Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
    Bryla{WspX, WspY, WspZ}, m_Wymiary{WymX,WymY,WymZ}
    {
        
        UstawWierzcholki();
    }
/*!
 * \brief Konstruktor prostopadloscianu z opcją wspolrzednej jako Wektor3D
 * \param wek Wektor3D wspolrzednych polozenia srodka prostopadloscianu
 * \param WymX wymiar x,
 * \param WymY wymiar y,
 * \param WymZ wymiar z,
 */
    Prostopadloscian(Wektor3D wek, double WymX, double WymY, double WymZ):
    Bryla(wek), m_Wymiary{WymX,WymY,WymZ}
    {
        UstawWierzcholki();
    }

/*!
 * \brief Metoda rysowania dziedziczona wirtualnie z klasy Bryla 
 */
    void Rysuj() override;


/*!
 * \brief Metoda obracania dziedziczona wirtualnie z klasy Bryla 
 */
    virtual void obroc(double kat, char kierunek)override;

/*!
 * \brief Metoda przesuwania dziedziczona wirtualnie z klasy Bryla
 * \param V Wektor3D o ktory srodek sie przesuwa
 */
    virtual void przesun(Wektor3D V)override;

/*!
 * \brief Getter
 * \param index od 0 do 7
 */
    const Wektor3D & operator[] (int index) const { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

/*!
 * \brief Setter
 * \param index od 0 do 7
 */
    Wektor3D & operator[] (int index) { assert(index>=0 && index<8); return this->m_Wierzcholki[index]; }

};

#endif