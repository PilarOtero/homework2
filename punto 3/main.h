#include <fstring>

class Number {
    public:
        virtual ~Number() = default;

        //Paso los valores con los que se va a hacer la operacion por referencia
        virtual Number* sum(const Number& other);
        virtual Number* susbtraction(const Number& other);
        virtual Number* product(const Number& other);
        virtual Number division(const Number& other);

        virtual string toString();
}