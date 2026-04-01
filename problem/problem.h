#include "../linalg/linalg.h"
#include "../linalg/matrix.h"
#include <math.h>

using namespace std;

double cost_fn(Matrix x);
Matrix cost_fn_gradient(Matrix x, double deltaX);