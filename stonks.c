#include "stonks.h"

struct instrument instrument;

struct state state;


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
		instrument->directionChange = 0;
		state->instruments[i] = instrument;
	}
	
	return state;
}

void setRiskLevel(struct state* state, int index, int level)
{
	state->instruments[index]->riskLevel = level;
}

void setVolatility(struct state* state, int index, int vol)
{
	state->instruments[index]->volatility = vol;
}

void setDirection(struct state* state, int index, int direction)
{
	state->instruments[index]->direction = direction;
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

void updateInstruments(struct state* state)
{
	int i;
	for(i = 0; i < NUM_INSTRUMENTS; i++)
	{
		float price = generateNewPrice(state->instruments[i]);
		updateInstrument(state, i, price);
	}
}

int maina()
{
	struct state* state = initState();
	updateInstrument(state, 3, 60);
	setRiskLevel(state, 3, DYNAMIC);
	setVolatility(state, 3, MEDIUM);
	setDirection(state, 3, UP);
	int i;
	for(i = 0; i < 100; i++)
	{
		float newPrice = generateNewPrice(state->instruments[3]);
		updateInstrument(state, 3, newPrice);
		printf("%f\n", newPrice);
	}
	return 0;
}