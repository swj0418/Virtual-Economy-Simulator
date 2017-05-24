#include "res.h"
#include <time.h>
#include <chrono>
#include <random>
using namespace std;

void Change(Company &Com, Worker W[])
{
	//Seeds for random generation
	srand(rand() * time(NULL));
	//Normal distribution seeds
	unsigned seedND = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seedND);
	normal_distribution<float> distribution(1.001f, 1.0f);

	//Company Change
	//Com.Payment = W1.Income + W2.Income + W3.Income + W4.Income + W5.Income;
	
	//Distributing K to Production of products
	for (int i = 0; i < Com.Prod_num; i++)
	{
		Com.Production_Default(); 
		//Com.Prod[i][0], Com.Prod[1][i], Com.Prod[2][i], Com.Prod[3][i], Com.Prod[4][i]

	} // Maybe I can't call fuction from this function.

	//Payment - Income relationship
	float Total_Payment = 0;
	for (int i = 0; i < sizeof(W); i++)
	{
		Total_Payment += W[i].Income;
	}
	Com.Payment = Total_Payment;
	/*for (int i = 0; i < sizeof(W); i++)
	{
		Com.Payment = W[i].Income;
	}*/

	//Company earning
	Com.Earning = (float)(distribution(generator) * (rand() % 2000 + 1));

	if ((Com.Equity / Com.Liability >= 4) && (Com.Liability - Com.Earning * 0.2) > 0 )
	{
		Com.Liability = Com.Liability - Com.Earning * 0.2;
		Com.Earning = Com.Earning - Com.Earning * 0.2;
	}
	else if (Com.Liability - Com.Earning * 0.2 < 0)
	{
		Com.Earning = Com.Earning - Com.Liability;
		Com.Liability = 0;
	}

	Com.Equity = Com.Equity + Com.Earning - Com.Payment - (Com.Liability * 0.05f); // Added earning is after deducting liability repayment.

	/*if ((Com.Equity / Com.Liability >= 4) && Com.Liability > 0 && (Com.Equity / 4) < (Com.Liability))
	{
		Com.Liability = Com.Liability - ((Com.Equity / 4));
		Com.Equity = Com.Equity - (Com.Equity / 4);
	}
	else if (Com.Equity / 4 > Com.Liability)
	{
		Com.Liability = 0;
		Com.Equity = Com.Equity - Com.Liability;
	}
	else if((Com.Equity - (Com.Liability * 4)) > Com.Liability)
	{
		Com.Liability = Com.Liability;
	}
	else
	{
		Com.Liability = Com.Liability;
	}*/
	

	Com.Asset = Com.Equity + Com.Liability;

	//Worker Change
	for (int i = 0; i < 5; i++)
	{
		WChange(W[i]);
	}
}
