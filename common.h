#ifndef COMMON_H
#define COMMON_H

typedef enum {

				ST_OK,
				ST_ERROR_NO_MEM,
				ST_ERROR_PUNTERO_NULO,
				ST_ERROR_CARGAR_ID,
				ST_ERROR_CARGAR_FECHA,
				ST_ERROR_CARGAR_PUNTAJE,
				ST_ERROR_CARGAR_RESENIAS,
				ST_ERROR_CANT_ARG,
				ST_ERROR_APERTURA_ARCHIVO,
				ST_ERROR_CANTIDAD_INVALIDA_DE_ARGUMENTOS,
	/**************** ERRORES PARA APP PUNTAJE ***********************/
				ST_ERROR_CMD_ARG_OPERACION,
				ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_BASE_DE_DATOS,
				ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_BASE_DATOS_INVALIDO,
				ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_A_MODIFICAR,
				ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_A_MODIFICAR_INVALIDO,
				ST_ERROR_CMD_ARG_BANDERA_PARA_ARCHIVO_MSJS_DE_ERRORES,
				ST_ERROR_CMD_ARG_NOMBRE_ARCHIVO_MSJ_DE_ERRORES_INVALIDO,
				ST_ERROR_APERTURA_ARCHIVO_DE_ENTRADA,
				ST_ERROR_APERTURA_ARCHIVO_DE_SALIDA,

				ST_ERROR_ID_REPETIDO


	/*****************************************************************/			
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
#endif

#define MAX_ARGC 2
#define BASE 10


