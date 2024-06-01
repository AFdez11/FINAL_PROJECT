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

    int cont;
    int altura;

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

    Pasajero *cab;

};
struct viaje *raiz, *aux, *aux2, *Bviaje;
struct Pasajero *auxP, *auxP2;



void posicionarIdenti(){

    int comparacion = strcmp(aux->identi,aux2->identi);

    if (comparacion < 0) {

        if (aux2->izq != NULL){
            aux2 = aux2->izq;
            posicionarIdenti();
        } else {
            aux2->izq = aux;
            aux = NULL;
        }
        
    } else if (comparacion > 0){
        
        if(aux2->der != NULL){
            aux2 = aux2->der;
            posicionarIdenti();
        }   
        else {

            aux2->der = aux;
            aux = NULL;
        }
        
    } else {

        if(aux2->der != NULL){
            aux2 = aux2->der;
            posicionarIdenti();
        }   
        else {

            aux2->der = aux;
            aux = NULL;
        }

    }

}

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
    aux->altura = 1;

    cout<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Su identificador es: "<<aux->identi<<endl;
    cout<<"**********************************"<<endl;
}

void registrarViaje(){
    datosViaje();
    
    cout<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Viaje registrado con exito."<<endl;
    cout<<"---------------------------"<<endl;

    if (raiz == NULL){ 
    
        raiz = aux;
        aux = NULL;
        free(aux);
    }else {
        aux2 = raiz;
        posicionarIdenti();
    }
    
}

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

}

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

void buscarP(char Buscar[10], viaje *Rama){ //Se buscaran los pasajeros de una embarcación en específico

    if (strcmp(Buscar, Rama->identi) == 0)
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
    
     int balance = ObtenerAltura(viaje);

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


//Funciones Pasajeros (FIFO)

void registrarPasajeros(viaje *recursive){

    int opcion = 0;
    int cont = 1;


    do
    {

        if (cont <= recursive->capacidad)
        {
            if (raiz->cab == NULL)
            {
                raiz->cab = (struct Pasajero *) malloc (sizeof(struct Pasajero));
                cout<<"Ingrese el primer nombre del pasajero: ";
                cin>>raiz->cab->nombre;

                cout<<"Ingrese el primer apellido del pasajero: ";
                cin>>raiz->cab->apellido;

                cout<<"Ingrese el ID del pasajero: ";
                cin>>raiz->cab->id;

                cout<<endl;
                cout<<"-------------------------"<<endl;
                cout<<"Pasajero registrado."<<endl;
                cout<<"-------------------------"<<endl;

                raiz->cab->sig = NULL;

            } else {
            
                auxP = (struct Pasajero *) malloc (sizeof(struct Pasajero));
                cout<<"Ingrese el primer nombre del pasajero: ";
                cin>>auxP->nombre;

                cout<<"Ingrese el primer apellido del pasajero: ";
                cin>>auxP->apellido;

                cout<<"Ingrese el ID del pasajero: ";
                cin>>auxP->id;
                auxP->sig = NULL;
                auxP2 = raiz->cab;

                cout<<endl;
                cout<<"-------------------------"<<endl;
                cout<<"Pasajero registrado."<<endl;
                cout<<"-------------------------"<<endl;

                while (auxP2->sig != NULL)
                {
                    auxP2 = auxP2->sig;
                }
                    auxP2->sig = auxP;
                    auxP2 = auxP = NULL;
                    free(auxP2);
                    free(auxP2);

                    free(auxP);
                    free(auxP2);

            }
            recursive->capacidad--;

            cout<<endl;
            cout<<"Desea agregar otro pasajero a esta embarcacion?"<<endl;
            cout<<endl;
            cout<<"1.       Si"<<endl;
            cout<<"2.       No"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;

        } else {

            cout<<"No hay cupos disponibles."<<endl;
            opcion = 2;
        }

        
        
    } while (opcion != 2);

    
}


void asignarViaje(char buscar[10]){

    int comparacion;
    comparacion = strcmp(buscar, Bviaje->identi);

    if (comparacion == 0){

        registrarPasajeros(raiz);

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
        asignarViaje(buscar);

    } else {

        cout<<"No hay viajes disponibles."<<endl;

    }

}


void mostrarP(char Buscar[10]){
    int i = 0; 
    int comparacion;
    comparacion = strcmp(Buscar,Bviaje->identi);
        
    if (comparacion == 0){
        for (auxP = raiz->cab; auxP != NULL; auxP=auxP->sig)
        {
            i++;
            cout<<i<<". Nombre del pasajero: "<<auxP->nombre<<endl;
            cout<<". Apellido del pasajero: "<<auxP->apellido<<endl;
            cout<<". ID del pasajero: "<<auxP->id<<endl;
            /*cout<<". Asiento del pasajero: "<<auxP->id<<endl; //cambiar*/
            cout<<"-----------------------------------------------------"<<endl;    
        }
    } else {
        cout<<"Identificador no valido."<<endl;
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

                registrarViaje();
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

            case 5:

                raiz->cab = NULL;
                auxP = NULL;
                auxP2 = NULL;     
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
