#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Persona{

    public:
        string tipoDoc, documento, nombre, apellido, sexo;
        double peso, estatura, edad;

Persona(){

};

    public:
        void pedirDatos(){
            cout<<"Ingrese el tipo de documento de la persona: "<<endl;
            cin>>tipoDoc;
            cout<<"Ingrese el N° de Documento: "<<endl;
            cin>>documento;
            cout<<"Ingrese el nombre de la persona: "<<endl;
            cin>>nombre;
            cout<<"Ingrese el apellido de la persona: "<<endl;
            cin>>apellido;
            cout<<"Ingrese el sexo de la persona (Masculino/Femenino): "<<endl;
            cin>>sexo;
            cout<<"Ingrese el peso de la persona (en Kg): "<<endl;
            cin>>peso;
            cout<<"Ingrese la estatura de la persona (en m)"<<endl;
            cin>>estatura;
            cout<<"Ingrese la edad de la persona: "<<endl;
            cin>>edad;
        }
        void mostrarPersona(){
            cout<<"Tipo de documento: "<<tipoDoc<<"\n"<<"N° de Documento: "<<documento<<"\n"<<"Nombre: "<<nombre<<"\n"<<"Apellido: "<<apellido<<"\n"<<"Sexo: "<<sexo<<"\n"<<"Peso: "<<peso<<"\n"<<"Estatura: "<<estatura<<"\n"<<"Edad: "<<edad<<endl;
        }

        void calcularImc(){
            double pesoActual = peso/pow(estatura,2);

            if(pesoActual<20){
                cout<<"El peso está por debajo de lo ideal."<<endl;
            }else if(pesoActual>=20 && pesoActual<=25){
                cout<<"El peso es ideal."<<endl;
            }else if(pesoActual>25){
                cout<<"Tiene sobrepeso."<<endl;
            }
        }
        void mayorEdad(){
            if(edad>18){
                cout<<"Es mayor de edad."<<endl;
            }else{
                cout<<"Es menor de edad."<<endl;
            }

        }

};

int main(){

    Persona carlitos;

    carlitos.pedirDatos();
    carlitos.mostrarPersona();
    carlitos.calcularImc();


    return 0;
}