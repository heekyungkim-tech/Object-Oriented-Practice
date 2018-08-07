#include <iostream>

using namespace std;

int main()
{
	int payment = 1;

	int numMonths;
	cout << "# of Months: ";
	cin >> numMonths;

	for (int i = 1; i <= numMonths; i++)
	{
		cout << "Month " << i << ": " << payment << endl;
		if (i % 2 == 0)
		{
			payment = payment * 3;
		}
		else
		{
			payment = payment * 2;
		}
	}







	system("PAUSE");
	return 0;
}