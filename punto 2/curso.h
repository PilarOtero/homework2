#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;
#ifndef MAIN_H
#define MAIN_H

class Curso;

class Estudiante{
    private: 

        string fullname; 
        int identification;
        vector<float> grades;
        float final_media; //Promedio final

    public:

        //Uso un constructor para crear un estudiante
        Estudiante(string n, int id){
            fullname = n;
            identification = id;
            //Inicializo el promedio final en 0
            final_media = 0.0;
        }

        //Metodos para obtener el nombre, legajo y promedio general.
        string get_name() { return fullname; }
        int get_id() { return identification; }
        float get_final_media() {return final_media; }

        //Metodo para agregar una nota a un curso
        void add_grade(float grade) {   
            grades.push_back(move(grade));
        }

        //Metodo para obtener el promedio final
        float calculate_final_media(){
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

        //VER ESTO
        void display_courses(){
            cout << "PROMEDIO FINAL - ESTUDIANTE: " << fullname << ". (Nro de legajo: " << identification << ")\n";
            cout << "Promedio general: " << final_media << endl;
            cout << "NOTAS FINALES POR CURSO: " << endl;
            for (const auto& grade : grades){
                cout << "Nota final: " << grade << endl;
            }
        }

};

class Curso {
    private: 

        string name;
        vector<shared_ptr<Estudiante>> students;

    public:
        
        //Constructor sin parametros
        Curso(): name(" ") {};

        //Constructor solo con nombre
        Curso(string course_name) : name(course_name) {}

        //Metodo para obtener el nombre del curso
        string get_course_name(){ return name; }

        //Constructor con alumnos
        Curso(string course_name, const vector<shared_ptr<Estudiante>>& class_students){
            name = course_name;
            students = class_students;
        }

        /*
        SHALLOW COPY de la clase Curso -> utilice un vector de shared pointers para representar a los alumnos, de manera que cualquier 
        modificacion en los atributos de estos punteros, se reflejara en todos los cursos.
        */ 
        Curso& operator= (const Curso& other){
            //Compruebo que la asignacion no apunta a la clase sobre la que estoy trabajando 
            if (this != &other){
                name = other.name;  
                students = other.students;
            }
            return *this;
        }

        //Metodo para agregar al estudiante al final del vector
        void add_student(shared_ptr<Estudiante> student){
            students.push_back(move(student));
        }

        void remove_student(int id){
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
        shared_ptr<Estudiante> find_student(int identification){
            for (const auto& student: students){
                if (student->get_id() == identification){
                    return student;
                }
            }
            return nullptr;
        }

        bool capacity (){
            if (students.size() == 20){
                cout << "El curso esta completo." << endl;
                return true;
            }

            cout << "El curso tiene " << students.size() << " estudiante(s). Aun tiene capacidad para " << 20 - students.size() << " alumnos mas. " << endl;
            return false;
        }

        //Metodo para ordenar a los estudiantes de la A a la Z
        bool sort_students(const shared_ptr<Estudiante> student1, const shared_ptr<Estudiante> student2){
            return student1->get_name() < student2->get_name();
        }

        void display_students(){
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
};

enum class Options{
    new_student = 1,
    remove_student,
    final_media,
    look4_student,
    students_list,
    capacity,
    OUT,
};


#endif