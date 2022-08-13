//Author: Andrea Carolina Terraza
//Fecha:10/08/2022
//Introducción HPC

#include <iostream>
//programa para conocer tu n
main() {

    int dia,mes,año;
    bool seguir=true;

    while(seguir==true){
        std::cout<<"Ingrese su dia de nacimiento: ";
        std::cin>>dia;
        if(dia>0 && dia<=31)
            seguir=false;
    }

    while(seguir==false){
        std::cout<<"Ingrese su mes de nacimiento: ";
        std::cin>>mes;
        if(mes>0 && mes<=12)
            seguir=true;
    }

    while(seguir==true){
        std::cout<<"Ingrese su año de nacimiento: ";
        std::cin>>año;
        if(año>=1000 && año<=2022)
            seguir=false;
    }

     int i=0;
     int suma = dia+mes+año;
     int digitos [4];

     while(suma>0){
         digitos[i]=suma%10;
         suma=suma/10;
         i++;
     }

     int suma2= digitos[0]+ digitos[1] +digitos[2] + digitos[3];
     int resultado=0;

     while(suma2>0){
         resultado+=suma2%10;
         suma2=suma2/10;
     }
     std::cout<<"su numero del tarot es: "<<resultado<<std::endl;
}

