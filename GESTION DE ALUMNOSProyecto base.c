#include <stdio.h>
#include <stdlib.h>
struct datos{
    int id;
    char nombre [30];
    char curso[30];
    float promedio;
    int estado;
};/*Bueno vamos de nuevo, me gustaria hacerlo
 o tenerlo listo en una semana pero entiendo q v tomar tiempito al
 repasar conceptos... 19/12/25
*/

int menu (int ingreso, struct datos alumno);//Declaracion del menu del programa
void cargarDatos(struct datos alumno []);

int main (){ //MAIN PRINCIPAL
    /*(26-12-25): Empece a laburar en una YPF... Ahora me mantengo solito. y Justamente por eso necesito meter
     -le pata a la carrera, no me tengo que olvidar de lo mas importante pero es dificil ser equilibrado, hoy por lo menos
     meto 1 hora a la mañana(son las 11 asi que hasta las 12 tengo )*/

    int ingreso;
    struct datos alumno [4];

    printf("\t___GESTION DE ALUMNOS___\n\t     <Bienvenido>\n");

    menu(ingreso,alumno);//LLAMA AL MENU
return 0;
}
int menu(int ingreso, struct datos alumno[]){//MENU DEL PROGRAMA- ELECCION DE OPCIONES
   do{
    printf("MENU:\n");
    printf("1.ingresar alumno nuevo. \n");//ingresa y guarda los datos del alumno en un archivo de texto.
    printf("2.Buscar alumno./s \n");// Muestra uno o todos los alumnos dependiendo del filtro que se precise: curso, edad, nombre, año etc....
    printf("3.Editar datos del alumno.\n");// permite editar uno o varios datos juntos (ejemplo ponerles a todos una misma nota)
    printf("4.Salir.");
    printf("\nElija una opcion >>   \n ingrese un numero del 1 al 4. \nOpcion elegida: ");
    scanf("%d",&ingreso);
        if(ingreso > 4 || ingreso < 1 ){
            printf("\n ingrese un numero valido para acceder a una opcion del menu\n");// validar esto mas tarde***
            system("cls");
        }
        /*(28.12.25):DI VUELTAS CASI TODO EL DIA HASTA QUE ME SENTE A HACER ESTO...NO PUEDE SER QUE PROCRASTINE TANTO
        ENCIMA hoy me toca franco... hasta el otro domingo, la verdad no se como voy a a hacer para adiministrarme este mes
        tampoco se cuanto me van a pagar por estos dos trabajos.En fin, otro dia mas de estudio.
        */
        switch(ingreso){
            case 1://ingresa y guarda los datos del alumno en un archivo de texto.
                cargarDatos(alumno);//no recuerdo como se hacia para pasar por copia un array de struct...-_-
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("\nHasta luego!");
                break;
        }
   }while(ingreso!= 4);
};
void cargarDatos(struct datos alumno[]){/*(31.12.25)llegue muy cansado
                    con un dolor de pies tremendo despues del laburo y encima
                     no se puede estar adentro de casa por el calor qu hace en verano...
                     necesito comprar un aire, encima hoy  tengo reu*/
    //ingreso de datos del alumno
    system("cls");
    int cantidad=0;
    printf("ingreso de datos del alumno-\n");
    printf("\nCantidad de alumnos a ingresar: ");
    scanf("%d",&cantidad);
    for(int i=0;i<cantidad;i++){
        alumno[i].id=i;  /*alumno es un array, no un struct individual. asi que usamos el índice:*/
        printf("nombre: ");
        scanf("%s",alumno[i].nombre);
        printf("curso:");
        scanf("%s",alumno[i].curso);/*NT: el ingreso de las notas y el caluculo del promedio
                                    preguntar despues de la opcion 2 del menu por que sino se
                                    hace pesado*/
    }

};

