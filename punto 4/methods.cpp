#include "main.h"
#include <iostream>

using namespace std;

double ask_money_sum(){
    double money;
    cout << "Ingrese la suma de dinero sobre la que se realizara la operacion>> ";
    cin >> money;
    
    return money;
}

bool set_money(double money){
    if (money > 0) return true;
    else{
        cout << "La suma de dinero debe ser positiva" << endl;
        return false;
    }
}

//CLASE BANKACCOUNT
//Constructor
BankAccount:: BankAccount(string owner, double balance): balance(balance), owner(owner) {}

//Getter
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

//Metodo para mostrar la informacion de la cuenta
void CajadeAhorro:: display_info(){
    quantity_display ++;
    if (quantity_display > 2){
        double new_balance = get_balance() - 20;
        set_balance(new_balance);

    }
    cout << "TITULAR CAJA DE AHORRO: " << owner << "\nBALANCE: $" << get_balance() << endl;
}

//Metodo de deposito
void CajadeAhorro:: deposit(){
    double deposit = ask_money_sum();
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
    if(set_money(extraction)){
        if (get_balance() >= extraction){
            set_balance(get_balance() - extraction);
            cout << "Se retiraron $" << extraction << " exitosamente.\nDINERO EN CAJA DE AHORRO: $" << get_balance() << endl;
        }
    }
    else{
        cout << "Fondos insuficientes en Caja de Ahorro." << endl;
    }
}


//CLASE CUENTA CORRIENTE
//Constructor
CuentaCorriente:: CuentaCorriente(string owner, double balance, CajadeAhorro* caja): BankAccount(owner, balance), cajadeahorro(caja){};

//Metodo para mostrar la informacion de la cuenta
void CuentaCorriente:: display_info(){
    cout << "TITULAR CUENTA CORRIENTE: " << owner << "\nBALANCE: $" << get_balance() << endl;
} 

//Metodo de deposito
void CuentaCorriente:: deposit(){
    double deposit = ask_money_sum();
    if (set_money(deposit)){
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
    if(set_money(extraction)){
        if (get_balance()>= extraction){
            set_balance(get_balance() - extraction);
            cout << "Se retiraron $" << extraction << " exitosamente\nDINERO EN CUENTA: $" << get_balance() << endl;
        }

        else {
            cout << "Fondos insuficientes en Cuenta Corriente. Se intentara extraer de la Caja de Ahorro.\n" << endl;
            
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
    



