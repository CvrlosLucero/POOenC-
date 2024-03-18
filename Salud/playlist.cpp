#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class SpotifyJam {

public:
    list<string> listaGeneral;
    list<string> lista1;
    list<string> lista2;

public:

    void addListaGeneral(string song) {
        listaGeneral.push_back(song);
    }

    void addLista1(string song) {
        lista1.push_back(song);
    }

    void addLista2(string song) {
        lista2.push_back(song);
    }

    void removeLista1(string song) {
        lista1.remove(song);
    }

    void removeLista2(string song) {
        lista2.remove(song);
    }

    void removeListaGeneral(string song) {
        listaGeneral.remove(song);
    }

    void displayListaGeneral() {
        for (string song : listaGeneral) {
            cout << song << endl;
        }
    }

    void displayLista1() {
        for (string song : lista1) {
            cout << song << endl;
        }
    }

    void displayLista2() {
        for (string song : lista2) {
            cout << song << endl;
        }
    }

    void displayJam(){
        for (string song : lista1) {
            cout << song << endl;
        }

        for (string song : lista2) {
        cout << song << endl;
        }
    }
};

int main() {
    SpotifyJam spotifyJam;
    string song1, song2, song3;
    int eleccion, eleccion1;
    bool continuar = true;

    while(continuar==true){
        cout<<"Bienvenido a Spotify Jam, ¿Qué deseas hacer?.\n(1) Para agregar canciones a la Lista General\n(2) Para agregar canciones a la Lista 1.\n(3) Para agregar canciones a la Lista 2.\n(4) Mostrar el contenido de las listas.\n(5) Mostrar el Jam de Spotify.\n(6) Eliminar contenido de las listas."<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
                cout<<"Agrega canciones a la Lista General (ingresa 'X' para dejar de agregar): "<<endl;
                while(cin >> song1 && song1 != "X") {
                    spotifyJam.addListaGeneral(song1);
                }
                break;
            case 2:
            spotifyJam.displayListaGeneral();
            cout<<"Agrega canciones a la lista 1 de la Lista General (ingresa 'X' para dejar de agregar): "<<endl;
            while (cin >> song2 && song2 != "X") {
                if (find(spotifyJam.listaGeneral.begin(), spotifyJam.listaGeneral.end(), song2) != spotifyJam.listaGeneral.end()) {
                    spotifyJam.addLista1(song2);
                } else{
                    cout<<"La canción no está en la lista general. No se puede agregar a la lista 1."<<endl;
                    cout<<"Se añadirá a la Lista General. (ingresa X para salir)"<<endl;
                    spotifyJam.addListaGeneral(song2);
                }
            }
            break;
            case 3:
                spotifyJam.displayListaGeneral();
                cout<<"Agrega canciones a la lista 2 de la Lista General (ingresa 'X' para dejar de agregar): "<<endl;
                while (cin>>song3 && song3 != "X") {
                    if (find(spotifyJam.listaGeneral.begin(), spotifyJam.listaGeneral.end(), song3) != spotifyJam.listaGeneral.end()) {
                        spotifyJam.addLista2(song3);
                    }else{
                        cout<<"La canción no está en la Lista General. No se puede agregar a la lista 2."<<endl;
                        cout<<"Se añadirá a la Lista General. (ingresa X para salir)"<<endl;
                        spotifyJam.addListaGeneral(song3);
                    }
            }
            break;
            case 4:
                cout << "Lista General:" << endl;
                spotifyJam.displayListaGeneral();
                cout << "Lista 1:" << endl;
                spotifyJam.displayLista1();
                cout << "Lista 2:" << endl;
                spotifyJam.displayLista2();
                break;
            case 5:
                cout << "Jam:" << endl;
                spotifyJam.displayJam();
                break;
            case 6:
                cout<<"¿De que lista deseas eliminar canciones?\n(1) Para eliminar canciones de la Lista General.\n(2) Para eliminar canciones de la lista 1.\n(3) Para eliminar canciones de la lista 2."<<endl;
                cin>>eleccion1;
                if(eleccion1==1){
                    cout<<"¿Qué canción deseas eliminar?"<<endl;
                    spotifyJam.displayListaGeneral();
                    cin>>song1;
                    spotifyJam.removeListaGeneral(song1);
                }
                else if(eleccion1==2){
                    cout<<"¿Qué canción deseas eliminar?"<<endl;
                    spotifyJam.displayLista1();
                    cin>>song2;
                    spotifyJam.removeLista1(song2);
                    cout<<"Se ha eliminado la lista."<<endl;
                }else if(eleccion1==3){
                    cout<<"¿Qué canción deseas eliminar?"<<endl;
                    spotifyJam.displayLista2();
                    cin>>song3;
                    spotifyJam.removeLista2(song3);
                }
                break;
            default:
                cout<<"Opción no válida."<<endl;
                break;
        }
    }
    return 0;
}
//ordenar las los elementos de las listas por nombre (A-Z), por artista (Z-A) y por duración (1-3 minutos).