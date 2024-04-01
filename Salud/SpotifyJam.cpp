#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Song {
    public:
        string nombre;
        string artista;
        int duracion;
    public:
        Song(const string& nombre = "", const string& artista = "", int duracion = 0)
        : nombre(nombre), artista(artista), duracion(duracion) {}

        friend istream& operator>>(istream& is, Song& song) {
            cout<<"Nombre: ";
                is>>song.nombre;
                if(song.nombre=="X"){
                    return is;
                }
            cout<<"Artista: ";
                is>>song.artista;
                if(song.artista=="X"){
                    return is;
                }
            cout<<"Duración: ";
                is>>song.duracion;
                if(song.duracion==0){
                    return is;
                }
            return is;
        }

        bool operator==(const Song& other) const {
            return nombre == other.nombre && artista == other.artista && duracion == other.duracion;
        }   
};

class Node {
    private:
    Song song;
    Node* next;

    public:
    Node(Song song, Node* next) : song(song), next(next) {}

    void setNext(Node* node) {
        next = node;
    }

    void setSong(Song song) {
        this->song = song;
    }

    Node* getNext(){
        return next;
    }
    Song getSong(){
        return song;
    }
};



class SpotifyJam {
    Node* jam;
public:
    list<Song> listaGeneral;
    list<Song> lista1;
    list<Song> lista2;

public:

    SpotifyJam() : jam(nullptr) {}

    void addListaGeneral(Song song) {  
        listaGeneral.push_back(song);
    }

    void addLista1(Song song) {
        lista1.push_back(song);
    }

    void addLista2(Song song) {
        lista2.push_back(song);
    }

    void removeLista1(Song song) {
        lista1.remove(song);
    }

    void removeLista2(Song song) {
        lista2.remove(song);
    }

    void removeListaGeneral(Song song) {
        listaGeneral.remove(song);
    }

    void displayListaGeneral() {
        for (Song song : listaGeneral) {
            cout<<"Nombre: "<<song.nombre<<", Artista: "<<song.artista<<", Duración: "<<song.duracion<<" minutos"<<endl;
        }
    }

    void displayLista1() {
        for (Song song : lista1) {
            cout<<"Nombre: "<<song.nombre<<", Artista: "<<song.artista<<", Duración: "<<song.duracion<<" minutos"<<endl;
        }
    }

    void displayLista2() {
        for (Song song : lista2) {
            cout<<"Nombre: "<<song.nombre<<", Artista: "<<song.artista<<", Duración: "<<song.duracion<<" minutos"<<endl;
        }
    }

    void createJam() {
        Node* tail = nullptr;
        for (Song song : lista1) {
            Node* newNode = new Node{song, nullptr};
            if (jam == nullptr) {
                jam = newNode;
            } else {
                tail->setNext(newNode);
            }
            tail = newNode;
        }
        for (Song song : lista2) {
            Node* newNode = new Node{song, nullptr};
            if (jam == nullptr) {
                jam = newNode;
            } else {
                tail->setNext(newNode);
            }
            tail = newNode;
        }
    }

    void displayJam() {
        Node* temp = jam;
        while (temp != nullptr) {
            Song song = temp->getSong();
            cout<<"Nombre: "<<song.nombre<<", Artista: "<<song.artista<<", Duración: "<<song.duracion<<" minutos"<<endl;
            temp = temp->getNext();
        }
    }

    void ordenarJamAZ(){
        Node* current = jam;
        while (current != nullptr) {
            Node* index = current->getNext();
            while (index != nullptr) {
                if (current->getSong().nombre > index->getSong().nombre) {
                    Song temp = current->getSong();
                    current->setSong(index->getSong());
                    index->setSong(temp);
                }
            index = index->getNext();
            }   
        current = current->getNext();
        }
    }

    void ordenarJamArtistaZA(){
        Node* current = jam;
        while (current != nullptr) {
            Node* index = current->getNext();
            while (index != nullptr) {
                if (current->getSong().artista < index->getSong().artista) {
                    Song temp = current->getSong();
                    current->setSong(index->getSong());
                    index->setSong(temp);
                }
                index = index->getNext();
            }
        current = current->getNext();
        }
    }

    void ordenarJamDuracion1a3() {
        Node* current = jam;
        while (current != nullptr) {
            Node* index = current->getNext();
            while (index != nullptr) {
                if (current->getSong().duracion >= 1 && current->getSong().duracion <= 3 && index->getSong().duracion >= 1 && index->getSong().duracion <= 3) {
                    if (current->getSong().duracion > index->getSong().duracion) {
                        Song temp = current->getSong();
                        current->setSong(index->getSong());
                        index->setSong(temp);
                    }
                }
            index = index->getNext();
            }
        current = current->getNext();
        }
    }

