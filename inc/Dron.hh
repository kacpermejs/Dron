#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"

#define WymiarXdrona 8
#define WymiarYdrona 4
#define WymiarZdrona 4
/*!
 * \brief Klasa opisujaca drona podwodnego
 */
class Dron: public InterfejsDrona, public Prostopadloscian
{
/*!
 * \brief Sruba lewa
 */
    Sruba L;
/*!
 * \brief Sruba prawa
 */
    Sruba P;
public:

/*!
 * \brief Konstruktor bezparametryczny z wymiarami zdefiniowanymi
 */
    Dron():
        Prostopadloscian(0,0,0,WymiarXdrona,WymiarYdrona,WymiarZdrona), 
        L(Wektor3D{-WymiarXdrona/2,WymiarYdrona/2,0}, MacierzOb(90, 'y')),
        P(Wektor3D{-WymiarXdrona/2,-WymiarYdrona/2,0}, MacierzOb(90, 'y'))
    {
        L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        L.obroc_z_dronem(m_MacOrientacji);
        P.obroc_z_dronem(m_MacOrientacji);
    }

/*!
 * \brief Konstruktor ustawiajacy tylko polozenie z wymiarami zdefiniowanymi
 * \param WspX wspolrzedna x,
 * \param WspY wspolrzedna y,
 * \param WspZ wspolrzedna z
 */
    Dron(double WspX, double WspY, double WspZ):
        Prostopadloscian(WspX, WspY, WspZ,WymiarXdrona,WymiarYdrona,WymiarZdrona), 
        L(Wektor3D{-WymiarXdrona/2,WymiarYdrona/2,0}, MacierzOb(90, 'y')),
        P(Wektor3D{-WymiarXdrona/2,-WymiarYdrona/2,0}, MacierzOb(90, 'y'))
    {
        L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        L.obroc_z_dronem(m_MacOrientacji);
        P.obroc_z_dronem(m_MacOrientacji);
    }

/*!
 * \brief Konstruktor z polozeniem i wymiarami do wyboru
 * \param WspX wspolrzedna x,
 * \param WspY wspolrzedna y,
 * \param WspZ wspolrzedna z,
 * \param WymX wymiar x,
 * \param WymY wymiar y,
 * \param WymZ wymiar z,
 */
    Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
        Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ),
        L(Wektor3D{-WymX/2,WymY/2,0}, MacierzOb(90, 'y')),
        P(Wektor3D{-WymX/2,-WymY/2,0}, MacierzOb(90, 'y'))
    {
        L.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        P.przesun_z_dronem(m_WekPol, m_MacOrientacji);
        L.obroc_z_dronem(m_MacOrientacji);
        P.obroc_z_dronem(m_MacOrientacji);
    }

/*!
 * \brief Metoda rysujaca calego drona ze srubami
 */
    void RysowaieDrona();

/*!
 * \brief Wymazujaca calego drona ze srubami
 */
    void WymazDrona();

/*!
 * \brief Metoda sterujaca dronem
 */
    void Sterowanie();
    
/*!
 * \brief Metoda realizujaca animacje plyniecia w kierunku x
 * \param odleglosc odleglosc jaka ma przeplynac dron
 * \param kat kat pod jakim plynie
 * Dron nie potrafi poruszac sie na boki liniowo
 * tylko na wprost.
 */
    void Plyn(double & odleglosc, double & kat);

/*!
 * \brief Metoda skrecania dronem na boki
 * \param kat kat obrotu
 */
    void Skrec(double & kat);

    //void AnimacjaWynurzania();
    //void AnimacjaZanurzania();
    //void PlynPrzod();
    //void PlynTyl();
    
    //void SkrecLewo();
    //void SkrecPrawo();
    
};

#endif