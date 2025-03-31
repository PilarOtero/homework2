#include "main.h"
#include <string>
#include <sstream>

using namespace std;

//CLASE ENTEROS
//Constructor
Entero:: Entero(int value): value(value) {}

//Metodo suma
Numero* Entero:: sum(const Numero& other){
    //Casteo el valor como Entero 
    const Entero& othernumber = dynamic_cast<const Entero&>(other);
    return new Entero(value + othernumber.value);
}

//Metodo producto
Numero* Entero:: product(const Numero& other){
    //Casteo el valor como Entero 
    const Entero& othernumber = dynamic_cast<const Entero&>(other);
    return new Entero(value * othernumber.value);
}

//Metodo resta
Numero* Entero:: subtraction(const Numero& other){
    //Casteo el valor como Entero 
    const Entero& othernumber = dynamic_cast<const Entero&>(other);
    return new Entero(value - othernumber.value);
}

//Metodo toString
string Entero:: toString(){return to_string(value);}


//CLASE REALES
//Constructor
Real:: Real(double value): value(value) {}

//Metodo suma
Numero* Real:: sum(const Numero& other){
    //Casteo el valor como Real 
    const Real& othernumber = dynamic_cast<const Real&>(other);
    return new Real(value + othernumber.value);
}

//Metodo producto
Numero* Real:: product(const Numero& other){
    //Casteo el valor como Real 
    const Real& othernumber = dynamic_cast<const Real&>(other);
    return new Real(value * othernumber.value);
}

//Metodo resta
Numero* Real:: subtraction(const Numero& other){
    //Casteo el valor como Real 
    const Real& othernumber = dynamic_cast<const Real&>(other);
    return new Real(value - othernumber.value);
}

//Metodo toString
string Real:: toString(){return to_string(value);}


//CLASE COMPLEJOS
//Constructor
Complejo:: Complejo(double re, double im): re(re), im(im) {}

//Metodo suma
Numero* Complejo:: sum(const Numero& other){
    //Casteo el valor como Complejo 
    const Complejo& othernumber = dynamic_cast<const Complejo&>(other);
    return new Complejo(re + othernumber.re, im + othernumber.im);
}

//Metodo producto
Numero* Complejo:: product(const Numero& other){
    //Casteo el valor como Complejo 
    const Complejo& othernumber = dynamic_cast<const Complejo&>(other);
    
    double real_part = re * othernumber.re - im * othernumber.im;
    double imaginary_part = re * othernumber.im + im * othernumber.re;
    return new Complejo(real_part, imaginary_part);
}

//Metodo resta
Numero* Complejo:: subtraction(const Numero& other){
    //Casteo el valor como Complejo 
    const Complejo& othernumber = dynamic_cast<const Complejo&>(other);
    return new Complejo(re - othernumber.re, im - othernumber.im);
}

//Metodo toString
string Complejo:: toString(){
    /*ostringstream me permite reescribir los valores como una cadena de caracteres (me permite controlar el formato al cambiar el signo de la 
    parte imaginaria) 
    */
    ostringstream oss;
    oss << re;

    if (im >= 0){
        oss << "+" << im << "i";
    }
    else{
        oss << "-" << abs(im) << "i";;
    }
    
    return oss.str();
}