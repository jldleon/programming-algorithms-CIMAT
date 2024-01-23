/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.

    Ejercicio 1. (15%) Programa que imprima la fecha en formato texto:
Entrada: Introduce Fecha (dd/mm/aaaa): 21/08/2023
Salida: veintiuno de agosto de dos mil veinte y tres (o veintitrés)
NOTA: a) La fecha de entrada puede ser cualquiera DC entre 0-9999 (ej. 15/3/101;
21/03/8560).

*******************************************************************/
#include <stdio.h>

void unidades(int);

void decenas(int);

void centenas(int);

void millares(int);

void meses(int);

int main() {
    int dia, mes, ano;

    printf("Introduce el dia \n");
    scanf("%d", &dia);

    printf("Introduce el mes \n");
    scanf("%d", &mes);


    printf("Introduce el año \n");
    scanf("%d", &ano);

    printf("%02d/%02d/%04d \n",dia, mes, ano);

    //Imprimir dia
    if (dia >= 10) {
        int dec = dia / 10;
        int uni = dia % 10;
        decenas(dec);
        if (dia % 10 != 0){
            printf(" y ");
        }
        unidades(uni);
    } else if (dia < 10) {
        unidades(dia);
    }

    printf(" de ");

    //Imprimir mes
    meses( mes);
    printf(" del ");

    //Imprimir año
    if (ano >= 1000) {
        int mil = ano / 1000;
        millares(mil);
        ano = ano % 1000;
    }

    printf(" ");

    if (ano >= 100) {
        int cen = ano / 100;
        centenas(cen);
        ano = ano % 100;
    }

    printf(" ");

    if (ano >= 10) {
        int dec = ano/10;
        decenas(dec);
        ano = ano % 10;
        printf( " y ");
    }


    unidades(ano);

    return 0;
}

void meses(int mes) {
    switch (mes) {
        case 1: printf("enero");    break;
        case 2: printf("febrero");  break;
        case 3: printf("marzo");    break;
        case 4: printf("abril");    break;
        case 5: printf("mayo");     break;
        case 6: printf("junio");    break;
        case 7: printf("julio");    break;
        case 8: printf("agosto");   break;
        case 9:  printf("septiembre"); break;
        case 10: printf("octubre");    break;
        case 11: printf("noviembre");  break;
        case 12: printf("diciembre");  break;
    }
}

void unidades(int num) {
    switch (num) {
        case 1: printf("uno");  return;
        case 2: printf("dos");  return;
        case 3: printf("tres"); return;
        case 4: printf("cuatro"); return;
        case 5: printf("cinco");  return;
        case 6: printf("seis");   return;
        case 7: printf("siete");  return;
        case 8: printf("ocho");   return;
        case 9: printf("nueve");  return;
    }
}

void decenas(int num) {
    switch (num) {
        case 1: printf("diez");  return;
        case 2: printf("veinte");  return;
        case 3: printf("treinta"); return;
        case 4: printf("cuarenta"); return;
        case 5: printf("cincuenta");  return;
        case 6: printf("sesenta");   return;
        case 7: printf("setenta");  return;
        case 8: printf("ochenta");   return;
        case 9: printf("noventa");  return;
    }

}

void centenas(int num) {
    switch (num) {
        case 1: printf("cien/to");  return;
        case 2: printf("doscientos");  return;
        case 3: printf("trecientos"); return;
        case 4: printf("cuatrocientos"); return;
        case 5: printf("quinientos");  return;
        case 6: printf("seiscientos");   return;
        case 7: printf("setecientos");  return;
        case 8: printf("ochocientos");   return;
        case 9: printf("novecientos");  return;
    }
}

void millares(int num) {
    switch (num) {
        case 1: printf("mil");  return;
        case 2: printf("dos mil");  return;
        case 3: printf("tres mil"); return;
        case 4: printf("cuatro mil"); return;
        case 5: printf("cinco mil");  return;
        case 6: printf("seis mil");   return;
        case 7: printf("siete mil");  return;
        case 8: printf("ocho mil");   return;
        case 9: printf("nueve mil");  return;
    }
}
