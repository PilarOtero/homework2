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
        BankAccount(string owner, double balance);
        
        //Metodos
        virtual void deposit() = 0;
        virtual void extract() = 0;
        ;
};

class CajadeAhorro: public BankAccount{
    private:
        double balance;
        int quantity_display = 0;
        void display_info() override;
    
    protected:
        string owner;
    
        public:
        //Constructor
        CajadeAhorro(string owner, double balance);
        
        //Metodos
        void deposit() override;
        void extract() override;

};

class CuentaCorriente: public BankAccount{
    friend class CajadeAhorro;

    private:
        double balance;
        void display_info() override;

    public:
        string owner;

    public:
        //Constructor
        CuentaCorriente(string owner, double balance);

        //Metodos 
        void deposit() override;
        void extract() override;
};

#endif