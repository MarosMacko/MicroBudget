#ifndef stonks_incl
#define stonks_incl

#include <stdlib.h>
#include <stdio.h>
#include "price_gen.h"
#define NUM_INSTRUMENTS 5
#define INIT_BALANCE 1000

extern struct instrument
{
    int len;
    float data[50000];
    float held;
    int direction;
    int directionChange;
    int riskLevel;
    int volatility;
} instrument;

extern struct state
{
    float balance;
    struct instrument* instruments[NUM_INSTRUMENTS];
} state;
extern struct state* initState();
void updateInstrument(struct state*, int, float);
void updateInstruments(struct state*);
void sellInstrument(struct state*, int, float);
void buyInstrument(struct state*, int, float);
float portfolioValue(struct state*);

#endif