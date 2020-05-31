#ifndef SRUBA_HH
#define SRUBA_HH

#include "Graniastoslup6.hh"

#define WYS_SRUBY 1
#define PR_SRUBY 1

/*!
 * \brief Klasa opisujaca sruby dla drona
 */
class Sruba: public Graniastoslup6
{
protected:

/*!
 * \brief Miejsce mocowania sruby
 */
    Wektor3D m_przes_mocowania;

/*!
 * \brief macierz obrotu o kacie mocowania sruby
 */
    MacierzOb m_orient_mocowania;

    double kat_obrotu_sruby;
//==============================================================================================================
public:
    Sruba()=delete;
/*!
 * \brief Konstruktor
 */
    Sruba(const Wektor3D pr_mocowania, MacierzOb or_mocowania):
        m_przes_mocowania(pr_mocowania), m_orient_mocowania(or_mocowania), kat_obrotu_sruby(0)
        
    {
        Graniastoslup6(m_przes_mocowania, WYS_SRUBY, PR_SRUBY);
    }
/*!
 * \brief Metoda krecenia sruba
 * \param kat obrotu
 * Zawsze w okol osi z
 */
    void krec(double kat);

/*!
 * \brief Metoda obracania miejsca polozenia sruby za ruchem drona
 */
    void obroc_z_dronem(MacierzOb nowa_orientacja_drona);

/*!
 * \brief Metoda przesuwania miejsca polozenia sruby za ruchem drona
 */
    void przesun_z_dronem(Wektor3D nowa_sr_drona, MacierzOb nowa_orientacja_drona);
};

#endif