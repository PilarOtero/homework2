#include <vector>
#include <memory>
#include <string>
#include <map>

#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Curso;

class Estudiante{
    private: 

        string fullname; 
        int identification;
        float grade;
        vector<float> grades;
        float final_media; //Promedio final

    public:

        //Constructor para crear un estudiante
        Estudiante(string n, int id);

        //Getters
        string get_name();
        int get_id();
        float get_final_media();

        //Setter
        bool setgrade(float grade);

        //Metodos
        void add_grade(float grade);
        float calculate_final_media();
        void display_finalmedia();

};

class Curso {
    private: 

        string name;
        vector<shared_ptr<Estudiante>> students;

    public:
        
        //Constructores
        Curso();
        Curso(string course_name, const vector<shared_ptr<Estudiante>>& class_students);

        /*
        SHALLOW COPY de la clase Curso -> utilice un vector de shared pointers para representar a los alumnos, de manera que cualquier 
        modificacion en los atributos de estos punteros, se reflejara en todos los cursos.
        */ 
        Curso& operator= (const Curso& other);

        //Metodos
        void add_student(shared_ptr<Estudiante> student);
        void remove_student(int id);
        shared_ptr<Estudiante> find_student(int identification);
        bool capacity();
        bool sort_students(const shared_ptr<Estudiante> student1, const shared_ptr<Estudiante> student2);
        void display_students();
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