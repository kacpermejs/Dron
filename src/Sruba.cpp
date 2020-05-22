#include "Sruba.hh"

void Sruba::obroc_z_dronem(MacierzOb nowa_orientacja_drona)
{
    m_MacOrientacji=nowa_orientacja_drona * m_orient_mocowania;
    m_MacOrientacji*= MacierzOb(kat_obrotu_sruby, 'z');
}

void Sruba::przesun_z_dronem(Wektor3D nowa_sr_drona, MacierzOb nowa_orientacja_drona)
{
    m_WekPol=nowa_sr_drona + nowa_orientacja_drona * m_przes_mocowania;
}

void Sruba::krec(double kat)
{
    kat_obrotu_sruby+=kat;
    if(kat_obrotu_sruby>=360 || kat_obrotu_sruby<=-360)
        kat_obrotu_sruby=0;
}