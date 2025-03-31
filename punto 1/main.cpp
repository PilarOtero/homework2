#include "functions.cpp"

int main(){
    int h, m, s, option;
    Time time;
    string p;
    
    while(true){
        cout << "Ingrese la opción deseada:\n 1- Ingresar hora\n 2- Ingresar hora y minutos\n 3- Ingresar hora minutos y segundos\n 4- Ingresar hora, minutos, segundos y período\n 5- OUT\n" << endl;
        cout << "Opción>> ";
        cin >> option;
        cin.ignore();
        
        try {
            switch(option){
            
                case static_cast<int>(Options1:: h):
                    handle_h(h);
                    return false;

                case static_cast<int>(Options1:: h_m):
                    handle_hm(h,m);
                    return false;

                case static_cast<int>(Options1:: h_m_s):
                    handle_hms(h,m,s);
                    return false;
            
                case static_cast<int>(Options1:: h_m_s_p):
                    handle_hmsp(h,m,s,p);
                    return false;

                case static_cast<int>(Options1:: OUT):
                    cout << "Cerrando programa..." << endl;
                    return false;

                default:
                    cout << "Opcion invalida. Ingrese nuevamente." << endl;
            }
        } 
        catch(invalid_argument &e){
            cout << e.what() << endl;
            return 1;
        }
    }
    return 0;
    
}
