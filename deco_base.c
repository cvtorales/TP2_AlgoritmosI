#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "common.h"

int main (int argc, char *argv[])
{
	FILE* fentrada;
	char* salida_csv;

	if((st = validar_argumentos_deco_base(argc,argv,&argv[1]))!=ST_OK)
		{
			fprintf(stderr, "Error en alguna validacion\n");
			return EXIT_FAILURE;
		}

	copy_bin_to_csv(%argv[1]);

	return ST_OK;
}
