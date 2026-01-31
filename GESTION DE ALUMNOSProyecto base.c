#include <stdio.h>
#include <stdlib.h>
struct datos
{
    char escuela[40];
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
void cargarNotas(struct datos *alumno);

void guardarAlumnoTXT( struct datos *alumno);//lo que se carga en el struct datos, lño escrive en un archivo de texto CSV

int main (){ //MAIN PRINCIPAL
    struct datos *alumno =NULL; //puntero a struct
    int cantidad= 0;
    int op=0;
    int valido = 0;

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");
    do //Menu:
    {
        printf("MENU:\n");
        printf("1.ingresar alumno nuevo. \n");
        printf("2.Mostrar alumno./s | buscar alumnos/n \n");
        printf("3.Editar datos del alumno.\n");
        printf("4.Salir.\n");
        scanf("%d",&op);

        if(op > 4 || op < 1 ) //validacion de la opcion ingresada
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
                valido = 1;
            break;
        case 2:
            if(valido){
                //mostrarAlumno()
            }
            break;

        }
    }
    while(op!= 4);

return 0;
}


void cargarDatos(struct datos *alumno, int cantidad)
{
    system("cls");
    int agregar = 0;
    float prom = 0;

    for(int i=0; i<cantidad; i++)
    {
        printf("-DATOS DEL ALUMNO-\n");
        alumno[i].legajo = i+1;  /*alumno es un array, no un struct individual. asi que usamos el índice:*/
        printf("nombre: ");
        scanf("%s",alumno[i].nombre);
        printf("curso:");
        scanf("%s",alumno[i].curso);

        printf("\nDesea cargar las notas del alumno ahora? \n1.si\n 2.cargar despues");
        scanf("%d",&agregar);

        if(agregar == 1){
             cargarNotas(&alumno[i]);
        }
     guardarAlumnoTXT(&alumno[i]);
    }
    system("pause");
    system("cls");


};
void cargarNotas(struct datos *alumno){
        float prom;
        printf("Nota 1:  ");
        scanf("%f", &alumno->nota1);

        printf("Nota 2:  ");
        scanf("%f", &alumno->nota2);

        printf("Nota 3:  ");
        scanf("%f", &alumno->nota3);

        prom = (alumno->nota1 + alumno->nota2 + alumno->nota3) / 3;
        alumno->promedio =prom;
        if(alumno->promedio > 6.50){
            alumno->estado = 1;//si estado vale 1 significa que aprueba
        }else {
            alumno->estado = 0;//
        }

}
void guardarAlumnoTXT(struct datos *alumno){

    FILE *archivo = fopen("alumnos.txt","a");
    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(archivo, "%d;%s;$s;%.2f;%.2f;%.2f;%.2f;%d\n", alumno->legajo,alumno->nombre,alumno->curso,alumno->nota1,alumno->nota2,alumno->nota3,alumno->promedio,alumno->estado);
    fclose (archivo);
}



/*(25-01-26) NT: agregar una opcion que permita preguntar a que escuela quiere guardar
    el alumno.ej naciones, n·38 etc y guarde esos datos enla escuela... agregar una opcion que
    permita tambien "mover"esos datos de una escuela a otra y permita eliminarlo de su anterior escuela
    pero bueno eso mas adelante*/
