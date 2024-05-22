#include <iostream>
#include <malloc.h>
#include <cstring> 

using namespace std;

struct viaje{

    int altura;

    //info del viaje.
    char nombreEmb[30]; //hace referencia al nombre de la embarcación
    char destino [30]; // destino viaje
    char matricula[10]; // matricula de la embarcacion
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
    if (viaje == NULL){
        return aux;
    }

    if (aux->matricula < viaje->matricula) {
        viaje->izq = insertar(viaje->izq);
    } else if (aux->matricula > viaje->matricula) {
        viaje->der = insertar(viaje->der);
    } else {
        return viaje;
    }

    viaje->altura = 1 + mayor(ObtenerAltura(viaje->izq), ObtenerAltura(viaje->der));
    
     int balance = ObtenerAltura(viaje);

    if (balance > 1 && aux->matricula < viaje->izq->matricula) {
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->matricula > viaje->der->matricula) {
        return rotarIzquierda(viaje);
    }

    if (balance > 1 && aux->matricula > viaje->izq->matricula) {
        viaje->izq = rotarIzquierda(viaje->izq);
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->matricula < viaje->der->matricula) {
        viaje->der = rotarDerecha(viaje->der);
        return rotarIzquierda(viaje);
    }

    return viaje;
}

int ObtenerAltura(struct viaje *n){

}

int mayor(int A, int B){
    return (A > B) ? A : B;
}

struct viaje* rotarDerecha(struct viaje *y) {
   
}

struct viaje* rotarIzquierda(struct viaje *x) {
   
}

int ObtenerBalance(struct viaje *n){
    
}

int main(){

    int opcion = 0;
    cout<<"";
    cout<<"Bienvenido, digite la opcion que desee realizar."<<endl;

    do
    {
        cout<<""<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"           EMBARCACIONES 'LA CONCHA'      "<<endl;
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


