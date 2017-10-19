#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "common.h"

int main(int argc, char *argv[])
{
	FILE *fentrada, *fsalida;
	juego_t *ptr_juego,juego;
	status_t st;
	char **arreglo;
	char str[12];
	int i;

	ptr_juego = &juego;

	if((st = validar_argumentos_deco(argc,argv,&fentrada,&fsalida))!=ST_OK)
	{
		fprintf(stderr, "Error en alguna validacion\n");
		return EXIT_FAILURE;
	}

	/*if((st = binario_a_CSV(&ptr_juego,&fentrada,&fsalida,&arreglo)) != ST_OK)
	{
		printf("HUBO ALGUN ERROR EN binario_a_CSV\n");
		return EXIT_FAILURE;
	}*/
	if((arreglo = (char **)malloc(sizeof(char *)*7)) == NULL)
	{
		printf("No hay memoria para crear el arreglo\n");
		fclose(fentrada);
		fclose(fsalida);
		return EXIT_FAILURE;
	}

	fseek( fentrada, 0, SEEK_SET );
	if ((fread(ptr_juego , sizeof(juego_t) , 1 , fentrada)) != 1)
	{
		printf("No se pudo leer la estructura\n");
		fclose(fentrada);
		fclose(fsalida);
		return EXIT_FAILURE;
	}
	
	do
	{
		sprintf(str, "%u", ptr_juego->id);
		if(((arreglo[0]) = (char *)malloc(sizeof(char)*strlen(str)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[0],str);

		if(((arreglo[1]) = (char *)malloc(sizeof(char)*strlen(ptr_juego->nombre)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[1],ptr_juego->nombre);

		if(((arreglo[2]) = (char *)malloc(sizeof(char)*strlen(ptr_juego->desarrollador)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[2],ptr_juego->desarrollador);

		if(((arreglo[3]) = (char *)malloc(sizeof(char)*strlen(ptr_juego->plataforma)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[3],ptr_juego->plataforma);

		if(((arreglo[4]) = (char *)malloc(sizeof(char)*strlen(ptr_juego->fecha)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[4],ptr_juego->fecha);

		sprintf(str, "%.0f", ptr_juego->puntaje);
		if(((arreglo[5]) = (char *)malloc(sizeof(char)*strlen(str)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[5],str);

		sprintf(str, "%u", ptr_juego->resenias);
		if(((arreglo[6]) = (char *)malloc(sizeof(char)*strlen(str)+1)) == NULL)
		{
			printf("No hay memoria\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[6],str);


		fprintf(fsalida, "%s,%s,%s,%s,%s,%s,%s\n",arreglo[0],arreglo[1],arreglo[2],arreglo[3],arreglo[4],arreglo[5],arreglo[6] );
		for(i=0;i<7;i++)
		{
			free(arreglo[i]);
			arreglo[i] = NULL;
		}
		
	/*fseek( fentrada, sizeof(juego_t), SEEK_CUR ); ESTA LINEA VA COMENTADA*/
	}while((fread(ptr_juego , sizeof(juego_t) , 1 , fentrada)) == 1);

	free(arreglo);
	arreglo = NULL;
	fclose(fentrada);
	fclose(fsalida);

	return EXIT_SUCCESS;
	
}

status_t validar_argumentos_deco(int argc, char *argv[], FILE **fentrada, FILE **fsalida)
{
	if( !argv )
	{
		printf("entre a ST_ERROR_PUNTERO_NULO\n");
		return ST_ERROR_PUNTERO_NULO;
	}
	if(argc != MAX_ARGC_DECO_BASE)
	{
		printf("entre a ST_ERROR_CANT_ARG\n");
		return ST_ERROR_CANT_ARG;
	}
	if((*fentrada = fopen(argv[1],"rb"))==NULL)
	{
		printf("entre a ST_ERROR_APERTURA_ARCHIVO\n");
		return ST_ERROR_APERTURA_ARCHIVO;
	}
	if((*fsalida = fopen("desbinarizacion_CSV.txt","wt"))==NULL)
	{
		printf("entre a ST_ERROR_APERTURA_ARCHIVO (desbinarizacion_CSV)\n");
		return ST_ERROR_APERTURA_ARCHIVO;
	}
	return ST_OK;
}