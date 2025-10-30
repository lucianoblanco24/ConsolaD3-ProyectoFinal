#include <samples.h>
#include <stdint.h>
#define NUM_ELEMENTS 37870

const uint8_t sampleS1[NUM_ELEMENTS] = {
    #include "../ArregloS1.C"
};
const uint32_t SAMPLE_S1_LEN = NUM_ELEMENTS;
