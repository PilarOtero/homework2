#include <methods.cpp>

int main(){
    int option;

    cout << "Ingrese 1. Operar sobre Cuenta Corriente\n 2.Operar sobre caja de Ahorro\n 3. OUT" << endl;
    cin >> option;
    
    switch(option){

        case static_cast<int>(Options::OUT):
            cout << "Cerrando programa..." << endl;
            break;

        default:
            cout << "Opcion invalida. Ingrese nuevamente." << endl;
    }
}