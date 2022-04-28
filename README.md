# DBandProcessInC
Comunicación entre procesos para la lectura de un .csv que consiste en una tabla con millones de incidencias.

IMPORTANTE!!

Para que el ejecutable guardar funcione de manera correcta debe de guardar el data.csv proporcionado por el progesor en la carpeta files, con el nombre de "data.csv".


¿Cómo correr el programa?

COMANDOS 



make
cd bin
./guardar

Terminal 1 en la carpeta bin

./interfaz

Terminal 2 en la carpeta bin

./buscar

o

(Solo despues de haber ingresado los datos en interfa)
./buscar2

EXPLICACIÓN

1. EJECUTAR EL COMANDO MAKE: Abrir la carpeta DBANDPROCESSINC en un terminal bash y ejecuto el comando " make", se crean todos los ejecutables y los *o en sus respectivas carpetas.

2. EJECUTAR EL COMANDO ./guardar: En caso de no estar creada, la función guarda todos los datos de el .csv en un binario de manera ordenada según una funcion hash.

3. EJECUTAR EL COMANDO ./interfaz: Activa la interfaz de usuario y guarda las entradas del mismo en el archivo de comunicacion.bin. Y luego se queda en espera de el dato de la media resultante en el mismo archivo.

4. EJECUTAR EL COMANDO ./buscar: Genera un proceso concurrente que está a la espera de el ingreso de datos por parte de interfaz. Y cuando ya tiene datos de entrada validos, envía el resultado de la busqueda atravez del archivo comunicación, hacia el proceso ./interfaz.

5. EJECUTAR EL COMANDO ./buscar2: Revisa el archivo de comunicación.bin y escribe una media en el archivo según los valores de entrada que encuantra en el mismo.



Cristhian David Mora Uribe cdmorau@unal.edu.co