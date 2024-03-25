#ifndef NEURAL_NETWORK_H_INCLUDED
#define NEURAL_NETWORK_H_INCLUDED
#include<stdio.h>
#include<math.h>
struct neurone {          //neurone
int b;                    //bias
int a;                    //activation
int w;                    //weight
}; typedef struct neurone neur ;
struct layer {
int n;                    //nombre de neutrone
neur *t;                  //tableau de neuronne de taille n
}; typedef struct layer l;
layer *network;
//segmoid function
int segm(int z){
int res;
res=1/(1+exp(-z));
return res;
}
#endif // NEURAL_NETWORK_H_INCLUDED
