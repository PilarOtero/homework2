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
        bool isValid = true;
        string error;
    
        // Validar horas
        if (h < 1 || h > 12) {
            error += "Hora invalida. Debe estar entre 1 y 12.\n";
            isValid = false;
        }
    
        // Validar minutos
        if (m < 0 || m >= 60) {
            error += "Minutos invalidos. Deben estar entre 0 y 59.\n";
            isValid = false;
        }
    
        // Validar segundos
        if (s < 0 || s >= 60) {
            error += "Segundos invalidos. Deben estar entre 0 y 59.\n";
            isValid = false;
        }
    
        // Validar periodo (a.m o p.m)
        if (period != "a.m" && period != "p.m") {
            error += "Periodo invalido. Debe ser 'a.m' o 'p.m'.\n";
            isValid = false;
        }
    
        //Imprimo los errores (si hay)
        if (!isValid) {
            cout << error;
        }
    
        return isValid;
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
    void display_hour(){ cout << "HORA: " << hours << "h "; }

    void display_minutes(){ cout << "MINUTOS: " << minutes << "m "; }

    void display_seconds(){ cout << "SEGUNDOS: " << seconds << "s "; }

    void display_period(){ cout << "PERIODO: " << period << endl; }

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

        if (period == "p.m" && hours != 12){
            hours24 += 12;
        }
        //Si la hora es 12, en reloj de 24hs pasa a ser 0
        else if (period == "a.m" && hours == 12){
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
    //m,
    h_m,
    //s,
    h_m_s,
    h_m_s_p,
    clock12hs,
    clock24hs,
    OUT,
};

#endif