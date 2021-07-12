/*
 ============================================================================
 Name        : parcialProgrRecuperoVelazcoMicaela.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//(id, procesador, marca, precio)
typedef struct
{
	int id;
	char procesador[50];
	char marca[50];
	float precio;
}eNotebook;

int contarCaracteres(char* cadena, char letra);
float aplicarDescuento(int precioOriginal);
void ordenarNotebook(eNotebook lista[], int len);
int main(void) {
	char palabra[20]="amaca";
	char letra='a';
	int retorno;
    int precioOriginal;
    float resultado;

	eNotebook notebook[10]=
	{
			{1,"Core i5","Intel",1000.2},
			{2,"Pentium","AMD",1200.3},
			{3,"Xeon","Qualcomm",1100.4},
			{4,"Dual-Core","TSMC",1320.5},
			{5,"Atom","IBM",1320.6 },
			{6,"Core i5","Intel",1150.7 },
			{7,"Pentium","AMD",1080.8 },
			{8,"Xeon","Qualcomm",1390.9 },
			{9,"Dual-Core","TSMC",1210.1 },
			{10,"Atom","IBM",1150.2 },
	};

    printf("Ingrese el precio: ");
    scanf("%d",&precioOriginal);

    resultado=aplicarDescuento(precioOriginal);
    printf("%.2f\n",resultado);

	retorno=contarCaracteres(palabra, letra);
	printf("la %c se repite %d",letra,retorno);

	ordenarNotebook(notebook, 10);


	return EXIT_SUCCESS;
}

/*2. Crear una función que se llame contarCaracteres que reciba una cadena de
 *  caracteres como primer parámetro y un carácter como segundo y devuelva la cantidad de veces que ese carácter
 *   aparece en la cadena */
int contarCaracteres(char* cadena, char letra)
{
	int len=strlen(cadena);
	int contador=0;

	for(int i=0; i<len; i++)
	{
		if(cadena[i]==letra)
		{
			contador++;
		}
	}

	return contador;
}


float aplicarDescuento(int precioOriginal)
{
    int precioConDescuento;
    int descuento;
    descuento=(float)(precioOriginal*5)/100;

    precioConDescuento=precioOriginal-descuento;

    return precioConDescuento;
}

/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un
 *  array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio.
 *  Hardcodear datos y mostrarlos desde el main. **/

void ordenarNotebook(eNotebook lista[], int len)
{
	eNotebook aux;

		if(lista!=NULL&&len> 0)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1; j<len;j++)
				{
					if(strcmp(lista[i].marca,lista[j].marca)<0||//de mayor a menor
						(lstrcmp(lista[i].marca,lista[j].marca)==0 &&
						lista[i].precio<lista[j].precio))//de mayor a menor
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
				}
			}
		}
	}
}



