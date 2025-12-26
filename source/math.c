#include <stdio.h>
#include "math.h"

int add(int a, int b){
  return a + b;
}

int multiply(int a, int b) {
  return a * b;
}

float divide(int a, int b) {
  if (b == 0) {
    return 0.00;
  } else {
    return (float) a / b;
  }
}

// Mean of an array
//
// Average of an array
//
// Max of an array
//
// Min of an array
