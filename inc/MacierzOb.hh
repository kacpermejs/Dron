#ifndef MACIERZ_OB

#define MACIERZ_OB

#include <cmath>
#include <vector>
#include "Macierz.hh"
#include "Wektor.hh"

#define PI 3.14159265

typedef Wektor<double,3> Wektor3D;
typedef MacierzKw<double,3> Macierz3D;

/*!
 * \brief Klasa dodajaca do Macierzy3D opcje Maciery obrotu
 */
class MacierzOb: public MacierzKw<double, 3>
{
public:
/*!
 * \brief Konstruktor bezparametryczny tworzy macierz obrotu o kacie 0
 */
    MacierzOb()
    {
        UstawMacierzOb(0,'z');
    }

/*!
 * \brief Konstruktor tworzacy macierz obrotu o kat w okol wybranej osi
 * \param kat kat obrotu w stopniach [deg]
 * \param kierunek os obrotu
 */
    MacierzOb(double kat, char kierunek)
    {
        UstawMacierzOb(kat, kierunek);
    }

/*!
 * \brief Konstruktor umozliwiajacy utworzenie macierzy obrotu kopiujac zwykla
 * \param Mac2 macierz do skopiowania
 */
    MacierzOb(Macierz3D Mac2)
    {
        UstawMacierz(Mac2);
    }

/*!
 * \brief Metoda ustawiajaca wartosci wmacierzy obrotu
 * Uzywana tylko w konstruktorze 
 */
    void UstawMacierzOb(double kat, char kierunek);
/*!
 * \brief Setter
 * \param kat kat obrotu w stopniach [deg]
 * \param kierunek os obrotu
 */
    void Set(double kat, char kierunek) {(*this)=MacierzOb(kat, kierunek);}

/*!
 * \brief Getter
 */
    const MacierzOb Get() const {return *this;}
    
};

#endif