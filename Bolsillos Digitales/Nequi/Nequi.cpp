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
        }

        void bolsillos(){

        }

        void sacarPlata(){

        }

        void movimientos(){

        }















};