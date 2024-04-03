#ifndef TEST_NETWORK_H_INCLUDED
#define TEST_NETWORK_H_INCLUDED
void print_layer(layer l) {
    printf("Number of neurons in this layer: %d\n", l.n);
    printf("Neuron details:\n");
    for (int i = 0; i < l.n; i++) {
        printf("Neuron %d:\n", i + 1);
        printf("  Bias (b): %f\n", l.t[i].b);
        printf("  Activation (a): %f\n", l.t[i].a);
        printf("  Weight (w): %f\n", l.t[i].w);
    }
}



#endif // TEST_NETWORK_H_INCLUDED
