#include <stdlib.h>
#include <stdio.h>
#include "exercises.h"
#include "printer.h"

void exercise_p1_e1() {
  // int x = 10;
  int *p = malloc(sizeof *p);
 
  *p = 10;

  free(p);
  // Not freeing the pointer sends no warning or error.
  // Why would gcc let you do this on purpose?
  // This concerns me.
  // Using valgrind on the compiled binary will point it out.
}

void exercise_p1_e2() {
  // Quick Memory encapsulation note:
  // vars x and y will be wiped form the memory
  // once the program exits the function/method.
  int x = 42;
  int *p = &x;

  printf("========P1_E2========");
  printf("Pointer pointing at value: %d\n", *p);
  printf("Pointer value is at address: %p\n", (void *)p);

  *p = *p + 3; // should be 45
  printf("Pointer value changed: %d\n", *p);

  printf("---------------------");
}
