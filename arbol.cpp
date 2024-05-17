#include <iostream>
#include <malloc.h>

using namespace std;

struct viaje{
    char nombre[30];
    char matricula[30];
    char destino [30];

    int codigo;
    int precio;
    int capacidad;

    int dia;
    int mes;
    int year;

    viaje *izq;
    viaje *der;
};




int main(){

    int opcion = 0;
    cout<<"";
    cout<<"Bienvenido, digite la opcion que desee realizar."<<endl;

    do
    {
        cout<<""<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"           NOMBRE DEL PROGRAMA      "<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"1.       REGISTRAR NUEVO VIAJE."<<endl;
        cout<<"2.       BUSCAR VIAJE."<<endl;
        cout<<"3.       LISTAR TODOS LOS VIAJES."<<endl;
        cout<<"4.       ELIMINAR VIAJE POR IDENTIFICADOR. "<<endl;
        cout<<"5.       REGISTRAR PASAJERO EN UN VIAJE."<<endl;
        cout<<"6.       LISTAR TODOS LOS PASAJEROS DE UN VIAJE."<<endl;
        cout<<"7.       SALIR."<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        
        
        switch (opcion) {
            
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:

            case 5:
                break;
                
            case 6:
                break;

            case 7:
                break;

            default:
                cout << "Opcion no valida." << endl;
                cout<<endl;
                break;
        }

    } while (opcion != 7);
    
}


