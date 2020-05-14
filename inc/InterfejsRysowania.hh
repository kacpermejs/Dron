#ifndef INTERFEJS_RYSOWANIA

#define INTERFEJS_RYSOWANIA

#include "Dr3D_gnuplot_api.hh"

class InterfejsRysowania
{
protected:

    /*!
     * \brief Wskaznik na API gnuplota
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
     * \brief Usuwanie obiektu o zadanym numerze
     * \param numer - numer obiektu do usuniecia
     * Obiekt usuwa sie tylko z wykresu gnuplota
     * Urzywanie przy zmianie polozenia
     */
    static void Usun(int numer)
    {
        api->erase_shape(numer);
    }

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