#include "../includes/funciones.h"
#include "../includes/estructuras.h"

double devolverMedia(int index);

int main(){

	system("clear");
	viajes mCompartida ={-1,-1,-1,-1};
    resetMCompartida();
	
	//Ciclo que deja en espera al proceso buscar hasta tener entradas validas para operar
    ///////// 
    while(mCompartida.origen==-1){
			FILE* cBi = fopen(COM_BIN,"rb");
		
			if (!cBi){
				perror("No fue posible abrir el archivo binario");
			}
			fread(&mCompartida,sizeof(viajes),1,cBi);
			
            if(mCompartida.destino==-2){
                return 1;
            }
            fclose(cBi);
            
	}

	// Obtiene las entradas proporcionadas por la INTERFAZ 
	obtenerInputs(&mCompartida);
	
	int h=hash(mCompartida.origen,mCompartida.destino,mCompartida.hora);
	
	// Devuelve un valor de media asociado a un indice en particular, con el cual busca dentro del archivo binario
	mCompartida.media = devolverMedia(h);
    mCompartida.origen=-1;
	
	printf("%d %d %d %lf \n", mCompartida.origen,mCompartida.destino,mCompartida.hora,mCompartida.media);
	
	//actulizar el archivo de memoria compartida
	update_mCompartida(&mCompartida);
    main();
	
}




// Devuelve un valor de media asociado a un indice en particular, con el cual busca dentro del archivo binario
double devolverMedia(int index){

	double media;
	FILE* dataB = fopen(BIN_MEDIAS,"rb");
	if (!dataB){
		perror("No fue posible abrir el archivo binario");
		return 1;
	}
	
	fseek(dataB,index*sizeof(double),SEEK_SET);
	fread(&media,sizeof(double),1,dataB);
	fclose(dataB);
	rewind(dataB);
	return media;
	
}
