#include <stdlib.h>
#include <stdio.h>
#include "exercises.h"
#include "printer.h"

#define ARRAY_1_SIZE 3

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
  printf("========P1_E2========\n");
  // Quick Memory encapsulation note:
  // vars x and p will be wiped form the memory
  // once the program exits the function/method.
  int x = 42;
  int *p = &x;

  printf("Pointer pointing at value: %d\n", *p);
  printf("Pointer value is at address: %p\n", (void *)p);

  *p = *p + 3; // should be 45
  printf("Pointer value changed: %d\n", *p);

  int *q = NULL;
  q = malloc(sizeof *q); // Removing this line creates a segfault.
  // Why? No clue, I need to look further into segmentation faults.
  // Why does malloc remove the segfault?
  // This creates a memory leak too.
  q = &x;
  printf("Printing new pointer at \"x\" with value: %d\n", *q); // prints 45.
  printf("New pointer \"q\" is pointing at address: %p\n", (void *)q);
  // I have changed the value that the pointer is pointing at.
  // In theory. Couldn't I create a program that affects the memory of another?
  // Could I in theory map out the memory used by other programs?
  // free(q);
  printf("---------------------\n");
}

void exercise_p1_e3() {
  printf("========P1_E3========\n");
  // inta a[3] ) {1,2,3}
  int a[ARRAY_1_SIZE] = {1, 2, 3};
  // You can Initialize after declaration too.
  // int size = 3;
  // int a[size];
  // a[0] = 1;
  // a[1] = 2;
  // a[2] = 3;
  int *p = a;

  for (int i = 0; i < ARRAY_1_SIZE; i++) {
    printf("Array<int> \"a\" at %d has value: %d\n", i, a[i]);
  }
  printf("Pointer value: %d\n", *p);

  // Resize array
  int new_size = ARRAY_1_SIZE + 1;
  int b[new_size];
  for (int i = 0; i < new_size; i++) {
    if (i < ARRAY_1_SIZE) {
      b[i] = a[i];
    }
    // PROMPT: Is there a "continue" or "break" to for loops in C?
  }

  printf("New Array \"b\" has size %d\n", new_size);
  for (int i = 0; i < new_size; i++) {
    printf("Array<int> \"b\" at %d has value: %d\n", i, b[i]);
    // b[3] is uninitialized and creates issues in valgrind
  }

  // Arrays decay into pointers
  // No bounds checking?
  // Compiler trusts me.
  // -> Why C vulnerabilites exist.
  printf("---------------------\n");
}

void pass_by_invalid(int x) {
  x++;
}

void pass_by_valid(int *x) {
  (*x)++;
}

void exercise_p2_e1() {
  printf("========P2_E1========\n");
  int x = 0;
  print_int(x);
  pass_by_invalid(x);
  pass_by_valid(&x);
  print_int(x);
  printf("---------------------\n");
}

void excercise_p3_e1() {
  // Undefined Behavior
  int x;
  x = 1; // Without this line, UB is picked up by gcc
  printf("%d\n", x); // UB

  // int a[2];
  // a[5] = 99; // UB

  // "This is where power lives"?
}

int exercise_p4_e1() {
  int *buf = malloc(100 * sizeof *buf);
  if (!buf) return -1;

  /* use buf */

  free(buf);
  buf = NULL;
  return 0;
  // Every malloc has one free
  // Never free twice
  // Never use after free
  // "This maps directly to real CVEs?"
}
