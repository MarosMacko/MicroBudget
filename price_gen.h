#ifndef pricegen_incl
#define pricegen_incl

#include "stonks.h"

#define CONSERVATIVE 1
#define BALANCED 5
#define DYNAMIC 10

#define LOW 0
#define MEDIUM 1
#define HIGH 2

#define UP 1
#define DOWN -1

#include "stdint.h"
#include "pcg_basic.h"

struct instrument;
struct state;

float generateNewPrice(struct instrument*);
void generateNewDirection(struct instrument*);

#endif