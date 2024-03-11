#include <iostream>
#include <math.h>
#include "../Salud/Persona.cpp"
#include "../Salud/Empleado.cpp"

using namespace std;

class Inicio{

    Persona carlitos;

};

int main(){

    Persona carlitos;
    Empleado juanita;
    int eleccion;
    bool bucle = true;

        while(bucle){
            cout<<"Sistema de peso ideal.\nElige que necesitas hacer: \n(1) Para pedir datos de la persona.\n(2) Para mostrar los datos pedidos de la persona.\n(3) Calcular si el peso es ideal.\n(4) Mostrar si la persona es mayor de edad."<<endl;
                cin>>eleccion;

            switch(eleccion){
                case 1:{
                    carlitos.pedirDatos();
                    break;
                }
                case 2:{
                    carlitos.mostrarPersona();
                    break;
                }
                case 3:{
                    double imc=carlitos.calcularImc();
                    cout<<"entro al 3"<<endl;
                    if(imc<20){
                        cout<<"El peso está por debajo de lo ideal."<<endl;
                    }else if(imc<=20 && imc>=25){
                        cout<<"El peso es ideal."<<endl;
                    }else if(imc>25){
                        cout<<"Tiene sobrepeso."<<endl;
                    }
                    break;
                }
                case 4:{
                    carlitos.mayorEdad();
                    break;
                }
                default:{
                    cout<<"Elección incorrecta."<<endl;
                    return main();
                }
             }
         }
    
    return 0;
}
