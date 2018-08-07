#include <iostream>

using namespace std;

int main()
{
	// Purpose:
	//		determine credit worthiness of loan applicants
	// Input:
	//		income: Monthly Income
	//		debt: Total debt
	//		minPay: Monthly minimum payments for the debt
	// Output:
	//		credit: available loan amount when total debt is less than 6 months monthly income

	// INPUT
	double debt;
	cout << "Total debt: ";
	cin >> debt;

	double minPay;
	cout << "Monthly minimum payments: ";
	cin >> minPay;

	double income;
	cout << "Total income: ";
	cin >> income;

	// PROCESSING

	double credit;
	credit = (income - minPay)*0.3;

	if (debt >= income*6) 
	{

	//OUTPUT
		cout << " No loan can be granted " << endl;
	}
	else
	{
		cout << "You are approved for upto this loan amounts: " << credit << endl;
	}

	system("PAUSE");
	return 0;

}