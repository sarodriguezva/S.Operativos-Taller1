#include "../includes/funciones.h"
#include "../includes/estructuras.h"

int main() {	
	viajes temporal;
    char buffer[200];
    
    double* medias= malloc(SIZE_HASH*sizeof(double));

    mediaOrderInArray( medias, temporal);

    arrayToBinFile( medias);
		
}
