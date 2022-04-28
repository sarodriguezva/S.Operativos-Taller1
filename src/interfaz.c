#include "../includes/funciones.h"
#include "../includes/estructuras.h"

int datos[]={99999,99999,99999};

int main(){

    viajes salir={-1,-2,-1,-1};
    
    resetMCompartida();
    
    int option = -999;

    system("clear");
    if((datos[0]+datos[1]+datos[2])==(99999*3)){
        printf("¡BIENVENIDO!\n\n");
    }
    printf("1. Ingresar origen\n");
    printf("2. Ingresar destino\n");
    printf("3. Ingresar hora\n");
    printf("4. Buscar tiempo de viaje medio\n");
    printf("5. Salir\n");

    

    entradas(1,5,&option);

    switch (option)
    {
    case 1:
        select123(option,&datos[option-1]);
        main();
        break;
    case 2:
        select123(option,&datos[option-1]);
        main();
        break;
    case 3:
        select123(option,&datos[option-1]);
        main();
        break;
    case 4:
        select4(datos[0],datos[1],datos[2]);
        printf("\nPresione enter para volver al menu principal");
        getchar();
        main();
        break;
    case 5:

        update_mCompartida(&salir);
        printf(" (•◡•) / (•◡•) / Gracias por el 5.0 profe (•◡•) / (•◡•) /\n\n\n");
        break;
    }
    



}





	

