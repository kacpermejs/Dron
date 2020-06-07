#ifndef PRZESZKODA_PROST_HH
#define PRZESZKODA_PROST_HH

#define MarginesPrzeszkodyProst 0.1

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"
#include "InterfejsDrona.hh"


/*!
 * \brief Klasa modelujaca prostopadloscienna przeszkode
 */
class PrzeszkodaProst: public Prostopadloscian, public Przeszkoda
{

public:
/*!
 * \brief Konstruktor przeszkody prostopadlosciennej
 * \param WspX wspolrzedna x polozenia srodka
 * \param WspY wspolrzedna y polozenia srodka
 * \param WspZ wspolrzedna z polozenia srodka
 * \param WymX wymiar x przeszkody
 * \param WymY wymiar y przeszkody
 * \param WymZ wymiar z przeszkody
 */
    PrzeszkodaProst(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
        Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ)
    {}



/*!
 * \brief Metoda sprawdzania kolizji
 * \param D wskaznik na interfejs drona
 */
    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)override;

/*!
 * \brief Metoda rysowania przeszkody
 */
    void Rysuj()override;
};


#endif