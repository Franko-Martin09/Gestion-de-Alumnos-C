#include <stdio.h>
#include <stdlib.h>

struct datos
{
    int id;
    char nombre[30];
    char curso[30];
    float promedio;
    int estado;
};

int menu(int ingreso);
void cargarDatos(struct datos alumno[], int max);

int main()
{
    int ingreso = 0;

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");

    menu(ingreso);
    return 0;
}

int menu(int ingreso)
{
    struct datos alumno[4];

    do
    {
        printf("\nMENU:\n");
        printf("1. Ingresar alumno nuevo\n");
        printf("2. Buscar alumno/s\n");
        printf("3. Editar datos del alumno\n");
        printf("4. Salir\n");
        printf("Opcion elegida: ");
        scanf("%d", &ingreso);

        if (ingreso < 1 || ingreso > 4)// validación de opcion elegida
        {
            printf("Opcion invalida\n");
            system("cls");
        }

        switch (ingreso)
        {
        case 1:
            cargarDatos(alumno, 4);//memoria dinamica y punteros
            break;

        case 4:
            printf("Hasta luego!\n");
            break;
        }
    }
    while (ingreso != 4);

    return ingreso;
}

void cargarDatos(struct datos alumno[], int max)
{
    int cantidad;

    system("cls");
    printf("Ingreso de datos del alumno\n");
    printf("Cantidad de alumnos a ingresar (max %d): ", max);
    scanf("%d", &cantidad);

    if (cantidad > max)
        cantidad = max;j

    for (int i = 0; i < cantidad; i++)
    {
        alumno[i].id = i;

        printf("Nombre: ");
        scanf("%s", alumno[i].nombre);

        printf("Curso: ");
        scanf("%s", alumno[i].curso);

        alumno[i].estado = 1;
    }
}
int mostrar datos (){
 printf(" Mostrando todos los registros de alumnos oredenados por curso- ")
 printf("Año 2026: 1A: CLASE :");
 for (int i: )//por hoy lo voy a dejar a ca pero se que tengo que tener un limite para no desbordarme conmigo mismo...."6/1/26-

}
