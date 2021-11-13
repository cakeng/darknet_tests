#ifndef EXTERN_LIBS
#define EXTERN_LIBS
#ifdef __cplusplus
extern "C"
{
#endif
#include "layer.h"
#include "network.h"

typedef layer convolutional_layer;

float *NCHWtoNHWC(float *input, int blocks, int channels, int height, int width);
float *NCHWtoNHWC_DIRECT(float *input, int blocks, int channels, int height, int width);
void deVectorize (layer l, int toNHWC);

void skip_convolutional_layer(convolutional_layer l, network net);
void gemmplus_convolutional_layer(convolutional_layer l, network net);
void armnn_convolutional_layer(convolutional_layer l, network net);
void xnnpack_convolutional_layer(convolutional_layer l, network net);
void make_xnnpack_layer(convolutional_layer* l);
void* xnnpack_pthreadpool_create();
void direct_convolutional_layer(convolutional_layer l, network net);
void openblas_convolutional_layer(convolutional_layer l, network net);

void make_armnn_layer(convolutional_layer* l);
void* armnn_make_runtime();


#ifdef __cplusplus
}
#endif


#endif
