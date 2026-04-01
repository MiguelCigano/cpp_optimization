#include "dynamics.hpp"

/** Parámetros físicos */
float m = 1.1f;
float b = 0.5f;
float k = 0.72f;

/**
 * @brief Integración Euler del sistema dinámico
 */
void step(float* x, float u, float dt) {

    float x1 = x[0];
    float x2 = x[1];

    float x1_dot = x2;
    float x2_dot = (u - b*x2 - k*x1) / m;

    x[0] += dt * x1_dot;
    x[1] += dt * x2_dot;
}