#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
#define NP 30
#define CATEGORIAS 6
 
void ValidarString(char[], char[], int);
int ValidarInt(int, int, int);
float ValidarFloat(float, float, float);
char ValidarChar(char, char, char);
int CalcularCat(int);
 
int main() {
 
	struct censo {
		char nombre[30];
		int edad;
		float peso;
		char nacionalidad;
		char sexo;
		int categoria;
	};
 
	struct censo personas[NP];
	char NomAux[100];
	int pmay, pmen;
	int m[CATEGORIAS] = { 0 }; 
	int f[CATEGORIAS] = { 0 }; 
	int v[CATEGORIAS] = { 0 }; 
	int e[CATEGORIAS] = { 0 }; 
	int tot[CATEGORIAS] = { 0 }; 
	int sumaedades[CATEGORIAS] = { 0 }; 
	int flag = 0;
	int SumaFinalEdades = 0;
	float porcentaje, promedio;
 
	printf("Ingrese los datos de las siguientes personas:\n");
	for (int i = 0; i<NP; i++)
	{
		printf("\n");
		printf("Nombre[%i]: ", i + 1);
		fflush(stdin);
		gets(NomAux);
		ValidarString(personas[i].nombre, NomAux, 30);
 
 
		printf("edad[%i]: ", i + 1);
		scanf("%i", &personas[i].edad);
		personas[i].edad = ValidarInt(personas[i].edad, 0, 120);
		personas[i].categoria = CalcularCat(personas[i].edad);
 
 
		printf("peso [%i]: ", i + 1);
		scanf("%f", &personas[i].peso);
		personas[i].peso = ValidarFloat(personas[i].peso, 0, 500);
 
 
 
		printf("Nacionalidad[%i]: ", i + 1);
		fflush(stdin);
		personas[i].nacionalidad = tolower(getchar());
		personas[i].nacionalidad = ValidarChar(personas[i].nacionalidad, 'v', 'e');
 
 
 
		printf("Sexo (M) O (F)[%i]: ", i + 1);
		fflush(stdin);
		personas[i].sexo = tolower(getchar());
		personas[i].sexo = ValidarChar(personas[i].sexo, 'm', 'f');
 
 
	}
 
	for (int i = 0; i<NP; i++)
	{
		switch (personas[i].sexo)
		{
		case 'f':
			f[personas[i].categoria]++;
			break;
		default:
			m[personas[i].categoria]++;
 
		}
		switch (personas[i].nacionalidad)
		{
		case 'v':
			v[personas[i].categoria]++;
			break;
 
		default:
			e[personas[i].categoria]++;
		}
 
		tot[personas[i].categoria]++;
		sumaedades[personas[i].categoria] += personas[i].edad;
		if (flag == 0)
		{
			pmay = i;
			pmen = i;
			flag = 1;
		}
		else
		{
			if (personas[i].edad>personas[pmay].edad)
				pmay = i;
 
			else
			{
				if (personas[i].edad<personas[pmen].edad)
					pmen = i;
 
			}
		}
	}
 
	printf("\n Categoria 0: de 0 a 10 años");
	printf("\n Categoria 1: de 11 a 15 años");
	printf("\n Categoria 2: de 16 a 25 años");
	printf("\n Categoria 3: de 26 a 35 años");
	printf("\n Categoria 4: de 36 a 40 años");
	printf("\n Categoria 5: de 41 a 45 años");
	printf("\n Categoria 6: de 46 en adelante");
 
	for (int i = 0; i<CATEGORIAS; i++)
	{
		printf("\n\n TOTAL Categoria %d: %d", i, tot[i]);
		printf("\n Masculinos :%d ", m[i]);
		printf("\n Femeninos :%d ", f[i]);
		printf("\n Venezolanos :%d ", v[i]);
		printf("\n Extranjeros :%d ", e[i]);
		if (tot[i] != 0)
		{
			promedio = (float)sumaedades[i] / tot[i];
			printf("\n Promedio Edad : %.2f ", promedio);
		}
		porcentaje = (float)tot[i] / NP * 100;
		printf("\n Porcentaje de Personas : %.2f", porcentaje);
		SumaFinalEdades += sumaedades[i];
 
	}
 
	promedio = (float)SumaFinalEdades / NP;
	printf("\n\n\n  Promedio Edad General : %.2f ", promedio);
	printf("\n\n Edad Maxima : %d ", personas[pmay].edad);
	printf("\n Corresponde a: %s", personas[pmay].nombre);
	printf("\n peso: %.2f", personas[pmay].peso);
	printf("\n nacionalidad: %c", personas[pmay].nacionalidad);
	printf("\n sexo: %c", personas[pmay].sexo);
 
	printf("\n\n Edad Minima: %d", personas[pmen].edad);
	printf("\n Corresponde a: %s", personas[pmen].nombre);
	printf("\n peso: %.2f", personas[pmen].peso);
	printf("\n nacionalidad: %c", personas[pmen].nacionalidad);
	printf("\n sexo: %c", personas[pmen].sexo);
 
 
	getchar(); getchar();
	return 0;
}
 
 
void ValidarString(char cadena[], char cadenaAux[], int limite)
{
	while (strlen(cadenaAux) >= limite)
	{
		printf("\n Error, debe ingresar una cadena menos de %d caracteres ", NP);
		printf("\n Reingrese :");
		fflush(stdin);
		gets(cadenaAux);
	}
	strcpy(cadena, cadenaAux);
 
}
 
 
int ValidarInt(int num, int min, int mayor)
{
	while (num<min || num>mayor)
	{
		printf("\nError, debe ingresar un Valor Entero entre : %d y %d ", min, mayor);
		printf("\nReingrese: ");
		scanf("%d", &num);
 
	}
 
	return num;
}
float ValidarFloat(float num, float min, float mayor)
{
	while (num<min || num>mayor)
	{
		printf("\nError, debe ingresar un Valor entre : %.2f y %.2f ", min, mayor);
		printf("\nReingrese: ");
		scanf("%f", &num);
 
	}
 
	return num;
 
}
 
char ValidarChar(char car, char uno, char otro)
{
	while (car != uno && car != otro)
	{
		printf("\nError, debe ingresar %c o %c ", uno, otro);
		printf("\nReingrese: ");
		fflush(stdin);
		car = tolower(getchar());
 
	}
	return car;
 
}
 
 
int CalcularCat(int edad)
{
	if (edad<11)
		return 0;
	if (edad<16)
		return 1;
	if (edad<26)
		return 2;
	if (edad<36)
		return 3;
	if (edad<46)
		return 4;
 
	return 5;
 
}
