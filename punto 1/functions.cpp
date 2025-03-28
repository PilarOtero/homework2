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

void handle_h(int &h){
    Time time;
    string option;
    int option2;
    
    askHour(h);
    time = Time(h);

    cout << "Desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askHour(h);
        time = Time(h);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.display_12hs_time();
            time.display_hour();
            break;
        case static_cast<int>(Options2:: clock24hs):
            string p;
            askPeriod(p);
            time = Time(h, 0, 0, p);
            time.display_24hs_time();
            //VER POR QUE SE IMPRME LA HORA AM
            time.display_hour();
            break;
    }
}

void handle_hm(int &h, int &m){
    Time time;
    string option;
    int option2;

    askHour(h);
    askMinutes(m);
    time = Time(h, m);

    cout << "Desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askHour(h);
        askMinutes(m);
        time = Time(h,m);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.display_12hs_time();
            time.display_hour();
            break;
        case static_cast<int>(Options2:: clock24hs):
            string p;
            askPeriod(p);
            time = Time(h, m, 0, p);
            time.display_24hs_time();
            //VER POR QUE SE IMPRME LA HORA AM
            time.display_hour();
            time.display_minutes();
            break;
    }

}


void handle_hms(int &h, int &m, int &s){
    Time time;
    string option;
    int option2;

    askHour(h);
    askMinutes(m);
    askSeconds(s);
    time = Time(h, m,s);

    cout << "Desea desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askHour(h);
        askMinutes(m);
        askSeconds(s);
        time = Time(h,m,s);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.display_12hs_time();
            time.display_hour();
            break;
        case static_cast<int>(Options2:: clock24hs):
            string p;
            askPeriod(p);
            time = Time(h, m, s, p);
            time.display_24hs_time();
            //VER POR QUE SE IMPRME LA HORA AM
            time.display_hour();
            time.display_minutes();
            time.display_seconds();
            break;
    }

}


void handle_hmsp(int &h, int &m, int &s, string p){
    Time time;
    string option;
    int option2;

    askHour(h);
    askMinutes(m);
    askSeconds(s);
    askPeriod(p);
    time = Time(h, m,s, p);

    cout << "Desea desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askHour(h);
        askMinutes(m);
        askSeconds(s);
        askPeriod(p);
        time = Time(h,m,s,p);
    }

    cout << "En que formato desea ver la hora?\n 1- Reloj de 12h\n 2- Reloj de 24 hs\n >>";
    cin >> option2;

    switch(option2){
        case static_cast<int>(Options2:: clock12hs):
            time.display_12hs_time();
            time.display_hour();
            break;
        case static_cast<int>(Options2:: clock24hs):
            time.display_24hs_time();
            //VER POR QUE SE IMPRME LA HORA AM
            time.display_hour();
            time.display_minutes();
            time.display_seconds();
            time.display_period();
            break;
    }

}



