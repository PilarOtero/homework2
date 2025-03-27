#include "main.h"
#include <string>
#include <iostream>

string choose_course(){
    string course_name; 

    cout << "Ingrese el curso\n>> " << endl;
    getline(cin, course_name);

    return course_name;
}

string student_name(){
    string fullname;
    cout << "Ingrese el nombre del estudiante \n>> " << endl;
    getline(cin, fullname);

    return fullname;
}

int student_id(){
    int id;
    cout << "Ingrese el numero de legajo\n>> " << endl;
    cin >> id; cin.ignore();

    return id;
}

int ask_grade(){
    float grade; 
    
    cout << "Ingrese la calificacion\n>> " << endl;
    cin >> grade; cin.ignore();

    return grade;
    
}