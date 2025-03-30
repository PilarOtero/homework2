#include "methods.cpp"
#include <iostream>

using namespace std;

void handle_options(Options cuentaocaja){
    string owner = ask_owner();
    double initial_balance = ask_initial_balance();

    CuentaCorriente cuenta(owner, initial_balance);
    CajadeAhorro caja(owner, initial_balance);

    int option;

    cout << "Ingrese la operacion a realizar\n 1. Depositar dinero\n 2. Extraer dinero\n 3. Ver informacion de la cuenta." << endl;
    cin >>option;

    switch(option){
        case static_cast<int>(Options2::deposit):
            if (cuentaocaja == Options:: cuentacorriente){
                cuenta.deposit();
            }
            else if (cuentaocaja == Options:: cajadeahorro){
                caja.deposit();
            }
            break;

        case static_cast<int>(Options2::extract):
            if (cuentaocaja == Options:: cuentacorriente){
                cuenta.extract();
            }
            else if (cuentaocaja == Options:: cajadeahorro){
                caja.extract();
            }
            break;

        case static_cast<int>(Options2::info):
            if (cuentaocaja == Options:: cuentacorriente){
                cuenta.get_info();
            }
            else if (cuentaocaja == Options:: cajadeahorro){
                caja.get_info();
            }
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    
    }

}