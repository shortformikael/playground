#include <stdio.h>

void myfunction(void) {
  printf("Printed from a function\n");
}

int main(void) {
  printf("Hello World\n");
  printf("%d\n%d\n", true, false);
  myfunction();
}

