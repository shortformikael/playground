#include <stdio.h>
#include "math.h"
#include "printer.h"
#include "counter.h"
#include "exercises.h"

Counter *count;

void ex_math(void) {  
  print_int(add(2, 3));
  print_int(multiply(2, 3));
  print_float(divide(2, 3));

  int x = 10;
  print_int_pointer(&x);
  printf("Here\n");
}

void ex_count(void) {
  count = counter_create(2);
  print_int(counter_get(count));

  counter_increment(count);
  print_int(counter_get(count));

  counter_set(count, 10);
  print_int(counter_get(count));
}

void ex_excercises(void){
  exercise_p1_e1();
  exercise_p1_e2();
}

void end_program(void) {
  counter_kill(count); 
}

int main(void) {
  ex_math();
  printf("------------------\n");

  ex_excercises();

  end_program();
  return 0;
}
