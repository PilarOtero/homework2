#include "functions.cpp"

int main(){
    int option, id;
    string student_fullname;

    Curso course;

    cout << "Elija una opcion\n 1. Inscribir alumno a curso\n 2. Desinscribir alumno\n 3. Agregar nuevas calificaciones a un alumno " << endl;
    cout << "Opcion>> " << endl;
    cin >> option;
    cin.ignore();

    switch(option){

        case static_cast<int> (Options:: new_student): 
            course = choose_course();

            student_fullname = student_name();
            id = student_id();
            shared_ptr<Estudiante> new_student = make_shared<Estudiante>(student_fullname, id);

            course.add_student(new_student);
            cout << "El alumno ha sido inscripto correctamente." << endl;
            
            break;
        
        case static_cast<int> (Options:: remove_student):
            course = choose_course();

            id = student_id();
            course.remove_student(id);

            cout << "El alumno ha sido desinscripto correctamente." << endl;

            break;
        
        //case static_cast<int>(Options:: add_grades):

    
    
    
    }
        


}