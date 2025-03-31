#include "functions.cpp"

int main(){
    int option;

        cout << "--MENU--\n 1. Operar sobre Cuenta Corriente\n 2. Operar sobre Caja de Ahorro\n 3. OUT" << endl;
        cin >> option;
        
        switch(option){
            case static_cast<int>(Options::cuentacorriente):
                handle_options(Options:: cuentacorriente);
                break;
            case static_cast<int>(Options::cajadeahorro):
                handle_options(Options:: cajadeahorro);
                break;
            case static_cast<int>(Options::OUT):
                cout << "Cerrando programa..." << endl;
                return false;
            default:
                cout << "Opcion invalida. Ingrese nuevamente." << endl;
        }
}


