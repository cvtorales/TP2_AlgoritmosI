#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define CANTIDAD_DE_ARGUMENTOS_PUNTAJE 8
#define NOMBRE_ARCHIVO_BASE_DE_DATOS "db.bin"
#define NOMBRE_ARCHIVO_A_MODIFICAR "data.bin"
#define NOMBRE_ARCHIVO_PARA_MSJS_DE_ERRORES "errores.txt"
/*************** NUMERO DE POSICIONES PARA ARGUMENTOS ******************/
#define ARG_CMD_NUMERO_DE_POSICION_OPERACION 1
#define ARG_CMD_NUMERO_DE_POSICION_BAMDERA_ARCHIVO_BASE_DE_DATOS 2
#define ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_BASE_DE_DATOS 3
#define ARG_CMD_NUMERO_DE_POSICION_BANDERA_ARCHIVO_A_MODIFICAR 4
#define ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_A_MODIFICAR 5
#define ARG_CMD_NUMERO_DE_POSICION_BANDERA_ARCHIVO_MSJS_ERROR 6
#define ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_MSJS_ERROR 7
/***********************************************************************/


status_t validar_argumentos_puntaje (int argc, char * argv[], FILE **fentrada, FILE ** fsalida);
status_t procesar_altas(FILE ** fentrada, FILE ** fsalida, juego_t * ptr_juego_data, juego_t * ptr_juego_db );
status_t procesar_bajas(FILE ** fentrada, FILE ** fsalida, juego_t **ptr_juego_data, juego_t **ptr_juego_db );
status_t procesar_modificaciones(FILE ** fentrada, FILE ** fsalida, juego_t * ptr_juego_data, juego_t * ptr_juego_db );

int main (int argc, char *argv[])
{
	FILE *data;   /* Registros para dar alta, baja o modificaciones */
	FILE *db;     /*  Base de datos */
	status_t st; 

	juego_t * ptr_juego_db,  * ptr_juego_data;
	juego_t juego_db, juego_data;
	ptr_juego_data= &juego_data;
	ptr_juego_db= &juego_db;

	/*size_t id_aux_data;
	size_t id_aux_db;
*/
		if((st = validar_argumentos_puntaje(argc, argv, &db, &data))!=ST_OK)
	{
		fprintf(stderr, "Error en alguna validacion\n");
		return EXIT_FAILURE;
	}

		switch(*(argv[1]))
		{
			case 'A':
					if((procesar_altas(&data, &db, ptr_juego_data, ptr_juego_db ))!=ST_OK)
						return EXIT_FAILURE;
					break;

			case 'B':
				printf("entre al switch\n");
					if((procesar_bajas(&db, &data, &ptr_juego_data, &ptr_juego_db ))!=ST_OK)
						return EXIT_FAILURE;
					break;
			
			case 'M':
					if((procesar_modificaciones(&data, &db, ptr_juego_data, ptr_juego_db ))!=ST_OK)
						return EXIT_FAILURE;
					break;
			default:
			
			return EXIT_FAILURE;
		}



	
	
	return EXIT_SUCCESS;
}




status_t validar_argumentos_puntaje (int argc, char * argv[], FILE **fentrada, FILE ** fsalida)
{

	if (argv == NULL)
		return ST_ERROR_PUNTERO_NULO;
		
/************ Se valida la cantidad de argumentos **************************/
	if  ( argc != CANTIDAD_DE_ARGUMENTOS_PUNTAJE )
		return ST_ERROR_CANTIDAD_INVALIDA_DE_ARGUMENTOS; 
	
/********************** Se validan las banderas ****************************/	
	if(*(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION]) != 'A'
		&& *(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION]) != 'B'
		&& *(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION]) != 'C')
				return ST_ERROR_CMD_ARG_OPERACION;
		
		

/*
	if(	strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION], "A") 
		&& strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION], "B")
		 &&	strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_OPERACION], "M") )
*/


	if (strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_BAMDERA_ARCHIVO_BASE_DE_DATOS], "-if"))
		return ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_BASE_DE_DATOS;
	
	if ( strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_BASE_DE_DATOS], NOMBRE_ARCHIVO_BASE_DE_DATOS) )
		return ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_BASE_DATOS_INVALIDO;
	
	if (strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_BANDERA_ARCHIVO_A_MODIFICAR], "-f"))
		return ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_A_MODIFICAR;

	if (strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_A_MODIFICAR], NOMBRE_ARCHIVO_A_MODIFICAR))
		return ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_A_MODIFICAR_INVALIDO;

	if (strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_BANDERA_ARCHIVO_MSJS_ERROR], "-log"))
		return ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_MSJS_DE_ERRORES;

/*	if (strcmp(argv[ARG_CMD_NUMERO_DE_POSICION_NOMBRE_ARCHIVO_MSJS_ERROR], NOMBRE_ARCHIVO_PARA_MSJS_DE_ERRORES))
		return ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_MSJ_DE_ERRORES_INVALIDO;
*/
		if((*fentrada = fopen(argv[3],"rb"))==NULL)
	{
		printf("entre a ST_ERROR_APERTURA_ARCHIVO_ENTRADA\n");
		return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
	}
			if((*fsalida = fopen(argv[5],"rb"))==NULL)
	{
		printf("entre a ST_ERROR_APERTURA_ARCHIVO_SALIDA\n");
		return ST_ERROR_APERTURA_ARCHIVO_DE_SALIDA;
	}

/********************* Fin de validacion de banderas ***********************/
		
	return ST_OK;
}

