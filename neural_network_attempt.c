#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 5
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1
#define BIAS 0

typedef struct Neuron
{
    double output;
    double *weights_tab;
} Neuron;

typedef struct Layer
{
    int num_neurons;
    Neuron *neurons_tab;
} Layer;

typedef struct NeuralNetwork
{
    int num_layers;
    Layer *layers_tab;
} Network;

// Initialize a neuron with random weights
void initialize_neuron(Neuron *neuron, int num_inputs)
{
    neuron->weights_tab = (double *)malloc(num_inputs * sizeof(double));
    for (int i = 0; i < num_inputs; i++)
    {
        neuron->weights_tab[i] = ((double)rand() / RAND_MAX) * 2; // Random weights between 0 and 1
    }
}

// Initialize a layer with random neurons
void initialize_layer(Layer *layer, int num_neurons, int num_inputs)
{
    layer->neurons_tab = (Neuron *)malloc(num_neurons * sizeof(Neuron));
    for (int i = 0; i < num_neurons; i++)
    {
        initialize_neuron(&(layer->neurons_tab[i]), num_inputs);
    }
}

// Initialize the neural network
void initialize_network(Network *neural_network, int num_layers)
{
    neural_network->layers_tab = (Network *)malloc(num_layers * sizeof(Network));
    Layer input_layer = neural_network->layers_tab[0];

    initialize_layer(&input_layer, INPUT_SIZE, INPUT_SIZE);

    int num_inputs_per_layer = INPUT_SIZE;
    for (int i = 1; i < num_layers - 1; i++)
    {
        initialize_layer(&(neural_network->layers_tab[i]), HIDDEN_SIZE, num_inputs_per_layer);
        num_inputs_per_layer = HIDDEN_SIZE;
    }
    Layer output_layer = (neural_network->layers_tab[num_layers - 1]);
    initialize_layer(&output_layer, OUTPUT_SIZE, HIDDEN_SIZE);
}

// the sigmoid activation function
double sigmoid(double value)
{
    return 1 / (1 + exp(-value));
}

// Forward pass through the neural network
void forward_pass(Network *neural_network, double *input)
{
    // get the outputs of each neuron within the input layer
    Layer input_layer = neural_network->layers_tab[0];
    for (int i = 0; i < input_layer.num_neurons; i++)
    {
        input_layer.neurons_tab[i].output = input[i];
    }

    // Calculate the outputs of each of the neurons within all hidden layers
    // for each hidden layer
    for (int k = 1; k < neural_network->num_layers - 1; k++)
    {
        // for each neuron in the hidden layer
        for (int i = 0; i < neural_network->layers_tab[k].num_neurons; i++)
        {
            double sum = 0;
            int num_inputs = input_layer.num_neurons; // num_outputs of the previous layer
            // for each neuron in the previous layer
            for (int j = 0; j < num_inputs; j++)
            {
                sum += neural_network->layers_tab[i - 1].neurons_tab[j].output * neural_network->layers_tab[i - 1].neurons_tab[j].weights_tab[j];
                num_inputs = neural_network->layers_tab[i - 1].num_neurons;
            }
            sum += BIAS;
            neural_network->layers_tab[k].neurons_tab[i].output = sigmoid(sum);
        }
    }

    // Calculate the outputs of each neuron in the output_layer
    // for each neuron
    Layer output_layer = (neural_network->layers_tab[neural_network->num_layers - 1]);
    for (int i = 0; i < output_layer.num_neurons; i++)
    {
        double sum = 0;
        // for each neuron in the previous layer
        for (int j = 0; j < neural_network->layers_tab[neural_network->num_layers - 2].num_neurons; j++)
        {
            sum += neural_network->layers_tab[i - 1].neurons_tab[j].output * neural_network->layers_tab[i - 1].neurons_tab[j].weights_tab[j];
        }
        sum += BIAS;
        output_layer.neurons_tab[i].output = sigmoid(sum);
    }
}

int main()
{
    srand(0); // Seed random number generator for reproducibility

    Network network;
    int layers_num = 3;
    initialize_network(&network, layers_num);

    // Define input
    double input[INPUT_SIZE] = {0.14, 0.75, 0.25, 0.78, 0.55};

    // Perform forward pass
    forward_pass(&network, input);

    // Print output
    for (int i = 0; i < network.layers_tab[network.num_layers - 1].num_neurons; i++)
    {
        printf("Output: %lf\n", network.layers_tab[network.num_layers - 1].neurons_tab[i].output);
    }

    // Clean up
    free(network.layers_tab);

    return 0;
}
