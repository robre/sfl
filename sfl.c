
#include "sfl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void do_maybe(void (*f)(), probability p) {
    // e.g. scale = 100, value = 50. (50/50 chance)
    uint32_t chance = p.value % ( p.scale + 1 ); // chance can only be 0...scale (inclusive, so +1)
    uint32_t destiny = (rand() %  p.scale) + 1; // on a scale of 100, this can be 1..100
    if( destiny <= chance ){ // with a 100% chance, this will always trigger. with a 0% chance, never.
        f();
    } 
}

int64_t random_int_between(int64_t start, int64_t end) {
    if(start > end)
        return -1;
    int64_t diff = end - start;
    int64_t ret = (rand() % diff) + start;
    return ret;
}

char random_b(){
    uint8_t result = rand() & 0xff;
    return (char)result;
}

uint16_t random_w(){
    uint16_t result = rand() & 0xff;
    result |= (rand() & 0xff) << 8;
    return result;
}

uint32_t random_dw(){
    uint32_t result = rand() & 0xff;
    result |= (rand() & 0xff) << 8;
    result |= (rand() & 0xff) << 16;
    result |= (rand() & 0xff) << 24;

    return result;
}

uint64_t random_qw(){
    uint64_t result = (uint64_t)(rand() & 0xff);
    result |= (uint64_t)(rand() & 0xff) << 8;
    result |= (uint64_t)(rand() & 0xff) << 16;
    result |= (uint64_t)(rand() & 0xff) << 24;
    result |= (uint64_t)(rand() & 0xff) << 32;
    result |= (uint64_t)(rand() & 0xff) << 40;
    result |= (uint64_t)(rand() & 0xff) << 48;
    result |= (uint64_t)(rand() & 0xff) << 56;
    return result;
}

void mutate_b(uint8_t* b){
    switch(rand() % 10){
        case 0:
            *b += 1;
            break;
        case 1:
            *b -= 1;
            break;
        case 2:
            *b = (char)0xff;
            break;
        case 3:
            *b = (char)1;
            break;
        case 4:
            *b = (char)0;
            break;
        default:
            return;
    }
}

void mutate_w(uint16_t* w){
    switch(rand() % 10){
        case 0:
            *w += 1;
            break;
        case 1:
            *w -= 1;
            break;
        case 2:
            *w = (uint16_t)0xffff;
            break;
        case 3:
            *w = (uint16_t)1;
            break;
        case 4:
            *w = (uint16_t)0;
            break;
        default:
            return;
            }
}

void mutate_dw(uint32_t* dw){
    switch(rand() % 10){
        case 0:
            *dw += 1;
            break;
        case 1:
            *dw -= 1;
            break;
        case 2:
            *dw = (uint32_t)0xffffffff;
            break;
        case 3:
            *dw = (uint32_t)1;
            break;
        case 4:
            *dw = (uint32_t)0;
            break;
        default:
            return;
            }

}

void mutate_qw(uint64_t* qw){
    switch(rand() % 10){
        case 0:
            *qw += 1;
            break;
        case 1:
            *qw -= 1;
            break;
        case 2:
            *qw = (uint64_t)0xffffffffffffffff;
            break;
        case 3:
            *qw = (uint64_t)1;
            break;
        case 4:
            *qw = (uint64_t)0;
            break;
        default:
            return;
            }
}

void rand_init(){
    srand((unsigned) time(0));
}
