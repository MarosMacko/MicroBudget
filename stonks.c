#include "stonks.h"

struct instrument
{
	int len;
	float data[50000];
	int held;
};

struct state
{
	float balance;
	struct instrument* instruments[NUM_INSTRUMENTS];
};

int getPrice()
{
	static int x = 0;
	return (x++)%3;
}

struct state* initState()
{
	struct state* state = malloc(sizeof(struct state));
	state->balance = INIT_BALANCE;
	int i;
	for(i = 0; i < NUM_INSTRUMENTS; i++)
	{
		struct instrument* instrument = malloc(sizeof(struct instrument));
		instrument->len = 0;
		instrument->held = 0;
		state->instruments[i] = instrument;
	}
	
	return state;
}

struct state* updateInstrument(struct state* state, int index, float price)
{
	int currentLen = state->instruments[index]->len;
	state->instruments[index]->data[currentLen] = price;
	state->instruments[index]->len++;
	return state;
}

int main()
{
	struct state* state = initState();
	updateInstrument(state, 3, 52.56);
	printf("%f\n", state->instruments[3]->data[0]);
	return 0;
}