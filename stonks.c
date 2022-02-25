#include <stonks.h>

struct instrument
{
	int len;
	int data[50000];
};

struct state
{
	int balance;
	struct instrument data[5];
};

int getPrice()
{
	return 0;
}