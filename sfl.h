#ifndef SFL_H
#define SFL_H 

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint32_t scale; // e.g. 100
    uint32_t value; // less than scale: we simply do %
} probability ;

void do_maybe(void (*f)(), probability p);

int64_t random_int_between(int64_t start, int64_t end);

char random_b();
uint16_t random_w();
uint32_t random_dw();
uint64_t random_qw();

void mutate_b(uint8_t* b);
void mutate_w(uint16_t* w);
void mutate_dw(uint32_t* dw);
void mutate_qw(uint64_t* qw);

//void random_choice(void * array, size_t size);
//void random_call(void * array);
void rand_init();

#endif /* SFL_H */
