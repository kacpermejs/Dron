#ifndef SRUBA_HH
#define SRUBA_HH

#include "Graniastoslup6.hh"

class Sruba: public Graniastoslup6
{
protected:
    Wektor3D m_przes_mocowania;
    MacierzOb m_orient_mocowania;

    double kat_obrotu_sruby;
public:

    Sruba(const Wektor3D pr_mocowania, MacierzOb or_mocowania):
        m_przes_mocowania(pr_mocowania), m_orient_mocowania(or_mocowania), kat_obrotu_sruby(0)
        
    {
        Graniastoslup6(m_przes_mocowania, 1, 1);
    }

    void krec(double kat);

    void obroc_z_dronem(MacierzOb nowa_orientacja_drona);

    void przesun_z_dronem(Wektor3D nowa_sr_drona, MacierzOb nowa_orientacja_drona);
};

#endif