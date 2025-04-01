#include "functions.cpp"

int main(){
    int option, id;
    string student_fullname;
    Curso course1;
    Curso course2;
    map<string, float> grades;
    float grade, final_media;
    shared_ptr<Estudiante> student;

    while (true){
        cout << "\n-- MENU --\n 1. Inscribir alumno a curso\n 2. Desinscribir alumno\n 3. Mostrar promedio final del alumno\n 4. Buscar alumno en curso\n 5. Ver listado de alumnos\n 6. Ver capacidad del curso\n 7. Copiar curso\n 8. OUT " << endl;
        cout << "Opcion>> ";
        cin >> option;
        cin.ignore();

        switch(option){

            case static_cast<int> (Options:: new_student): 
                handle_adding_student(course1);
                break;
            
            case static_cast<int> (Options:: remove_student):
                handle_removing_student(course1);
                break;

            case static_cast<int>(Options:: final_media):
                handle_final_media(course1);
                break;
            
            case static_cast<int>(Options:: look4_student):
                handle_searching_student(course1);
                break;

            case static_cast<int>(Options:: students_list):
                handle_students_list(course1);
                break;

            case static_cast<int>(Options:: capacity):
                handle_capacity(course1);
                break;
            
            case static_cast<int>(Options::copy):
                course1.operator=(course2);
                break;

            case static_cast<int>(Options:: OUT):
                    cout << "Cerrando programa..." << endl;
                    return false;

            default:
                cout << "Opción inválida. Ingrese nuevamente." << endl;
            
        }
    }
}

        


    
    
        


