#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the activation function (here, using sigmoid)
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Define the neuron structure
typedef struct {
    double *weights;
    double value;
} Neuron;

// Define the layer structure
typedef struct {
    Neuron *neurons;
    int num_neurons;
} Layer;

// Define the neural network structure
typedef struct {
    Layer *layers;
    int num_layers;
} NeuralNetwork;

// Initialize a neural network with given structure
NeuralNetwork* initialize_neural_network(int num_input_neurons, int num_hidden_layers, int num_hidden_neurons, int num_output_neurons) {
    NeuralNetwork* network = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    network->num_layers = num_hidden_layers + 2; // Include input and output layers

    network->layers = (Layer*)malloc(network->num_layers * sizeof(Layer));

    // Initialize input layer
    network->layers[0].num_neurons = num_input_neurons;
    network->layers[0].neurons = (Neuron*)malloc(num_input_neurons * sizeof(Neuron));
    for (int i = 0; i < num_input_neurons; i++) {
        network->layers[0].neurons[i].value = 0.0;
    }

    // Initialize hidden layers
    for (int i = 1; i <= num_hidden_layers; i++) {
        network->layers[i].num_neurons = num_hidden_neurons;
        network->layers[i].neurons = (Neuron*)malloc(num_hidden_neurons * sizeof(Neuron));
        for (int j = 0; j < num_hidden_neurons; j++) {
            network->layers[i].neurons[j].value = 0.0;
        }
    }

    // Initialize output layer
    network->layers[network->num_layers - 1].num_neurons = num_output_neurons;
    network->layers[network->num_layers - 1].neurons = (Neuron*)malloc(num_output_neurons * sizeof(Neuron));
    for (int i = 0; i < num_output_neurons; i++) {
        network->layers[network->num_layers - 1].neurons[i].value = 0.0;
    }

    return network;
}

// Forward pass function
void forward_pass(NeuralNetwork *network) {
    // Perform forward pass through hidden layers
    for (int i = 1; i < network->num_layers - 1; i++) {
        Layer current_layer = network->layers[i];
        Layer prev_layer = network->layers[i - 1];
        for (int j = 0; j < current_layer.num_neurons; j++) {
            double sum = 0.0;
            for (int k = 0; k < prev_layer.num_neurons; k++) {
                sum += prev_layer.neurons[k].value * current_layer.neurons[j].weights[k];
            }
            current_layer.neurons[j].value = sigmoid(sum);
        }
    }

    // Perform forward pass through output layer
    Layer output_layer = network->layers[network->num_layers - 1];
    Layer prev_layer = network->layers[network->num_layers - 2];
    for (int i = 0; i < output_layer.num_neurons; i++) {
        double sum = 0.0;
        for (int j = 0; j < prev_layer.num_neurons; j++) {
            sum += prev_layer.neurons[j].value * output_layer.neurons[i].weights[j];
        }
        output_layer.neurons[i].value = sigmoid(sum);
    }
}

// Free memory allocated for the neural network
void free_neural_network(NeuralNetwork *network) {
    for (int i = 0; i < network->num_layers; i++) {
        free(network->layers[i].neurons);
    }
    free(network->layers);
    free(network);
}

int main() {
    // Define the neural network structure
    int num_input_neurons = 2;
    int num_hidden_layers = 1;
    int num_hidden_neurons = 3;
    int num_output_neurons = 1;

    // Initialize the neural network
    NeuralNetwork* network = initialize_neural_network(num_input_neurons, num_hidden_layers, num_hidden_neurons, num_output_neurons);

    // Static weights (manually initialized)
    network->layers[1].neurons[0].weights = (double[]){0.1, 0.2};
    network->layers[1].neurons[1].weights = (double[]){0.3, 0.4};
    network->layers[1].neurons[2].weights = (double[]){0.5, 0.6};

    network->layers[2].neurons[0].weights = (double[]){0.7, 0.8, 0.9};

    // Input values
    network->layers[0].neurons[0].value = 0.1;
    network->layers[0].neurons[1].value = 0.2;

    // Perform forward pass
    forward_pass(network);

    // Print the output
    printf("Output: %lf\n", network->layers[network->num_layers - 1].neurons[0].value);

    // Free memory
    free_neural_network(network);

    return 0;
}