status_t procesar_altas(FILE ** fentrada, FILE ** fsalida, juego_t * ptr_juego_data, juego_t * ptr_juego_db )
{

	


			FILE * temp;
					if((temp=fopen("temp.bin","wb"))==NULL)
				{
					printf("entre a error de archivo temporal\n");
					return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
				}

	while(fread(ptr_juego_db,sizeof(juego_t),1, *fsalida) == 1 )
	{	
		while(fread(ptr_juego_data,sizeof(juego_t),1, *fentrada) == 1)
		{			
			if(((ptr_juego_data)->id) != ((ptr_juego_db)->id))
			{
			

			printf("entre una vez\n");
			fwrite(ptr_juego_db,sizeof(juego_t),1, temp);
			
			}
			if(((ptr_juego_data)->id) == ((ptr_juego_db)->id))
				return ST_ERROR_ID_REPETIDO;

		}
	}

	fclose(*fsalida);
	fclose(*fentrada);

	if((*fsalida=fopen("db.bin","wb"))==NULL)
	{
		printf("entre a error de archivo temporal\n");
		return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
	}

	while(fread(ptr_juego_db,sizeof(juego_t),1, temp) == 1 )
	{
		fwrite(ptr_juego_db,sizeof(juego_t),1, *fsalida);
	}	

	fclose(*fsalida);
	fclose(temp);

	return ST_OK;





/*

				while(fread(&((ptr_juego_data)->id),sizeof(size_t),1, *fentrada) != EOF)
				{	
					while(fread(&((ptr_juego_db)->id),sizeof(size_t),1, *fsalida) != EOF )
					{		
						if(((ptr_juego_data)->id) == ((ptr_juego_db)->id))
							return ST_ERROR_ID_REPETIDO;

						fseek(*fsalida,SEEK_END,0);
						fwrite(ptr_juego_db,sizeof(juego_t),1, *fsalida);
					}
				}
	return ST_OK;  */
}

status_t procesar_bajas(FILE ** fentrada, FILE ** fsalida, juego_t **ptr_juego_data, juego_t **ptr_juego_db )
{
	FILE * temp;
	juego_t juego_aux,*ptr_aux;

	ptr_aux = &juego_aux;
					if((temp=fopen("temp.bin","wb"))==NULL)
				{
					printf("entre a error de archivo temporal\n");
					return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
				}
	printf("linea 215\n\n");

	fseek( *fentrada, 0, SEEK_SET );
	fseek( *fsalida, 0, SEEK_SET );
	
	
	while(fread(*ptr_juego_data,sizeof(juego_t),1, *fsalida) == 1 )
		
	{	
		printf("primer while\n");
	while(fread(*ptr_juego_db,sizeof(juego_t),1, *fentrada) == 1)
		
		{	
		printf("segundo while\n");		
			if(((*ptr_juego_data)->id) != ((*ptr_juego_db)->id))
			{
			

			printf("entre una vez\n");
			fwrite(*ptr_juego_db,sizeof(juego_t),1, temp);
			/*printf("Estructura:\nID: %lu \nNOMBRE: %s\nDESARROLLADOR: %s\nPLATAFORMA: %s\nFECHA: %s\nPUNTAJE: %f\nRESENIAS: %lu\n", ptr_juego_db->id, ptr_juego_db->nombre, ptr_juego_db->desarrollador, ptr_juego_db->plataforma, ptr_juego_db->fecha, ptr_juego_db->puntaje, ptr_juego_db->resenias);*/
	
			
			}

		}
	}

	fclose(*fsalida);
	fclose(*fentrada);

	if((*fsalida=fopen("db.bin","wb"))==NULL)
	{
		printf("entre a error de archivo temporal\n");
		return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
	}
	printf("abrio archivo de.bin nuevamente\n");
		fseek( temp, 0, SEEK_SET );

	while(fread(ptr_aux,sizeof(juego_t),1, temp) == 1 )
	{
		printf("leo de temp y paso a db.bin\n");
		fwrite(ptr_aux,sizeof(juego_t),1, *fsalida);
		
		/*printf("Estructura:\nID: %lu \nNOMBRE: %s\nDESARROLLADOR: %s\nPLATAFORMA: %s\nFECHA: %s\nPUNTAJE: %f\nRESENIAS: %lu\n", ptr_juego_db->id, ptr_juego_db->nombre, ptr_juego_db->desarrollador, ptr_juego_db->plataforma, ptr_juego_db->fecha, ptr_juego_db->puntaje, ptr_juego_db->resenias);*/
	}	

	fclose(*fsalida);
	fclose(temp);

	return ST_OK;
}


status_t procesar_modificaciones(FILE ** fentrada, FILE ** fsalida, juego_t * ptr_juego_data, juego_t * ptr_juego_db )
{
	FILE * temp;
	
	while(fread(ptr_juego_db,sizeof(juego_t),1, *fsalida) == 1 )
	{	
		while(fread(ptr_juego_data,sizeof(juego_t),1, *fentrada) == 1)
		{			
			if(((ptr_juego_data)->id) != ((ptr_juego_db)->id))
			{
			
				if((temp=fopen("temp.bin","wb"))==NULL)  /* puse ab porque escribo dos veces */
				{
					printf("entre a error de archivo temporal\n");
					return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
				}
				
					fwrite(ptr_juego_db,sizeof(juego_t),1, temp);
			
			}else
			{
				fwrite(ptr_juego_data,sizeof(juego_t),1, temp);
			}

		}
	}

	fclose(*fsalida);
	fclose(*fentrada);

	if((*fsalida=fopen("db.bin","wb"))==NULL)
	{
		printf("entre a error de archivo temporal\n");
		return ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA;
	}

	while(fread(ptr_juego_db,sizeof(juego_t),1, temp) == 1 )
	{
		fwrite(ptr_juego_db,sizeof(juego_t),1, *fsalida);
	}	

	fclose(*fsalida);
	fclose(temp);

	return ST_OK;
}