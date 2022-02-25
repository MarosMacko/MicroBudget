#include "price_gen.h"

float generateNewPrice(struct instrument* instrument)
{
	int index = instrument->len;
	float currentPrice = instrument->data[index];
	generateNewDirection(instrument);
	
	float maxDelta = 0.01 * instrument->riskLevel;
	float deltaPercent = pcg32_random() / UINT32_MAX * maxDelta * instrument->direction;
	instrument->lastChange = deltaPercent;
	return currentPrice + deltaPercent * currentPrice;
}

void generateNewDirection(struct instrument* instrument)
{
	int degree, interval;
	if(instrument->volatility == LOW)
	{
		if(instrument->directionChange < 5) return;
		interval = instrument->directionChange - 4;
		degree = 5;
	}
	
	else if(instrument->volatility == MEDIUM)
	{
		if(instrument->directionChange < 3) return;
		interval = instrument->directionChange - 2;
		degree = 4;
	}
	
	else //HIGH
	{
		degree = 3;
	}
	
	int denominator = degree - instrument->directionChange + 1;
	if(pcg32_random()%denominator == 0) //change direction
	{
		instrument->directionChange = 1;
		instrument->direction = 1 - instrument->direction;
	}
	
	else
	{
		instrument->directionChange++;
	}
}