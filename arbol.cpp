#include <iostream>
#include <malloc.h>
#include <cstring> 

using namespace std;

struct Pasajero
{
    char nombre[30];
    char apellido[30];
    char id[10];

    Pasajero *sig;
};


struct viaje{

    int altura;
    int verifi;

    //info del viaje.
    char nombreEmb[30]; //hace referencia al nombre de la embarcación
    char destino [30]; // destino viaje
    char matricula[10]; // matricula de la embarcacion
    char identi [10];
     
    char dia[03];
    char mes[03];
    char year[05];

    int precio;
    int capacidad;
        
    viaje *izq;
    viaje *der;
    viaje *sig;

    Pasajero *cab = NULL;

};
struct viaje *raiz, *aux, *Bviaje, *padre;
Pasajero *auxP = NULL, *auxP2 = NULL, *Auxcab = NULL;


void datosViaje(){

    char primerosDos[12];
    
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

    aux->altura = 1;
    aux->verifi = 0;

    strcpy(primerosDos, aux->matricula);
    
    for (int i = 2; i < 12; i++)
    {
        primerosDos[i] = '\0';
    }

    strcpy(aux->identi,primerosDos);
    strcat(aux->identi,aux->year);
    strcat(aux->identi,aux->mes);
    strcat(aux->identi,aux->dia);

    aux->izq = aux->der = NULL;

    cout<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Su identificador es: "<<aux->identi<<endl;
    cout<<"**********************************"<<endl;
    
}


//BUSQUEDAS

void buscarViajeI(char BuscarV[10], viaje *rama){ //será utilizado para buscar el viaje por medio del identificador
    
    if (strcmp(BuscarV, rama->identi) == 0)
    {
        Bviaje = rama;

    } else {

        if (rama->izq != NULL){

            buscarViajeI(BuscarV, rama->izq);
        }
        if (rama->der != NULL){
            
            buscarViajeI(BuscarV,rama->der);
        }
        
    }
}

void viajeI(char BuscarV[10]){
    int comparacion = strcmp(BuscarV, Bviaje->identi);

    if (comparacion == 0)
    {
        cout<<"Embarcacion: "<<Bviaje->nombreEmb<<" con viaje en: "<<" "<<Bviaje->dia<<"/"<<
        Bviaje->mes<<"/"<<Bviaje->year<<endl;
        cout<<"     - Matricula: "<<Bviaje->matricula<<endl;
        cout<<"     - Capacidad: "<<Bviaje->capacidad<<endl;
        cout<<"     - Destino: "<<Bviaje->destino<<endl;
        cout<<"     - Precio: "<<Bviaje->precio<<endl;
    } else {

        cout<<"No se encontro el identificador"<<endl;
    }

    Bviaje = NULL;

}

void buscarViajeM(char BuscarV[10], viaje *rama){ //Buscar viaje por medio de la matricula


    if (strcmp(BuscarV, rama->matricula) == 0)
    {
        Bviaje = rama;

    } else {

        if (rama->izq != NULL){

            buscarViajeM(BuscarV, rama->izq);
        }
        if (rama->der != NULL){
            
            buscarViajeM(BuscarV,rama->der);
        }
        
    }
 
}

void viajeM(char BuscarV[10]){
    int comparacion = strcmp(BuscarV, Bviaje->matricula);

    if (comparacion == 0)
    {
        cout<<"Embarcacion: "<<"'"<<Bviaje->nombreEmb<<"'"<<" con viaje en: "<<" "<<Bviaje->dia<<"/"<<
        Bviaje->mes<<"/"<<Bviaje->year<<endl;
        cout<<"     - Identificador: "<<Bviaje->identi<<endl;
        cout<<"     - Capacidad: "<<Bviaje->capacidad<<endl;
        cout<<"     - Destino: "<<Bviaje->destino<<endl;
        cout<<"     - Precio: "<<Bviaje->precio<<endl;
    } else {

        cout<<"No se encontro el identificador"<<endl;
    }

    Bviaje = NULL;

}


void buscarP(char Buscar[10], viaje *Rama){ //Se buscaran los pasajeros de una embarcación en específico

    int comparacion = strcmp(Buscar, Rama->identi);

    if (comparacion == 0)
    {
        Bviaje = Rama;

    } else {

        if (Rama->izq != NULL){

            buscarP(Buscar, Rama->izq);
        }
        if (Rama->der != NULL){
            
            buscarP(Buscar, Rama->der);
        }
        
    }

}


//BALANCEO

int ObtenerAltura(struct viaje *n){

    if (n == NULL)
    {
        return 0;
    }

    return n->altura;

}

int mayor(int A, int B){
    return (A > B) ? A : B;
}

struct viaje *rotarDerecha(struct viaje *y) {

    struct viaje *x  = y->izq;
    struct viaje *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(ObtenerAltura(y->izq), ObtenerAltura(y->der)) +1;
    x->altura = mayor(ObtenerAltura(x->izq), ObtenerAltura(x->der)) +1;

    return x;
}

struct viaje* rotarIzquierda(struct viaje *x) {
    
