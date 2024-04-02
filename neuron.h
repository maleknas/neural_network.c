#ifndef NEURAL_NETWORK_H_INCLUDED
#define NEURAL_NETWORK_H_INCLUDED

#include <stdio.h>
#include <math.h>

struct neuron {
    double b;  // Bias
    double a;  // Activation
    double w;  // Weight
};
typedef struct neuron neuron;

struct layer {
    int n;    // Number of neurons
    neuron *t;  // Array of neurons of size n
};
typedef struct layer layer;

// Sigmoid function
double sigmoid(double z) {
    return 1 / (1 + exp(-z));
}

// Loss function
// - outl : output layer
// - y    : wanted output
// - m    : number of samples
double loss(neuron *outl, int *y, int m) {
    double l = 0;
    for (int i = 0; i <= m; i++) {
        l -= y[i] * log(outl[i].a) + (1 - y[i]) * log(1 - outl[i].a);
    }
    return l / m; // Return the average loss
}

#endif // NEURAL_NETWORK_H_INCLUDED
typedef struct neuron neuron;

struct layer {
    int n;    // Number of neurons
    neuron *t;  // Array of neurons of size n
};
typedef struct layer layer;

// Sigmoid function
double sigmoid(double z) {
    return 1 / (1 + exp(-z));
}

// Loss function
// - outl : output layer
// - y    : wanted output
// - m    : number of samples
double loss(neuron *outl, int *y, int m) {
    double l = 0;
    for (int i = 0; i =< m; i++) {
        l -= y[i] * log(outl[i].a) + (1 - y[i]) * log(1 - outl[i].a);
    }
    return l / m; // Return the average loss
}

#endif // NEURAL_NETWORK_H_INCLUDED
