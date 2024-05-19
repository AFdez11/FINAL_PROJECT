#include <iostream>
#include <malloc.h>
#include <cstring> 

using namespace std;

struct viaje{

    int altura;

    //info del viaje.
    char nombreEmb[30]; //hace referencia al nombre de la embarcación
    char destino [30];
    char matricula[10];
    char identi [15];

    int precio;
    int capacidad;

    int dia;
    int mes;
    int year;

    //info del pasajero
    char nombrePas[20]; //hace referencia al nombre del pasajero
    char apellidoPas[20];
    
    int id;

    viaje *izq;
    viaje *der;
};

struct viaje *raiz, *aux;

void DatosViaje(){

    char primerosDos[2];

    aux = ((struct viaje *) malloc (sizeof(struct viaje)));
 
    cout<<"Ingrese el nombre de la embaracacion: ";
    cin>>aux->nombreEmb;

    cout<<"Ingrese la matricula de la embaracacion: ";
    cin>>aux->matricula;

    cout<<"Ingrese la capacidad de la embaracacion: ";
    cin>>aux->capacidad;

    cout<<"Ingrese el destino del viaje: ";
    cin>>aux->destino;

    cout<<"Ingrese el precio del viaje: ";
    cin>>aux->precio;

    cout<<"Ingrese el dia del viaje numericamente (DD): ";
    cin>>aux->dia;

    cout<<"Ingrese el mes del viaje numericamente (MM): ";
    cin>>aux->mes;

    cout<<"Ingrese el a"<<char(164) <<"o del viaje numericamente (YYYY): ";
    cin>>aux->year;
    
    strncpy(primerosDos, aux->matricula, 2);
 
    aux->izq = aux->der = NULL;
    aux->altura = 1;
    
}

void DatosPasajeros(){

    cout<<"Ingrese el primer nombre del pasajero: "<<endl;
    cin>>aux->nombrePas;

    cout<<"Ingrese el primer nombre del pasajero: "<<endl;
    cin>>aux->apellidoPas;

    cout<<"Ingrese el primer nombre del pasajero: "<<endl;
    cin>>aux->id;

}

struct viaje * insertar(struct viaje* viaje)
{
    if (viaje == NULL)
    {
        return aux;
    }

    
    
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


