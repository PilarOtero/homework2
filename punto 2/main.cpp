#include "functions.cpp"

int main(){
    int option, id;
    string student_fullname, course_name;
    Curso course;
    map<string, float> grades;
    float grade, final_media;
    shared_ptr<Estudiante> student;

    while (true){
        cout << "-- MENU --\n 1. Inscribir alumno a curso\n 2. Desinscribir alumno\n 3. Agregar nuevas calificaciones a un alumno\n 4. Mostrar promedio final del alumno\n 5. Buscar alumno en curso\n 6. Ver listado de alumnos\n 7. Ver capacidad del curso\n 8- OUT " << endl;
        cout << "Opcion>> ";
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

            case static_cast<int>(Options:: final_media):
                handle_final_media(course);
                break;
            
            case static_cast<int>(Options:: look4_student):
                handle_searching_student(course);
                break;

            


            case static_cast<int>(Options:: capacity):
                handle_capacity(course);
                break;
            /*
            case static_cast<int>(Options:: final_media):
                

                break;
            

            case static_cast<int>(Options:: students_list):
                
            */
            
            case static_cast<int>(Options:: OUT):
                    cout << "Cerrando programa..." << endl;
                    return false;

            default:
                cout << "Opcion invalida. Ingrese nuevamente." << endl;
            
        }
    }
}

        


    
    
        


