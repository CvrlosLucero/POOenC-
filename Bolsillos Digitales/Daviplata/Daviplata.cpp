#include <iostream>
#include <string>

using namespace std;

class Daviplata{

    private:
        string numTelefono, Contrasena;
        int saldo;

    public:
        Daviplata(){}

        void setNumTelefono(string numTel){
            numTelefono = numTel;
        }

        string getNumTelefono(){
            return numTelefono;
        }

        void setContrasena(string contra){
            Contrasena = contra;
        }

        string getContrasena(){
            return Contrasena;
        }

        void setSaldo(int money){
            saldo = money;
        }

        int getSaldo(){
            return saldo;
        }

        void Recarga(){
            int eleccion;
            cout<<"Recarga de Daviplata:"<<endl;
            cout<<"¿Qué tipo de recarga necesita?\n(1) Para Puntos DaviPlata \n(2) Para cuentas Davivienda\n(3) Por giros nacionales o internacionales\n(4) Por cajero"<<endl;
            cin>>eleccion;
            //hacer metodos para las recargas y agregar a saldo.
            switch (eleccion){
                case 1:{}
                case 2:{}
                case 3:{}
                case 4:{}
                default:{}
            }
        }

        void pagos(){
            int eleccion1;
            cout<<"Pagos con Daviplata:"<<endl;
            
        }

        void movimientos(){
            int eleccion2;
            cout<<"¿Como quiere ver sus movimientos?\n(1) Para últimos 10.\n(2) Solo envíos\n(3) Solo recibidos\n(4) Todos sus movimientos"<<endl;
        }













};