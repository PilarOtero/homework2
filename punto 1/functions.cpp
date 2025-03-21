#include <iostream>
#include <iomanip>

using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
        string period; //a.m o p.m;

        //Valido los valores
        bool validate_values(int h, int m, int s, string period){
            return (h >= 0 && h <= 12) && (m >=0 && m < 60) && (s >=0 && s < 60) && (period == "a.m" || period == "p.m")};

    public:
    //Constructores para inicializar en los casos pedidos

    //Sin parametros
    Time (): hours(0), minutes(0), seconds(0), period("a.m") {}
    Time(int h): Time() {if (validate_values(h, 0, 0, "a.m")) hours = h; };
    Time(int h, int m): Time(h) {if (validate_values(h,m, 0, "a.m")) minutes = m};
    }




