#include "main.h"
#include <fstream>

using namespace std;

void askHour(){
    int hour;
    cout << "Ingrese la hora: " << endl;
    string input;
    getline(cin, input);

    hour = stoi(input);
}

void askMinutes(){
    int minutes;
    cout << "Ingrese los minutos: " << endl;
    string input;
    getline(cin, input);

    minutes = stoi(input);
}

void askSeconds(){
    int seconds;
    cout << "Ingrese los segundos: " << endl;
    string input;
    getline(cin, input);

    seconds = stoi(input);
}

void askPeriod(){
    string period;
    cout << "Ingrese el periodo (a.m / p.m): " << endl;
    cin.ignore(); getline(cin, period);
}







