#include "rl_poly.hpp"
#include "dynamics.hpp"
#include "utils.hpp"
#include <stdio.h>

/** Model parameter */
float theta[N_FEATURES] = {0}; // actor
float w[N_FEATURES] = {0};     // critic

/** Hiperparametros */
float alpha_w       = 0.01f;
float alpha_theta   = 0.005f;
float gamma         = 0.99f;
float dt            = 0.01f;
float U_MAX         = 10.0f;

/** Rango para normalizacion */
float X1_MIN = -2.0f, X1_MAX = 2.0f;
float X2_MIN = -2.0f, X2_MAX = 2.0f;

/**
 * @brief Normaliza el estado a [0,1]
 *
 * Esto es crítico para estabilidad numerica.
 */
void normalize(float* x) {
    x[0] = (x[0] - X1_MIN) / (X1_MAX - X1_MIN);
    x[1] = (x[1] - X2_MIN) / (X2_MAX - X2_MIN);
}

/**
 * @brief Build features polinomiales
 */
void compute_features(float* x, float* phi) {

    float x1 = x[0];
    float x2 = x[1];

    phi[0] = 1.0f;
    // phi[0] = x1 * x1;
    phi[1] = x1;
    phi[2] = x2;
    phi[3] = x1 * x1;
    phi[4] = x1 * x2;
    phi[5] = x2 * x2;
}

/**
 * @brief dot product
 */
float dot(float* a, float* b) {
    float sum = 0.0f;
    for (int i = 0; i < N_FEATURES; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

/**
 * @brief Control policy
 */
float policy(float* phi) {
    return dot(phi, theta);
}

/**
 * @brief Funcion de valor
 */
float value(float* phi) {
    return dot(phi, w);
}

/**
 * @brief Función de recompensa
 *
 * Penaliza:
 * - posicion (x1)
 * - velocidad (x2)
 * - esfuerzo de control (u)
 */
float reward(float* x, float u) {
    float x1 = x[0];
    float x2 = x[1];

    return - (x1*x1 + 0.1f*x2*x2 + 0.001f*u*u);
}

/**
 * @brief Loop principal de entrenamiento Actor-Critic
 */
void train() {

    FILE* f = fopen("trajectory.csv", "w");

    float x[2] = {0.5f, 0.0f}; // estado inicial
    float phi[N_FEATURES];
    float phi_next[N_FEATURES];

    for (int t = 0; t < 8000; t++) {

        float x_norm[2] = {x[0], x[1]};
        normalize(x_norm);

        compute_features(x_norm, phi);

        float u = policy(phi);

        /// Exploracion
        u += 0.1f * randn();

        /// Saturacion
        if (u > U_MAX) u = U_MAX;
        if (u < -U_MAX) u = -U_MAX;

        float r = reward(x, u);

        float x_next[2] = {x[0], x[1]};
        step(x_next, u, dt);

        float x_next_norm[2] = {x_next[0], x_next[1]};
        normalize(x_next_norm);

        compute_features(x_next_norm, phi_next);

        float V = value(phi);
        float V_next = value(phi_next);

        /// TD error
        float delta = r + gamma * V_next - V;

        /// Actualizacion critic
        for (int i = 0; i < N_FEATURES; i++) {
            w[i] += alpha_w * delta * phi[i];
        }

        /// Actualizacion actor
        for (int i = 0; i < N_FEATURES; i++) {
            theta[i] += alpha_theta * delta * phi[i];
        }

        /// avanzar estado
        x[0] = x_next[0];
        x[1] = x_next[1];

        fprintf(f, "%f,%f\n", x[0], x[1]);
    }

    fclose(f);
}