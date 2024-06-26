#include "optimization_tools.h"
#include "activation_functions.h"
#include "derivative_activation_functions.h"

double gradient_descent(double input, double target_output, double learning_rate, int num_iterations) {
  // P.S : the learning rate is usually low so the predicted output is close to the target
    double weight = 0.5; // Initial weight
    double bias = 0.5;   // Initial bias
    double predicted_output, error;

    for (int i = 0; i < num_iterations; i++) {
        // Forward pass, it shows us the predicted output of the neural network
        predicted_output = ReLU(weight * input + bias); // in this example, we used the Sigmoid function, we could use ReLU

        // Backpropagation, it computes the gradients of the loss function with respect to the parameters, 
        //enabling the model to learn from the training data and improve its predictions over time
        error = predicted_output - target_output;

        // Gradient descent update
        weight -= learning_rate * error * derivative_ReLU(predicted_output) * input;
        bias -= learning_rate * error * derivative_ReLU(predicted_output);

        // Calculate binary cross-entropy loss for monitoring
        double loss_value = loss(predicted_output, target_output);
        printf("Iteration %d: Predicted Output = %.4f, Error = %.4f, Loss = %.4f\n", i+1, predicted_output, error, loss_value);
    }
    printf("FINAL Predicted Output = %.4f,FINAL Error = %.4f,FINAL Loss = %.4f\n", predicted_output, error, loss_value);
    return predicted_output;
}
