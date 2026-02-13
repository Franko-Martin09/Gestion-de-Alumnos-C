#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    int estado;//1 aprobado, 0 desaprobado
    int datosCargados;// flag para saber si guardarlo o no en el txt.
};


int menu (int ingreso );//menu del programa
void cargarDatos( struct datos *alumno, int cantidad);//guarda los datos en el struct alumno
void cargarNotas(struct datos *alumno);

void guardarAlumnoTXT( struct datos *alumno);//lo que se carga en el struct datos, lño escrive en un archivo de texto CSV

void salir(struct datos *alumno, int cantidad);//recorre todo el struct cargado para verficar si: 1 el alumno fue cargado

int main (){ //MAIN PRINCIPAL
    struct datos *alumno =NULL; //puntero a struct
    int cantidad= 0;
    int op=0;
    int valido = 0, opSalir = 0;

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");
    do //Menu:
    {
        printf("MENU:\n");
        printf("1.Ingresar alumno nuevo. \n");
        printf("2.Mostrar alumno./s | buscar alumnos/n \n");
        printf("3.Editar datos del alumno. | Eliminar Alumno. | Editar registros.\n");
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
                printf("\n||REGISTROS||\n");
                printf("\n1.Mostrar Alumnos ");
                printf("\n2.Buscar Alumnos");
                scanf("%d",&valido);
                if(valido == 1){
                    //mostrarAlumno()
                }if(valido == 2){
                    buscarAlumno(alumno,cantidad);
                }
            }
            break;
        case 4:

            for(int i =0;i<cantidad; i++){//for para recorrer y buscar
                if (alumno[i].datosCargados == 0){
                    printf("\nHay alumnos sin cargar datos desea salir sin guardar cambios? \n(1.Si/2.No) : ");
                    printf("\n ¡¡Se perderan todos los alumnos que no hayan sido completados!!");
                    scanf("%d",&opSalir);
                    if(opSalir == 1){
                        salir(alumno,cantidad);
                    }else{
                        printf("\nGuardando registros y cerrando el programa...");
                        printf("\n\t >>Presione 'Enter' para cerrar esta ventana<<");
                    }
                }
            }
            break;

        }
    }
    while(op!= 4);

return 0;
}


void cargarDatos(struct datos *alumno, int cantidad)// Carga los datos básicos del alumno, el usuario elige si desea cargar o no las notas en ese momento.
{
    system("cls");
    int agregar = 0;
    float prom = 0;

    for(int i=0; i<cantidad; i++)
    {
        printf("-DATOS DEL ALUMNO-\n");
        alumno[i].legajo = i+1;  /*alumno es un array, no un struct individual. asi que usamos el índice:*/
        printf("\n Año: ");
        scanf("%d",&alumno[i].year);
        printf("\nnombre: ");
        scanf("%s",alumno[i].nombre);
        printf("\ncurso:");
        scanf("%s",alumno[i].curso);

        printf("\nDesea cargar las notas del alumno ahora? \n1.si\n 2.cargar despues");
        scanf("%d",&agregar);

        if(agregar == 1){//si elige cargar completamente el alumno datosCargados vale 1 por que estaria completo.
             cargarNotas(&alumno[i]);//se cargan las notas.
        } else{
             alumno[i].datosCargados=0;// '1'para completo, '0' para incompleto.
        }

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
        alumno->datosCargados = 1;//alumno completo una vez que se cargan las notas
}
void guardarAlumnoTXT(struct datos *alumno){//debe usarse al final solo cuando todos lo datos esten cargados(tengo que aprender a editar txt)

    FILE *archivo = fopen("alumnos.txt","a");
    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f;%d\n", alumno->legajo,alumno->nombre,alumno->curso,alumno->nota1,alumno->nota2,alumno->nota3,alumno->promedio,alumno->estado);
    fclose (archivo);
}

void salir(struct datos *alumno, int cantidad){//funcion clave para recorrer el struct cargado. y saber si hay alumnos incompletos...
    system("cls");
    int op=0;
    printf("\n||CIERRE DE PROGRAMA- GUARDADO DE REGISTROS ||");
    for(int i=0; i<cantidad; i++) {
            if(alumno[i].datosCargados == 0){
                printf("Alumno legajo: Nro %d \n Faltan datos, desea cargarlos? (1.Si|2.No)",alumno[i].legajo +1);
                scanf("%d",&op);
                if(op == 1){//el usuario decide completar los datos del alumno
                    cargarNotas(&alumno[i]);
                    guardarAlumnoTXT(&alumno[i]);//guardar todo en el archivo.
                }if(op == 2){//el usuario decide NO completar los datos del alumno.
                    printf("\nNo se agregaron los datos faltantes, para agregarlos mas tarde vaya a la opcion (3)'Editar alumno'.");
                }if(alumno[i].datosCargados ==1){//si esta completo se guarda en el archivo.
                    guardarAlumnoTXT(&alumno[i]);
                }
            }
    }
    //salir detecta problemas y le pregunta al user que quiere hacer con eso...
}


//voy a hacer esto solo.
/*¿Un alumno incompleto puede existir en memoria? si, osea que puede estar incompleto pero solo mientras no se lo guarda, si se lo guarda debe completarse

¿Un alumno incompleto puede existir en el archivo? NO... solo se toca el archivo de texto cuando  ya esta completo el struct.

¿El archivo se escribe muchas veces o una sola vez? por el momento 1 sola vez. al finalizar el programa guarda todo...carga de datos + ediciones

¿Quién tiene la última palabra: el usuario o el programa? en definitiva, el programa, el usuario solo se adapta a las reglas no?
*/
///TArea para Mañana:  definir las 3 reglas del programa y Hacer validacion usando CargarDatos como flag.
// 1. Un alumno solo se guarda en archivo cuando está completo
//2. un alumno esta completo cuando datosCargados vale 1
//3.
/*(25-01-26) NT: agregar una opcion que permita preguntar a que escuela quiere guardar
    el alumno.ej naciones, n·38 etc y guarde esos datos enla escuela... agregar una opcion que
    permita tambien "mover"esos datos de una escuela a otra y permita eliminarlo de su anterior escuela
    pero bueno eso mas adelante*/
