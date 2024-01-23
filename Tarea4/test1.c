/* Tarea 4. Programación y Algoritmos.
    Parte 1. Lenguaje C.

                Jose Luis de Leon Carmona.

Ejercicio 1. Programa que calcule:
a) El “promedio”, de una imagen IMxN mediante una ventana deslizante
�!,!; �Î(3,5,7, ... ):

�(�,�) = Promedio(�!,!(i, j));
Esto es, reemplazar el valor central de Wm,m(i,j) por P(i,j).

*******************************************************/
#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una imagen
typedef struct {
    int width;
    int height;
    unsigned char* data;  // Datos de la imagen (valores de píxeles)
} Image;

// Función para cargar una imagen desde un archivo PGM (Portable GrayMap)
Image* loadPGM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return NULL;
    }

    char magic[3];
    int width, height, maxval;

    // Leer encabezado PGM
    if (fscanf(file, "%2s %d %d %d\n", magic, &width, &height, &maxval) != 4 || magic[0] != 'P' || magic[1] != '5') {
        fprintf(stderr, "Formato PGM no válido\n");
        fclose(file);
        return NULL;
    }

    // Crear una nueva imagen
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (unsigned char*)malloc(width * height);

    // Leer los datos de píxeles
    fread(img->data, 1, width * height, file);

    fclose(file);
    return img;
}

// Función para guardar una imagen en formato PGM
void savePGM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return;
    }

    // Escribir el encabezado PGM
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);

    // Escribir los datos de píxeles
    fwrite(img->data, 1, img->width * img->height, file);

    fclose(file);
}

// Función para calcular el promedio de una ventana deslizante en una imagen
void calcularPromedioVentana(Image* input, Image* output, int ventanaSize) {
    int mitadVentana = ventanaSize / 2;
    int i, j, x, y;

    for (i = 0; i < input->height; i++) {
        for (j = 0; j < input->width; j++) {
            double suma = 0;
            int contador = 0;

            for (x = -mitadVentana; x <= mitadVentana; x++) {
                for (y = -mitadVentana; y <= mitadVentana; y++) {
                    int ni = i + x;
                    int nj = j + y;

                    if (ni >= 0 && ni < input->height && nj >= 0 && nj < input->width) {
                        suma += input->data[ni * input->width + nj];
                        contador++;
                    }
                }
            }

            output->data[i * input->width + j] = (unsigned char)(suma / contador);
        }
    }
}

int main() {
    Image* inputImage = loadPGM("len_out.pgm");  // Cambia "input.pgm" al nombre de tu archivo de imagen
    if (!inputImage) {
        return 1;
    }

    int ventanaSize = 3;  // Tamaño de la ventana deslizante
    Image* outputImage = (Image*)malloc(sizeof(Image));
    outputImage->width = inputImage->width;
    outputImage->height = inputImage->height;
    outputImage->data = (unsigned char*)malloc(inputImage->width * inputImage->height);

    calcularPromedioVentana(inputImage, outputImage, ventanaSize);

    savePGM("output.pgm", outputImage);  // Guardar la imagen promedio resultante

    free(inputImage->data);
    free(inputImage);
    free(outputImage->data);
    free(outputImage);

    return 0;
}
