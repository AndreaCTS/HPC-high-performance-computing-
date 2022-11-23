#ifndef LINEAR_REGRESION_H
#define LINEAR_REGRESION_H
#include<eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <cmath>

class linear_regresion
{
public:
    float F_OLS_Costo (Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd thetha);
    std::tuple<Eigen::VectorXd, std::vector<float>> gradientDescent (Eigen::MatrixXd X,
                                                                     Eigen::MatrixXd y,
                                                                     Eigen::VectorXd thetha,
                                                                     float alpha,
                                                                     int num_iter);
    float R2score (Eigen::MatrixXd y, Eigen::MatrixXd y_hat);
    float MSE (Eigen::MatrixXd y, Eigen::MatrixXd y_hat );
    float RMSE (Eigen::MatrixXd y, Eigen::MatrixXd y_hat );
    float CoeficienteDeterminados (Eigen::MatrixXd y, Eigen::MatrixXd y_hat );
};

#endif // LINEAR_REGRESION_H
