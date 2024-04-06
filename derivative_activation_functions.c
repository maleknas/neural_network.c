#include <math.h>

//DERIVATIVE OF SIGMOID
double derivative_sigmoid(double input)
{
    return (1 / (1 + exp(-input))*(1-(1 / (1 + exp(-input)))));  //
}

//DERIVATIVE OF ReLU
double derivative_ReLU(double input)
{
    if (input > 0)
        return 1;
    else
        return 0;
}
