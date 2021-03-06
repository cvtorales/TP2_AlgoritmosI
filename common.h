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
				char fecha[12];
				double puntaje;
				size_t resenias;
				} juego_t;
#endif

#define MAX_ARGC_CREAR_BASE 3
#define MAX_ARGC_DECO_BASE 2
#define BASE 10
#define DELIMITADOR ','
#define MSJ_ERROR_VALIDACION "Error en alguna validacion\n"
#define MSJ_ERROR_NO_MEM_ARR "No hay memoria para crear el arreglo\n"
#define MSJ_ERROR_LECTURA_STRUCT "No se pudo leer la estructura\n"
#define MSJ_ERROR_NO_MEM_ARR2 "No hay memoria para crear el arreglo[2]\n"
#define MSJ_ERROR_SPLIT "Error al parsear con la funcion split\n"
#define MSJ_ERROR_CARGA_STRUCT "error al cargar la estructura\n"

