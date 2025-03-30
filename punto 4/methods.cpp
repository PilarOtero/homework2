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
string ask_owner(){
    string owner;
    cout << "Ingrese el nombre del titular de la cuenta>> ";
    cin >> owner;

    return owner;
}

double ask_initial_balance(){
    double initial_balance;
    cout << "Ingres el balance inicial de la cuenta>> ";
    cin >> initial_balance;

    return initial_balance;
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
    double balance = get_balance();
    if (quantity_display > 2){
        balance -=20;
    }
    cout << "TITULAR CUENTA CORRIENTE: " << owner << "\nBALANCE: $" << balance << endl;
}

//Metodo de deposito
void CajadeAhorro:: deposit(){
    double deposit = ask_money_sum();
    if (set_money(deposit)){
        set_balance(get_balance() + deposit);
        cout << "El deposito de $" << deposit << " se ha realizado correctamente.\nDINERO EN CUENTA: $" << get_balance() << endl;
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
            cout << "Se retiraron $" << extraction << " exitosamente.\nDINERO EN CUENTA: $" << get_balance() << endl;
        }
    }
    else{
        cout << "Fondos insuficientes en Caja de Ahorro." << endl;
    }
}


//CLASE CUENTA CORRIENTE
//Constructor
CuentaCorriente:: CuentaCorriente(string owner, double balance): BankAccount(owner, balance) {}

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
            //VER ESTOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
            cout << "Fondos insuficientes en Cuenta Corriente. Se intentara extraer de la Caja de Ahorro.\n" << endl;
            
            CajadeAhorro* saved_money = new CajadeAhorro(owner,get_balance());
            saved_money->extract();
    
            delete saved_money;
        }
    }
}
    



