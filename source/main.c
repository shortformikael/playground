#include <stdio.h>
#include "math.h"

void print_result(int r){
  printf("Result: %d\n", r);
}

void print_result_float(float f) {
  printf("Result: %f\n", f);
}

void ex_math(void) {
  print_result(add(2, 3));
  print_result(multiply(2, 3));
  print_result_float(divide(2, 3));
}

int main(void) {
  printf("New init \n");
  ex_math();

  return 0;
}
