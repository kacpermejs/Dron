#include <iostream>
#include <unistd.h>

#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"


using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;





void wait4key()
{
    do
    {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}
/*
int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}

*/


int main()
{
    //std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-20,20,-20,20,-20,20,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
    Dron D1;
    //Prostopadloscian D1;
    //Plaszczyzna P1(20,20,0,0,10);

    char input='0';
    D1.Rysuj();
    //P1.Rysuj();

	while(input!='k')
	{
		//InterfejsRysowania::Usun(D1.GetNumer());
		input=D1.Input();
		D1.Sterowanie();
		D1.RysowaieDrona();
		InterfejsRysowania::Odswiez();
		usleep(250);

	}
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
/*
#include "Graniastoslup6.hh"

int main()
{
    Prostopadloscian G1(0,0,0,10,5, 15);
    char input='0';
    G1.Rysuj();

    while(input!='k')
    {   
        if(kbhit())
        {
            InterfejsRysowania::Usun(G1.GetNumer());
            input=getchar();
            
            //G1.przesun({1,0,0});
            G1.Rysuj();
            G1.obroc(5, 'y');
            //wait4key();
            //G1.obroc(5, 'z');
            
            InterfejsRysowania::Odswiez();
        }

    }




}
*/