    struct viaje *y = x->der;
    struct viaje *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(ObtenerAltura(x->izq), ObtenerAltura(x->der)) + 1;
    y->altura = mayor(ObtenerAltura(y->izq), ObtenerAltura(y->der)) + 1;

    return y;
}

int ObtenerBalance(struct viaje *n){
    
    if (n == NULL)
    {
        return 0;
    }

    return ObtenerAltura(n->izq) - ObtenerAltura (n->der);
    

}

struct viaje* insertar(struct viaje* viaje)
{
    if (viaje == NULL){
        return aux;
    }

    if (aux->identi < viaje->identi) {
        viaje->izq = insertar(viaje->izq);
    } else if (aux->identi > viaje->identi) {
        viaje->der = insertar(viaje->der);
    } else {
        return viaje;
    }

    viaje->altura = 1 + mayor(ObtenerAltura(viaje->izq), ObtenerAltura(viaje->der));
    
    int balance = ObtenerBalance(viaje);

    if (balance > 1 && aux->identi < viaje->izq->identi) {
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->identi > viaje->der->identi) {
        return rotarIzquierda(viaje);
    }

    if (balance > 1 && aux->identi > viaje->izq->identi) {
        viaje->izq = rotarIzquierda(viaje->izq);
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->identi < viaje->der->identi) {
        viaje->der = rotarDerecha(viaje->der);
        return rotarIzquierda(viaje);
    }

    return viaje;
}


// RECORRIDO

void InOrden (viaje *recursive){
   
    if (recursive->izq != NULL){
        InOrden(recursive->izq);
    }

    cout<<endl;
    cout<<"- Embarcacion: "<< recursive->nombreEmb<<endl;
    cout<<"- Identificador unico: "<< recursive->identi<<endl;
    cout<<"- Destino: "<< recursive->destino <<endl;

    if (recursive->der != NULL){
        InOrden(recursive->der);
    }

}


// ELIMIMINAR
void buscar(char Buscar[10], viaje *Rama){

    if (strcmp(Buscar, Rama->identi) == 0)
    {
        Bviaje = Rama;

    } else {

        if (Rama->izq != NULL){

            buscar(Buscar, Rama->izq);
        }
        if (Rama->der != NULL){
            
            buscar(Buscar, Rama->der);
        }
        
    }
}

void buscarpadre(viaje *rama){
	
    if ((rama->izq != NULL)&&(rama->izq != Bviaje))
    {
        buscarpadre(rama->izq);

    } else if (rama->izq == Bviaje){

        padre = rama;
    }
    
    if ((rama->der != NULL)&&(rama->der != Bviaje))
    {
        buscarpadre(rama->der);

    } else if (rama->der == Bviaje){
        
        padre = rama;
    }
}

int eliminarCaso1(viaje *rama){

    if (Bviaje != rama)
    {
        buscarpadre(rama);

        if (padre->izq == Bviaje)
        {
            padre->izq = NULL;

        } else if (padre->der == Bviaje){

            padre->der = NULL;

        }
        Bviaje = NULL;
        free(Bviaje);
    }
    return 0;
}

int eliminarCaso2(viaje *rama){

    if (Bviaje != rama)
    {
        buscarpadre(rama);

        if ((padre->izq == Bviaje) && (padre->izq != NULL))
        {
            padre->izq = Bviaje->izq;
        } else {

            padre->izq = Bviaje->der;
        }
        
    } else if (padre->der == Bviaje){
        
        if (Bviaje->izq != NULL)
        {
            padre->der = Bviaje->izq;
        } else {
            padre->der = Bviaje->der;
        }
        
        Bviaje = NULL;
        free(Bviaje);
    }
    return 0;
}

int reubicar(struct viaje *recursive){

    if (recursive == NULL)
    {
        cout<<"No hay viajes disponibles."<<endl;
    } else if (recursive->izq != NULL){
        reubicar(recursive->izq);
    } else {

        aux = recursive;
    }
    

    return 0;
}

void eliminar (){

    char buscarIdenti[10]; //lo utilizaremos para almacenar el identificador a eliminar

    cout<<"Ingrese el identificador unico de la embarcacion a eliminar: ";
    cin>>buscarIdenti;

    cout<<endl;

    buscar(buscarIdenti, raiz);
    if ((Bviaje->der == NULL) && (Bviaje->izq == NULL)){
       
        eliminarCaso1(raiz);
        cout<<"Embarcacion eliminada."<<endl;

    } else if ((Bviaje->der == NULL) && (Bviaje->der != NULL)  &&
              (Bviaje->izq == NULL) && (Bviaje->izq != NULL)){

        eliminarCaso2(raiz);
        cout<<"Embarcacion eliminada."<<endl;    

    } else if (buscarIdenti == raiz->identi){
        raiz = NULL;
    }

    raiz = insertar(raiz);
    
}


//Funciones Pasajeros (FIFO)

