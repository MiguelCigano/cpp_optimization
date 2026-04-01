#pragma once

/**
 * @brief Genera una muestra de ruido gaussiano (media 0, varianza 1)
 *
 * Se usa para exploración en RL (policy stochastic).
 *
 * @return float valor aleatorio gaussiano
 */
float randn();