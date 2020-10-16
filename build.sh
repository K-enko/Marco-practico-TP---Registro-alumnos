#!/bin/bash

## Borro el directorio build si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

## Creo los directorios para el Binario
mkdir ./build/

## Compilo el Binario
g++ -Wall -std=c++11 -c students.cpp 
g++ -Wall -std=c++11 -c main.cpp 
g++ students.o main.o  -o ./build/students.bin

## Limpio los códigos objeto
rm ./*.o