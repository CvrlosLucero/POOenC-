#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Persona {
private:
    string tipoDoc, documento, nombre, apellido, sexo;
    double peso, estatura, edad;

public:
    Persona() {}

    void setTipoDoc(string tipo) {
        tipoDoc = tipo;
    }

    string getTipoDoc() const {
        return tipoDoc;
    }

    void setDocumento(string doc) {
        documento = doc;
    }

    string getDocumento() const {
        return documento;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    string getNombre() const {
        return nombre;
    }

    void setApellido(string ape) {
        apellido = ape;
    }

    string getApellido() const {
        return apellido;
    }

    void setSexo(string sex) {
        sexo = sex;
    }

    string getSexo() const {
        return sexo;
    }

    void setPeso(double p) {
        peso = p;
    }

    double getPeso() const {
        return peso;
    }

    void setEstatura(double e) {
        estatura = e;
    }

    double getEstatura() const {
        return estatura;
    }

    void setEdad(double ed) {
        edad = ed;
    }

    double getEdad() const {
        return edad;
    }

    void pedirDatos() {
        cout << "Ingrese el tipo de documento de la persona(C.C/T.I): " << endl;
        cin >> tipoDoc;
        cout << "Ingrese el N° de Documento: " << endl;
        cin >> documento;
        cout << "Ingrese el nombre de la persona: " << endl;
        cin >> nombre;
        cout << "Ingrese el apellido de la persona: " << endl;
        cin >> apellido;
        cout << "Ingrese el sexo de la persona (Masculino/Femenino): " << endl;
        cin >> sexo;
        cout << "Ingrese el peso de la persona (en Kg): " << endl;
        cin >> peso;
        cout << "Ingrese la estatura de la persona (en m)" << endl;
        cin >> estatura;
        cout << "Ingrese la edad de la persona: " << endl;
        cin >> edad;
    }

    void mostrarPersona() {
        cout << "Tipo de documento: " << tipoDoc << "\n"
             << "N° de Documento: " << documento << "\n"
             << "Nombre: " << nombre << "\n"
             << "Apellido: " << apellido << "\n"
             << "Sexo: " << sexo << "\n"
             << "Peso: " << peso << "\n"
             << "Estatura: " << estatura << "\n"
             << "Edad: " << edad << endl;
    }

    double calcularImc(){
        double pesoActual = peso / pow(estatura, 2);
            return pesoActual;
    }

    void mayorEdad() {
        if (edad > 18) {
            cout << "Es mayor de edad." << endl;
        } else {
            cout << "Es menor de edad." << endl;
        }
    }
};
