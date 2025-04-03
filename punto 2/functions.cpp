#include "methods.cpp"
#include <string>
#include <iostream>
using namespace std;

//Ingreso del nombre del estudiante
string student_name(){
    string fullname;
    cout << "Ingrese el nombre del estudiante \n>> " << endl;
    getline(cin, fullname);

    return fullname;
}

//Ingreso del legajo del estudiante
int student_id(){
    int id;
    cout << "Ingrese el numero de legajo\n>> " << endl;
    cin >> id; cin.ignore();

    return id;
}

//Ingreso de la cantidad de calificaciones del estudiante
int grades(){
    int grades;
    cout << "Ingrese la cantidad de notas" << endl;
    cin >> grades;
    return grades;
}

//Ingreso de las calificaciones del estudiante
float ask_grade(){
    float grade; 
    
    cout << "Ingrese la calificacion\n>> " << endl;
    cin >> grade; cin.ignore();

    return grade;
    
}

//En la funciones que están a continuación, paso course como parámetro por referencia para que los cambios se reflejen en main

void handle_adding_student(Curso& course){
    string student_fullname = student_name();
    int id = student_id();

    //Si se encuentra al alumno en el curso, no es necesario inscribirlo nuevamente
    if (course.find_student(id)){
        cout << "El legajo " << id << " ya pertenece al curso." << endl;
    }
    
    else {
        //Crea al estudiante y se agrega al curso
        shared_ptr<Estudiante> student = make_shared<Estudiante>(student_fullname, id);
        course.add_student(student);
        cout << "El alumno " << student_fullname<< " ha sido inscripto correctamente." << endl;

        //Ingreso de las calificaciones
        int n = grades();
        for (int i = 0; i < n; i ++){
            float grade = ask_grade();
            student->add_grade(grade);
        }
    }
 
}

//Función para eliminar un estudiante del curso
void handle_removing_student(Curso& course){
    int id = student_id();

    if (course.find_student(id)){
        course.remove_student(id);
        cout << "El alumno con numero de legajo " << id << " ha sido desinscripto correctamente." << endl;
    }
    else{ 
    cout << "El alumno con numero de legajo " << id << " no está inscripto en el curso" << endl; 
    }
}

//Cálculo del promedio final del estudiante
void handle_final_media(Curso& course){
    int id = student_id();
    const shared_ptr<Estudiante> student = course.find_student(id);

    if (! student){
        cout << "El alumno con ID " << id << " no esta inscripto en el curso." << endl;
        return;
    }

    float final_media = student->calculate_final_media();
    student->display_finalmedia();
}

//Capacidad del curso
void handle_capacity(Curso& course){
    course.capacity();
}

    
//Búsqueda de alumno por legajo
void handle_searching_student(Curso& course){
    int id = student_id();
    if (course.find_student(id)){
        cout << "El alumno pertenece al curso." << endl;
    }
}

//Muestra del listado de estudiantes inscriptos
void handle_students_list(Curso& course){
    course.display_students();
}
