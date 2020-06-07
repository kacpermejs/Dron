#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

class InterfejsDrona;

/*!
 * \brief Klasa abstrakcyjna do tworzenia przeszkod
 */
class Przeszkoda
{
public:
/*!
 * \brief Metoda czysto wirtualna sprawdzania kolizji
 */
    virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)=0;

/*!
 * \brief Metoda czysto wirtualna dla umozliwienia rysowania przeszkody
 */
    virtual void Rysuj()=0;
    
};




#endif