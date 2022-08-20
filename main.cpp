/*******************************
Author:Andrea Carolina Terraza
Materia: Introducción a HPC
Taller de Eigen
Fecha:19/08/2022
********************************/
//Librerias para usar std y Eigen
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>

int main(){
    //se crean dos matrices de tamañp 2x2 tipo float
    Eigen::Matrix2f A;
    Eigen::Matrix2f B;

    //se asignan manualmente los valores de las matrices
    A<< 4,-2,1,-7;
    B<<-1,2,6,-5;

    std::cout<<"Se imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"Se imprime matriz B:\n"<<B<<std::endl;
    std::cout<<"Ecuación: X = 3A -4B "<<std::endl;

    //Se crea otra matriz que va a guardar el resultado
    Eigen::Matrix2f resultado;

    resultado = 3*A - 4*B;
    std::cout<<"Se imprime resultado:\n"<<resultado<<std::endl;

    /********************* B) X = (3BA -4A)/2 ********************/
    std::cout<<"Ejercicio b)"<<std::endl;

    //Se crea la matriz X 2x2 de float que es el resultado de la ecuación
    Eigen::MatrixXf X;
    //Se reasignan los valores de las matrices A,B
    A<<0,-1,2,1;
    B<<1,2,3,4;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"\nSe imprime matriz B:\n"<<B<<std::endl;

    std::cout<<"Ecuación: X = (3BA -4A)/2 "<<std::endl;

    //Matriz X va a tomar el valor de las operaciones a realizar
    X=(3*B*A - 4*A) * 1/2;
    std::cout<<"resultado matriz X:\n"<<X<<std::endl;

    /***************** C) X = A^-1 * C * B^-1 ****************/
    std::cout<<"\nEjercicio c)"<<std::endl;
    //Se crea la matriz C
    Eigen::Matrix2f C,Y;
    C<<1,1,0,0;

    //Se reasignan los valores de las matrices A,B
    A<<-3,-2,3,3;
    B<<5,3,9,4;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"\nSe imprime matriz B:\n"<<B<<std::endl;
    std::cout<<"\nSe imprime matriz C:\n"<<C<<std::endl;
    std::cout<<"\nSe imprime matriz B transpuesta:\n"<<B.transpose()<<std::endl;

    std::cout<<"Ecuación:  X = A^-1 * C * B^-1 "<<std::endl;
    //Matriz X es el resultado de la Ec.
    X = A.inverse() * C * B.transpose().inverse();
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

    /***************** d) X = B * A^-1 ****************/
    std::cout<<"\nEjercicio d)"<<std::endl;
    //Se reasignan los valores de las matrices A,B
    A<<2,1,-4,-3;
    B<<2,2,6,4;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"\nSe imprime matriz B:\n"<<B<<std::endl;

    //Matriz X es el resultado de la Ec.
    std::cout<<"Ecuación: X = B * A^-1"<<std::endl;
    X = B * A.inverse();
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

    /***************** e) X = 2(AB +C) ****************/
    std::cout<<"\nEjercicio e)"<<std::endl;
    //Se reasignan los valores de la matriz C
    C<<-2,0,-2,-5;

    //Se crean nuevas matrices con diferentes dimensiones
    // para A1 y B1

    Eigen::MatrixXf A1 (2,3);
    Eigen::MatrixXf B1 (3,2);

    //Se asignan los valores a A1 y B1
    A1 << 3,0,-1,
          0,2,1;

    B1 <<1,2,
         1,0,
         0,6;

    std::cout<<"\n\nSe imprime matriz A1:\n"<<A1<<std::endl;
    std::cout<<"\nSe imprime matriz B1:\n"<<B1<<std::endl;
    std::cout<<"\nSe imprime matriz C:\n"<<C<<std::endl;

    std::cout<<"Ecuación: X = 2(AB +C)"<<std::endl;
    //Matriz X es el resultado de la Ec.
    X =2*(A1*B1 + C );
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;


    /***************** f) X =A + 3B ****************/
    std::cout<<"\nEjercicio F)"<<std::endl;

    //SE crean nuevas matrices con diferentes dimensiones
    //de 3x3 para A2 y B2
    Eigen::Matrix3f A2,B2;
    //Se asignan los valores a A2 y B2
    A2 << 1,5,-1,
          -1,2,2,
          0,-3,3;

    B2 <<-1,-4,3,
          1,-2,-2,
          -3,3,-5;

    std::cout<<"\n\nSe imprime matriz A2:\n"<<A2<<std::endl;
    std::cout<<"\nSe imprime matriz B2:\n"<<B2<<std::endl;
    std::cout<<"\nEcuación:  X =A + 3B"<<std::endl;
    //Matriz X1 es el resultado de la Ec.
    X = A2 + 3*B2;
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;


    /***************** g) X = B * A^-1 ****************/
    std::cout<<"\nEjercicio g)"<<std::endl;

    //Se reasignan los valores de las matrices A2,B2
    // que tienen dimensión 3x3
    A2<<2,7,3,
        3,9,4,
        1,5,3;
    //Se le asigna la matriz identidad a la matriz B2
    B2<<1,0,2,
        0,1,0,
        0,0,1;

    std::cout<<"\n\nSe imprime matriz A2:\n"<<A2<<std::endl;
    std::cout<<"\nSe imprime matriz B2:\n"<<B2<<std::endl;
    std::cout<<"\nEcuación: X = B * A^-1"<<std::endl;
    //Matriz X es el resultado de la Ec.
    X = B2 * A2.inverse();
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

    /***************** h) X = A^-1 * B ****************/
    std::cout<<"\nEjercicio h)"<<std::endl;

    //Se reasignan los valores de las matrices A2,B2
    // que tienen dimensión 3x3
    A2<<1,1,1,
        6,5,4,
        13,10,8;
    //Se le asigna la matriz identidad a la matriz B2
    B2<<0,1,2,
        1,0,2,
        1,2,0;

    std::cout<<"\n\nSe imprime matriz A2:\n"<<A2<<std::endl;
    std::cout<<"\nSe imprime matriz B2:\n"<<B2<<std::endl;
    std::cout<<"\nEcuación:  X = A^-1 * B"<<std::endl;
    //Matriz X es el resultado de la Ec.
    X = A2.inverse() * B2;
    std::cout<<"resultado matriz X:"<<X<<std::endl;

    /********************* I) X= At * A - 2*A *******************/
    std::cout<<"Ejercicio I)"<<std::endl;

    //Se reasignan los valores de la matriz A
    A<<3,-1,0,2;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"Ecuación: X= At * A - 2*A  "<<std::endl;

    //Matriz X va a tomar el valor de las operaciones a realizar
    X=A.transpose() * A - 2*A;
    std::cout<<"resultado matriz X:\n"<<X<<std::endl;

    /********************* J) X=A^3 *******************/
    std::cout<<"Ejercicio J)"<<std::endl;

    //Se reasignan los valores de la matriz A
    A<<4,2,-1,0;

    X=A*A*A;
    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"Ecuación: X= A^3 "<<std::endl;

    //Matriz X va a tomar el valor de las operaciones a realizar
    std::cout<<"resultado matriz X:\n"<<X<<std::endl;

    /********************* K) X=At^-1 *C * B^-1 *******************/
    std::cout<<"Ejercicio K)"<<std::endl;

    //Se reasignan los valores de las matrices A,B,C
    C<<7,5,6,1;
    A<<2,4,3,2;
    B<<1,0,2,1;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A<<std::endl;
    std::cout<<"\nSe imprime matriz B:\n"<<B<<std::endl;
    std::cout<<"\nSe imprime matriz C:\n"<<C<<std::endl;
    std::cout<<"Ecuación:X=At^-1 *C * B^-1  "<<std::endl;
    X=A.transpose().inverse() * C * B.inverse();

    //Matriz X va a tomar el valor de las operaciones a realizar
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

    /********************* L) X=A*At -2A*B *******************/
    std::cout<<"\nEjercicio L)"<<std::endl;

    //Se reasignan los valores de las matrices A1,B1
    //Que tienes dimensiones 2x3 y 3x2
    A1<<1,0,-2,
        2,-1,3;
    B1<<2,-3,
       -2,0,
       -1,-2;

    std::cout<<"\n\nSe imprime matriz A:\n"<<A1<<std::endl;
    std::cout<<"\nSe imprime matriz B:\n"<<B1<<std::endl;
    std::cout<<"Ecuación:X=A*At -2A*B  "<<std::endl;
    X=A1 * A1.transpose() - 2*A1*B1;

    //Matriz X va a tomar el valor de las operaciones a realizar
    std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

    /********************* M) X=A*B*C *******************/
        std::cout<<"\nEjercicio M)"<<std::endl;

        //Se reasignan los valores de la matriz B1
        B1<<3,2,
           0,1,
           -1,0;
        //Se crean los vectores v1 y v2
        Eigen::MatrixXf v1 (1,3);
        Eigen::MatrixXf v2 (2,1);

        //Se asignan los valores
        v1<<4,8,12;
        v2<<3,-1;

        std::cout<<"\n\nSe imprime matriz B:\n"<<B1<<std::endl;
        std::cout<<"\nSe imprime vector v1:\n"<<v1<<std::endl;
        std::cout<<"Se imprime vector v2:\n"<<v2<<std::endl;
        std::cout<<"Ecuación:X=A*B*C"<<std::endl;
        X=v1* B1 * v2;

        //Matriz X va a tomar el valor de las operaciones a realizar
        std::cout<<"\nresultado matriz X:\n"<<X<<std::endl;

        /***************** O)X = B * A^-1  ****************/
        std::cout<<"\nEjercicio O)"<<std::endl;

        //Se reasignan los valores de las matrices A2,B2
        // que tienen dimensión 3x3
        A2<<2,5,7,
            6,3,4,
            5,-2,-3;
        //Se le asigna la matriz identidad a la matriz B2
        B2<<-1,1,0,
            0,1,1,
            1,0,-1;

        std::cout<<"\n\nSe imprime matriz A2:\n"<<A2<<std::endl;
        std::cout<<"\nSe imprime matriz B2:\n"<<B2<<std::endl;
        std::cout<<"\nEcuación:  X = B * A^-1"<<std::endl;
        //Matriz X es el resultado de la Ec.
        X =B2 * A2.inverse() ;
        std::cout<<"resultado matriz X:\n"<<X<<std::endl;

        /***************** P) X= A^-1 *B  ****************/
        std::cout<<"\nEjercicio P)"<<std::endl;
        //Se crean dos matrices de 4x4
        Eigen::Matrix4f A3,B3;
        //Se asignan los valores de las matrices A3,B3

        A3<<1,1,1,1,
            1,1,-1,-1,
            1,-1,1,-1,
            1,-1,-1,1;
        //Se le asigna la matriz identidad a la matriz B2
        B3<<1,1,0,0,
            1,0,1,0,
            1,0,0,1,
            1,0,1,1;

        std::cout<<"\n\nSe imprime matriz A3:\n"<<A3<<std::endl;
        std::cout<<"\nSe imprime matriz B3:\n"<<B3<<std::endl;
        std::cout<<"\nEcuación:  X = A^-1 * B"<<std::endl;
        //Matriz X es el resultado de la Ec.
        X =A3.inverse() * B3;
        std::cout<<"resultado matriz X:\n"<<X<<std::endl;

}


