/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona

    Ejercicio 1. Strings

    (20%) Escriba un programa que realice las siguientes operaciones sobre cadenas de
caracteres (strings); no usar memoria dinámica:
a) int Longitud_str(str): Función que regrese la longitud de un string str (sin contar el
carácter nulo);
b) char *copia_str(dst, src): copia el string src a dst, incluyendo el carácter nulo \0;
regresa un apuntador a dst.
Nota: La función debe verificar que los strings no estén superpuestos y si hay
suficiente espacio en dst para copia src; en caso que no, incluir solo hasta donde sea
posible almacenar en dst;
c) int compara_str(str1, str2): Función que compare lexicográficamente dos strings y
regrese un número mayor que, igual a o menor que cero, si str1 es mayor que, igual a
o menor que str2. El valor que regrese debe coincidir con la diferencia en magnitud
del caracter actual comparado;
d) int concatena_str(str1, str2, str3): Función que concatene tres strings (en el orden
dado) separados por un espacio y los almacene en str1; debe regresar la nueva
longitud de str1;
Nota: La función debe verificar que los strings no estén superpuestos y si hay
suficiente espacio en str1 para almacenar todos losstrings; en caso que no, incluir solo
hasta donde sea posible almacenar en str1;
e) int encuentra_str(str1, str2): Función que busque un sub-string str1 en str2 y regrese
el número de veces que lo encuentra.
f) int **frecuencia(str): Encuentre la frecuencia de cada elemento de str, y regrese un
arreglo bidimensional donde se almacene la letra (1er columna) y frecuencia (2da
columna).
Salida: w – 10, r – 5, s – 4, etc..
NOTA: En este ejercicio pueden usar memoria estáQca o dinámica.
g) char *sin_repeBr(str): Función que encuentre las palabras en str que no tengan letras
repeQdas y las imprima (dentro de la misma función por simplicidad)

*****************************************************/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LENGTH 10

int Longitud_str(char str[]);

char *copia_str(char *dst, char *src);

int compara(char str1[], char str2[]);

int concatena_str(char *str1, char *str2, char *str3);

int encuentra_str(char *str1, char *str2);

void frecuencia(const char *str);

bool tiene_letras_repetidas(const char *palabra);

void sin_repetir(const char *str);



int main() {
    //Inciso a
    printf("Inciso a) \n");
    printf("*********************************************** \n");
    char str[] = "September 2021";

    int longitud = Longitud_str(str);

    printf("La longitud de %s es: %d \n", str, longitud);


    //Inciso b
    printf("*********************************************** \n\n");
    printf("Inciso b) \n");
    printf("*********************************************** \n");

    char src[] = "Hola, mundo!";
    char dst[10]; // Tamaño de menos

    copia_str(dst, src);

    printf("src: %s\n", src);
    printf("dst: %s\n", dst);


    //Inciso c
    printf("*********************************************** \n\n");
    printf("Inciso c) \n");
    printf("*********************************************** \n");

    char str1[] = "tres";
    char str2[] = "dos";

    int result = compara(str1, str2);

    if (result > 0) {
        printf("La cadena: %s es mayor que %s por %d \n", str1, str2, result);
    } else if (result < 0) {
        printf("La cadena: %s es mayor que %s por %d \n", str2, str1, result);
    } else {
        printf("La cadena: %s es igual a %s \n", str1, str2);
    }

    //Inciso d
    printf("*********************************************** \n\n");
    printf("Inciso d) \n");
    printf("*********************************************** \n");

    char str1_d[MAX_LENGTH] = "Hola,";
    char *str2_d = "esto";
    char *str3_d = "funciona?";

    int nueva_longitud = concatena_str(str1_d, str2_d, str3_d);
    printf("str1: %s\n", str1_d);
    printf("Nueva longitud de str1: %d\n", nueva_longitud);

    //Inciso e
    printf("*********************************************** \n\n");
    printf("Inciso e) \n");
    printf("*********************************************** \n");

    char *str1_e = "ab";
    char *str2_e = "ababcabab";

    int veces_encontrado = encuentra_str(str1_e, str2_e);
    printf("'%s' se encontró %d veces en '%s'\n", str1_e, veces_encontrado, str2_e);


    //Inciso f
    printf("*********************************************** \n\n");
    printf("Inciso f) \n");
    printf("*********************************************** \n");

    const char *str_f = "abracadabra";
    frecuencia(str_f);

    //Inciso g
    printf("\n *********************************************** \n\n");
    printf("Inciso g) \n");
    printf("*********************************************** \n");

    const char *str_g = "hola mundo programacion hasimoto cimat";
    printf("Palabras sin letras repetidas: ");
    sin_repetir(str_g);






    return 0;






    return 0;
}

