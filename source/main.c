#include <stdio.h>
#include "math.h"
#include "printer.h"

void ex_math(void) {  
  print_int(add(2, 3));
  print_int(multiply(2, 3));
  print_float(divide(2, 3));
}

int main(void) {
  ex_math();

  printf("------------------\n");

  return 0;
}
