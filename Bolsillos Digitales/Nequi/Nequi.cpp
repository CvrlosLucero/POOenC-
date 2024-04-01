#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

class Usuario{
    private:
        string numTelefono;
        string contrasena;
        double saldo;

    public:

        Usuario(string num, string pass, double sal){
            numTelefono = num;
            contrasena = pass;
            saldo = sal;
        }

        string getNumTelefono(){
            return numTelefono;
        }

        string getContrasena(){
            return contrasena;
        }

        double getSaldo(){
            return saldo;
        }


};

class Nequi{
    public:
        vector<Usuario> usuarios;
    public:
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
            cout<<"Ingrese su contraseña: " << endl;
            cin>>contrasena;
            if (contrasena.length() != 4) {
                cout << "La contraseña debe tener exactamente 4 caracteres." << endl;
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
};

int main(){
    Nequi nequi;

    nequi.acceso();
    return 0;
}