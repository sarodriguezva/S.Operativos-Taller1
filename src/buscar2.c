#include "../includes/funciones.h"
#include "../includes/estructuras.h"

double devolverMedia(int index);

int main(){

	system("clear");
	viajes mCompartida ={-1,-1,-1,-1};
	
	//Bajar los datos de la memoria compartida

	obtenerInputs(&mCompartida);
	
	int h=hash(mCompartida.origen,mCompartida.destino,mCompartida.hora);
	
	//obtener la media correspondiente en base a los datos que ingreso el usuario en la interfaz
	mCompartida.media = devolverMedia(h);
    mCompartida.origen=-1;
	
	printf("%d %d %d %lf \n", mCompartida.origen,mCompartida.destino,mCompartida.hora,mCompartida.media);
	
	//actulizar el archivo de memoria compartida
	update_mCompartida(&mCompartida);

	
}


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
