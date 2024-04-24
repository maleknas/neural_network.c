void train_neural_network(const char *filename) {
    // Load the dataset
    float dataset[MAX_ROWS][MAX_COLS];
    int num_rows;
    read_csv(filename, dataset, &num_rows);

    // Define initial weights and biases
    float weight = 0.5; // Initial weight
    float bias = 0.5;   // Initial bias

    // Perform gradient descent iterations
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        // Iterate over each row in the dataset
        for (int i = 0; i < num_rows; i++) {
            // Extract input and target from the dataset
            float input[INPUT_SIZE];
            float target;
            input[0] = dataset[i][0];  // Feature1
            input[1] = dataset[i][1];  // Feature2
            target = dataset[i][2];    // Label

            // Perform gradient descent update using the predefined function
            weight -= gradient_descent(input[0], target, LEARNING_RATE, 1);
            bias -= gradient_descent(1.0, target, LEARNING_RATE, 1);
        }

        // Print loss every 10 epochs
        if (epoch % 10 == 0) {
            // Compute average loss
            float total_loss = 0;
            for (int i = 0; i < num_rows; i++) {
                float input[INPUT_SIZE];
                float target;
                input[0] = dataset[i][0];  // Feature1
                input[1] = dataset[i][1];  // Feature2
                target = dataset[i][2];    // Label
                float predicted_output = sigmoid(weight * input[0] + bias);
                total_loss += 0.5 * pow(predicted_output - target, 2);
            }
            float avg_loss = total_loss / num_rows;
            printf("Epoch %d: Average Loss = %.4f\n", epoch, avg_loss);
        }
    }

    printf("Training complete.\n");
}
