#include <iostream>
#include <list>
#include <string>

using namespace std;

class SpotifyJam {
    list<string> lista1;
    list<string> lista2;

public:
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
    string song1, song2;
    int eleccion, eleccion1;
    bool continuar = true;

    while(continuar==true){
        cout<<"Bienvenido a Spotify Jam, ¿Qué deseas hacer?.\n(1) Para agregar canciones a la Lista 1.\n(2) Para agregar canciones a la Lista 2.\n(3) Mostrar el contenido de las 2 playlists.\n(4) Mostrar el Jam de Spotify.\n(5) Eliminar contenido de las listas."<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
                cout<<"Agrega canciones a la lista 1 (ingresa 'X' para dejar de agregar): "<<endl;
                while(cin >> song1 && song1 != "X") {
                    spotifyJam.addLista1(song1);
                }
                break;
            case 2:
                cout<<"Agrega canciones a la lista 2 (ingresa 'X' para dejar de agregar): "<<endl;
                while(cin >> song2 && song2 != "X") {
                    spotifyJam.addLista2(song2);
                }
                break;
            case 3:
                cout << "Playlist 1:" << endl;
                spotifyJam.displayLista1();
                cout << "Playlist 2:" << endl;
                spotifyJam.displayLista2();
                break;
            case 4:
                cout << "Jam:" << endl;
                spotifyJam.displayJam();
                break;
            case 5:
                cout<<"¿De que lista deseas eliminar canciones?\n(1) Para eliminar canciones de la lista 1.\n(2) Para eliminar canciones de la lista 2."<<endl;
                cin>>eleccion1;
                if(eleccion1==1){
                    cout<<"¿Qué canción deseas eliminar?"<<endl;
                    spotifyJam.displayLista1();
                    cin>>song1;
                    spotifyJam.removeLista1(song1);
                    cout<<"Se ha eliminado la lista."<<endl;
                }else if(eleccion1==2){
                    cout<<"¿Qué canción deseas eliminar?"<<endl;
                    spotifyJam.displayLista2();
                    cin>>song2;
                    spotifyJam.removeLista2(song2);
                }
                break;
            default:
                cout<<"Opción no válida."<<endl;
                break;
        }
    }
    return 0;
}