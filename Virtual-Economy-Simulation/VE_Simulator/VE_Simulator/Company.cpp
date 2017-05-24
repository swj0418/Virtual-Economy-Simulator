#include "res.h"
using namespace std;

class Company
{
public:
	//General Info
	int LaborCapacity;
	int Code;
	float Equity;
	float Asset;
	float Liability;
	float Payment;
	float Earning;

	/*float LaborTime; // Labor Time (Assume full employment, at LaborCapacity, general labor time per worker = 8hours)
	float A; // Techonology */


	//Initial Setups
	void Setup(int LaborCapacity, int Code, float Equity, float Asset, float Liability, float Payment, float Earning);
	void Status_Print()
	{
		cout << "========================================== CompanyStatus ==============================================" << endl;
		cout << "Cap" << "\t" << "Code" << "\t" << "Equity" << "\t" << "Asset" << "\t" << "Liab" << "\t" << "Payment" << "\t" << "Earning" << endl;
		cout << LaborCapacity << "\t" << Code << "\t" << Equity << "\t" << Asset << "\t" << Liability << "\t" << Payment << "\t" << Earning << endl;
	}
	void Inventory_Print();
	Company();

	//Production Info
	float Prod_num;
	int Prod_Ty; // 0 << labor intensive
				//       capital intensive >>10

	float Prod[5][10]; // 1: LaborTime 2: Capital 3:Technology 4:Product type 5. Output (Temporary inventory)
	

	//Production Functions
	void Production_Default();
	void Setup_Prod(int Prod_num, float K, float L, float A, int P_Ty);
};
Company::Company()
{

}

void Company::Setup(int LaborCapacity, int Code, float Equity, float Asset, float Liability, float Payment, float Earning)
{
	this->LaborCapacity = LaborCapacity;
	this->Code = Code;
	this->Equity = Equity + Earning;
	this->Liability = Liability;
	this->Payment = Payment;
	this->Earning = Earning;
	this->Asset = Equity + Liability;
}
void Company::Setup_Prod(int Prod_num, float K, float L, float A, int P_Ty)
{
	this->Prod_num = Prod_num;
	for (int i = 0; i < Prod_num; i++)
	{
		this->Prod[0][i] = L * 8; // Labor * 8 hours
		this->Prod[1][i] = K;
		this->Prod[2][i] = A;
		this->Prod[3][i] = P_Ty;
		this->Prod[4][i] = 0;
	} // Setup and goto Functions::Production for output
}

void Company::Inventory_Print()
{
	cout << ">>>>>>>>   Inventory for the Round   <<<<<<<<" << endl;
	for (int i = 0; i < Prod_num; i++)
	{
		cout << "Product [" << i << "] :::: " << Prod[4][i] << endl;
	}
}


