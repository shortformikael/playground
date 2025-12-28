#include <stdlib.h>
#include "counter.h"

struct Counter {
  int value;
};

Counter *counter_create(int start) {
  Counter *c = malloc(sizeof(Counter));
  c->value = start;
  return c;
}

int counter_get(const Counter *c) {
  return c->value;
}

void counter_set(Counter *c, int n) {
  c->value = n;
}

void counter_increment(Counter *c) {
  c->value = c->value + 1;
}

void counter_kill(Counter *c) {
  free(c);
}
