#include <stdio.h>
#include <stdlib.h>
struct datos
{
    int legajo;
    int year;
    char nombre [30];
    char curso[30];
    float nota1;
    float nota2:
    float nota3;
    float promedio;
    int estado;
};


int menu (int ingreso );//menu del programa
void cargarDatos( satruct datos *alumno);//guarda los datos en el struct alumno

int main (){ //MAIN PRINCIPAL
    struct datos *alumno; //puntero a struct
    alumno=malloc(sizeof(strcut datos)); //malloc + el peso de un struct
    int op=0;

    if(alumno == Null){//validacion de memoria asignada
        printf("\nError al asignar memoria.\n");
        return 1;
    }

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");
    do
    {
        printf("MENU:\n");
        printf("1.ingresar alumno nuevo. \n");
        printf("2.Buscar alumno./s \n");
        printf("3.Editar datos del alumno.\n");
        printf("4.Salir.");
        scanf("%d",&op);

        if(op > 4 || op < 1 )
        {
            printf("\n ingrese una opcion valida");
            system("cls");
        }

        switch(op) {
        case 1: cargarDatos(alumno);
            break;

        }
    }
    while(op!= 4);

return 0;
}


void cargarDatos()
{

    //ingreso de datos del alumno
    system("cls");
    int cantidad=0;
    printf("ingreso de datos del alumno-\n");
    printf("\nCantidad de alumnos a ingresar: ");
    scanf("%d",&cantidad);
    for(int i=0; i<cantidad; i++)
    {
        alumno[i].id=i;  /*alumno es un array, no un struct individual. asi que usamos el índice:*/
        printf("nombre: ");
        scanf("%s",alumno[i].nombre);
        printf("curso:");
        scanf("%s",alumno[i].curso);
    }

};

