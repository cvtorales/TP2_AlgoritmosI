#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGC 2
#define BASE 10

typedef enum {

				ST_OK,
				ST_ERROR_NO_MEM,
				ST_ERROR_PUNTERO_NULO,
				ST_ERROR_CARGAR_ID,
				ST_ERROR_CARGAR_FECHA,
				ST_ERROR_CARGAR_PUNTAJE,
				ST_ERROR_CARGAR_RESENIAS,
				ST_ERROR_CANT_ARG,
				ST_ERROR_APERTURA_ARCHIVO

			} status_t;


typedef struct {
				size_t id;
				char nombre[100];
				char desarrollador[100];
				char plataforma[50];
				size_t fecha; /* lo cambie temporalmente, despues vuelve a ser time_t */
				double puntaje;
				size_t resenias;
				} juego_t;

int main(int argc, char *argv[])
{
	FILE *f;
	juego_t *ptr_juego,juego;

	ptr_juego = &juego;

	if( !argv )
	{
		printf("entre a ST_ERROR_PUNTERO_NULO\n");
		return EXIT_FAILURE;
	}
	if(argc != MAX_ARGC)
	{
		printf("entre a ST_ERROR_CANT_ARG\n");
		return EXIT_FAILURE;
	}
	if((f = fopen(argv[1],"rb"))==NULL)
	{
		printf("entre a ST_ERROR_APERTURA_ARCHIVO\n");
		return EXIT_FAILURE;
	}

	fread(ptr_juego,sizeof(juego_t),1,f);
	printf("Estructura:\nID: %u \nNOMBRE: %s\nDESARROLLADOR: %s\nPLATAFORMA: %s\nFECHA: %u\nPUNTAJE: %f\nRESENIAS: %u\n", ptr_juego->id, ptr_juego->nombre, ptr_juego->desarrollador, ptr_juego->plataforma, ptr_juego->fecha, ptr_juego->puntaje, ptr_juego->resenias);
	fclose(f);

	return EXIT_SUCCESS;
}