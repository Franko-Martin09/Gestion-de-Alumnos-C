#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct datos //Definicion de estructura para datos del alumno-
{
    //char escuela[40];
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

//Persistencia (archivo):
struct datos* cargarDesdeArchivo(int *cantidad);
void guardarAlumnoTXT( struct datos *alumno);//lo que se carga en el struct datos, lo escribe en un archivo de texto con formato CSV
void salir(struct datos *alumno, int cantidad);//recorre todo el struct cargado para verficar si: 1 el alumno fue cargado

//Sistema (Lógica del programa):
void cargarDatos( struct datos *alumno, int cantidad);//guarda los datos en el struct alumno
void cargarNotas(struct datos *alumno);// completa los datos faltantes(notas y promedio) del alumno.

//Interfaz (visualizacion del programa):

int main (){ //MAIN PRINCIPAL
        int cantidad= 0;
        struct datos *alumno = cargarDesdeArchivo(&cantidad);

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
        case 1:// Carga de alumno: !!Ojo aca deberia haber una validacion/lectura del archivo de txt para ver si lo que ingresa no esta ya ingresado no?
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
        case 2:// Buscar alumnos | Mostrar registros
            if(valido){
                printf("\n||REGISTROS||\n");
                printf("\n1.Mostrar Alumnos ");
                printf("\n2.Buscar Alumnos");
                scanf("%d",&valido);
                if(valido == 1){
                    //mostrarAlumno()
                }if(valido == 2){
                    salir(alumno,cantidad);
                }
            }
            break;
        case 3: //Editar datos del alumno. | Eliminar Alumno. | Editar registros

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
    free(alumno);
return 0;
}
struct datos *alumno cargarDesdeArchivo( int *cantidad){//cargar desde archivo de texto, recibe por parametro cantidad para saber cuanto
    FILE *archivo = fopen("alumnos.txt","r");//Esta es la funcion para 'abrir' archivos.
    int contador= 0;//para contar si hay alumnos en el archivo con el while
    struct datos aux;

    if(archivo==NULL){//validacion de que se pudo abrir el archivo.
        printf("\n Datos no cargados. ingrese registros_ ");
        *cantidad= 0;// no hay alumnos
        return NULL;//no hay memoria
    }else{
           //lee linea por linea (9) , es como un printf inverso y va contando alumnos hasta llegar a 9 datos por linea. si hay 10 datos no los va a leer
            while (fscanf(archivo,"%d %d %s %s %f %f %f %f %d",
              &aux.legajo,
              &aux.year,
              aux.nombre,
              aux.curso,
              &aux.nota1,
              &aux.nota2,
              &aux.nota3,
              &aux.promedio,
              &aux.estado) == 9) {
                contador++;
            }
       rewind(archivo);//"rebobina" hasta el principio y te pocisiona al principio del archivo
       struct datos *alumnos = malloc(sizeof(struct datos) * contador);
       for (int i = 0; i < contador; i++) {

    fscanf(archivo,"%d %d %s %s %f %f %f %f %d",
           &alumnos[i].legajo,
           &alumnos[i].year,
           alumnos[i].nombre,
           alumnos[i].curso,
           &alumnos[i].nota1,
           &alumnos[i].nota2,
           &alumnos[i].nota3,
           &alumnos[i].promedio,
           &alumnos[i].estado);
    }
    }

*cantidad = contador;
fclose(archivo);
return alumnos;
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

    FILE *archivo = fopen("alumnos.txt","w");
    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f;%d\n", alumno->legajo,alumno->nombre,alumno->curso,alumno->nota1,alumno->nota2,alumno->nota3,alumno->promedio,alumno->estado);
    fclose (archivo);
}

void salir(struct datos *alumno, int cantidad){// recorre el struct cargado. para si hay alumnos incompletos...
    system("cls");
    int op=0;
    printf("\n||CIERRE DE PROGRAMA- GUARDADO DE REGISTROS ||");
    for(int i=0; i<cantidad; i++) { //salir detecta datos incompletos y le pregunta al usuario que quiere hacer con eso...
            if(alumno[i].datosCargados == 0){
                printf("Alumno legajo: Nro %d \n Faltan datos, desea cargarlos? (1.Si|2.No)",alumno[i].legajo +1);
                scanf("%d",&op);
                if(op == 1){// si decide completar los datos del alumno
                    cargarNotas(&alumno[i]);
                }if(op == 2){// si decide NO completar los datos del alumno.
                    printf("\nNo se agregaron los datos faltantes, para agregarlos mas tarde vaya a la opcion (3)'Editar alumno'.");
                }
            }
    }
    for(int i=0; i<cantidad; i++) {
         if(alumno[i].datosCargados ==1){//si esta completo se guarda en el archivo.
          guardarAlumnoTXT(&alumno[i]);//guardar todo en el archivo.
         }
    }
}


//(23-2-26):Ok, esto se está complejisando...pucha
/* (19/2-26): correcciones a hacer>
            1 corregir datos duplicados-
            2 Liberar memoria antes de terminar el programa
            3 Corregir fuga de memoria
            4 Mostrar alumnos
            5 Buscar alumnos
*/

/// 1. Un alumno solo se guarda en archivo cuando está completo
/// 2. un alumno esta completo cuando datosCargados vale 1

//voy a hacer esto solo.
/*(25-01-26) NT: agregar una opcion que permita preguntar a que escuela quiere guardar
    el alumno.ej naciones, n·38 etc y guarde esos datos enla escuela... agregar una opcion que
    permita tambien "mover"esos datos de una escuela a otra y permita eliminarlo de su anterior escuela
    pero bueno eso mas adelante*/
