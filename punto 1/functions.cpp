#include <fstream>
#include <iostream>
#include "main.h"

using namespace std;

void askHour(int &hour){
    cout << "Ingrese la hora\n>> ";
    string input;
    cin >> input;
    cin.ignore();
    
    hour = stoi(input);

}

void askMinutes(int &minutes){
    cout << "Ingrese los minutos\n>> ";
    string input;
    getline(cin, input);

    minutes = stoi(input);
}

void askSeconds(int &seconds){
    cout << "Ingrese los segundos\n>> ";
    string input;
    getline(cin, input);
    cin.ignore();
    seconds = stoi(input);
}

void askPeriod(string &p){
    cout << "Ingrese el periodo (a.m / p.m): ";
    cin >> p;
}

void askTime(int &h, int &m, bool with_minutes, int &s, bool with_seconds, string &p, bool with_period){
    askHour(h);
    if (with_minutes) askMinutes(m);
    if (with_seconds) askSeconds(s);
    if (with_period) askPeriod(p);
}

void ask_clock(int &h, int &m, bool with_minutes, int &s, bool with_seconds, string &p, bool with_period){
    Time time;
    int option;

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option;

    switch(option){
        case static_cast<int>(Options2:: clock12hs):
            time.set12hstime();
            time.sethour();
            if (with_minutes) time.setminutes();
            if (with_seconds) time.setseconds();
            if (with_period) time.setperiod();

            break;
        case static_cast<int>(Options2:: clock24hs):
            time = Time(h, m, s, p);
            time.set24hstime();

            time.sethour();
            if (with_minutes) time.setminutes();
            if (with_seconds) time.setseconds();

            break;
    }
}

void handle_h(int &h){
    Time time;
    string option;
    int option2;
    int m = 0, s = 0;
    string p = "a.m";
    
    askTime(h,m,false,s,false,p,false);
    time = Time(h);

    cout << "Desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askTime(h,m,false,s,false,p,false);
        time = Time(h);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.set12hstime();
            time.sethour();
            break;
        case static_cast<int>(Options2:: clock24hs):
            time.set24hstime();
            time.sethour();
            break;
    }
}

void handle_hm(int &h, int &m){
    Time time;
    string option;
    int option2;
    int s = 0;
    string p = "a.m";

    askTime(h,m,true,s,false,p,false);
    time = Time(h, m);

    cout << "Desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askTime(h,m,true,s,false,p,false);
        time = Time(h,m);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.set12hstime();
            
            time.sethour();
            time.setminutes();
            
            break;

        case static_cast<int>(Options2:: clock24hs):
            time.set24hstime();

            time.sethour();
            time.setminutes();

            break;
    }

}

void handle_hms(int &h, int &m, int &s){
    Time time;
    string option;
    int option2;
    string p = "a.m";

    askTime(h,m,true,s,true,p, false);
    time = Time(h, m,s);

    cout << "Desea desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askTime(h,m,true,s,true,p, false);
        time = Time(h,m,s);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.set12hstime();
            time.sethour();
            time.setminutes();
            time.setseconds();

            break;

        case static_cast<int>(Options2:: clock24hs):
            time.set24hstime();

            time.sethour();
            time.setminutes();
            time.setseconds();

            break;
    }

}


void handle_hmsp(int &h, int &m, int &s, string p){
    Time time;
    string option;

    askTime(h,m,true,s,true,p,true);
    time = Time(h, m,s, p);

    cout << "Desea desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askTime(h,m,true,s,true,p,true);
        time = Time(h,m,s,p);
    }

    ask_clock(h,m,true,s,true,p,true);

}



