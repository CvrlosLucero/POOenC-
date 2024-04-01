#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;

// Clase Usuario que contiene los atributos numTelefono, contrasena y saldo
class Usuario{
    private:
        string numTelefono;
        string contrasena;
        double saldo, colchon;
        int diaColchon, mesColchon, anoColchon;

    public:
        // Constructor que inicializa los atributos en vacío
        Usuario() {
            numTelefono = "";
            contrasena = "";
            saldo = 0.0;
        }
        // Constructor que inicializa los atributos con los valores ingresados
        Usuario(string num, string pass, double sal){
            numTelefono = num;
            contrasena = pass;
            saldo = sal;
        }
        // Getters y Setters
        string getNumTelefono(){
            return numTelefono;
        }

        string getContrasena(){
            return contrasena;
        }

        double getSaldo(){
            return saldo;
        }
        
        // Método que agrega un monto al saldo
        void agregarSaldo(double monto) {
            saldo += monto;
        }

        void establecerColchon(double cantidad, int dia, int mes, int ano) {
            if (cantidad < saldo) {
                colchon = cantidad;
                saldo -= cantidad;
                diaColchon = dia;
                mesColchon = mes;
                anoColchon = ano;
            } else {
                cout<<"La cantidad ingresada es mayor al saldo disponible."<<endl;
            }
        }

        void moverDineroColchonASaldo(int dia, int mes, int ano){
            if (dia == diaColchon && mes == mesColchon && ano == anoColchon) {
                saldo += colchon;
                colchon = 0;
            }else{
                cout<<"No se puede mover el dinero del colchón al saldo hasta la fecha especificada."<<endl;
            }
        }


};
/*
class Nequi{
    public:
        //Lista de usuarios
        vector<Usuario> usuarios;

        // Constructor que inicializa la lista de usuarios
        Nequi(){
        Usuario usuario1("3175349604", "8901", 1200000);
        Usuario usuario2("3001234567", "7890", 3500000);
        Usuario usuario3("3112345678", "5678", 700000);
        Usuario usuario4("3153456789", "9012", 990000);
        Usuario usuario5("3167890123", "6423", 5000);
        Usuario usuario6("3107482523", "0259", 6000000);

        usuarios.push_back(usuario1);
        usuarios.push_back(usuario2);
        usuarios.push_back(usuario3);
        usuarios.push_back(usuario4);
        usuarios.push_back(usuario5);
        usuarios.push_back(usuario6);
        }

        // Método que verifica si el número de teléfono y la contraseña ingresados coinciden con algún usuario
        bool acceso(){
            string numTelefono, contrasena;
            bool accesoConcedido = false;
            bool soloDigitos = true;

            cout<<"Bienvenido a Nequi."<<endl;
            cout<<"Ingrese su número de telefono: "<<endl;
                cin>>numTelefono;
            do{
                cout<<"Ingrese su contraseña: "<<endl;
                    cin>>contrasena;
                if (contrasena.length() != 4) {
                cout<<"La contraseña debe tener exactamente 4 caracteres."<<endl;
                }
                }while(contrasena.length() != 4);

            // Verificamos si el número de teléfono y la contraseña coinciden con algún usuario
            for (Usuario u : usuarios){
                if(numTelefono == u.getNumTelefono() && contrasena == u.getContrasena()){
                    accesoConcedido = true;
                    cout<<"Acceso concedido."<<endl;
                break;
            }
            
            }
            // Solo mostramos el mensaje de error si no se concedió el acceso
            if(accesoConcedido==false){
                cout<<"Número de teléfono o contraseña incorrectos."<<endl;
            }
        return accesoConcedido;
        }

        void Recarga(){
            Usuario u;
            int eleccion, eleccion1;
            double monto;
            cout<<"Recarga de Nequi:"<<endl;
            cout<<"¿Qué tipo de recarga necesita?\n(1) Para Efectivo\n(2) Para Bancos [PSE]\n(3) Por código"<<endl;
            cin>>eleccion;
            //hacer metodos para las recargas y agregar a saldo.
            switch (eleccion){
                case 1:{
                    cout<<"Ve a un Punto Nequi o Corresponsal Bancolombia."<<endl;
                }
                case 2:{
                    cout<<"Recarga por PSE."<<endl;
                    cout<<"Elige el banco para recargar:"<<endl;
                    cout<<"(1) Bancolombia\n(2) Davivienda\n(3) BBVA\n(4) Colpatria\n(5) AV Villas"<<endl;
                    cin>>eleccion1;
                    switch (eleccion1){
                        case 1:{
                            cout<<"Recarga por PSE en Bancolombia."<<endl;
                            cout<<"Ingrese el monto a recargar: "<<endl;
                                cin>>monto;
                            //Agregar monto a saldo
                            u.agregarSaldo(monto);
                            break;
                        }
                        case 2:{
                            cout<<"Recarga por PSE en Davivienda."<<endl;
                                cin>>monto;
                            //Agregar monto a saldo
                            u.agregarSaldo(monto);
                            break;
                        }
                        case 3:{
                            cout<<"Recarga por PSE en BBVA."<<endl;
                                cin>>monto;
                            //Agregar monto a saldo
                            u.agregarSaldo(monto);
                            break;
                        }
                        case 4:{
                            cout<<"Recarga por PSE en Colpatria."<<endl;
                                cin>>monto;
                            //Agregar monto a saldo
                            u.agregarSaldo(monto);
                            break;
                        }
                        case 5:{
                            cout<<"Recarga por PSE en AV Villas."<<endl;
                                cin>>monto;
                            //Agregar monto a saldo
                            u.agregarSaldo(monto);
                        }
                        default:{
                            cout<<"Opción no válida."<<endl;
                            break;
                        }
                    }

                }
                case 3:{
                    // Generar un código aleatorio de 12 caracteres
                    string codigo = "";
                    string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

                    random_device rd;
                    mt19937 generator(rd());

                    for(int i = 0; i < 12; i++) {
                        uniform_int_distribution<> distrib(0, caracteres.size() - 1);
                        codigo += caracteres[distrib(generator)];
                    }

                    // Generar un saldo aleatorio entre 10000 y 50000
                    uniform_int_distribution<> distribSaldo(10000, 50000);
                    double saldoAleatorio = distribSaldo(generator);

                    // Agregar el saldo aleatorio al saldo del usuario
                    u.agregarSaldo(saldoAleatorio);

                    cout<<"Se ha generado el código "<< codigo<<" con un saldo de "<<saldoAleatorio<<endl;
                    break;
                    }
                default:{
                    cout<<"Opción no válida."<<endl;
                    break;
                }
            }
        }

    
};

int main(){
    bool accesoConcedido = false;
    Nequi nequi;

    nequi.acceso();

    while(accesoConcedido==true){
        
    }
    return 0;
}
*/