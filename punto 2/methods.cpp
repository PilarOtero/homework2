#include "main.h"
#include <iostream>
#include <algorithm>

using namespace std;

//CLASE ESTUDIANTE

//Constructor 
Estudiante:: Estudiante(string n, int id){
    fullname = n;
    identification = id;
    //Inicializo el promedio final en 0
    final_media = 0.0;
}

//Getters
string Estudiante::get_name() { return fullname; }
int Estudiante::get_id() { return identification; }
float Estudiante::get_final_media() {return final_media; }

//Setter
bool Estudiante:: setgrade(float grade){
    if (grade <= 10 && grade >= 1){
        grade = grade;
        return true;
    }
    return false;
}

//Metodo para agregar una nota a un curso
void Estudiante::add_grade(float grade) {   
    if (setgrade(grade)){
        grades.push_back(move(grade));
        cout << "Calificacion agregada exitosamente." << endl;
    }
    else{
        cout << "Calificacion invalida." << endl;
    }
}

//Metodo para calcular el promedio
float Estudiante:: calculate_final_media(){
    if (grades.empty()){
        final_media = 0.0;
        return final_media;
    }
    
    float partial_media = 0.0;
    for (const auto& grade : grades){
        partial_media += grade;
    }
    
    final_media = partial_media / grades.size();
    return final_media;
}

//Metodo para mostrar el promedio final
void Estudiante:: display_finalmedia(){
    cout << "PROMEDIO FINAL - ESTUDIANTE: " << fullname << ". (Nro de legajo: " << identification << ")\n";
    cout << "Promedio general: " << final_media << endl;
}


//CLASE CURSO

//Constructores

//Constructor sin parametros
Curso:: Curso(): name(" ") {};

//Constructor con alumnos
Curso:: Curso(string course_name, const vector<shared_ptr<Estudiante>>& class_students){
    name = course_name;
    students = class_students;
}

Curso& Curso:: operator= (const Curso& other){
    //Compruebo que la asignacion no apunta a la clase sobre la que estoy trabajando 
    if (this != &other){
        name = other.name;  
        students = other.students;
    }
    return *this;
}

//Metodo para agregar al estudiante al final del vector
void Curso:: add_student(shared_ptr<Estudiante> student){
    students.push_back(move(student));
}

//Metodo para eliminar estudiantes
void Curso:: remove_student(int id){
    //Uso iteradores para recorrer la lista y poder utilizar la funcion erase
    for (auto it = students.begin(); it != students.end(); ++it){
        if ((*it)->get_id() == id){
            it = students.erase(it);
            cout << "El alumno ha sido eliminado exitosamente." << endl;
            return;
        }
    }
}

//Metodo para encontrar al estudiante cuyo legajo sea el ingresado
shared_ptr<Estudiante> Curso:: find_student(int identification){
    for (const auto& student: students){
        if (student->get_id() == identification){
            return student;
        }
    }
    return nullptr;
}

//Metodo para ver la capacidad del curso
bool Curso::capacity (){
    if (students.size() == 20){
        cout << "El curso esta completo." << endl;
        return true;
    }

    cout << "El curso tiene " << students.size() << " estudiante(s). Aun tiene capacidad para " << 20 - students.size() << " alumnos mas. " << endl;
    return false;
}

//Metodo para ordenar a los estudiantes de la A a la Z
bool Curso::sort_students(const shared_ptr<Estudiante> student1, const shared_ptr<Estudiante> student2){
    return student1->get_name() < student2->get_name();
}

//Metodo para mostrar listado de alumnos
void Curso::display_students(){
    if (students.empty()){
        cout << "El curso esta vacio" << endl;
        return;
    }
    
    sort(students.begin(), students.end(),
    //Llamo al metodo de la clase Curso (uso this porq va al objeto puntual dentro de la clase) que ordena a los estudiantes
    [this] (const shared_ptr<Estudiante> student1, const shared_ptr<Estudiante> student2){
        return sort_students(student1, student2);});
    
    cout << "LISTADO DE ESTUDIANTES:" << endl;
    for (const auto& student: students){
        cout << student->get_name() << endl;
    }

}


