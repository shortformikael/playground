#include <stdio.h>
#include "printer.h"

void print_int(int a) {
  printf("Integer: %d\n", a);
}

void print_float(float a){
  printf("Float: %.2f\n", a);
}

void print_char(char a) {
  printf("Char: %c\n", a);
}

void print_string(char *a){
  printf("String: %s\n", a);
}

void print_int_pointer(int *a){
  printf("Pointer with value %d at address %p\n", *a, (void *)a);
}

void print_double(double a){
  printf("Double: %lf\n", a);
}
