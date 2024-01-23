/* Tarea 6. Programación y algoritmos.
    Parte 1. Lenguaje C.

                José Luis de León Carmona.
Ejercicio 2. Crear un archivo de estructuras con la siguiente información:
struct escuela {
char grupo; // A, B, C, D, E, F
char turno; // Matutino o Vespertino (toda la palabra)
}
struct estudiante {
char *nombre;
char * calif_promedio; // Formato USA {A+ > A > A- > B+ > B > B- > C+ >... > F-}
int edad;
struct escuela *E;
};
Leer el archivo como arreglo de estructuras y desplegar un menú de opciones que se
realicen de manera indefinida:
1) Imprimir archivo
2) Ordenar por nombre:
3) Ordenar por Edad;
4) Ordenar por Promedio
5) Número de estudiantes por grupo
6) Número de estudiantes por turno
7) Baja estudiante
8) Alta estudiante
9) Fin -> Imprimir arreglo final en archivo
Desplegar el resultado de cada opción seleccionada en pantalla dentro de la función
main(), no dentro de las función de ordenamiento (esto es, la función main() debe
conocer los cambios que se hicieron en cada una de las funciones).
NOTA 1: El archivo debe de darse como línea de comando (ejem: ./ ejecutable archivo),
usando los argumentos de main(argc,*argv[]).
NOTA 2: Cada vez que mande llamar a una función del sistema, verificar si existe error
mediante la variable errno.

NOTA 3: Usar solo una función para ordenar independientemente del tipo de dato; use
un apuntador a función como argumento para la comparación de datos en la función
ordenar.
NOTA 4: Las opciones 7-8 deben modificar el archivo final al imprimir los datos.

*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura escuela
struct escuela {
    char grupo; // A, B, C, D, E, F
    char *turno; // Matutino o Vespertino (toda la palabra)
};

// Definición de la estructura estudiante
struct estudiante {
    char *nombre;
    char *calif_promedio; // Formato USA {A+ > A > A- > B+ > B > B- > C+ >... > F-}
    int edad;
    struct escuela *E;
};

enum calificaciones {
    F_MINUS, F, F_PLUS, E_MINUS, E, E_PLUS,
    D_MINUS, D, D_PLUS, C_MINUS, C, C_PLUS,
    B_MINUS, B, B_PLUS, A_MINUS, A, A_PLUS
};

struct estudiante *readFile(const char* input_file, int *n);

void print(struct estudiante *estudiantes, int n);

void writeFile(struct estudiante *estudiantes, int n);

struct estudiante *sortName(struct estudiante *estudiantes, int n);

struct estudiante *sortAge(struct estudiante *estudiantes, int n);

struct estudiante *sortCalif(struct estudiante *estudiantes, int n);

int *countGruop(struct estudiante *estudiantes, int n);

int *countTurno(struct estudiante *estudiantes, int n);

struct estudiante *alta_estudiante(struct estudiante *estudiantes, int *n);

struct estudiante *baja_estudiante(struct estudiante *estudiantes, int *n);

enum calificaciones Numcalif(const char *str);

void freeStruc(struct estudiante *estudiantes, int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso %s <input file> \n", argv[0]);
    }

    const char* input_file = argv[1];
    int *n = (int *)calloc(1, sizeof(int));

    //Leer archvo
    struct estudiante *estudiantes;
    estudiantes = readFile(input_file, n);

    int opt;
    char grp;
    char *turno;
    int *cnts;

    while(opt!=9){
        printf( "\n               MENU:                   \n");
        printf("1.- Imprimir en pantalla.\n");
        printf("2.- Ordenar por nombre.\n");
        printf("3.- Ordenar por edad.\n");
        printf("4.- Ordenar por promedio.\n");
        printf("5.- Numero de estudiantes por grupo.\n");
        printf("6.- Numero de estudiantes por turno.\n");
        printf("7.- Baja de estudiante.\n");
        printf("8.- Alta de estudiante.\n");
        printf("9.- Finalizar programa.\n");

        scanf("%d",&opt);
        switch(opt){
            case 1:
                print(estudiantes, n[0]);
                break;
            case 2:
                estudiantes = sortName(estudiantes, *n);
                printf("\nLa base de datos ha sido ordenanda.\n");
                break;
            case 3:
                estudiantes = sortAge(estudiantes, *n);
                printf("\nLa base de datos ha sido ordenanda.\n");
                break;
            case 4:
                 estudiantes = sortCalif(estudiantes, *n);
                printf("\nLa base de datos ha sido ordenanda.\n");
            case 5:
                cnts = countGruop(estudiantes, *n);
                printf("En el grupo A hay %d alumnos.\n",cnts[0]);
                printf("En el grupo B hay %d alumnos.\n",cnts[1]);
                printf("En el grupo C hay %d alumnos.\n",cnts[2]);
                printf("En el grupo D hay %d alumnos.\n",cnts[3]);
                printf("En el grupo E hay %d alumnos.\n",cnts[4]);
                break;
            case 6:
                cnts = countTurno(estudiantes, *n);
                printf("En el turno Matutino hay %d alumnos.\n",cnts[0]);
                printf("En el turno Matutino hay %d alumnos.\n",cnts[1]);
                break;
            case 7:
                estudiantes = baja_estudiante(estudiantes, n);
                printf("El estudiante ha sido dado de baja.\n");
                break;
            case 8:
                estudiantes = alta_estudiante(estudiantes, n);
                printf("El estudinate ha sido dado de alta.\n");
                break;
            case 9:
                writeFile(estudiantes, n[0]);
                printf("La base de datos ha sido actualizada en out.txt");
                printf("Saliendo del programa ...");
                break;
            default :
                printf("Opcion invalida, intente otra opcion.\n");
        }
    }
    free(n);
    free(cnts);
    freeStruc(estudiantes, *n);

    return 0;
}

void freeStruc(struct estudiante *estudiantes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(estudiantes[i].nombre);
        free(estudiantes[i].calif_promedio);
        free(estudiantes[i].E->turno);
        free(estudiantes[i].E);
    }
    free(estudiantes);
}

enum calificaciones Numcalif(const char *str){
    if (strcmp(str, "A+") == 0) return A_PLUS;
    if (strcmp(str, "A") == 0) return A;
    if (strcmp(str, "A-") == 0) return A_MINUS;
    if (strcmp(str, "B+") == 0) return B_PLUS;
    if (strcmp(str, "B") == 0) return B;
    if (strcmp(str, "B-") == 0) return B_MINUS;
    if (strcmp(str, "C+") == 0) return C_PLUS;
    if (strcmp(str, "C") == 0) return C;
    if (strcmp(str, "C-") == 0) return C_MINUS;
    if (strcmp(str, "D+") == 0) return D_PLUS;
    if (strcmp(str, "D") == 0) return D;
    if (strcmp(str, "D-") == 0) return D_MINUS;
    if (strcmp(str, "E+") == 0) return E_PLUS;
    if (strcmp(str, "E") == 0) return E;
    if (strcmp(str, "E-") == 0) return E_MINUS;
    if (strcmp(str, "F+") == 0) return F_PLUS;
    if (strcmp(str, "F") == 0) return F;
    if (strcmp(str, "F-") == 0) return F_MINUS;

    return -1;
}



struct estudiante *baja_estudiante(struct estudiante *estudiantes, int *n) {
    printf("\nNombre del alumno unido por puntos: \n");
    int i;
    char nombre[100];
    scanf("%s", nombre);
    for(i=0; i<*n; i++){
        if(strcmp(estudiantes[i].nombre,nombre)==0){
            //Liberamos la memoria que hay en este lugar
            free(estudiantes[i].nombre);
            free(estudiantes[i].calif_promedio);
            free(estudiantes[i].E->turno);
            free(estudiantes[i].E);
            //Reorganizamos
            if (i < (*n) - 1) estudiantes[i] = estudiantes[(*n) - 1];
            (*n)--;
            estudiantes = (struct estudiante *)realloc(estudiantes, (*n)*sizeof(struct estudiante));
            return estudiantes;
        }
    }
    printf("\nAlumno no encontrado...\n");
    return estudiantes;
}

struct estudiante *alta_estudiante(struct estudiante *estudiantes, int *n) {
    estudiantes = (struct estudiante *)realloc(estudiantes, ((*n)+1)*(sizeof(struct estudiante)));

    struct estudiante *temp = (struct estudiante *)malloc(sizeof(struct estudiante));
    struct escuela *stemp = (struct escuela * )malloc(sizeof(struct escuela));
    temp->E = stemp;


    int edad;
    char nombre[100];
    char promedio[10];
    char grupo;
    char turno[20];

    printf("Ingrese el nombre del alumno unido por puntos \n");
    scanf("%s",nombre);

    printf("\nEdad: \n");
    scanf("%d", &edad);

    printf("\nIngrese el promedio. Formato USA.\n");
    scanf("%s",promedio);

    printf("\nIngrese el grupo: \n");
    scanf(" %c", &grupo);

    printf("\nIngrese el turno: \n");
    scanf("%s", turno);

    temp->nombre = strdup(nombre);
    temp->edad = edad;
    temp->calif_promedio = strdup(promedio);
    temp->E->grupo = grupo;
    temp->E->turno = strdup(turno);

    estudiantes[*n] = *temp;
    (*n)++;

    return estudiantes;
}

int *countTurno(struct estudiante *estudiantes, int n) {
    int i;
    int *t = (int *)calloc(2, sizeof(int));

    for(i=0; i<n; i++){
        if(strcmp(estudiantes[i].E->turno,"Matutino")==0) t[0]++;
        else if(strcmp(estudiantes[i].E->turno,"Vespertino")==0) t[1]++;
    }
    return t;
}

int *countGruop(struct estudiante *estudiantes, int n) {
    int i;
    int *g = (int *)calloc(5, sizeof(int));

    for( i=0; i<n; i++){
        switch(estudiantes[i].E->grupo){
            case 'A':
                g[0]++;
                break;
            case 'B':
                g[1]++;
                break;
            case 'C':
                g[2]++;
                break;
            case 'D':
                g[3]++;
                break;
            case 'E':
                g[4]++;
                break;
        }
    }
    return g;


}

struct estudiante *sortCalif(struct estudiante *estudiantes, int n) {
    int i, j;
    struct estudiante temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (Numcalif(estudiantes[j].calif_promedio) > Numcalif(estudiantes[j + 1].calif_promedio)) {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
    return estudiantes;
}

struct estudiante *sortAge(struct estudiante *estudiantes, int n) {
    int i, j;
    struct estudiante temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (estudiantes[j].edad > estudiantes[j + 1].edad) {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
    return estudiantes;
}

struct estudiante *sortName(struct estudiante *estudiantes, int n) {
    int k = 0;
    int i, j;
    struct estudiante temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            k = strcmp(estudiantes[j].nombre, estudiantes[j+1].nombre);
            if (k > 0) {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
    return estudiantes;
}


void writeFile(struct estudiante *estudiantes, int n) {
    FILE *output_file = fopen("out.txt", "w");
    if (output_file == NULL) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    int i;

    for(i = 0; i < n; i++) {
        fprintf(output_file, "%s %s %d %c %s \n", estudiantes[i].nombre, estudiantes[i].calif_promedio, estudiantes[i].edad, estudiantes[i].E->grupo, estudiantes[i].E->turno);
    }

    fclose(output_file);
}

void print(struct estudiante *estudiantes, int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%s %s %d %c %s \n", estudiantes[i].nombre, estudiantes[i].calif_promedio, estudiantes[i].edad, estudiantes[i].E->grupo, estudiantes[i].E->turno);
    }
}

struct estudiante *readFile(const char* input_file, int *n) {
    FILE* file = fopen(input_file, "r");

    if (file == NULL) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    *n = 0; //numero de estudiante
    char c;

    while ( (c = fgetc(file)) != EOF) {
        if (c == '\n') {
            (*n)++;
        }
    }

    fseek(file, 0, SEEK_SET);

    //Crear memoria para almacenar los estudiantes en el archivo
    struct estudiante *estudiantes;
    struct escuela *temp;

    estudiantes = (struct estudiante *)malloc(*n * sizeof(struct estudiante));
    int i;
    for (i = 0; i < *n; i++) {
        temp = (struct escuela *)malloc(sizeof(struct escuela));
        estudiantes[i].E = temp;
    }

    for (i = 0; i < *n; i++) {
        int edad;
        char nombre[100];
        char promedio[10];
        char grupo;
        char turno[10];
        fscanf(file, "%s %s %n %c %s", nombre, promedio, &edad, &grupo, turno);

        estudiantes[i].nombre = strdup(nombre);
        estudiantes[i].edad = edad;
        estudiantes[i].calif_promedio = strdup(promedio);
        estudiantes[i].E->grupo = grupo;
        estudiantes[i].E->turno = strdup(turno);
    }

    fclose(file);

    return estudiantes;
}

