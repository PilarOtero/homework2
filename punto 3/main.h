#include <string>
#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Numero {
    public:
        virtual ~Numero() = default;

        virtual Numero* sum(const Numero& other) = 0;
        virtual Numero* subtraction(const Numero& other) = 0;
        virtual Numero* product(const Numero& other) = 0;

        virtual string toString() = 0;
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

enum class Options{
    enteros = 1,
    reales,
    complejos,
};

enum class Options2{
    sum = 1,
    subtraction,
    product,
    OUT,
};

#endif