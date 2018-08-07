#include <iostream>

using namespace std;

int main()
{
	cout << "***************************************************************************" << endl;
	cout << "				Congratulations!! " << endl;
	cout << "If you are using this program, that means you won the You-Are-Awesome award!" << endl;
	cout << "***************************************************************************" << endl;

	cout << "I am sure you are dying to know how much you won, let's compute!" << endl;


	int month;
	cout << "For how many months did they say you will recieve payments? ";
	cin >> month;

	cout << "Here are the monthly installment amounts: " << endl;

	double payment = 1;

	for (int i = 0; i < month; i++)
	{
		cout << "Month " << i + 1 << ":		$" << payment << endl;

		if (i % 2 == 0)
			payment *= 2;
		else
			payment *= 3;
	}

	system("PAUSE");
	return 0;
}
