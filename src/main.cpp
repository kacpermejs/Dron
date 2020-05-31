#include <iostream>
#include <unistd.h>

#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "Dno.hh"
#include "Tafla.hh"
#include "PrzeszkodaProst.hh"


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

int main()
{
    //std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-20,20,-20,20,-20,20,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
    
    //Prostopadloscian D1;
    vector<std::shared_ptr<Dron>> Kolekcja_Dronow;
    vector<std::shared_ptr<Przeszkoda>> Kolekcja_Przeszkod;

    Kolekcja_Dronow.push_back(std::shared_ptr<Dron>(std::make_shared<Dron>()));

    Tafla woda(40, 40, 15);
    Dno podloze(40, 40, -19);

    PrzeszkodaProst klocek(10,10,0,5,5,15);

    char input='0';

    for(auto elem: Kolekcja_Dronow)
        {
            elem->Rysuj();
        }

    woda.Rysuj();
    podloze.Rysuj();
    klocek.Rysuj();
    

    while(input!='k')
    {
        //system("clear");
        
        for(auto elem: Kolekcja_Dronow)
        {
            input=elem->Input();
            elem->Sterowanie();
            elem->UI();
            elem->Usun();
            elem->Rysuj();

            

            if( podloze.czy_kolizja(elem) || woda.czy_kolizja(elem) || klocek.czy_kolizja(elem))
            {
                elem->RejestrujKolizje();
            }
            else
            {
                elem->RejestrujBrakKolizji();
            }
            
            
            
        }
        
        
        InterfejsRysowania::Odswiez();
        
        usleep(50000);
    }
}


/*
int main()
{
    Prostopadloscian G1;
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




}*/
