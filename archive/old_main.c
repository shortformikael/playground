#include <stdio.h>

void myfunction(void) {
  printf("Printed from a function\n");
  printf("Hello World\n");
  printf("%d\n%d\n", true, false);
}

void ex_for(void) {
  for (int i = 0; i < 5; i++) {
    printf("i: %d\n", i);
  }
}

int ex_add(int a, int b){
  return a + b;
}

void ex_vtypes(void) {
  int count = 20;
  float price = 9.99;
  char letter = 'A';
  printf("int: %d, float: %d, char: %d\n", count, price, letter);
  
  int result = ex_add(2,3);
  printf("Added result: %d\n", result);
}

void ex_pointers(void) {
  int x = 10;
  int *p = &x;

  printf("Variable: value %d at address %p\n", x, &x);
  printf("Pointer:  value %d at address %p\n", *p, p);
}

void ex_arrays(void) {
  int numbers[3] = {1, 2, 3};
}

int main(void) {
  myfunction();
  ex_for();
  ex_vtypes();
  ex_pointers();

  
  return 0;
}

