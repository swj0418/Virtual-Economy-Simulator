#include "res.h"
using namespace std;

class Worker
{
public:
	int EntityCode;
	int Employer;
	float Account;
	float Debt;
	float Income;

	void Setup(int EntityCode, int Employer, float Account, float Debt, float Income);
	void Output();
};

void Worker::Setup(int EntityCode, int Employer, float Account, float Debt, float Income)
{
	this->Income = Income;
	this->Employer = Employer;
	this->EntityCode = EntityCode;
	this->Debt = Debt;
	this->Account = Account;
}
void Worker::Output()
{
	cout << "====================================== Worker " << EntityCode << "=============================================" << endl;
	cout << "Code" << "\t" << "Empl" << "\t" << "Account" << "\t" << "Debt" << "\t" << "Income" << endl;
	cout << EntityCode << "\t" << Employer << "\t" << Account << "\t" << Debt << "\t" << Income << endl;
}
