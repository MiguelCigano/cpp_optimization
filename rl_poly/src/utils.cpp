#include "utils.hpp"
#include <stdlib.h>
#include <math.h>

/**
 * @brief Implementación Box-Muller para generar ruido gaussiano
 *
 * Convierte dos variables uniformes en una normal estándar.
 */
float randn() {
    float u1 = (rand() + 1.0f) / (RAND_MAX + 1.0f);
    float u2 = (rand() + 1.0f) / (RAND_MAX + 1.0f);
    return sqrtf(-2.0f * logf(u1)) * cosf(2.0f * M_PI * u2);
}