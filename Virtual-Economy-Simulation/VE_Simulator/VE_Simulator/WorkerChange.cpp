#include "res.h"
using namespace std;

void WChange(Worker &W)
{
	W.Account = W.Account + W.Income - (W.Debt * 0.11f);

	if ((W.Account / W.Debt) >= 3 && (W.Debt - (W.Account / 3)) > 0) // In case a personal account exceeds three times of a debt
	{
		W.Debt = W.Debt - (W.Account / 3); // Debt settlement
		W.Account = W.Account - (W.Account / 3); // Debt settlement deduction from the account
	}
	else if ((W.Debt - (W.Account / 3)) < 0)
	{
		W.Debt = 0;
		W.Account = W.Account - W.Debt;
	}
	else
	{
		W.Debt = W.Debt;
	}
}