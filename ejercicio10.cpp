//Author: Andrea Carolina Terraza
//Fecha:10/08/2022
//Introducción HPC

#include <iostream>
main() {

    int n,j=0;

    std::cout<<"Ingrese hasta que numero calcular centro numerico"<<std::endl;
    std::cin>>n;
    int mitad =0, sumaIzq=0, sumaDer=0, CenNumerico=0;

    if(n%2 != 0){
        mitad = n/2+1;
    }else{
        mitad = n/2;
    }
    for (int i=mitad;i<=n;i++){
        sumaIzq=0;
        sumaDer=0;
        for(j=1; j<i; j++){
            sumaIzq = sumaIzq + j;

        }

        for(int k=(i+1); k<=n; k++){
            sumaDer = sumaDer + k;

        }

        if(sumaIzq == sumaDer){
            CenNumerico = i;
            std::cout<<CenNumerico<<std::endl;
        }
    }
}
