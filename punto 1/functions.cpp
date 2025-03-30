#include <fstream>
#include <iostream>
#include "time.cpp"

using namespace std;

void askHour(int &hour){
    cout << "Ingrese la hora\n>> ";
    string input;
    getline(cin, input);
    
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
            time = Time(h,m,s,p);
            time.display_12hs_time();
            time.display_hour();
            if (with_minutes) time.display_minutes();
            if (with_seconds) time.display_seconds();
            if (with_period) time.display_period();

            break;
        case static_cast<int>(Options2:: clock24hs):
            time = Time(h, m, s, p);
            time.display_24hs_time();

            time.display_hour();
            if (with_minutes) time.display_minutes();
            if (with_seconds) time.display_seconds();

            break;
        
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
}

void handle_h(int &h){
    Time time;
    string option;
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

    ask_clock(h,m,false,s,false,p,false);
}

void handle_hm(int &h, int &m){
    Time time;
    string option;
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

    ask_clock(h,m,true,s,false,p,false);

}

void handle_hms(int &h, int &m, int &s){
    Time time;
    string option;
    string p = "a.m";

    askTime(h,m,true,s,true,p, false);
    time = Time(h, m,s);

    cout << "Desea desea realizar cambios? Si/No\n";
    cin >> option;

    if (option == "Si" || option == "SI" || option == "si"){
        askTime(h,m,true,s,true,p, false);
        time = Time(h,m,s);
    }

    ask_clock(h,m,true,s,true,p,false);

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



