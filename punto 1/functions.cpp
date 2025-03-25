#include <fstream>
#include <iostream>

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








