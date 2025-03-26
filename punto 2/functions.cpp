#include "main.h"
#include <string>
#include <iostream>

Curso choose_course(){
    string selected_course; 

    cout << "Ingrese el curso\n>> " << endl;
    getline(cin, selected_course);

    Curso course(selected_course);

    return course;
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

pair<string,float> add_grade(){
    string course;
    float grade; 

    cout << "Ingrese el curso en el que agregar la nueva calificacion\n>> " << endl;
    getline(cin, course);

    cout << "Ingrese la calificacion\n>> " << endl;
    cin >> grade; cin.ignore();

    return make_pair(course, grade);

}