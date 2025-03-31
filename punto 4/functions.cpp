#include "methods.cpp"
#include <iostream>

using namespace std;

bool handle_options(Options cuentaocaja){
    string owner = "Juan Tomatis";
    double initial_balance_caja = 200000;
    double initial_balance_cuenta = 180000;

    CajadeAhorro caja(owner, initial_balance_caja);
    CuentaCorriente cuenta(owner, initial_balance_cuenta, &caja);

    int option;

    cout << "\nIngrese la operacion a realizar\n 1. Depositar dinero\n 2. Extraer dinero\n 3. Ver informacion de la cuenta\n" << endl;
    cin >>option;

    switch(option){
        //Dentro de cada switch, opero sobre el menu interactivo que se desprende para cada opcion.
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
    return false;
}