    void mostrarCancionesConA() {
        Node* current = jam;
        while (current != nullptr) {
            if (current->getSong().nombre[0] == 'a' || current->getSong().nombre[0] == 'A'){
                cout<<current->getSong().nombre<<endl;
            }
        current = current->getNext();
        }
    }

    void mostrarCancionesArtista(string artista) {
        Node* current = jam;
        while (current != nullptr) {
            if (current->getSong().artista == artista) {
                cout << current->getSong().nombre << std::endl;
            }
        current = current->getNext();
        }
    }

    void ordenarJamMasDe3Minutos() {
        Node* current = jam;
        while (current != nullptr) {
            Node* index = current->getNext();
            while (index != nullptr) {
                if (current->getSong().duracion > 3 && index->getSong().duracion > 3) {
                    if (current->getSong().duracion > index->getSong().duracion) {
                        Song temp = current->getSong();
                        current->setSong(index->getSong());
                        index->setSong(temp);
                    }
                }
            index = index->getNext();
            }
        current = current->getNext();
        }
    }
};

int main() {
    SpotifyJam spotifyJam;
    Song song1, song2, song3;
    int eleccion, eleccion1, eleccion2;
    bool continuar = true;

    while(continuar){
        cout<<"Bienvenido a Spotify Jam, ¿Qué deseas hacer?.\n(1) Para agregar canciones a la Lista General\n(2) Para agregar canciones a la Lista 1.\n(3) Para agregar canciones a la Lista 2.\n(4) Mostrar el contenido de las listas.\n(5) Mostrar el Jam de Spotify.\n(6) Eliminar contenido de las listas.\n(7) Ordenamientos de Jam."<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
                cout<<"Agrega canciones a la Lista General (ingresa 'X' o '0' (En duración) para dejar de agregar): "<<endl;
                while(cin >> song1 && song1.nombre != "X" && song1.artista != "X" && song1.duracion != 0) {
                    spotifyJam.addListaGeneral(song1);
                }
                break;
            case 2:
            spotifyJam.displayListaGeneral();
            cout<<"Agrega canciones a la lista 1 de la Lista General (ingresa 'X' o '0' (En duración) para dejar de agregar): "<<endl;
            while (cin >> song2 && song2.nombre != "X" && song2.artista != "X" && song2.duracion != 0) {
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
                cout<<"Agrega canciones a la lista 2 de la Lista General (ingresa 'X' o '0' (En duración) para dejar de agregar): "<<endl;
                while (cin>>song3 && song3.nombre != "X" && song3.artista != "X" && song3.duracion != 0) {
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
                spotifyJam.createJam();
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
            case 7:
                cout<<"Ordenamientos de las canciones en el Jam de Spotify.\n(1) Ordenar por nombre (A-Z).\n(2) Ordenar por artista (Z-A).\n(3) Ordenar por duración (1-3 minutos).\n(4) Canciones por la letra 'a'.\n(5) Canciones que pertenecen a un mismo artista.\n(6) Todas las canciones que duren más de 3 minutos."<<endl;
                cin>>eleccion2;
                switch(eleccion2){
                    case 1:{
                        spotifyJam.ordenarJamAZ();
                        cout<<"Se ha ordenado el Jam de Spotify por nombre (A-Z)."<<endl;
                        spotifyJam.displayJam();
                        break;
                    }
                    case 2:{
                        spotifyJam.ordenarJamArtistaZA();
                        cout<<"Se ha ordenado el Jam de Spotify por artista (Z-A)."<<endl;
                        spotifyJam.displayJam();
                        break;
                    }
                    case 3:{
                        spotifyJam.ordenarJamDuracion1a3();
                        cout<<"Se ha ordenado el Jam de Spotify por duración (1-3 minutos)."<<endl;
                        spotifyJam.displayJam();
                        break;
                    }
                    case 4:{
                        cout<<"Canciones que empiezan con la letra 'a':"<<endl;
                        spotifyJam.mostrarCancionesConA();
                        break;
                    }
                    case 5:{
                        string artista;

                        cout<<"Canciones que pertenecen a un mismo artista."<<endl;
                        cout<<"Ingresa el nombre del artista: ";
                        cin>>artista;
                        spotifyJam.mostrarCancionesArtista(artista);
                        break;
                    }
                    case 6:{
                        spotifyJam.ordenarJamMasDe3Minutos();
                        cout<<"Se ha ordenado el Jam de Spotify por duración (más de 3 minutos)."<<endl;
                        spotifyJam.displayJam();
                        break;

                    }
                    default:{
                        cout<<"Opción no válida."<<endl;
                        break;
                    }
                }
                break;
            default:
                cout<<"Opción no válida."<<endl;
                break;
        }
    }
    return 0;
}