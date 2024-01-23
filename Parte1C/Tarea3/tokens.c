/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona.

Ejercicio 5. Separe un string en tokens de acuerdo a un caracter especial dado como entrada
(puede ser espacio, /, %, etc.) y que regrese un arreglo que apunte a cada uno de los
tokens encontrados:

char **tokens(char *str, char ch)
o NULL en caso de no encontrar algún token:

********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokens(char *str, char ch);

int main() {
    char str[] = "hola,mundo,esto,funciona?";
    char ch = ',';

    // Llamar a la función para obtener los tokens
    char **tokenArray = tokens(str, ch);

    if (tokenArray != NULL) {
        // Imprimir los tokens
        for (int i = 0; tokenArray[i] != NULL; i++) {
            printf("Token %d: %s\n", i + 1, tokenArray[i]);
        }

        // Liberar la memoria asignada a los tokens y al arreglo de apuntadores
        for (int i = 0; tokenArray[i] != NULL; i++) {
            free(tokenArray[i]);
        }
        free(tokenArray);
    } else {
        printf("No se encontraron tokens.\n");
    }

    return 0;
}

// Función para separar un string en tokens usando un carácter delimitador
char **tokens(char *str, char ch) {
    char **tokenArray = NULL;
    int tokenCount = 0;
    int tokenMaxLength = 0;
    int tokenStart = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            // Encontramos un delimitador, agregamos el token anterior al arreglo
            tokenArray = realloc(tokenArray, (tokenCount + 1) * sizeof(char *));
            if (tokenArray == NULL) {
                perror("Error en realloc");
                exit(1);
            }
            int tokenLength = i - tokenStart;
            tokenArray[tokenCount] = (char *)malloc((tokenLength + 1) * sizeof(char));
            if (tokenArray[tokenCount] == NULL) {
                perror("Error en malloc");
                exit(1);
            }
            strncpy(tokenArray[tokenCount], str + tokenStart, tokenLength);
            tokenArray[tokenCount][tokenLength] = '\0';
            tokenCount++;
            tokenStart = i + 1;

            // Actualizar la longitud máxima del token si es necesario
            if (tokenLength > tokenMaxLength) {
                tokenMaxLength = tokenLength;
            }
        }
    }

    // Agregar el último token
    int tokenLength = strlen(str) - tokenStart;
    tokenArray = realloc(tokenArray, (tokenCount + 1) * sizeof(char *));
    if (tokenArray == NULL) {
        perror("Error en realloc");
        exit(1);
    }
    tokenArray[tokenCount] = (char *)malloc((tokenLength + 1) * sizeof(char));
    if (tokenArray[tokenCount] == NULL) {
        perror("Error en malloc");
        exit(1);
    }
    strncpy(tokenArray[tokenCount], str + tokenStart, tokenLength);
    tokenArray[tokenCount][tokenLength] = '\0';
    tokenCount++;

    // Si no se encontraron tokens, devolver NULL
    if (tokenCount == 0) {
        free(tokenArray);
        return NULL;
    }

    return tokenArray;
}
