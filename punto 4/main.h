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
        
        //Getter
        double get_balance();
        string get_owner();
        void get_info();

        //Setter
        void set_balance(double balance);

        //Metodos
        virtual void deposit() = 0;
        virtual void extract() = 0;
        ;
};

class CajadeAhorro: public BankAccount{
    private:
        int quantity_display = 0;
        void display_info() override;
    
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
        void display_info() override;
        CajadeAhorro * cajadeahorro;


    public:
        //Constructor
        CuentaCorriente(string owner, double balance, CajadeAhorro* caja);

        //Metodos 
        void deposit() override;
        void extract() override;
};

enum class Options{
    cuentacorriente = 1,
    cajadeahorro,
    OUT,
};

enum class Options2{
    deposit = 1,
    extract,
    info,
};

#endif