int Longitud_str(char str[]) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0' ) {
        count++;
        i++;
    }

    return count;
}


char *copia_str(char *dst, char *src) {
    // Verifica si los punteros no son nulos
    if (dst == NULL || src == NULL) {
        return NULL;
    }

    size_t size = sizeof(dst); // Obtiene el tamaño del búfer dst
    char *dst_start = dst; // Guarda el inicio del destino

    // Copia cada carácter de src a dst hasta que alcance size o encuentre '\0'
    while (*src != '\0' && size > 1) {
        *dst = *src;
        dst++;
        src++;
        size--;
    }

    *dst = '\0'; // Agrega el carácter nulo al final

    return dst_start; // Devuelve el puntero al inicio de dst
}



int compara(char str1[], char str2[]) {
    int i=0, aux=0;

    while ( (str2[i] != '\0') && (str1[i]!='\0') ) {

        if (str1[i] != str2[i]) {
            aux = str1[i] - str2[i];
            return aux;
        }
        i++;
    }

    aux = 0;
    return aux;

}

int concatena_str(char *str1, char *str2, char *str3) {
    // Calcula la longitud de str1, str2 y str3
    int len1 = Longitud_str(str1);
    int len2 = Longitud_str(str2);
    int len3 = Longitud_str(str3);


    // Verifica si hay suficiente espacio en str1
    int total_length = len1 + len2 + len3 + 2; // 2 para los dos espacios
    if (total_length >= MAX_LENGTH) {
        total_length = MAX_LENGTH - 1; // Resta 1 para el carácter nulo
    }

    // Concatena los strings en str1
    int i;
    for (i = 0; i < len2 && len1 + i < total_length - 1; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + i] = ' '; // Agrega un espacio entre str2 y str3
    for (int j = 0; j < len3 && len1 + i + 1 < total_length - 1; i++, j++) {
        str1[len1 + i + 1] = str3[j];
    }
    str1[len1 + i + 1] = '\0'; // Agrega el carácter nulo al final

    return len1 + i + 1; // Devuelve la nueva longitud de str1
}

int encuentra_str(char *str1, char *str2) {
    int count = 0;
    int str1_len = Longitud_str(str1);
    int str2_len = Longitud_str(str2);

    if (str1_len == 0) {
        return -1; // Substring vacío, no se puede buscar
    }

    if (str1_len > str2_len) {
        return 0; // str1 es más largo que str2, no puede estar contenido
    }

    for (int i = 0; i <= str2_len - str1_len; i++) {
        if (compara(str1, str2 + i) == 0) {
            count++;
        }
    }

    return count;
}

void frecuencia(const char *str) {
    int letras[26] = {0}; // Arreglo para contar la frecuencia de cada letra
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

    // Contar la frecuencia de cada letra en la cadena
    for (int i = 0; str[i] != '\0'; i++) {
        char letra = str[i];
        if (letra >= 'a' && letra <= 'z') {
            letras[letra - 'a']++;
        }
    }

    // Imprimir la letra y su frecuencia
    for (int i = 0; i < 26; i++) {
        if (letras[i] > 0) {
            printf("%c - %d, ", alfabeto[i], letras[i]);
        }
    }
}

// Función para verificar si una palabra tiene letras repetidas
bool tiene_letras_repetidas(const char *palabra) {
    int longitud = 0;
    while (palabra[longitud] != '\0') {
        longitud++;
    }

    for (int i = 0; i < longitud; i++) {
        for (int j = i + 1; j < longitud; j++) {
            if (palabra[i] == palabra[j]) {
                return true; // Letras repetidas encontradas
            }
        }
    }
    return false; // No hay letras repetidas
}

// Función para encontrar y imprimir las palabras sin letras repetidas
void sin_repetir(const char *str) {
    char palabra[100]; // Puedes ajustar el tamaño según tus necesidades
    int indice = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            palabra[indice] = str[i];
            indice++;
        } else {
            palabra[indice] = '\0';
            if (!tiene_letras_repetidas(palabra)) {
                printf("%s ", palabra);
            }
            indice = 0;
        }
    }

    palabra[indice] = '\0';
    if (!tiene_letras_repetidas(palabra)) {
        printf("%s ", palabra);
    }

    printf("\n");
}
