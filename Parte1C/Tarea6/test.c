/* Tarea 6. Programacin y Algoritmos.
    Parte 1. Lenguaje C.

                José Luis de León Carmona.

Ejercicio 1. Implementar un sistema de cifrado para imágenes basado en un generador de números
aleatorios basado en teoría de caos denominado mapa Logístico:

f(x_n) = x_n = 4*x_(n-1)[1 - x_(x-1)]
0 < x < 1; x_0 condicion inicial dada,

El sistema de cifrado es simétrico (el que envía como el que recibe tiene las mismas
condiciones iniciales) y trabaja de la siguiente manera:
- Definir el valor inicial 0 < x_0 < 1;
- El mapa logístico se evalúa como una composición de funciones (en este caso solo
hay una función f)

Esto es, la salida de x_n = f(x_{n-1}) es la entrada a la misma función x_{n+1} = f(x_n).
- La salida actual del mapa logístico x_{n} provee un valor flotante entre 0 y 1, por lo que
debe convertirlo a entero multiplicándolo por 255, y tomar solo la parte entera.
- Para cada pixel de la imagen de entrada, realizar la siguiente operación:
O(m,n) = I(m,n) xor (int)(x_{n+1} = f(x_n)> ∗ 255);
Donde O(m,n) es la salida de la imagen cifrada. Cada pixel de la imagen debe
transformarse con un valor caótico distinto.
Escribir dos programas, uno para cifrar la imagen y escribirla en un archivo pgm, y el
otro para descifrar y escribir la imagen de salida original también en pgm. Me van a
preguntar si es posible hacerlo todo en un solo programa, si es posible.
**************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estructura para representar una imagen
typedef struct {
    int width;
    int height;
    unsigned char* data;  // Datos de la imagen (valores de píxeles)
} Image;

// Función del mapa logístico
double logistic_map(double x, double r) {
    return r * x * (1 - x);
}

// Función para cargar una imagen desde un archivo PGM
Image* load_image(const char* image_path) {
    FILE* file = fopen(image_path, "rb");
    if (!file) {
        perror("Error al abrir la imagen");
        exit(1);
    }

    // Leer el encabezado PGM
    char magic[3];
    int width, height, max_val;
    fscanf(file, "%s %d %d %d", magic, &width, &height, &max_val);
    if (magic[0] != 'P' || magic[1] != '5') {
        fprintf(stderr, "Formato de imagen no válido\n");
        fclose(file);
        exit(1);
    }

    // Crear la estructura de imagen
    Image* image = (Image*)malloc(sizeof(Image));
    if (!image) {
        perror("Error al asignar memoria para la imagen");
        fclose(file);
        exit(1);
    }
    image->width = width;
    image->height = height;
    image->data = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    if (!image->data) {
        perror("Error al asignar memoria para los datos de la imagen");
        free(image);
        fclose(file);
        exit(1);
    }

    // Leer los datos de píxeles
    fread(image->data, sizeof(unsigned char), width * height, file);

    fclose(file);
    return image;
}

// Función para guardar una imagen en un archivo PGM
void save_image(const char* image_path, const Image* image) {
    FILE* file = fopen(image_path, "wb");
    if (!file) {
        perror("Error al abrir el archivo de salida");
        exit(1);
    }

    // Escribir el encabezado PGM
    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);

    // Escribir los datos de píxeles
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);
}

// Función para cifrar una imagen
void encrypt_image(Image* image, double x0, double r) {
    // Inicialización del mapa logístico
    double x = x0;

    // Cifrado de la imagen
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            x = logistic_map(x, r);
            unsigned char pixel = image->data[i * image->width + j];
            unsigned char encrypted_pixel = pixel ^ (unsigned char)(x * 255);
            image->data[i * image->width + j] = encrypted_pixel;
        }
    }
}

// Función para descifrar una imagen cifrada
void decrypt_image(Image* image, double x0, double r) {
    // Inicialización del mapa logístico con la misma condición inicial
    double x = x0;

    // Descifrado de la imagen
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            x = logistic_map(x, r);
            unsigned char pixel = image->data[i * image->width + j];
            unsigned char decrypted_pixel = pixel ^ (unsigned char)(x * 255);
            image->data[i * image->width + j] = decrypted_pixel;
        }
    }
}

int main() {
    const char* input_image_path = "len_out.pgm";  // Ruta de la imagen de entrada
    const char* encrypted_image_path = "encrypted.pgm";  // Ruta de la imagen cifrada
    const char* decrypted_image_path = "decrypted.pgm";  // Ruta de la imagen descifrada
    double x0 = 0.51;  // Condición inicial x0
    double r = 4.0;   // Parámetro r del mapa logístico (ajusta según tus necesidades)

    // Cargar la imagen de entrada
    Image* input_image = load_image(input_image_path);

    // Cifrar la imagen
    encrypt_image(input_image, x0, r);

    // Guardar la imagen cifrada
    save_image(encrypted_image_path, input_image);

    // Descifrar la imagen
    decrypt_image(input_image, x0, r);

    // Guardar la imagen descifrada
    save_image(decrypted_image_path, input_image);

    // Liberar memoria
    free(input_image->data);
    free(input_image);

    return 0;
}
