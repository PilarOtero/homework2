#include <string>
#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Numero {
    public:
        virtual ~Numero() = default;

        //Paso los valores con los que se va a hacer la operacion por referencia
        virtual Numero* sum(const Numero& other);
        virtual Numero* subtraction(const Numero& other);
        virtual Numero* product(const Numero& other);

        virtual string toString();
};

class Entero: public Numero{
    private:
        int value;
    
    public:
        //Constructor
        Entero(int value);

        //Metodos
        Numero* sum(const Numero& other) override;
        Numero* product(const Numero& other) override;
        Numero* subtraction(const Numero& other) override;

        string toString() override;
}; 

class Real: public Numero{
    private:
        double value;

    public:
        //Constructor
        Real(double value);

        //Metodos
        Numero* sum(const Numero& other) override;
        Numero* product(const Numero& other) override;
        Numero* subtraction(const Numero& other) override;

        string toString() override;

};


class Complejo: public Numero{
    private:
        double re;
        double im;

    public:
        //Constructor
        Complejo(double re, double im);

        //Metodos
        Numero* sum(const Numero& other) override;
        Numero* product(const Numero& other) override;
        Numero* subtraction(const Numero& other) override;

        string toString() override;

};
#endif