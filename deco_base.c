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

	ptr_juego = &juego;

	if((st = validar_argumentos_deco(argc,argv,&fentrada,&fsalida))!=ST_OK)
	{
		fprintf(stderr, "Error en alguna validacion\n");
		return EXIT_FAILURE;
	}
	
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
		if(((arreglo[2]) = (char *)malloc(sizeof(char)*strlen(ptr_juego->nombre)+1)) == NULL)
		{
			printf("No hay memoria para crear el arreglo[2]\n");
			free(arreglo);
			arreglo = NULL;
			fclose(fentrada);
			fclose(fsalida);
			return EXIT_FAILURE;
		}
		strcpy(arreglo[2],ptr_juego->nombre);

		printf("arreglo[2]: %s\n",arreglo[2] );
		free(arreglo[2]);
		arreglo[2] = NULL;
	}while((fread(ptr_juego , sizeof(juego_t) , 1 , fentrada)) == 1);

	free(arreglo);
	arreglo = NULL;
	fclose(fentrada);
	fclose(fsalida);

	return EXIT_SUCCESS;
	
}