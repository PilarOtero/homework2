#include <iostream>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class Estudiante{
    private: 
        string fullname; 
        int identification;
        //Uso map para asociar curso (key) con nota (value)
        map<string, float> courses;
        float final_media;

    public:
    //Uso un constructor para crear un estudiante
    Estudiante(string n, int id){
        fullname = n;
        identification = id;
    }

    //Metodos para obtener el nombre, legajo y promedio general.
    string get_name() { return fullname; }
    int get_id() { return identification; }
    int get_final_media() {return final_media; }

    //Metodo para agregar una nota a un curso
    void add_grade(string course, int grade) {
        courses[course] = grade;
    }

    //Metodo para obtener el promedio final de cada curso
    float get_media(){
        if (courses.empty()) {return 0.0;}

        float partial_media = 0;
        for (const auto& [couse, grade] : courses){
            partial_media += grade;
        }
        return partial_media / courses.size();
    }

    void display_courses(){
        cout << "PROMEDIO FINAL - ESTUDIANTE: " << fullname << ". Numero de legajo: " << identification << endl;
        cout << "NOTAS FINALES POR ASIGNATURA: " << endl;
        for (const auto& [course,grade] : courses){
            cout << "CURSO->: " << course << "NOTA FINAL-> " << grade << endl;
        }
    }

};

class Curso {
    private: 
    vector<unique_ptr<Estudiante>> students;

    public:
        void add_student(unique_ptr<Estudiante> student){
            students.push_back(student);
        }

        void display_students() {
            cout << "ESTUDIANTES:\n" << endl;
            for (const auto& student: students){

            }
        }
}