#ifndef BRYLA

#define BRYLA

#include "MacierzOb.hh"

class Bryla
{
protected:
    MacierzOb MacObX;
    MacierzOb MacObY;
    MacierzOb MacObZ;
    Wektor<double,3> WekPol; //wektor wspolrzednych srodka obiektu
public:
    /*!
    * \brief Konstruktor bezparametryczny tworzy bryle w punkcie (0,0,0)
    */
    Bryla(): WekPol{0,0,0} {}
    /*!
    * \brief Constructor
    * \param WspX - Wspolrzedna X,
    * \param WspY - Wspolrzedna Y,
    * \param WspZ - Wspolrzedna Z,
    */
    Bryla(double WspX, double WspY, double WspZ): WekPol{WspX, WspY, WspZ} {}

    /*!
    * \brief Setter
    * \param Wek2 - Wektor wspolrzednych,
    * Uzycie: O.SetWekPol({x,y,z});
    */
    void SetWekPol(Wektor<double,3> Wek2) {this->WekPol=Wek2;}
    /*!
    * \brief Getter
    * \return WekPol - Wektor wspolrzednych (kopia),
    * Uzycie: O.SetWekPol({x,y,z});
    */
    const Wektor<double,3> GetWekPol(){return this->WekPol;}
    /*!
    * \brief Getter dla macierzy obrotu
    * \param kierunek Ktora MacierzOb zwrocic 'x' || 'y' || 'z'
    * \return MacObX/MacObY/MacObZ - Macierz obrotu bryly zalezna od wybranego kierunku,
    */
    const MacierzKw<double, 3> GetMacierzObrotu(char kierunek);

    /*!
    * \brief Metoda obracania bryly
    * \param kat Kat obrotu w stopniach,
    * \param kierunek W okol ktorej osi obracac (char) 'x' || 'y' || 'z',
    * Metoda czysto wirtualna do zdefiniowana w klasie dziedziczacej.
    */
    virtual void obroc(double kat, char kierunek)=0;
    /*!
    * \brief Metoda przesuwania bryly
    * \param V Wektor przesuniecia
    * Metoda czysto wirtualna do zdefiniowana w klasie dziedziczacej.
    */
    virtual void przesun(Wektor<double,3> V)=0;

};

#endif