#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura donde se guardan los datos del alumno
struct datosAlumno
{
    char *nombre;
    int creditos;
    int semestre;
};

typedef struct datosAlumno Alumno;
typedef Alumno *AlumnoPtr; 


//Estrutura anidada donde se guardan los datos y la dirección
struct nodo
{
    Alumno estudiante;
    struct nodo *siguiente;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr; 


//Firmas de funciones
NodoPtr crearNodo(AlumnoPtr);
void insertarNodoOrdenadoCréditos(NodoPtr*, NodoPtr);
AlumnoPtr crearAlumno(char*, int, int);
void imprimirLista(NodoPtr);

int main(){

    NodoPtr cabecera=NULL;

    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(crearAlumno("Kuh Esquivel Mauro Arif", 28, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(crearAlumno("Ruz Ruz Carlos Israel", 35, 4)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(crearAlumno("Gongora Tun Jaqueline", 30, 7)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(crearAlumno("Gonzales Mariana Estefanía", 40, 6)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(crearAlumno("Rodriguez Couoh Isaias Orlando", 32, 3)));
    imprimirLista(cabecera);

    return 0;

}


//Se guardan los datos de los alumnos en la estructura
AlumnoPtr crearAlumno(char *nombre, int creditos, int semestre){

    AlumnoPtr nuevo;
    nuevo = (AlumnoPtr)malloc(sizeof(Alumno));

    nuevo->nombre=strdup(nombre);
    nuevo->creditos=creditos;
    nuevo->semestre=semestre;

    return nuevo;
}


NodoPtr crearNodo(AlumnoPtr nuevo){
    
    NodoPtr nodoNuevo;
    nodoNuevo= (NodoPtr)malloc(sizeof(Nodo));

    nodoNuevo->estudiante.nombre= strdup(nuevo->nombre);
    nodoNuevo->estudiante.creditos=nuevo->creditos;
    nodoNuevo->estudiante.semestre=nuevo->semestre;
    nodoNuevo->siguiente=NULL;

    return nodoNuevo;
}

void insertarNodoOrdenadoCréditos(NodoPtr* cabecera, NodoPtr nuevo){

  NodoPtr actual, anterior;

    if(*cabecera == NULL){
        *cabecera=nuevo;
    }else{
        actual=*cabecera;
        anterior=NULL;

        while (actual->siguiente != NULL && (nuevo->estudiante.creditos < actual->estudiante.creditos)){
        anterior=actual;
        actual=actual->siguiente;
    }

    if(actual==NULL ||(actual!=NULL && anterior != NULL)){
        nuevo->siguiente=anterior->siguiente;
        anterior->siguiente= nuevo;
    }else{
        nuevo->siguiente=actual;
        *cabecera=nuevo;
    }
        

    }


}

void imprimirLista(NodoPtr cabecera){

if(cabecera==NULL){
    puts("Lista Vacía");
    return;
}else{
    while (cabecera!=NULL)
    {
      printf("%s, %d, %d -->", cabecera->estudiante.nombre,cabecera->estudiante.creditos, cabecera->estudiante.semestre);
      cabecera=cabecera->siguiente;  
    }
    
    printf("--> Null \n");

}

}