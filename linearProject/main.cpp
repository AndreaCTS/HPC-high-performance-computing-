/*
 * Fecha:21 septiembre 2022
 * Author:ANdrea Terraza
 * Materia: HPC
 * tópico: Implementación de la regresión linear como
 * modelo en C++
 * Requerimeintos:
 * -Construit una clase Extraction, que permita
 * manipular, extraer y cargas los dtaos
 * -Construir una clase LInearRegression,que permita
 * los calculos de la función costo,gradiente descendiente
 * entre otras.*/


#include "ExtractionData/extractiondata.h"
#include<iostream>
#include<eigen3/Eigen/Dense>
#include<list>
#include<boost/algorithm/string.hpp>
#include<vector>
#include<fstream>
#include"LinearRegresion/linear_regresion.h"

int main()
{	
    std::string delimitador = ",";
    std::string ruta = "adm_data.csv";	
    //std::ifstream archivo("adm_data.csv");
    /*Se necesitan 3 argumentos de entrada
    std::cout<<"Argv 1 "<<argv[1]<<std::endl;
    std::cout<<"Argv 2 "<<argv[2]<<std::endl;
    std::cout<<"Argv 3 "<<argv[3]<<std::endl;*/

    /*Se crea un objeto de tipo ExtractionData*/
    ExtractionData ExData  (ruta,delimitador,false);
    /*se instancia la clase de regresion lineal en un un objeto*/
    linear_regresion modeloLR;

    /*SE crea un vector de vectores del tipo string
     * para cargar objeto ExData*/

    std::vector<std::vector<std::string>> dataframe = ExData.LeerCSV();

    /*Cantidad de filas y columnas*/
    int filas = dataframe.size();
    int columnas = dataframe[0].size();


    //std::cout<<"Filas "<<filas<<std::endl;
    //std::cout<<"Columnas "<<columnas<<std::endl;

    Eigen::MatrixXd matData = ExData.CSVtoEigen(dataframe,filas,columnas);
    /*Se normaliza la matriz de datos*/
    Eigen::MatrixXd matNormalizada = ExData.Normalizacion(matData);

    //std::cout<<"Matriz  \n"
    //        <<matData<<std::endl;

    /*SE divide en datos de entrenamiento y en datos de prueba*/
    Eigen::MatrixXd X_Train, y_Train, X_Test,y_Test;
    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> div_datos = ExData.TrainTestSplit(matNormalizada,0.8);

    /* Se descomprime la tupla en 4 conjuntos */
    std:: tie (X_Train, y_Train, X_Test,y_Test)= div_datos;
    /*SE crean vectores auxiliares para prueba y entrenamiento inicializados en 1 */
    Eigen::VectorXd V_train = Eigen::VectorXd::Ones(X_Train.rows());
    Eigen::VectorXd V_test = Eigen::VectorXd::Ones(X_Test.rows());

    std::cout<<"Filas Entrenamiento "<<V_train.rows()<<std::endl;
    /*SE redimensiona matriz de entrenamiento y de prueba para
     * ser ajustada a los vectores auxiliares anteriores*/

    X_Train.conservativeResize(X_Train.rows(),X_Train.cols()+1);
    X_Train.col(X_Train.cols()-1) = V_train;

    X_Test.conservativeResize(X_Test.rows(),X_Test.cols()+1);
    X_Test.col(X_Test.cols()-1) = V_test;

    /*SE crea el vector de coeficientes thetha*/
    Eigen::VectorXd thetha = Eigen::VectorXd::Zero(X_Train.cols());
    /*SE crea el vector de coeficientes thetha*/
    Eigen::VectorXd thethaTest = Eigen::VectorXd::Zero(X_Test.cols());
    /*SE establece el alpha como ratio de aprendizaje
     * de tipo flotante */
    float alpha = 0.01;
    int iteraciones = 1000;


    //SE crea un vector para almacenar las thethas de salida
    Eigen::VectorXd thethasOut;
    Eigen::VectorXd thethasOutTest;
    //SE crea un vector sencillo de flotantes para almacenar
    //los valores del costo
    std::vector<float> costo;
    std::vector<float> costoTest;
    //SE calcula el gradiente descendiente

    std::tuple<Eigen::VectorXd, std::vector<float>> g_decendiente = modeloLR.gradientDescent(X_Train,
                                                                             y_Train,
                                                                             thetha,
                                                                             alpha,
                                                                             iteraciones);

    /*std::tuple<Eigen::VectorXd, std::vector<float>> g_decendienteTest = modeloLR.gradientDescent(X_Test,
                                                                             y_Test,
                                                                             thethaTest,
                                                                             alpha,
                                                                             iteraciones);
*/
    //SE desempaqueta el gradiente
    std::tie(thethasOut,costo) = g_decendiente;
    //std::tie(thethasOutTest,costoTest) = g_decendienteTest;
    /* se almacena los valores de thethas y costos en un fichero para posteriormente
     * ser visualizado*/
    //ExData.vectorToFile(costo,"costos.txt");
    //ExData.EigenToFile(thethasOut,"thethas.txt");
    //std::cout<<"thethas "<<thethasOutTest<<std::endl;
    /*Se extrae el promedio de la matriz de entrada*/
    auto prom_data = ExData.Promedio(matData);
    /*SE extraen los valores de la variable independiente*/
    auto var_prom_independientes = prom_data(0,7);
    std::cout<<"data "<<var_prom_independientes<<std::endl;
    /*SE escalan los datos */
    auto datos_escalados = matData.rowwise()-matData.colwise().mean();
    /*Se extrae la desviación estandar de los datos escalados*/
    auto desv_stand = ExData.DevStand(datos_escalados);
    //std::cout<<"Desviación estandar desv "<<desv_stand<<std::endl;
    /*SE extraen los valores de la variable independiente*/
    auto var_desv_independientes = desv_stand(0,7);
    /*SE crea una matriz para almacenar los valores estimados de entrenamiento*/
    Eigen::MatrixXd y_train_hat = (X_Train * thethasOut * var_desv_independientes).array() + var_prom_independientes;
    Eigen::MatrixXd y_test_hat = (X_Test * thethasOut * var_desv_independientes).array() + var_prom_independientes;


    /*Matriz para los valores reales de y*/
    Eigen::MatrixXd yT = matData.col(7).bottomRows(X_Test.rows());
    Eigen::MatrixXd y = matData.col(7).topRows(X_Train.rows());
    //std::cout<<y<<std::endl;
    /*Se revisa que tan bueno fue el modelo a traves de la metrica de rendimiento*/
    float metrica_R2 = modeloLR.R2score(y,y_train_hat);
    float metrica_R2Test = modeloLR.R2score(yT,y_test_hat);

    std::cout << "metrica_R2 Train: "<< metrica_R2<<std::endl;
    std::cout << "metrica_R2 Test: "<< metrica_R2Test<<std::endl;
    /*
    float metrica_MSE = modeloLR.MSE(y, y_train_hat);
    float metrica_RMSE = modeloLR.RMSE(y, y_train_hat);
    float metrica_MSET = modeloLR.MSE(yT, y_test_hat);
    float metrica_RMSET = modeloLR.RMSE(yT, y_test_hat);
    float metrica_Coeficiente = modeloLR.CoeficienteDeterminados(y, y_train_hat);
    std::cout << "metrica_MSE Train: "<< metrica_MSE<<std::endl;
    std::cout << "metrica_MSE Test: "<< metrica_MSET<<std::endl;
    std::cout << "metrica_RMSE Train: "<< metrica_RMSE<<std::endl;
    std::cout << "metrica_RMSE Test: "<< metrica_RMSET<<std::endl;
    std::cout << "metrica_Coeficientes Train: "<< metrica_Coeficiente<<std::endl;
    //ExData.vectorToFile(costo,"costos.txt");
    */

















































    return EXIT_SUCCESS;

}
