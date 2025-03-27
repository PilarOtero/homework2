#include "functions.cpp"


int main(){
    int option, id, grade;
    string student_fullname, course_name;
    map<string, Curso> courses;
    map<string, float> grades;
    shared_ptr<Estudiante> student;

    cout << "Elija una opcion\n 1. Inscribir alumno a curso\n 2. Desinscribir alumno\n 3. Agregar nuevas calificaciones a un alumno\n 4. Mostrar promedio final del alumno\n 5. Buscar alumno en curso\n 6. Ver listado de alumnos\n 7. Ver capacidad del curso " << endl;
    cout << "Opcion>> " << endl;
    cin >> option;
    cin.ignore();

    switch(option){

        case static_cast<int> (Options:: new_student): 
            course_name = choose_course();  

            //Itero sobre el mapa de cursos para ver si existe
            if (courses.find(course_name) == courses.end()) {
                courses[course_name] = Curso(course_name);
            }

            student_fullname = student_name();
            id = student_id();
            student = make_shared<Estudiante>(student_fullname, id);

            courses[course_name].add_student(student);
            cout << "El alumno " << student_fullname<< " ha sido inscripto correctamente." << endl;
            
            break;
        
        case static_cast<int> (Options:: remove_student):
            course_name = choose_course();
            id = student_id();
            
            if (courses[course_name].find_student(id)){
                courses[course_name].remove_student(id);
                cout << "El alumno con numero de legajo " << id << "ha sido desinscripto correctamente." << endl;
            }
            
            cout << "El alumno con numero de legajo " << id << "no esta inscripto en el curso" << endl; 
            break;
        
        case static_cast<int>(Options:: add_grades):
            student_fullname = student_name();
            id = student_id();
            student = make_shared<Estudiante>(student_fullname, id);

            while (true){
                course_name = choose_course();
                if (courses.find(course_name) == courses.end()) {
                    courses[course_name] = Curso(course_name);
                }
             
                grade = ask_grade(); 

                bool added = student->add_grade(course_name, grade);
                
                if (added){
                    cout << "Se ha realizado la operacion correctamente." << endl;
                }

                string continue_adding;
                cout << "Desea seguir agregando calificaciones de este alumno?" << endl;
                cin >> continue_adding;

                if (continue_adding == "No" || continue_adding == "NO" || continue_adding == "no"){
                    return false;
                }
            
            break;
            }
            
            
        //VER
        /*case static_cast<int>(Options:: final_media):
            student_fullname = student_name();
            id = student_id();
            course_name = choose_course();

            if (courses[course_name].find_student(id)){
                shared_ptr<Estudiante> student = nullptr; //Esto asi puedo recorrer el curso y hacer que apunte al alumno (ya existe)

                float final_media = student->calculate_final_media();
                cout << "El promedio de este alumno en el curso es " << final_media << endl;
            }
            else {
                cout << "El alumno con id " << id << " no esta inscripto a este curso" << endl;
            }

            break;
        */

        case static_cast<int>(Options:: students_list):
            course_name = choose_course();
            courses[course_name].display_students();
            break;
        
        case static_cast<int>(Options:: capacity):
            course_name = choose_course;
            courses[course_name].is_full();
            break;
        }
        }

        


    
    
        


