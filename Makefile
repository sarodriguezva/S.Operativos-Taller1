all: guardar interfaz buscar buscar2
	clear

# Directorios
SRC_DIR    = ./src/
BIN_DIR    = ./bin/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
F_DIR      = ./files/


#Generar el ejecutable guardar
guardar: $(OBJ_DIR)guardar.o $(OBJ_DIR)funciones.o
	gcc -o $(BIN_DIR)guardar $(OBJ_DIR)guardar.o $(OBJ_DIR)funciones.o

$(OBJ_DIR)guardar.o: $(SRC_DIR)guardar.c $(INC_DIR)funciones.h $(INC_DIR)estructuras.h
	gcc -c $(SRC_DIR)guardar.c -o $(OBJ_DIR)guardar.o


#Generar el ejecutable interfaz
interfaz: $(OBJ_DIR)interfaz.o $(OBJ_DIR)funciones.o
	gcc -o $(BIN_DIR)interfaz $(OBJ_DIR)interfaz.o $(OBJ_DIR)funciones.o

$(OBJ_DIR)interfaz.o: $(SRC_DIR)interfaz.c $(INC_DIR)funciones.h $(INC_DIR)estructuras.h
	gcc -c $(SRC_DIR)interfaz.c -o $(OBJ_DIR)interfaz.o


#Generar el ejecutable de buscar
buscar: $(OBJ_DIR)buscar.o $(OBJ_DIR)funciones.o
	gcc -o $(BIN_DIR)buscar $(OBJ_DIR)buscar.o $(OBJ_DIR)funciones.o

$(OBJ_DIR)buscar.o: $(SRC_DIR)buscar.c $(INC_DIR)funciones.h $(INC_DIR)estructuras.h
	gcc -c $(SRC_DIR)buscar.c -o $(OBJ_DIR)buscar.o


#Generar el ejecutable de buscar2
buscar2: $(OBJ_DIR)buscar2.o $(OBJ_DIR)funciones.o
	gcc -o $(BIN_DIR)buscar2 $(OBJ_DIR)buscar2.o $(OBJ_DIR)funciones.o

$(OBJ_DIR)buscar2.o: $(SRC_DIR)buscar2.c $(INC_DIR)funciones.h $(INC_DIR)estructuras.h
	gcc -c $(SRC_DIR)buscar2.c -o $(OBJ_DIR)buscar2.o



#Generar el archivo objeto de funciones o 
$(OBJ_DIR)funciones.o: $(SRC_DIR)funciones.c $(INC_DIR)funciones.h $(INC_DIR)estructuras.h
	gcc -c $(SRC_DIR)funciones.c -o $(OBJ_DIR)funciones.o


#Borra todos los *.o los ejecutables en bin  y los archivos binarios de comunicacion.bin y binM.bin
cleanF:

	rm -r $(OBJ_DIR)*o $(BIN_DIR)guardar $(BIN_DIR)interfaz $(BIN_DIR)buscar $(BIN_DIR)buscar2
	rm $(F_DIR)binM.bin $(F_DIR)comunicacion.bin
	clear

#Borra todos los *.o los ejecutables en bin
clean:

	rm -r $(OBJ_DIR)*o $(BIN_DIR)guardar $(BIN_DIR)interfaz $(BIN_DIR)buscar $(BIN_DIR)buscar2
	clear
