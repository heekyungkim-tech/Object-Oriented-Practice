#include <iostream>

using namespace std;

int main()
{
	double total = 0;
	int count = 0;

	char another;

	do
	{
		cout << endl;
		cout << "Need Office Space?" << endl;
		cout << "==================" << endl;

		cout << "1- Private Office" << endl;
		cout << "2- Colocation" << endl;
		cout << "3- Temporary Workspace" << endl;
		cout << "What type of space? ";
		int otype;
		cin >> otype;
		
		double price;
		if (otype == 1) 
		{
			price = 1000;
		}
		else if (otype == 2)
		{
			price = 500;
		}
		else if (otype == 3)
		{
			int days;
			cout << "# of days do you need? ";
			cin >> days;

			price = days * 60;
		}

		char phone;
		cout << "Phone service? (y/n) ";
		cin >> phone;
		if (phone == 'y') 
		{
			int minutes;
			cout << "How many minute do you need? ";
			cin >> minutes;
			price += minutes * 0.5;
		}

		cout << "Your monthly charge is $" << price << endl;
		count++;
		total += price;

		cout << "Another quote (y/n)? ";
		cin >> another;
	} while (another == 'y');


	cout << "Average quotation provided was $" << total / count << endl;

	system("PAUSE");
	return 0;
}