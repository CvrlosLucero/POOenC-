#include <iostream>
#include <string>
#include "Persona.cpp"

using namespace std;

class Empleado:public Persona
{

    private:
        string cargo, departamento;
        int valorHora, horasTrabajadas, fechaNacimiento;
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
        void setFechaNacimiento(int birth){
            fechaNacimiento=birth;
        }
        int getFechaNacimiento(){
            return fechaNacimiento;
        }
        void calcularHonorarios(){
            double reteica=(valorHora*horasTrabajadas*0.00966);
            double honorarios = (valorHora*horasTrabajadas)- reteica;
        }
        void pedirDatos(){
            Persona::pedirDatos();
            cout<<"Ingrese el cargo en el que el empleado está: "<<endl;
            cin>>cargo;
            cout<<"Ingrese el departamento en el que el empleado está: "<<endl;
            cin>>departamento;
            cout<<"Ingrese el valor de la hora del empleado: "<<endl;
            cin>>valorHora;
            cout<<"Ingrese las horas trabajadas del empleado: "<<endl;
            cin>>horasTrabajadas;
            cout<<"Ingrese el año de nacimiento: "<<endl;
            cin>>fechaNacimiento;

        }
        string mayorEdad(int fechaNacimiento){
            
            this->fechaNacimiento=fechaNacimiento;

            int edad=2024-fechaNacimiento;

            if(edad<18){
                return "Es menor de edad.";
            }else{
                return "Es mayor de edad.";
            }
        }
};

int main(){
    Empleado juanita;
    juanita.pedirDatos();
    juanita.mayorEdad(juanita.getFechaNacimiento());
    juanita.calcularHonorarios();

    return 0;
}