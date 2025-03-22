#include "main.h"
#include "functions.cpp"

int main(){
    int h, m, s, option;
    Time time;
    string p;
    
    while(true){
        cout << "Ingrese la opcion deseada:\n 1-Ingresar hora\n 2-Ingresar hora y minutos\n 3-Ingresar hora minutos y segundos\n 4-Ingresar horas, minutos, segundos y periodo\n 5- Reloj de 12 hs\n 6-Reloj 24 hs\n 7-OUT\n" << endl;
        cin >> option;
        cin.ignore();
        cout << "\n>> ";

        switch(option){
            case static_cast<int>(Options:: h):
                askHour(h);
                
                time = Time(h);
                time.display_12hs_time();

                return false;
            
            case static_cast<int>(Options:: h_m):
                askHour(h);
                askMinutes(m);

                time = Time(h, m);
                time.display_12hs_time();

                return false;

            case static_cast<int>(Options:: h_m_s):
                askHour(h);
                askMinutes(m);
                askSeconds(s);

                time = Time(h,m,s);
                time.display_12hs_time();

                return false;
     
            case static_cast<int>(Options:: h_m_s_p):
                askHour(h);
                askMinutes(m);
                askSeconds(s);
                askPeriod(p);

                time = Time(h,m,s, p);
                time.display_12hs_time();

                return false;

            case static_cast<int>(Options:: clock12hs):  
                askHour(h);
                askMinutes(m);
                askSeconds(s);
                askPeriod(p);

                time = Time(h,m,s, p);
                time.display_12hs_time();

                return false;

            case static_cast<int>(Options:: clock24hs):
                askHour(h);
                askMinutes(m);
                askSeconds(s);
                //VER LO DE LAS 24 HS

                time = Time(h,m,s);
                time.display_24hs_time();
                return false;

            case static_cast<int>(Options:: OUT):
                cout << "Cerrando programa..." << endl;
                return false;

            default:
                cout << "Opcion invalida. Ingrese nuevamente." << endl;
            }
        }
    return 0;
}
