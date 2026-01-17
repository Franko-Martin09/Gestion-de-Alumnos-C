#include <stdio.h>
#include <stdlib.h>

#define CANT 3

struct datos{
    int legajo;
    char nombre[30];
    float nota;
};

void cargarAlumno(struct datos alumno[], float *max);
void mostrarAlumno(struct datos alumno[], float max);
float calcularPromedio(struct datos alumno[]);
void buscarLegajo(struct datos alumno[]);

int main(){
    struct datos alumno[CANT];
    int op = 0;
    int valido = 0;//validacion para poder acceder al case/opcion 2
    float max = 0;
    int mostrar;

    while(op != 4){
        printf("\nMenu gestion de notas");
        printf("\n1. Ingresar alumnos");
        printf("\n2. Mostrar registros");
        printf("\n3. Buscar alumno por legajo");
        printf("\n4. Salir\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                cargarAlumno(alumno, &max);
                valido = 1;
                system("cls");
                break;

            case 2:
                if(valido){
                    mostrarAlumno(alumno, max);
                    system("pause");
                    printf("\n Mostrar promedios del curso? ('1' confirmar)");
                    scanf("%d",&mostrar);
                    if(mostrar == 1){
                       calcularPromedio(alumno);
                    }
                    system("pause");
                    system("cls");
                } else {
                    printf("\nPrimero cargue alumnos\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                if(valido){
                    buscarLegajo(alumno);
                }
        }
    }

    return 0;
}

void cargarAlumno(struct datos alumno[], float *max){
    *max = 0;

    for(int i = 0; i < CANT; i++){
        printf("\nAlumno %d", i + 1);

        printf("\nLegajo: ");
        scanf("%d", &alumno[i].legajo);

        printf("Nombre: ");
        scanf("%29s", alumno[i].nombre);

        printf("Nota: ");
        scanf("%f", &alumno[i].nota);

        if(alumno[i].nota > *max){
            *max = alumno[i].nota;
        }
    }
}

void mostrarAlumno(struct datos alumno[], float max){
    printf("\nAlumnos cargados:");

    for(int i = 0; i < CANT; i++){
        printf("\n\nAlumno %d", i + 1);
        printf("\nLegajo: %d", alumno[i].legajo);
        printf("\nNombre: %s", alumno[i].nombre);
        printf("\nNota: %.2f", alumno[i].nota);

        if(alumno[i].nota >= 6){
            printf("\nEstado: APROBADO");
        } else {
            printf("\nEstado: DESAPROBADO\n");
        }

        if(alumno[i].nota == max){
            printf("\n>> NOTA MAS ALTA <<");
        }
     }
}
float calcularPromedio(struct datos alumno []){//aclaracion: Promedio del curso, no de cada alumno:
    float suma =0;

    printf("\nPromedio de cada estudiante: ");
    for(int i = 0; i < CANT; i++){
        suma += alumno[i].nota;
    }
    printf("\nPromedio del curso: %.2f", suma/3);
}
void buscarLegajo(struct datos alumno[]){
    int encontrado =0;
    int comparacion=0;

    printf("\n===BUSQUEDA POR LEGAJO(alumnos)===");
    printf("\nIngrese legajo del alumno: ");
    scanf("%d",&comparacion);

    for(int i = 0; i < CANT; i++){
        if(alumno[i].legajo == comparacion){
            encontrado = 1;

                printf("\nBusqueda finalizada: ");
                printf("\n\nAlumno %d", i + 1);
                printf("\nLegajo: %d", alumno[i].legajo);
                printf("\nNombre: %s", alumno[i].nombre);
                printf("\nNota: %.2f", alumno[i].nota);
         }
    }
    if(!encontrado){
       printf("\n<No se encontraron coincidencias>");
    }
    system("pause");
    system("cls");
}
