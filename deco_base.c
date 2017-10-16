#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "common.h"

int main (int argc, char *argv[])
{
	FILE* fentrada, fsalida;
	char* salida_csv;

	if((st = validar_argumentos_deco_base(argc,argv,&fentrada))!=ST_OK)
		{
			fprintf(stderr, "Error en alguna validacion\n");
			return EXIT_FAILURE;
		}

	copy_bin_to_csv(argv[1],salida_csv);

	return ST_OK;
}
