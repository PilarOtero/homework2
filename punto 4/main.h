#include <string>

#ifndef MAIN_H
#define MAIN_H
using namespace std;

class BankAccount{
    private:
        double balance;

    protected:
        string owner;

    public:
        //Constructor
        BankAccount(string owner, double balance);

        virtual void display_info() = 0;
        
        //Getter
        double get_balance();
        string get_owner();

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
    
        public:
        //Constructor
        CajadeAhorro(string owner, double balance);
        void display_info() override;

        
        //Metodos
        void deposit() override;
        void extract() override;

};

class CuentaCorriente: public BankAccount{
    friend class CajadeAhorro;

    private:
        CajadeAhorro * cajadeahorro;


    public:
        //Constructor
        CuentaCorriente(string owner, double balance, CajadeAhorro* caja);

        void display_info() override;

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
    OUT,
};

#endif
