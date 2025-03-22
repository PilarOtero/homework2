#include "main.h"
#include "functions.cpp"

int main(){
    int h, m, s, option;
    string p;
    while(true){
        cout << "Ingrese la opcion deseada: 1-Ingresar hora\n, 2-Ingresar hora y minutos\n, 3-Ingresar hora, minutos y segundos\n, 4-Ingresar horas, minutos, segundos y periodo\n, 5- Reloj de 12 hs, 6-Relojs 24 hs, 7-OUT\n" << endl;
        cin >> option;
        cin.ignore();

        switch(option){
            case static_cast<int>(Options:: h):
                askHour();
                break;

            case static_cast<int>(Options:: h_m):
                askHour();
                askMinutes();
                break;

            
            case static_cast<int>(Options:: h_m_s):
                askHour();
                askMinutes();
                askSeconds();
                break;

            
            case static_cast<int>(Options:: h_m_s_p):
                askHour();
                askMinutes();
                askSeconds();
                break;

            
            }
        }
}
