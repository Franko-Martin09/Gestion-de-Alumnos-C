#include <stdio.h>
#include <stdlib.h>
struct datos
{
    int legajo;
    int year;
    char nombre [30];
    char curso[30];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
    int estado;
};


int menu (int ingreso );//menu del programa
void cargarDatos( struct datos *alumno, int cantidad);//guarda los datos en el struct alumno

int main (){ //MAIN PRINCIPAL
    struct datos *alumno =NULL; //puntero a struct
    int cantidad= 0;
    int op=0;

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");
    do //Menu:
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
        case 1:// Carga de alumno:
                printf("ingreso de datos del alumno-\n");
                printf("\nCantidad de alumnos a ingresar: ");
                scanf("%d",&cantidad);
                alumno=malloc(sizeof(struct datos) * cantidad); //malloc + el peso de un struct, cantidad es cuantos struct va a usar
                if(alumno == NULL){//validacion de memoria asignada
                    printf("\nError al asignar memoria.\n");
                    return 1;
                }
                cargarDatos(alumno,cantidad);//1ra opcion carga de datos
            break;

        }
    }
    while(op!= 4);

return 0;
}


void cargarDatos(struct datos *alumno, int cantidad)
{
    system("cls");

    for(int i=0; i<cantidad; i++)
    {
        alumno[i].legajo = i+1;  /*alumno es un array, no un struct individual. asi que usamos el índice:*/
        printf("nombre: ");
        scanf("%s",alumno[i].nombre);
        printf("curso:");
        scanf("%s",alumno[i].curso);
    }
    system("pause");
    system("cls");

};
/*(25-01-26) NT: agregar una opcion que permita preguntar a que escuela quiere guardar
    el alumno.ej naciones, n·38 etc y guarde esos datos enla escuela... agregar una opcion que
    permita tambien "mover"esos datos de una escuela a otra y permita eliminarlo de su anterior escuela
    pero bueno eso mas adelante*/
