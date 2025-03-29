#include <string>

#ifndef MAIN_H
#define MAIN_H
using namespace std;

class BankAccount{
    private:
        double balance;
        virtual void display_info() = 0;

    protected:
        string owner;

    public:
        //Constructor
        BankAccount(string owner, double initial_balance): balance(initial_balance), owner(owner) {};
        
        //Metodos
        virtual void deposit(double money) = 0;
        virtual void extract(double money) = 0;
        ;
};

#endif;