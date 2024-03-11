#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Nequi{

    private:
        string numTelefono, Contrasena;
        int saldo;

    public:
        Nequi(){}

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




        //estructura de datos para los usuarios y contraseñas
        /*
        
        
        
        
        
        
        
        
        
        
        */

        bool acceso(){

            cout<<"Bienvenido a Nequi."<<endl;
            cout<<"Ingrese su número de telefono: "<<endl;
            cin>>numTelefono;
            cout<<"Ingrese su contraseña: "<<endl;
            cin>>Contrasena;

            //validaciones de ingreso correcto de sesión
            return true;
        }

        void Recarga(){
            int eleccion;
            cout<<"Recarga de Nequi:"<<endl;
            cout<<"¿Qué tipo de recarga necesita?\n(1) Para Efectivo\n(2) Para Bancos [PSE]\n(3) Por código"<<endl;
            cin>>eleccion;
            //hacer metodos para las recargas y agregar a saldo.
            switch (eleccion){
                case 1:{}
                case 2:{}
                case 3:{}
                default:{}
            }
        }

        void colchon(){
            //hacer verificaciones 
            int recargaColchon;
            cout<<"Colchon de Nequi:"<<endl;
            cout<<"¿Cuanto vas a meter en el colchon?"<<endl;
            cin>>recargaColchon;
            saldo += recargaColchon;
        }

        void meta(){
            string nombreMeta;
             int diaMeta, mesMeta, ahorro;
            cout<<"Meta de nequi:"<<endl;
            cout<<"Ingresa el nombre de la meta a lograr: "<<endl;
                cin>>nombreMeta;
            cout<<"Ingresa el día para lograr tu meta: "<<endl;
                cin>>diaMeta;
            cout<<"Ingresa el mes para lograr tu meta: "<<endl;
                cin>>mesMeta;
            cout<<"Ingresa la cantidad para ahorrar: "<<endl;
                cin>>ahorro;
                //crear funcionalidad
        }

        void bolsillos(){

        }

        void sacarPlata(){
            cout<<"Saca tu plata de Nequi:"<<endl;
            cout<<"Opciones para sacar:\n(1) Por cajero\n(2) Por Punto Físico"<<endl;
            cin<<eleccion2;
            //crear funcionalidad
            switch(eleccion2){
                case 1:{}
                case 2:{}
                default:{}
            }
        }

        void movimientos(){
            int eleccion3;
            cout<<"Movimientos de Nequi:"<<endl;
            cout<<"¿Como quiere ver sus movimientos?\n(1) Para últimos 10.\n(2) Solo recarga.\n(3) Solo colchon.\n(4) Solo Meta.\n(4) Solo Bolsillos.\n(5) Solo retiros.\n(6) Todos sus movimientos."<<endl;
            //crear funcionalidad
            switch(eleccion3){
                case 1:{}
                case 2:{}
                case 3:{}
                case 4:{}
                case 5:{}
                case 6:{}
                default:{}
            }
        }















};