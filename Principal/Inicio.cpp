#include <iostream>
#include <math.h>
#include "Persona.cpp"

using namespace std;

class Inicio{
    Persona user;

};

int main(){

    Persona carlitos;
    
    if(carlitos.calcularImc()=="PESOBAJO"){
        cout<<"El peso está por debajo de lo ideal."<<endl;
    }else if(carlitos.calcularImc()=="PESOIDEAL"){
        cout<<"El peso es ideal."<<endl;
    }else if(carlitos.calcularImc()=="SOBREPESO"){
        cout<<"Tiene sobrepeso."<<endl;
    }
   
    return 0;
}