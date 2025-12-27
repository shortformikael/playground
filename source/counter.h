#ifndef COUNTER_H
#define COUNTER_H

typedef struct Counter Counter;

Counter* counter_create(int start);
int counter_get(const Counter *c);
void counter_set(Counter *c, int n);
void counter_increment(Counter *c);
void counter_kill(Counter *c);

#endif
