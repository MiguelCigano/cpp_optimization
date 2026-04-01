#pragma once

/**
 * @brief Número de features polinomiales
 *
 * φ(x) = [1, x1, x2, x1^2, x1*x2, x2^2]
 */
#define N_FEATURES 6

extern float theta[N_FEATURES]; ///< parámetros del actor
extern float w[N_FEATURES];     ///< parámetros del critic

/**
 * @brief Calcula las features polinomiales φ(x)
 *
 * @param x estado [x1, x2]
 * @param phi vector de salida
 */
void compute_features(float* x, float* phi);

/**
 * @brief Política (actor)
 *
 * u = θ^T φ(x)
 */
float policy(float* phi);

/**
 * @brief Función de valor (critic)
 *
 * V(x) = w^T φ(x)
 */
float value(float* phi);

/**
 * @brief Entrenamiento Actor-Critic
 */
void train();

