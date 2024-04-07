#include <math.h>

//DERIVATIVE OF SIGMOID
double derivative_sigmoid(double input)
{
    return (input * (1-input));  // sigmoid(x)*(1-sigmoid(x))
}

//DERIVATIVE OF ReLU
double derivative_ReLU(double input)
{
    if (input > 0)
        return 1;
    else
        return 0;
}
