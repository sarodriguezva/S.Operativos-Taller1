#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

#define DATA_CSV    "../files/data.csv"
#define BIN_MEDIAS  "../files/binM.bin"
#define COM_BIN     "../files/comunicacion.bin"
#define SIZE_HASH   32294400

#ifdef FUNCIONES
#define FUNCIONES



//Calculo función Hash
int hash(int origen, int destino, int hora);

//Pone todos los datos en -1 en el archivo de comunicación
void resetMCompartida();



//USADAS POR GUARDAR


//Organiza los datos del csv en un archivo array de doubles creado en malloc
void mediaOrderInArray( double* medias, viajes temporal);

//Ingresa los datos previamente almacenados en un array de doubles en malloc, dentro de un archivo binario para ejecutar esa busqueda sobre ese .bin ordenado
void arrayToBinFile( double* medias);


//USADAS POR INTERFAZ

//Valida que las entradas del usuario cumplan con ciertos limites 
void entradas(int minimo,int maximo,int* option);

//Envío de mensajes en pantalla segun las entradas para las opciones 1 2 y 3
void select123(int option,int* dato);

//Envío de mensajes en pantalla para la entrada en la opción 4.
void select4(int origen, int destino, int hora);


//USADAS POR INTERFAZ  y BUSCAR

//Lee los datos almacenados en el archivo de comunicacion.bin
void obtenerInputs(viajes* mCompartida);

//Reemplaza los datos almacenados en el archivo comunicacion.bin
void update_mCompartida(viajes* mCompartida);

//Hay otra función al final del archivo buscar.c y buscar2.c

#endif



