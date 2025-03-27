#include "functions.cpp"

int main(){
    int option, id;
    string student_fullname, course_name;
    Curso course;
    map<string, float> grades;
    float grade, final_media;
    shared_ptr<Estudiante> student;

    while (true){
        cout << "Elija una opcion\n 1. Inscribir alumno a curso\n 2. Desinscribir alumno\n 3. Agregar nuevas calificaciones a un alumno\n 4. Mostrar promedio final del alumno\n 5. Buscar alumno en curso\n 6. Ver listado de alumnos\n 7. Ver capacidad del curso " << endl;
        cout << "Opcion>> " << endl;
        cin >> option;
        cin.ignore();

        switch(option){

            case static_cast<int> (Options:: new_student): 
                handle_adding_student(course);
                break;
            
            case static_cast<int> (Options:: remove_student):
                handle_removing_student(course);
                break;
            
            case static_cast<int>(Options:: add_grades):
                handle_adding_grades(course);
                break;
                }


            /*
            case static_cast<int>(Options:: final_media):
                student_fullname = student_name();
                id = student_id();

                final_media = student->calculate_final_media();
                //Muestra el promedio del alumno en cada curso y el promedio final general
                student->display_courses();

                break;
            

            case static_cast<int>(Options:: students_list):
                course_name = choose_course();
                courses[course_name].display_students();
                break;
            
            case static_cast<int>(Options:: capacity):
                course_name = choose_course();
                courses[course_name].is_full();
                break;
            */
        }
    }

        


    
    
        


