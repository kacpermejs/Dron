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

    Kolekcja_Dronow.push_back(std::shared_ptr<Dron>(new Dron()));
    Kolekcja_Dronow.push_back(std::shared_ptr<Dron>(new Dron(15,-15,8)));

    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(new PrzeszkodaProst(-10,-10,0,5,5,15) ) );
    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(new PrzeszkodaProst(10,10,0,5,5,15) ) );

    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(new Tafla(40, 40, 15) ) );
    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(new Dno(40, 40, -19) ) );

    char input='0';
    int numer_drona=0;

    for(auto elem: Kolekcja_Dronow)
    {
        elem->Rysuj();
    }
    std::cout << "Ilosc dronow: " << Kolekcja_Dronow.size() << "\n";
    for(auto elem: Kolekcja_Przeszkod)
    {
        elem->Rysuj();
    }
    
    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(Kolekcja_Dronow[0]));
    Kolekcja_Przeszkod.push_back(std::shared_ptr<Przeszkoda>(Kolekcja_Dronow[1]));

    while(input!='k')
    {
        system("clear");
        if(input=='d')
        {
            std::cout << "Ilosc dronow: " << Kolekcja_Dronow.size() << "\n";
            std::cout << "wybierz drona: ";
            std::cin >> numer_drona;
        }
        
            input=Kolekcja_Dronow[numer_drona]->Input();
            Kolekcja_Dronow[numer_drona]->Sterowanie();

            std::cout << "Aktualna liczba wektorow3D: " << Wektor3D::zwroc_aktualna_liczbe();
            std::cout << "\nCalkowita liczba wektorow3D: " << Wektor3D::zwroc_calkowita_liczbe() << "\n";

            Kolekcja_Dronow[numer_drona]->UI();
            Kolekcja_Dronow[numer_drona]->Usun();
            Kolekcja_Dronow[numer_drona]->Rysuj();
            

        
        for(auto elem: Kolekcja_Przeszkod)
        {
            
            if(elem==std::shared_ptr<Przeszkoda>(Kolekcja_Dronow[numer_drona]) )
            {
                Kolekcja_Dronow[numer_drona]->RejestrujBrakKolizji();
            }
            else if(elem->czy_kolizja(Kolekcja_Dronow[numer_drona]))
            {
                Kolekcja_Dronow[numer_drona]->RejestrujKolizje();
                break;
            }
            else
            {
                Kolekcja_Dronow[numer_drona]->RejestrujBrakKolizji();
            }
            
        }
        
        
        InterfejsRysowania::Odswiez();
        
        usleep(500000);
    }
}


/*
int main()
{
    Wektor3D wek1({1,2,3});
    Wektor3D wek2;
    Wektor3D *wsk_wek;

    cout << "Wektor 1: " << wek1 << endl;
    cout << "Wektor 2: " << wek2 << endl;
    cout << "Wektor wsk: " << wsk_wek << endl;

    while(1)
    {
        std::cout << "Aktualna liczba wektorow3D: " << Wektor3D::zwroc_aktualna_liczbe();
        std::cout << "\nCalkowita liczba wektorow3D: " << Wektor3D::zwroc_calkowita_liczbe() << "\n";
        wsk_wek=new Wektor3D(wek2+wek1);
        wek2=*wsk_wek;

        cout << "Wektor 1: " << wek1 << endl;
        cout << "Wektor 2: " << wek2 << endl;
        cout << "Wektor wsk: " << wsk_wek << endl;
        wait4key();
        delete wsk_wek;
    }
}
*/
/*
int main()
{
    Dron d1;

    d1.Rysuj();
    InterfejsRysowania::Odswiez();
    wait4key();
    wait4key();
}*/