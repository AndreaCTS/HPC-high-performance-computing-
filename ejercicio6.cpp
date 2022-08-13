#include <stdio.h>
#include <iostream>
main() {

    seguir = true;
    while(seguir){
        std::cout <<" ingrese el dato a:"<<std::endl;
        cin >>a;
        std::cout <<" ingrese el dato b:"<<std::endl;
        cin >>b;
        if(a>=0 && b>=0)
            seguir=false;
   }
    if(a>b){
        b=a;
        a=b;
        for (i = b; i <= a; i++){
            if(i%5==0)
                std::cout<<"numero multiplo de 5:",i<<std::endl;
        }
    }else if(a<b){
        for (i = a; i <= b; i++){
            if(i%5==0)
                std::cout<<"numero multiplo de 5:",i<<std::endl;
        }
    }

}
