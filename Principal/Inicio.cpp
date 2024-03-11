#include <iostream>
#include <math.h>
#include "../Salud/Persona.cpp"

using namespace std;

class Inicio{

    Persona carlitos;

};

int main(){

    Persona carlitos;
    int eleccion;
    bool bucle = true;

        while(bucle=true){
            cout<<"Sistema de peso ideal.\nElige que necesitas hacer: \n(1) Para pedir datos de la persona.\n(2) Para mostrar los datos pedidos de la persona.\n(3) Calcular si el peso es ideal.\n(4) Mostrar si la persona es mayor de edad."<<endl;
                cin>>eleccion;

            switch(eleccion){
                case 1:{
                    carlitos.pedirDatos();
                }
                case 2:{
                    carlitos.mostrarPersona();
                }
                case 3:{
                    carlitos.calcularImc();
                    
                    if(carlitos.calcularImc()=="PESOBAJO"){
                        cout<<"El peso está por debajo de lo ideal."<<endl;
                    }else if(carlitos.calcularImc()=="PESOIDEAL"){
                        cout<<"El peso es ideal."<<endl;
                    }else if(carlitos.calcularImc()=="SOBREPESO"){
                        cout<<"Tiene sobrepeso."<<endl;
                    }
                }
                case 4:{
                    carlitos.mayorEdad();
                }
                default:{
                    cout<<"Elección incorrecta."<<endl;
                    return main();
                }
             }
         }
    
    return 0;
}
