# HPC (high-performance-computing)
Soy Andrea Carolina Terraza
Estudiante de Ciencias de la computación e inteligencia artificial

Bienvenido al repositorio, aquí encontraras ejercicios para familiarizarte 
con el lenguaje de programación c++ y la biblioteca de algebra linear
Eigen, lo anterior se ejecuta en Qt creator, que es un IDE multiplataforma.

Si quieres instalar Qt creator sigue el siguiente link:
https://web.stanford.edu/dept/cs_edu/resources/qt/install-linux

Para Ejecutar Qt desde la terminal sigue los pasos:
1. Crea un directorio o proyecto
 *  mkdir ProyectoQt
2. Crea un archivo .cpp dentro del directorio
 *  vim mainEjemplo.cpp
3. Copia y guarda tu código en el archivo en blanco que se 
creo dentro del directorio
4.Dentro del directorio ejecuta:
 * 	qmake -project
 5.  vim ProyectoQt.pro
 Dentro de ese archivo debemos agregar
    *	 QT += gui widgets
 Para poder compilar el proyecto desde la terminal
 ![image](https://user-images.githubusercontent.com/90526089/185759650-f217cc04-ed6d-4c24-8962-b1224c41f817.png)

6. Crear un ejecutable del programa(crea un makefile)
 * 	qmake ProyectoQt.pro
7 Para compilar el makefile en un programa ejecutable
 * 	qmake ProyectoQt.pro
8. Prueba el programa
 * 	./ProyectoQt

