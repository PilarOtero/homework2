#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
#ifndef MAIN_H
#define MAIN_H

class Time {
    private:

        int hours;
        int minutes;
        int seconds;
        string period; //a.m o p.m;

    public:

    bool validate_time (int h, int m, int s, string period){
        while (true){
            try{             
                if (h < 0 || h > 12){
                    throw invalid_argument("Hora invalida. Debe estar entre 1 y 12.");
                }

                if (m >= 60 || m < 0){
                    throw invalid_argument("Minutos invalidos. .");
                }
            
                if (s >= 60 || s < 0){
                    throw invalid_argument("Segundos invalidos. Ingrese nuevamente.");
                }

                if (period != "a.m" && period != "p.m"){
                    throw invalid_argument("Periodo invalido. Ingrese nuevamente.");
                }
            }
        catch(const invalid_argument &e){
            cout << e.what() << endl;
            return false;
        }
    return true;
    }  
} 

    //Constructores para inicializar en los casos pedidos
    //Sin parametros
    Time (): hours(0), minutes(0), seconds(0), period("a.m") {}
    
    //Ingresando hora
    Time(int h): Time(){
        if (validate_time(h,0, 0, "a.m")){ 
            hours = h; 
        }
    }
    
    //Ingresando hora y minutos
    Time(int h, int m): Time(){
        if (validate_time(h,m, 0, "a.m")){ 
            hours = h; 
            minutes = m; 
        }
    }
    
    //Ingresando hora, minutos y segundos
    Time (int h, int m, int s): Time(){
        if (validate_time(h,m,s, "a.m")){
            hours = h; 
            minutes = m; 
            seconds = s;
        }
    }
    
    //Ingresando hora, minutos, segundos y periodo
    Time (int h, int  m, int s, string p) : Time(){
        if (validate_time(h,m,s,p)){
            hours = h;
            minutes = m;
            seconds = s;
            period = p;
        }
    }
    
    //Metodos para obtener los valores por separado
    int get_hours() {return hours; }
    int get_minutes() {return minutes; }
    int get_seconds(){ return seconds; }
    string get_period(){ return period; }

    //Metodos para mostrar los datos por separado
    void display_hour(){ cout << hours << "h "; }

    void display_minutes(){ cout << minutes << "m "; }

    void display_seconds(){ cout << seconds << "s "; }

    void display_period(){ cout << period << endl; }

    //Metodo para mostrar la hora en formato de 12hs
    void display_12hs_time(){
        //Imprimo con el formato HHh, MMm, SSs, a.m/p.m
        cout << setfill('0') << setw(2) << hours << "h";
        cout << setfill('0') << setw(2) << minutes << "m";
        cout << setfill('0') << setw(2) << seconds << "s";
        cout << " " << period << endl;
    }

    //Metodo para mostrar la hora en formato de 24hs
    void display_24hs_time(){
        //Defino una variable auxiliar ya que hours es un atributo de la clase
        int hours24 = hours;

        if ( hours != 12){
            hours24 += 12;
        }
        //Si la hora es 12, en reloj de 24hs pasa a ser 0
        else if (hours == 12){
            hours24 = 0; 
        }
        //Imprimo con el formato HHh,MMm, SSs
        cout << setfill('0') << setw(2) << hours24 << "h";
        cout << setfill('0') << setw(2) << minutes << "m";
        cout << setfill('0') << setw(2) << seconds << "s" << endl;
    }

};

enum class Options {
    h = 1,
    h_m,
    h_m_s,
    h_m_s_p,
    clock12hs,
    clock24hs,
    OUT,
};

#endif