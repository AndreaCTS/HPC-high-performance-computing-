//Author: Andrea Carolina Terraza
//Fecha:10/08/2022
//Introducción HPC
#include <stdio.h>
#include <iostream>
//programa para hacer una serie matematica hasta cierto n
main() {

    float a=0, b,x=4,y=3,i;
    float serie_resultado;

    std::cout <<" ingrese hasta que numero realizar la serie:"<<std::endl;
    std::cin >>b;

    std::cout <<" Resultados de la Serie:"<<std::endl;
    for (i = a; i <= b; i++){
         serie_resultado= 1 /(x + (i*y));

         std::cout<<"R: "<<serie_resultado<<std::endl;
     }
    return 0;
}
