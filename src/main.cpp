#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <Dibujo.hpp>
#include <Archivo.hpp>
#include <thread>
#include <list>
#include <experimental/random>
using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{
    Archivo zelda("./images/zelda.txt");
    Archivo link("./images/link.txt");
    list<Dibujo> dibujos;
   
    for (size_t i = 0; i < 20; i++)
    {
        Dibujo d = zelda.CrearDibujo();
        d.EstablecerPosicion(
            experimental::randint(0,5),
            experimental::randint(0,5)
        );
        dibujos.push_back(d);
    }

    
    

    auto Pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Full()
    );

    while(true){
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        for (auto &&i : dibujos)
        {
            i.DesplazarX(experimental::randint(-1,1));
            i.DesplazarY(experimental::randint(-1,1));
        }

       
        for (auto &&i : dibujos)
        {
            i.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout<<Pantalla.ResetPosition();          
    }

    return 0;
}