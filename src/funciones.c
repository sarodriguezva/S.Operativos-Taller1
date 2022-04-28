#include "../includes/funciones.h"
#include "../includes/estructuras.h"


//Calculo función Hash

int hash(int origen, int destino, int hora){
    return (origen-1)+1160*(destino-1)+1160*1160*(hora);

	//1160*1160*24
	//1160*1160*23+1160*1160
	//1160*1160*hora + destino*1159 + origen
	//(origen-1)+1160*(destino-1)+1160*1160*(hora)

}

void resetMCompartida(){
	viajes entrada={-1,-1,-1,-1};

	FILE* comunicacionBin = fopen(COM_BIN,"wb");
	if (!comunicacionBin){
		perror("No fue posible abrir el archivo binario");
	}
	
	rewind(comunicacionBin);
	fwrite(&entrada,sizeof(viajes),1,comunicacionBin);
	
	fclose(comunicacionBin);

}

// Funciones usadas para crear mBin.bin

void mediaOrderInArray( double* medias, viajes temporal){
	
	char buffer[200];
	FILE *data = fopen(DATA_CSV,"r");
	if (!data){
		perror("No fue posible abrir el CSV");
	}

	fgets(buffer,200,data);
	
	while(!feof(data)){
		fscanf(data,"%d,%d,%d,%lf",&temporal.origen,&temporal.destino,&temporal.hora,&temporal.media);
		fgets(buffer,200,data);
		int h =hash(temporal.origen,  temporal.destino,  temporal.hora);
		medias [(int)h ] = temporal.media;	
	}
	fclose(data);
}


	


void arrayToBinFile( double* medias){

	FILE *bin = fopen(BIN_MEDIAS,"w+b");
	if (!bin){
		perror("No fue posible abrir el archivo binario");
	}
	
	for(int i = 0; i<=SIZE_HASH; i++){
		fwrite(&medias[i],sizeof(double),1,bin);
	}
	fclose(bin);
	free(medias);
}


//Funciones usadas por buscar


void obtenerInputs(viajes* mCompartida){
	
	//Bajar los datos de la memoria compartida
	
	FILE* comunicacionBi = fopen(COM_BIN,"rb");

	if (!comunicacionBi){
		perror("No fue posible abrir el archivo de comunicación");
	}
	
	fread(mCompartida,sizeof(viajes),1,comunicacionBi);
	fclose(comunicacionBi);

}

// Función que reemplaza la estructura guardada en comunicacion.bin

void update_mCompartida(viajes* mCompartida){

	FILE* comunicacionBin = fopen(COM_BIN,"w+b");

	if (!comunicacionBin){
		perror("No fue posible abrir el archivo de comunicación");
	}
	
	fwrite(mCompartida,sizeof(viajes),1,comunicacionBin);
	fclose(comunicacionBin);
	
}

// Funciones usadas por la interfaz


void entradas(int minimo,int maximo,int *option){
	
	scanf("%d",option);
	system("clear");
	if( (*option >= minimo) && (*option <= maximo) ){
		while (getchar() != '\n');
	}
	else{
		
		printf("La opción ingresada es invalida..\n\n(⌣̩̩́_⌣̩̩̀) (⌣̩̩́_⌣̩̩̀) (⌣̩̩́_⌣̩̩̀) (⌣̩̩́_⌣̩̩̀) (⌣̩̩́_⌣̩̩̀) (⌣̩̩́_⌣̩̩̀) \n\n\n");
		printf("Por favor ingrese un valor entre %d y %d: ",minimo,maximo);

		while (getchar() != '\n');
		entradas(minimo,maximo,option);
	}

}

//Envío de mensajes en pantalla segun las entradas para las opciones 1 2 y 3

void select123(int option,int* dato){
	system("clear");
	int min[]={1,1,0},max[]={1160,1160,23};
	
	char* solicitudes[]= {
		"Ingrese ID del Origen: ",
		"Ingrese ID del Destino: ",
		"Ingrese Hora del Día: "
	};


	//Enviar inputMessage
	printf("%s",solicitudes[option-1]);

	//Tomando la entrada del dato y verificando que se encuentre dentro del rango
	entradas(min[option-1],max[option-1],dato);

}


//Envío de mensajes en pantalla para la entrada de la opción 4

void select4(int origen, int destino, int hora){


	if((origen+destino+hora)>9999){
		printf("Aún faltan los siguientes datos por cargar\n");

		if(origen>9999)
		{
			printf("Origen\n");
		}
		if(destino>9999)
		{
			printf("Destino\n");
		}
		if(hora>9999)
		{
			printf("Hora\n");
		}

	}
	else{
		viajes mCompartida;
		mCompartida.origen=origen;
		mCompartida.destino=destino;
		mCompartida.hora=hora;
		double a =-1.0;
		mCompartida.media=a;

		update_mCompartida(&mCompartida);

		//Ciclo while que pone en espera al proceso interfaz 
		while(mCompartida.media==a){
			FILE* cBi = fopen(COM_BIN,"rb");
		
			if (!cBi){
				perror("No fue posible abrir el archivo binario");
			}
			fread(&mCompartida,sizeof(viajes),1,cBi);
			fclose(cBi);
		}
		//1114,694,19,1268.8,341.98,1222.41,1.32


		printf("¡¡ LA VALIDACION HA SIDO EXITOSA ᕙ(`▿´)ᕗ !!\n\n");
		printf("	ORIGEN =	%d\n",origen);
		printf("	DESTINO =	%d\n",destino);
		printf("	HORA =		%d\n\n",hora);
		if(mCompartida.media==0){
			printf("	NA\n\n");
			printf("	Lo sentimos el registro no se encuentra en la base de datos \n\n");
			printf("	(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)(╥﹏╥)\n");
			
		}
		else{
			printf("	MEDIA =	 %lf\n\n\n",mCompartida.media);
		}
		

	}

}


