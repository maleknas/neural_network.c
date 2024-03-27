#ifndef INITIALISATION_NETWORK_H_INCLUDED
#define INITIALISATION_NETWORK_H_INCLUDED

#include "neural_network.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generate_random(int min, int max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

// Function to initialize a neuron with random values
void init_neur(neur *neu) {
    neu->a = generate_random(0, 1);
    neu->b = 0;
    neu->w = generate_random(0, 1);
}

// Function to initialize a layer with random neurons
void init_layer(layer *l, int numneur) {
    l->n = numneur;
    l->t = (neur*)malloc(numneur * sizeof(neur));
    for (int i = 0; i < numneur; i++) {
        init_neur(&l->t[i]);
    }
}

// Function to initialize a network with random layers
void init_network(network *net, int numlayer, int *numneur) {
    net->num_layers = numlayer;
    net->layers = (layer*)malloc(numlayer * sizeof(layer));
    for (int i = 0; i < numlayer; i++) {
        init_layer(&net->layers[i], numneur[i]);
    }
}

#endif // INITIALISATION_NETWORK_H_INCLUDED
