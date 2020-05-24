#ifndef BRYLA

#define BRYLA

#include "MacierzOb.hh"
#include "InterfejsRysowania.hh"

/*!
 * \brief Klasa wirtualna do tworzenia obiektow 3D
 * 
 */
class Bryla: public InterfejsRysowania
{
protected:

    /*!
     * \brief Macierz obrotu obiektu wzgledem srodka
     */
    MacierzOb m_MacOrientacji;

    /*!
     * \brief Wektor polozenia srodka bryly 
     */
    Wektor3D m_WekPol; //wektor wspolrzednych srodka obiektu
public:

    /*!
    * \brief Konstruktor bezparametryczny tworzy bryle w punkcie (0,0,0)
    */
    Bryla(): m_WekPol{0,0,0} {}

    /*!
    * \brief Konstruktor przyjmujący obiekt klasy wektor
    * \param wek - Wektor wspolrzednych,
    */
    Bryla(Wektor3D wek): m_WekPol(wek) {}

    /*!
    * \brief Konstruktor przyjmujący 3 wspolrzedne
    * \param WspX - Wspolrzedna X,
    * \param WspY - Wspolrzedna Y,
    * \param WspZ - Wspolrzedna Z,
    */
    Bryla(double WspX, double WspY, double WspZ): m_WekPol{WspX, WspY, WspZ} {}

    /*!
    * \brief Setter
    * \param Wek2 - Wektor wspolrzednych,
    * Uzycie: O.SetWekPol({x,y,z});
    */
    void SetWekPol(Wektor3D Wek2) {this->m_WekPol=Wek2;}

    /*!
    * \brief Getter
    * \return WekPol - Wektor wspolrzednych (kopia),
    * Uzycie: O.SetWekPol({x,y,z});
    */
    const Wektor3D GetWekPol(){return this->m_WekPol;}

    /*!
    * \brief Getter dla macierzy obrotu
    * \param kierunek Ktora MacierzOb zwrocic 'x' || 'y' || 'z'
    * \return MacObX/MacObY/MacObZ - Macierz obrotu bryly zalezna od wybranego kierunku,
    */
    const MacierzKw<double, 3> GetMacierzObrotu()
    {
        return m_MacOrientacji;
    }

    /*!
    * \brief Setter dla macierzy obrotu
    * \param MacOb2 macierz ktora trzeba skopiowac
    */
    void SetMacierzObrotu(MacierzOb MacOb2)
    {
        m_MacOrientacji=MacOb2;
    }

    /*!
    * \brief Metoda wirtualna obracania bryly
    * \param kat Kat obrotu w stopniach,
    * \param kierunek W okol ktorej osi obracac (char) 'x' || 'y' || 'z',
    * Metoda czysto wirtualna do zdefiniowana w klasie dziedziczacej.
    */
    virtual void obroc(double kat, char kierunek)=0;

    /*!
    * \brief Metoda wirtualna przesuwania bryly
    * \param V Wektor przesuniecia
    * Metoda czysto wirtualna do zdefiniowana w klasie dziedziczacej.
    */
    virtual void przesun(Wektor3D V)=0;

};

#endif