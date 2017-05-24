#include "res.h"
#include <random>
#include <time.h>
#include <chrono>


using namespace std;

class Market
{
public:
	int Pop; //Population
	int FirmN; //Firm Numbers
	float TAsset; // Total Assets
	float TLia; //Total Liabilities issued by the central bank -- will add central bank

	//For Determining certain product's demand (Assuming Perfect Competition thus price will be determined in the demand side)
	float Demand[5][10]; // Demand for product [second], properties[first].
	// 0 : Pop demanding this commodity 1: 

	//Participants contained in the market

	void Market_Setup(int Pop, int FirmN, float TAsset, float TLia);

};
void Market::Market_Setup(int Pop, int FirmN, float TAsset, float TLia)
{
	this->Pop = Pop;
	this->FirmN = FirmN;
	this->TAsset = TAsset;
	this->TLia = TLia;

}

class M_Participant
{
public:
	float Participant_Info[7][100];
	//0:EntityCode 1:Account 2:Debt 3:Consumption 4:ConsumingProduct 5: Income 6:Job Status

	//General Info
	int EntityCode;
	float Account;
	float Debt;
	float Income;
	int Job_Status;

	//Consumption Behavior
	float Consumption;
	int ConsumingProduct;
	int ConsumptionCategory; // Why did I put this here? don't remember

	//Setup
	void Participant_Setup(int Pop);
	void Participant_Info_Print(int Pop);
};
void M_Participant::Participant_Setup(int Pop)
{ 
	unsigned seedforMarket = chrono::system_clock::now().time_since_epoch().count();
	srand((rand() * time(NULL)));
	default_random_engine generatorforMarket(seedforMarket);
	normal_distribution<float> distributionforMarket(1.0f, 1.0f);
	chi_squared_distribution<float> Chi_distributionforMarket(1.0f);	

	


	for (int i = 0; i < Pop; i++)
	{
		//this->EntityCode = i;
		this->Participant_Info[0][i] = i;
		this->Participant_Info[1][i] = (float)((Chi_distributionforMarket(generatorforMarket)) * (rand() % 2000 + 1));
		this->Participant_Info[2][i] = (float)(rand() % 2000 + 1);
		this->Participant_Info[3][i] = 0;
		this->Participant_Info[4][i] = 1;
	}

	//Temporary Average Asset
	float Avg_Asset = 0;
	float Tot_Asset = 0;
	for (int i = 0; i < Pop; i++)
	{
		Tot_Asset += Participant_Info[1][i];
	}
	Avg_Asset = Tot_Asset / Pop;
	//Generating Income level based on their initial asset
	for (int i = 0; i < Pop; i++)
	{
		if (Participant_Info[1][i] >= Avg_Asset)
		{
			this->Participant_Info[5][i] = (float)((Chi_distributionforMarket(generatorforMarket)) * (rand() % 500 + 1));
		}
		else if (Participant_Info[1][i] < Avg_Asset)
		{
			this->Participant_Info[5][i] = (float)((Chi_distributionforMarket(generatorforMarket)) * (rand() % 500 + 1));
		}
	}
	cout << Avg_Asset << endl;
	
}

void M_Participant::Participant_Info_Print(int Pop)
{
	for (int i = 0; i < Pop; i++)
	{
		cout << "------ Participant Code [" << Participant_Info[0][i] << "] Information ------" << endl;
		cout << "Asset : " << Participant_Info[1][i] << endl;
		cout << "Debt : " << Participant_Info[2][i] << endl;
		cout << "Consumption : " << Participant_Info[3][i] << endl;
		cout << "Income : " << Participant_Info[5][i] << endl;
		cout << "Job Status(Hired by) : " << Participant_Info[6][i] << endl;
	}
}

class CentralBank
{
	float C_Asset;//Central Bank Asset
	float C_Lia;//Central Bank Liabilities
};