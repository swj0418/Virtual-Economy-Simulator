#include "res.h"
using namespace std;

void Demand_Default(float Participant_Info[][100])
{

	float AggregateAccount = 0;
	//0:EntityCode 1:Account 2:Debt 3:Consumption 4:ConsumingProduct
	for (int i = 0; i < 100; i++)
	{
		AggregateAccount += Participant_Info[1][i];
	}
	cout << AggregateAccount << " <<<<< Aggregate Account" << endl;
}