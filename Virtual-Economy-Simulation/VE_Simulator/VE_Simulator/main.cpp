#include "res.h"
#include <vector>
using namespace std;

void main()
{
	Market Kor;
	Kor.Market_Setup(100, 1, 0.0f, 0.0f); // Market Setup

	M_Participant Kor_P_1;
	Kor_P_1.Participant_Setup(100); // Market >> Participants Setup.

	Company A;
	A.Setup(10, 1, 5000, 0, 2000, 0, 2000); // Company Setup

	
	Worker A_W1, A_W2, A_W3, A_W4, A_W5;
	A_W1.Setup(1, A.Code, 500, 0, 100);
	A_W2.Setup(2, A.Code, 700, 100, 120);
	A_W3.Setup(3, A.Code, 1000, 0, 150);
	A_W4.Setup(4, A.Code, 200, 400, 80);
	A_W5.Setup(5, A.Code, 4000, 0, 300); // Setup loop required
	Worker A_W[5] = { A_W1, A_W2, A_W3, A_W4, A_W5 }; // Containing Workers in an array
	

	//Employee_Hire(Kor_P_1.Participant_Info);
	A.Status_Print(); // Initial Company A Status Output
	
	//Company Production Input Setup
	A.Setup_Prod(1, (A.Equity / 5), sizeof(A_W), 2.5F, 5); // one product , input captial 1 / 5 of their equity, input labor all, technology level 2.5, labor-capital indifferent product

	
	
	for (int i = 0; i < 100; i++)
	{
		Change(A, A_W);
		//A.Status_Print();
		A.Inventory_Print();
		Demand_Default(Kor_P_1.Participant_Info);
	}

	Kor_P_1.Participant_Info_Print(Kor.Pop);
}