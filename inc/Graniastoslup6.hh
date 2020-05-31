#ifndef GRANIASTOSLUP6
#define GRANIASTOSLUP6

#include "Bryla.hh"

/*!
 * \brief Klasa opisujaca graniastoslup prawidlowy szesciokatny
 * Dziedziczy z klasy Bryla.
 */
class Graniastoslup6: public Bryla
{
protected:
/*!
 * \brief wysokosc graniastoslupa
 */
    double m_wysokosc;

/*!
 * \brief odleglosc srodka podstawy od wierzcholka podstawy graniastoslupa
 */
    double m_promien;
/*!
 * \brief tablica std::vector obiektow Wektor3D zawierajaca lokalne wierzcholki
 */
    std::vector < Wektor<double, 3> > m_Wierzcholki=std::vector < Wektor<double, 3> >(12);

/*!
 * \brief Metoda ustawiania wierzcholkow w lokalnym ukladzie wspolrzednych
 * Tylko do konstruktora
 */
    void UstawWierzcholki();
//=================================================================================================================
public:
/*!
 * \brief Konstruktor bezparametryczny tworzacy przykladowy graniastoslup
 */
    Graniastoslup6(): m_wysokosc(1), m_promien(1)
    {
        UstawWierzcholki();
    }

/*!
 * \brief Konstruktor graniastoslupa
 * \param WspX wspolrzedna x,
 * \param WspY wspolrzedna y,
 * \param WspZ wspolrzedna z,
 * \param WymX wymiar x,
 * \param WymY wymiar y,
 * \param WymZ wymiar z,
 */
    Graniastoslup6(double WspX, double WspY, double WspZ, double Wysokosc, double Promien):
    Bryla{WspX, WspY, WspZ}, m_wysokosc(Wysokosc), m_promien(Promien)
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
    Graniastoslup6(Wektor3D wspolrzedne_sr, double Wysokosc, double Promien):
    Bryla(wspolrzedne_sr), m_wysokosc(Wysokosc), m_promien(Promien)
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
    const Wektor3D & operator[] (int index) const { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }

/*!
 * \brief Setter
 * \param index od 0 do 7
 */
    Wektor3D & operator[] (int index) { assert(index>=0 && index<12); return this->m_Wierzcholki[index]; }

};

#endif