void registrarPasajeros(){

    int cont = 1;

    if (cont <= Bviaje->capacidad)
    {
            auxP = (struct Pasajero *) malloc (sizeof(struct Pasajero));
            cout<<"Ingrese el primer nombre del pasajero: ";
            cin>>auxP->nombre;
            cout<<"Ingrese el primer apellido del pasajero: ";
            cin>>auxP->apellido;
            cout<<"Ingrese el ID del pasajero: ";
            cin>>auxP->id;
            auxP->sig = NULL;
            Auxcab = Bviaje->cab;
            cout<<endl;
            cout<<"-------------------------"<<endl;
            cout<<"Pasajero registrado."<<endl;
            cout<<"-------------------------"<<endl;

        if (Bviaje->verifi == 0)
        {
            Auxcab = auxP;
            Bviaje->cab = Auxcab;
            Bviaje->verifi = Bviaje->verifi+1;
            Auxcab = auxP = NULL;
            
        } else {
        
            auxP2 = Auxcab;
            while (auxP2->sig != NULL)
            {
                auxP2 = auxP2->sig;
            }
                auxP2->sig = auxP;
                Bviaje->verifi = Bviaje->verifi + 1;
                auxP2 = auxP = Auxcab = NULL;
                free(auxP2);
                free(auxP2);
                free(Auxcab);
        }
        
    }   
  
}

void asignarViaje(char buscar[10]){

    int comparacion;
    comparacion = strcmp(buscar, Bviaje->identi);

    if (comparacion == 0){
        registrarPasajeros();

    } else {

        cout<<"Identificador no valido."<<endl;
    }

}


void verificadorR(char buscar[10]){    //se encarga de verificar que haya embarcaciones disponibles y de paso asigna el viaje
    

    if (raiz != NULL)
    { 

        cout<<"***********************************"<<endl;
        cout<<"Los viajes disponibles son: "<<endl;
        cout<<"***********************************"<<endl;

        InOrden(raiz);
        cout<<endl;

        cout<<"Ingrese el identificador de la embarcacion la cual desea abordar: ";
        cin>>buscar;      
        buscarP(buscar, raiz);
        cout<<"Embarcacion encontrada con exito."<<endl;
        cout<<endl;
        asignarViaje(buscar);

    } else {

        cout<<"No hay viajes disponibles."<<endl;

    }

}

void mostrarP(char Buscar[10]){ //Imprime a los pasajeros de x embarcación
    int i = 0; 
    int comparacion;
    comparacion = strcmp(Buscar,Bviaje->identi);
        
    for (auxP = Bviaje->cab; auxP != NULL; auxP=auxP->sig)
    {
        i++;
        cout<<i<<". Nombre del pasajero: "<<auxP->nombre<<endl;
        cout<<". Apellido del pasajero: "<<auxP->apellido<<endl;
        cout<<". ID del pasajero: "<<auxP->id<<endl;
        /*cout<<". Asiento del pasajero: "<<auxP->id<<endl; //cambiar*/
        cout<<"-----------------------------------------------------"<<endl;    
    }

}

void verificadorL(char buscar[10]){    //se encarga de verificar que haya embarcaciones disponibles y de paso lista los pasajeros de x embarcación

    
    if (raiz != NULL)
    { 

        cout<<"***********************************"<<endl;
        cout<<"Los viajes disponibles son: "<<endl;
        cout<<"***********************************"<<endl;

        InOrden(raiz);
        cout<<endl;

        cout<<"Ingrese el identificador de la embarcacion sobre la cual desea obtener los pasajeros: ";
        cin>>buscar;
        buscarP(buscar,raiz);
        cout<<endl;
        mostrarP(buscar);
        cout<<endl; 

    } else {

        cout<<"No hay viajes disponibles."<<endl;

    }

    Bviaje = NULL;

}

int main(){

    int opcion = 0, opcion2 = 0, opcion3 = 0;
    char ident[20];
    char busqueda[20];

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

                datosViaje();
                raiz = insertar(raiz);
                cout<<endl;
                
                break;

            case 2:
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"Por cual medio desea realizar su busqueda?"<<endl;
                cout<<endl;
                cout<<"1.       IDENTIFICADOR."<<endl;
                cout<<"2.       MATRICULA."<<endl;
                cout<<"Opcion: ";
                cin>>opcion3;

                switch (opcion3)
                {

                case 1:
                    cout<<"Ingrese el identificador del viaje el cual desea buscar: ";
                    cin>>ident;
                    cout<<endl;

                    buscarViajeI(ident, raiz);
                    viajeI(ident);
                    
                    break;

                case 2:
                    cout<<"Ingrese la matricula de la embarcacion la cual desea buscar: ";
                    cin>>ident;
                    cout<<endl;

                    buscarViajeM(ident,raiz);
                    viajeM(ident);

                    break;
                
                default:
                    cout<<"Opcion no valida."<<endl;
                    cout<<endl;                    

                    break;
                }
                break;

            case 3: 
                InOrden(raiz);
                cout<<endl; 
                break;

            case 4:
            
                eliminar();
                cout<<endl;
                break;
            case 5:    
                verificadorR(busqueda);
                break;
                
            case 6:
                verificadorL(busqueda);
                break;

            case 7:
                cout<<"Gracias por confiar en nosotros. :)"<<endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
                cout<<endl;
                break;
        }

    } while (opcion != 7);
    
}
