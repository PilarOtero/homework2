#include "methods.cpp"
#include <iostream>

int askEntero(){
    int number;
    cout << "Ingrese el numero: ";
    cin >> number;

    return number;
}

double askReal(){
    double number;
    cout << "Ingrese el numero: ";
    cin >> number;

    return number;
}

void handle_enteros_sum(){
    int number1 = askEntero();
    int number2 = askEntero();

    //Uso constructor para castearlos como Enteros
    Entero entero1(number1);
    Entero entero2(number2);

    Numero* result = entero1.sum(entero2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_enteros_subtraction(){
    int number1 = askEntero();
    int number2 = askEntero();

    //Uso constructor para castearlos como Enteros
    Entero entero1(number1);
    Entero entero2(number2);

    Numero* result = entero1.subtraction(entero2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_enteros_product(){
    int number1 = askEntero();
    int number2 = askEntero();

    //Uso constructor para castearlos como Enteros
    Entero entero1(number1);
    Entero entero2(number2);

    Numero* result = entero1.product(entero2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_reales_sum(){
    double number1 = askReal();
    double number2 = askReal();

    //Uso constructor para castearlos como Enteros
    Real real1(number1);
    Real real2(number2);

    Numero* result = real1.sum(real2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_reales_subtraction(){
    double number1 = askReal();
    double number2 = askReal();

    //Uso constructor para castearlos como Enteros
    Real real1(number1);
    Real real2(number2);

    Numero* result = real1.subtraction(real2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_reales_product(){
    double number1 = askReal();
    double number2 = askReal();

    //Uso constructor para castearlos como Enteros
    Real real1(number1);
    Real real2(number2);

    Numero* result = real1.product(real2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_complejos_sum(){
    cout << "VALOR1\nParte Real>> ";
    double re1 = askReal();
    cout << "Parte Imaginaria>> ";
    double im1 = askReal();

    cout << "VALOR2\nParte Real>> ";
    double re2 = askReal();
    cout << "Parte Imaginaria>> ";
    double im2 = askReal();

    //Uso constructor para castearlos como Enteros
    Complejo complejo1(re1,im1);
    Complejo complejo2(re2,im2);

    Numero* result = complejo1.sum(complejo2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}


void handle_complejos_subtraction(){
    cout << "VALOR1\nIngrese la parte Real>> ";
    double re1 = askReal();
    cout << "Ingrese la parte Imaginaria>> ";
    double im1 = askReal();

    cout << "VALOR2\nIngrese la parte Real>> ";
    double re2 = askReal();
    cout << "Ingrese la parte Imaginaria>> ";
    double im2 = askReal();

    //Uso constructor para castearlos como Enteros
    Complejo complejo1(re1,im1);
    Complejo complejo2(re2,im2);

    Numero* result = complejo1.subtraction(complejo2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}


void handle_complejos_product(){
    cout << "VALOR1\nIngrese la parte Real>> ";
    double re1 = askReal();
    cout << "Ingrese la parte Imaginaria>> ";
    double im1 = askReal();

    cout << "VALOR2\nIngrese la parte Real>> ";
    double re2 = askReal();
    cout << "Ingrese la parte Imaginaria>> ";
    double im2 = askReal();

    //Uso constructor para castearlos como Enteros
    Complejo complejo1(re1,im1);
    Complejo complejo2(re2,im2);

    Numero* result = complejo1.product(complejo2);
    cout << "RESULTADO = " << result->toString() << endl;

    delete result;
}

void handle_options(Options2 operation){
    int option;

    cout << "Ingrese el conjunto de numeros sobre el que desea operar:\n 1. Enteros\n 2. Reales\n 3. Complejos\n" << endl;
    cout << ">>";
    cin >> option;

    switch(option){
        case static_cast<int>(Options:: enteros):
            if (operation == Options2:: sum){
                handle_enteros_sum();
            }
            else if (operation == Options2:: subtraction){
                handle_enteros_subtraction();
            }
            else if (operation == Options2:: product){
                handle_enteros_product();
            }
            break;

        case static_cast<int>(Options:: reales):
            if (operation == Options2:: sum){
                handle_reales_sum();
            }
            else if (operation == Options2:: subtraction){
                handle_reales_subtraction();
            }
            else if (operation == Options2:: product){
                handle_reales_product();
            }
            break;

        case static_cast<int>(Options:: complejos):
            if (operation == Options2:: sum){
                handle_complejos_sum();
            }
            else if (operation == Options2:: subtraction){
                handle_complejos_subtraction();
            }
            else if (operation == Options2:: product){
                handle_complejos_product();
            }
            break;
    }
}

