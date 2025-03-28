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
    
        if (h < 1 || h > 12) {
            error += "Hora invalida. Debe estar entre 1 y 12.\n";
            isValid = false;
        }

        if (m < 0 || m >= 60) {
            error += "Minutos invalidos. Deben estar entre 0 y 59.\n";
            isValid = false;
        }
    
        if (s < 0 || s >= 60) {
            error += "Segundos invalidos. Deben estar entre 0 y 59.\n";
            isValid = false;
        }
    
        if (period != "a.m" && period != "p.m") {
            error += "Periodo invalido. Debe ser 'a.m' o 'p.m'.\n";
            isValid = false;
        }

        //Si el string error no esta vacio, hay errores. Genero un argumento invalido
        if (error != ""){
            throw invalid_argument(error);
        }
        
        return true;
    }
    
    //Setters
    void sethour(int h){
        if (validate_time(h,0, 0, "a.m")){ 
            hours = h; 
        }
    }

    void setminutes(int m){
        if (validate_time(1,m, 0, "a.m")){ 
            minutes = m; 
        }
    }

    void setseconds(int s){
        if (validate_time(1,0,s, "a.m")){ 
            seconds = s;
        }
    }

    void setperiod(string p){
        if (validate_time(1,0,0,p)){
            period = p;
        }
    }

    //Constructores para inicializar en los casos pedidos
    //Sin parametros
    Time (): hours(0), minutes(0), seconds(0), period("a.m") {}
    
    //Ingresando hora
    Time(int h): Time(){
        sethour(h);
    }
    
    //Ingresando hora y minutos
    Time(int h, int m): Time(){
        sethour(h);
        setminutes(m);
    }
    
    //Ingresando hora, minutos y segundos
    Time (int h, int m, int s): Time(){
        sethour(h);
        setminutes(m);
        setseconds(s);
    }
    
    //Ingresando hora, minutos, segundos y periodo
    Time (int h, int  m, int s, string p) : Time(){
        sethour(h);
        setminutes(m);
        setseconds(s);
        setperiod(p);
    }
    
    //Getters para obtener los valores por separado
    int gethours() {return hours; }
    int getminutes() {return minutes; }
    int getseconds(){ return seconds; }
    string getperiod(){ return period; }

    //Metodos para visualizar los elementos por separado
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

        //Actualizo hours para que se corresponda con la hora en el reloj de 24hs
        hours = hours24;

        //Imprimo con el formato HHh,MMm, SSs
        cout << setfill('0') << setw(2) << hours24 << "h";
        cout << setfill('0') << setw(2) << minutes << "m";
        cout << setfill('0') << setw(2) << seconds << "s" << endl;
    }

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