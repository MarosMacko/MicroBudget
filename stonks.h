#include <stdlib.h>
#include <stdio.h>
#define NUM_INSTRUMENTS 5
#define INIT_BALANCE 1000

struct instrument;
struct state;
struct state* initState();
void updateInstrument(struct state*, int, float);
void sellInstrument(struct state*, int, int);
void buyInstrument(struct state*, int, int);
float portfolioValue(struct state*);