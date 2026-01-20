#include <stdio.h>
#include <stdlib.h>
struct datos
{
    int id;
    char nombre [30];
    char curso[30];
    float promedio;
    int estado;
};


int menu (int ingreso );//menu del programa
void cargarDatos( );//guarda los datos en el struct alumno

int main (){ //MAIN PRINCIPAL

    int ingreso;
    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");

    menu(ingreso);//LLAMA AL MENU
    return 0;
}

int menu(int ingreso) //MENU DEL PROGRAMA- ELECCION DE OPCIONES
{
     struct datos alumno [4];
    do
    {
        printf("MENU:\n");
        printf("1.ingresar alumno nuevo. \n");//ingresa y guarda los datos del alumno en un archivo de texto.
        printf("2.Buscar alumno./s \n");// Muestra uno o todos los alumnos dependiendo del filtro que se precise: curso, edad, nombre, año etc....
        printf("3.Editar datos del alumno.\n");// permite editar uno o varios datos juntos (ejemplo ponerles a todos una misma nota)
        printf("4.Salir.");
        printf("\nElija una opcion >>   \n ingrese un numero del 1 al 4. \nOpcion elegida: ");
        scanf("%d",&ingreso);
        if(ingreso > 4 || ingreso < 1 )
        {
            printf("\n ingrese un numero valido para acceder a una opcion del menu\n");// validar esto mas tarde***
            system("cls");
        }

        switch(ingreso)
        {
        case 1://ingresa y guarda los datos del alumno en un archivo de texto.

          cargarDatos();//no recuerdo como se hacia para pasar por copia un array de struct...-_-
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("\nHasta luego!");
            break;
        }
    }
    while(ingreso!= 4);
};
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
//version 1.0
///By FRANCOApps 2026
