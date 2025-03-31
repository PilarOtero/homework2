#include "main.h"
#include <iostream>

using namespace std;

double ask_money_sum(){
    //Permito al usuario ingresar el dinero (ya sea para depositar o extraer)
    double money;
    cout << "Ingrese la suma de dinero sobre la que se realizara la operacion>> ";
    cin >> money;
    
    return money;
}

bool set_money(double money){
    //La suma de dinero no puede ser negativa
    if (money > 0) return true;
    else{
        cout << "La suma de dinero debe ser positiva" << endl;
        return false;
    }
}

//CLASE BANK ACCOUNT
//Constructor
BankAccount:: BankAccount(string owner, double balance): balance(balance), owner(owner) {}

//Getters
double BankAccount:: get_balance() {return balance; }
string BankAccount:: get_owner() {return owner; }
void BankAccount:: get_info(){display_info();}

//Setter
void BankAccount:: set_balance(double new_balance) {
    balance = new_balance;
}


//CLASE CAJA DE AHORRO
//Constructor
CajadeAhorro:: CajadeAhorro(string owner, double balance): BankAccount(owner, balance){}

//Metodo de deposito
void CajadeAhorro:: deposit(){
    double deposit = ask_money_sum();
    
    //Verifico que la cantidad ingresada sea positiva
    if (set_money(deposit)){
        set_balance(get_balance() + deposit);
        cout << "El deposito de $" << deposit << " se ha realizado correctamente.\nDINERO EN CAJA DE AHORRO: $" << get_balance() << endl;
    }
    else{
        cout << "No se pudo realizar la operacion" << endl;
    }
}

//Metodo de extraccion
void CajadeAhorro:: extract(){
    double extraction = ask_money_sum();
    
    //Verifico que la cantidad ingresada sea positiva
    if(set_money(extraction)){
        if (get_balance() >= extraction){
            //Actualizo el balance de la Caja de Ahorro en funcion del dinero retirado
            set_balance(get_balance() - extraction);
            cout << "Se retiraron $" << extraction << " exitosamente.\nDINERO EN CAJA DE AHORRO: $" << get_balance() << endl;
        }
    }
    else{
        cout << "Fondos insuficientes en Caja de Ahorro." << endl;
    }
}

//Metodo para mostrar la informacion de la cuenta
void CajadeAhorro:: display_info(){
    if (quantity_display > 2){
        set_balance(get_balance() - 20);
    }
    quantity_display ++;
    cout << "TITULAR CAJA DE AHORRO: " << owner << "\nBALANCE: $" << get_balance() << endl;
}


//CLASE CUENTA CORRIENTE
//Constructor -> inicializo la Cuenta Corriente tambien considerando la Caja de Ahorro para poder acceder 
CuentaCorriente:: CuentaCorriente(string owner, double balance, CajadeAhorro* caja): BankAccount(owner, balance), cajadeahorro(caja){};

//Metodo de deposito
void CuentaCorriente:: deposit(){
    double deposit = ask_money_sum();
    
    //Verifico que la cantidad ingresada sea positiva
    if (set_money(deposit)){
        //Actualizo el balance
        set_balance(get_balance() + deposit);
        cout << "El deposito de $" << deposit << " se ha realizado correctamente\nDINERO EN CUENTA: $" << get_balance()  << endl;
    }
    else{
        cout << "No se pudo realizar la operacion" << endl;
    }
}

//Metodo de retiro
void CuentaCorriente:: extract(){
    double extraction = ask_money_sum();
    
    //Verifico que la cantidad ingresada sea positiva
    if(set_money(extraction)){
        if (get_balance()>= extraction){
            //Actualizo el balance
            set_balance(get_balance() - extraction);
            cout << "Se retiraron $" << extraction << " exitosamente\nDINERO EN CUENTA: $" << get_balance() << endl;
        }

        else {
            cout << "Fondos insuficientes en Cuenta Corriente. Se intentara extraer de la Caja de Ahorro.\n" << endl;
            //Accedo a la caja de ahorro para ver si se puede retirar el dinero de esta
            if (cajadeahorro != nullptr){
                if (cajadeahorro->get_balance() >= extraction){
                    cajadeahorro->extract();
                }
            }
            else {
                cout << "No hay Caja de Ahorro asociada a esta Cuenta corriente" << endl;
            } 

        }
    }
}

//Metodo para mostrar la informacion de la cuenta
void CuentaCorriente:: display_info(){
    cout << "TITULAR CUENTA CORRIENTE: " << owner << "\nBALANCE: $" << get_balance() << endl;
} 
    



