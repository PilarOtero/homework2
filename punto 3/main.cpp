#include "functions.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    int option;

    //Dentro de cada opción elegida, se despliega un nuevo menú
    cout << "--MENU--\nElija la operacion a realizar\n 1. Suma\n 2. Resta\n 3. Producto\n 4. OUT" << endl;
    cout << ">>";
    cin >> option;
    
    switch(option){
        case static_cast<int>(Options2:: sum):
            handle_options(Options2::sum);
            break;
        
        case static_cast<int>(Options2:: product):
            handle_options(Options2:: product);
            break;

        case static_cast<int>(Options2:: subtraction):
            handle_options(Options2:: subtraction);
            break;
        
        case static_cast<int>(Options2::OUT):
            cout << "Cerrando programa..." << endl;
            break;

        default:
            cout << "Opcion invalida. Ingrese nuevamente." << endl;

    }
}