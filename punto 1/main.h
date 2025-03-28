#include <string>
#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Time {
    private:

        int hours;
        int minutes;
        int seconds;
        string period; //a.m o p.m;

    public:

        bool validate_time (int h, int m, int s, string period);
             
        //Setters
        void sethour(int h);
        void setminutes(int m);
        void setseconds(int s);
        void setperiod(string p);
    
        //Constructores 
        Time ();
        Time(int h);
        Time(int h, int m);
        Time (int h, int m, int s);
        Time (int h, int  m, int s, string p);
    
        //Getters 
        int gethours();
        int getminutes();
        int getseconds();
        string getperiod();
    
        //Metodos para visualizar los elementos por separado
        void display_hour();
        void display_minutes();
        void display_seconds();
        void display_period();
    
        //Metodo para mostrar la hora en formato de 12hs
        void display_12hs_time();
    
        //Metodo para mostrar la hora en formato de 24hs
        void display_24hs_time();

};

enum class Options1 {
    h = 1,
    h_m,
    h_m_s,
    h_m_s_p,
    OUT,
};

enum class Options2 {
    clock12hs = 1,
    clock24hs,
};

#endif