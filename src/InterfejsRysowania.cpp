#include "InterfejsRysowania.hh"
#include "RysowanieUstawienia.hh"

using drawNS::APIGnuPlot3D;

std::shared_ptr<drawNS::Draw3DAPI> InterfejsRysowania::api(new APIGnuPlot3D(-WYMIAR_X,WYMIAR_X,-WYMIAR_Y,WYMIAR_Y,-WYMIAR_Z,WYMIAR_Z,ODSWIEZANIE));

void InterfejsRysowania::Usun()
{
    api->erase_shape(m_Numer);
}