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
		instrument->len = -1;
		instrument->held = 0;
		state->instruments[i] = instrument;
	}
	
	return state;
}

void updateInstrument(struct state* state, int index, float price)
{
	state->instruments[index]->len++;
	int currentLen = state->instruments[index]->len;
	state->instruments[index]->data[currentLen] = price;
}

void buyInstrument(struct state* state, int index, int amount)
{
	int currentLen = state->instruments[index]->len;
	float price = state->instruments[index]->data[currentLen] * amount;
	if(price > state->balance) return; //not enough money
	state->instruments[index]->held += amount;
	state->balance -= price;
}

void sellInstrument(struct state* state, int index, int amount)
{
	int held = state->instruments[index]->held;
	if(amount > held) return; //cant sell that much
	int currentLen = state->instruments[index]->len;
	float price = state->instruments[index]->data[currentLen] * amount;
	state->instruments[index]->held -= amount;
	state->balance += price;
	return;
}

float portfolioValue(struct state* state)
{
	float total = state->balance;
	int i;
	for(i = 0; i < NUM_INSTRUMENTS; i++)
	{
		int amount = state->instruments[i]->held;
		int index = state->instruments[i]->len;
		if(index == -1) continue;
		float price = state->instruments[i]->data[index];
		total += price * amount;
	}
	
	return total;
}

int maina()
{
	struct state* state = initState();
	updateInstrument(state, 3, 52.56);
	printf("%f\n", state->instruments[3]->data[0]);
	buyInstrument(state, 3, 4);
	sellInstrument(state, 3, 2);
	updateInstrument(state, 3, 62.56);
	printf("%f\n", state->instruments[3]->data[0]);
	printf("%d\n", state->instruments[3]->held);
	printf("%f\n", state->balance);
	printf("%f\n", portfolioValue(state));
	return 0;
}