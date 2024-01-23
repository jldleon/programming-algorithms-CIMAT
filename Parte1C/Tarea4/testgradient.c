#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estructura para representar una imagen
typedef struct {
    int width;
    int height;
    unsigned char* data;  // Datos de la imagen (valores de píxeles)
} Image;

Image* loadPGM(const char* filename);

void savePGM(const char* filename, Image* img);

void calcularGradienteSobel(Image* input, Image* output);

int main() {
    Image* inputImage = loadPGM("len_out.pgm");  // Cambia "input.pgm" al nombre de tu archivo de imagen
    if (!inputImage) {
        return 1;
    }

    Image* gradientImage = (Image*)malloc(sizeof(Image));
    gradientImage->width = inputImage->width;
    gradientImage->height = inputImage->height;
    gradientImage->data = (unsigned char*)malloc(inputImage->width * inputImage->height);

    calcularGradienteSobel(inputImage, gradientImage);

    savePGM("gradient.pgm", gradientImage);  // Guardar la imagen del gradiente

    free(inputImage->data);
    free(inputImage);
    free(gradientImage->data);
    free(gradientImage);

    return 0;
}

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

// Función para calcular el gradiente de una imagen utilizando el operador Sobel
void calcularGradienteSobel(Image* input, Image* output) {
    int i, j;
    int Gx, Gy;

    for (i = 1; i < input->height - 1; i++) {
        for (j = 1; j < input->width - 1; j++) {
            Gx = (-1 * input->data[(i - 1) * input->width + (j - 1)] - 2 * input->data[i * input->width + (j - 1)] - input->data[(i + 1) * input->width + (j - 1)] +
                  input->data[(i - 1) * input->width + (j + 1)] + 2 * input->data[i * input->width + (j + 1)] + input->data[(i + 1) * input->width + (j + 1)]);

            Gy = (-1 * input->data[(i - 1) * input->width + (j - 1)] - 2 * input->data[(i - 1) * input->width + j] - input->data[(i - 1) * input->width + (j + 1)] +
                  input->data[(i + 1) * input->width + (j - 1)] + 2 * input->data[(i + 1) * input->width + j] + input->data[(i + 1) * input->width + (j + 1)]);

            output->data[i * input->width + j] = (unsigned char)(sqrt(Gx * Gx + Gy * Gy));
        }
    }
}

