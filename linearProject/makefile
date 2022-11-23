
# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation

CC=g++
#-ansi -pedantic -std=c++11
CFLAGS=-c -Wall 

all: output

output: main.o linear_regresion.o extractiondata.o
	$(CC) main.o linear_regresion.o extractiondata.o -o output

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

linear_regresion.o: LinearRegresion/linear_regresion.h LinearRegresion/linear_regresion.cpp
	$(CC) $(CFLAGS) LinearRegresion/linear_regresion.cpp

extractiondata.o: ExtractionData/extractiondata.h  ExtractionData/extractiondata.cpp
	$(CC) $(CFLAGS)  ExtractionData/extractiondata.cpp

clean:
	rm -rf *o output
