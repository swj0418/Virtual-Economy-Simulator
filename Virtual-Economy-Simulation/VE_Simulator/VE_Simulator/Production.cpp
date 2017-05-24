#include "res.h"
#include <math.h>
using namespace std;


void Company::Production_Default() // Using Cobb-Doubglas Production Function.
{
	//Y = A * K^a * L^(1-a)
	/*float A;//Productivity
	int L;//Labor
	float K;//Capital*/

	//Array properties 1: LaborTime 2: Capital 3:Technology 4:Product type 5:Output
	for (int i = 0; i < Prod_num; i++)
	{
		float a = 0;
		if (Prod[3][i] == 0)
		{
			a = 0;
		}
		else if (Prod[3][i] == 1)
		{
			a = 0.1;
		}
		else if (Prod[3][i] == 2)
		{
			a = 0.2;
		}
		else if (Prod[3][i] == 3)
		{
			a = 0.3;
		}
		else if (Prod[3][i] == 4)
		{
			a = 0.4;
		}
		else if (Prod[3][i] == 5)
		{
			a = 0.5;
		}
		else if (Prod[3][i] == 6)
		{
			a = 0.6;
		}
		else if (Prod[3][i] == 7)
		{
			a = 0.7;
		}
		else if (Prod[3][i] == 8)
		{
			a = 0.8;
		}
		else if (Prod[3][i] == 9)
		{
			a = 0.9;
		}
		else
		{
			a = 1;
		}

		Prod[4][i] += Prod[2][i] * pow(Prod[1][i], a) * pow(Prod[0][i], 1 - a);
	}
	





} // Declared in a "Company" Class