#include <iostream>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
        string period; //a.m o p.m;
    
        bool validate_time (int h, int m, int s, string period){
            return (h % 12 >= 1 && h % 12 < 12) && (m % 60 >= 0 && m % 60 < 60) && (s % 60 >= 0 && s % 60 < 60) && (period == "a.m" || period == "p.m");}

    public:
    //Constructores para inicializar en los casos pedidos

    //Sin parametros
    Time (): hours(0), minutes(0), seconds(0), period("a.m") {}
    //Pasandole hora
    Time(int h): Time() {if (validate_time(h,0, 0, "a.m")) hours = h; };
    //Pasandole hora y minutos
    Time(int h, int m): Time() {if (validate_time(h,m, 0, "a.m")) hours = h; minutes = m; }
    //Pasandole hora, minutos y segundos
    Time (int h, int m, int s): Time() {if (validate_time(h,m,s, "a.m")) hours = h; minutes = m; seconds = s; }
    //Pasandole hora, minutos, segundos y periodo
    Time (int h, int  m, int s, string p) : Time(){
        if (validate_time(h,m,s,period)){
            hours = h % 12;
            minutes = m % 60;
            seconds = s % 60;
            period = p;
        }
    }
};