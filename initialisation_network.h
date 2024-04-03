#ifndef INITIALISATION_NETWORK_H_INCLUDED
#define INITIALISATION_NETWORK_H_INCLUDED

#include "neural_network.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random float between 0 and 1 (inclusive)
float generate_random_float() {
    return (float)rand() / RAND_MAX;
}

// Function to initialize a neuron with random values
void init_neur(neuron *neu) {
    neu->a = generate_random_float();
    neu->b = generate_random_float();
    neu->w = generate_random_float();
}

// Function to initialize a layer with random neurons
void init_layer(layer l, int numneur) {
    l.n = numneur;
    l.t = (neuron*)malloc(numneur * sizeof(neuron));
    for (int i = 0; i < numneur; i++) {
        init_neur(&l.t[i]);
    }
}

// Function to initialize a network with random layers
void init_network(layer *net, int numlayer, int *numneur) {
    for (int i = 0; i < numlayer; i++) {
        init_layer(net[i], numneur[i]);
    }
}


#endif // INITIALISATION_NETWORK_H_INCLUDED
