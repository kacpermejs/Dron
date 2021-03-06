#ifndef INTERFEJS_RYSOWANIA

#define INTERFEJS_RYSOWANIA

#include "Dr3D_gnuplot_api.hh"

class InterfejsRysowania
{
protected:

    /*!
     * \brief Wskaznik na API gnuplota
     * definicja parametrow wyswietlania w pliku RysowanieUstawienia.hh
     */
    static std::shared_ptr<drawNS::Draw3DAPI> api;

    /*!
     * \brief Numer narysowanego obiektu
     */ 
    int m_Numer;
public:

    /*!
     * \brief Wirtualna metoda rysowania do zdefiniowana w klasie dziedziczacej
     */
    virtual void Rysuj() = 0;

    /*!
     * \brief Usuwanie (wymazywanie) obiektu z wykresu
     * Obiekt usuwa sie tylko z wykresu gnuplota
     * Uzywane przy zmianie polozenia
     */
    virtual void Usun();

    /*!
     * \brief Metoda odswiezania gnuplota
     * 
     */
    static void Odswiez()
    {
        api->redraw();
    }

    /*!
     * \brief Getter dla numeru rysunku
     * \return Numer narysowanego obiektu
     */
    const int GetNumer() const {return m_Numer;}
};

#endif