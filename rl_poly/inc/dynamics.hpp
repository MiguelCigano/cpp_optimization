#pragma once

/**
 * @brief Parámetros del sistema masa-resorte-amortiguador
 */
extern float m; ///< masa
extern float b; ///< coeficiente de amortiguamiento
extern float k; ///< constante del resorte

/**
 * @brief Avanza el sistema dinámico un paso en el tiempo
 *
 * Modelo:
 *   x1_dot = x2
 *   x2_dot = (u - b*x2 - k*x1)/m
 *
 * @param x estado actual [x1, x2]
 * @param u entrada de control
 * @param dt paso de integración
 */
void step(float* x, float u, float dt);