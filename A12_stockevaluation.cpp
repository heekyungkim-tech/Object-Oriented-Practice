#include <iostream>

using namespace std;

// This program computes the current fair value of a stock
// User can perofrm the calculation in one of the 3 available methods
// Method 1: Zero Growth
// Method 2: Constant Growth
// Method 3: Limited Growth
int main()
{
	char computeAgain = 'y';
	while (computeAgain == 'y')
	{
		cout << endl;
		cout << "Welcome to STOCK Valuation v1.1" << endl;
		cout << "===============================" << endl;

		int method;
		cout << "Method 1: Zero Growth" << endl;
		cout << "Method 2: Constant Growth" << endl;
		cout << "Method 3: Limited Growth" << endl;
		cout << "Which method do you want to use? ";
		cin >> method;

		double P;

		double E;
		cout << "This year's earnings per share? ";
		cin >> E;

		double R;
		cout << "Desired rate of return? ";
		cin >> R;

		if (method == 1) 
		{
			// Method 1: Zero Growth
			P = E / R;
		}
		else if (method == 2)
		{
			// Method 2: Constant Growth
			double G;
			cout << "Growth rate of earnings? ";
			cin >> G;
			
			P = E / (R - G);
		}
		else if (method == 3)
		{
			// Method 3: Limited Growth
			double G;
			cout << "Growth rate of earnings? ";
			cin >> G;

			double N;
			cout << "Number of years earnings will grow? ";
			cin >> N;

			P = 0; // we will 50 years
			for (int x = 1; x <= 50; x++)
			{
				int power; // first N years of that 50 years we will use x as the power, N otherwise
				if (x < N) 
					power = x;
				else
					power = N;

				P += E * pow(1 + G, power) / pow(1 + R, x);
			}
		}

		cout << endl << "The present fair market value of the stock is " << P << "." << endl << endl;

		cout << "Do you want to compute another one? (y/n)";
		cin >> computeAgain;
	}

	system("PAUSE");
	return 0;
}