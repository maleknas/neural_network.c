#include <stdio.h>
#include <stdlib.h>
#include "neural_network.h"
#include "initialisation_network.h"
#include "test_network.h"

int main() {
    int numlayer, *numneur;
    // Input the number of layers
    printf("Enter the number of layers: ");
    scanf("%d", &numlayer);

    // Input the number of neurons for each layer
    printf("Enter the number of neurons for each layer:\n");}
    numneur = (int *)malloc(numlayer * sizeof(int));
    for (int i = 0; i < numlayer; i++) {
        printf("Layer %d: ", i + 1);
        scanf("%d", &numneur[i]);
    }

    // Initialize the network
    layer *net = (layer *)malloc(numlayer * sizeof(layer));
    if(net==NULL){ 
        printf("error d'allocation pour la network !!!");
    init_network(net, numlayer, numneur);

    // Free dynamically allocated memory
    free(numneur);
    free(net);

    // Print the details of neurons in each layer
    for(int i = 0; i <2; i++) {
        printf("Details of neurons in Layer %d:\n", i + 1);
        print_layer(net[3]);
    }

    return 0;
}
