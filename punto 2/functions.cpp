#include "main.h"
#include <string>
#include <iostream>

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

float ask_grade(){
    float grade; 
    
    cout << "Ingrese la calificacion\n>> " << endl;
    cin >> grade; cin.ignore();

    return grade;
    
}

void handle_adding_student(Curso course){
    string student_fullname = student_name();
    int id = student_id();
    shared_ptr<Estudiante> student = make_shared<Estudiante>(student_fullname, id);

    course.add_student(student);
    cout << "El alumno " << student_fullname<< " ha sido inscripto correctamente." << endl;
}

void handle_removing_student(Curso course){
    int id = student_id();

    if (course.find_student(id)){
        course.remove_student(id);
        cout << "El alumno con numero de legajo " << id << " ha sido desinscripto correctamente." << endl;
    }

    cout << "El alumno con numero de legajo " << id << " no esta inscripto en el curso" << endl; 
}

void handle_adding_grades(Curso course){
    int id = student_id();
    shared_ptr<Estudiante> student = course.find_student(id);
    if (student){
        float grade = ask_grade();
        student->add_grade(course.get_name(), grade);
        cout << "Se ha agregado la calificacion corretamente." << endl;
    }

}