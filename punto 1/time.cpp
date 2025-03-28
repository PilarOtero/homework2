#include "main.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

bool Time::validate_time (int h, int m, int s, string period){
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
void Time::sethour(int h){
    if (validate_time(h,0, 0, "a.m")){ 
        hours = h; 
    }
}

void Time::setminutes(int m){
    if (validate_time(1,m, 0, "a.m")){ 
        minutes = m; 
    }
}

void Time::setseconds(int s){
    if (validate_time(1,0,s, "a.m")){ 
        seconds = s;
    }
}

void Time::setperiod(string p){
    if (validate_time(1,0,0,p)){
        period = p;
    }
}

//Constructores 

//Sin parametros
Time:: Time (): hours(0), minutes(0), seconds(0), period("a.m") {}

//Ingresando hora
Time:: Time(int h): Time(){
    sethour(h);
}

//Ingresando hora y minutos
Time:: Time(int h, int m): Time(){
    sethour(h);
    setminutes(m);
}

//Ingresando hora, minutos y segundos
Time:: Time (int h, int m, int s): Time(){
    sethour(h);
    setminutes(m);
    setseconds(s);
}

//Ingresando hora, minutos, segundos y periodo
Time:: Time (int h, int  m, int s, string p) : Time(){
    sethour(h);
    setminutes(m);
    setseconds(s);
    setperiod(p);
}

//Getters 
int Time::gethours() {return hours; }
int Time::getminutes() {return minutes; }
int Time::getseconds(){ return seconds; }
string Time::getperiod(){ return period; }

//Metodos para visualizar los elementos por separado
void Time::display_hour(){ cout << "HORA: " << hours << "h "; }
void Time::display_minutes(){ cout << "MINUTOS: " << minutes << "m "; }
void Time::display_seconds(){ cout << "SEGUNDOS: " << seconds << "s "; }
void Time::display_period(){ cout << "PERIODO: " << period << endl; }

//Metodo para mostrar la hora en formato de 12hs
void Time::display_12hs_time(){
    //Imprimo con el formato HHh, MMm, SSs, a.m/p.m
    cout << setfill('0') << setw(2) << hours << "h";
    cout << setfill('0') << setw(2) << minutes << "m";
    cout << setfill('0') << setw(2) << seconds << "s";
    cout << " " << period << endl;
}

//Metodo para mostrar la hora en formato de 24hs
void Time::display_24hs_time(){
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