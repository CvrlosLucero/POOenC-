#include <iostream>
#include <string>
#include "Persona.cpp"

using namespace std;

class Empleado:public Persona
{

    private:
        string cargo, departamento;
        int valorHora, horasTrabajadas;
    public:

        void setCargo(string carge){
            cargo = carge;
        }
        string getCargo(){
            return cargo;
        }
        void setDepartamento(string depa){
            departamento = depa;
        }
        string getDepartamento(){
            return departamento;
        }
        void setValorHora(int hourValue){
            valorHora=hourValue;
        }
        int getValorHora(){
            return valorHora;
        }
        void setHorasTrabajadas(int hoursWorked){
            horasTrabajadas=hoursWorked;
        }
        int getHorasTrabajadas(){
            return horasTrabajadas;
        }


};

int main(){
    Empleado juanita;
    juanita.pedirDatos();
    cout<<juanita.getApellido();
}