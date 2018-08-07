#include <iostream>

using namespace std;

int main()
{
	int basePremium = 50;
	int premium;

	int age;
	cout << "Enter the age of the driver: ";
	cin >> age;

	int numOfAcc;
	cout << "Enter the number of accidents in the past 5 years: ";
	cin >> numOfAcc;

	// Case 1: the age of driver is less than 25
	if (age < 25 && numOfAcc <= 1)
	{
		premium= basePremium + 100;
		cout << "The total monthly premium: $" << premium << endl;
	}

	else if (age < 25 && numOfAcc < 3)
	{
		premium = basePremium + 100 + (numOfAcc * 40);
		cout << "The total monthly premium: $" << premium << endl;
	}
		
	else if (age < 25 && numOfAcc >= 3 && numOfAcc < 4)
	{
		premium = basePremium + 100 + (numOfAcc * 60);
		cout << " The total monthly premium: $" << premium << endl;
	}

	else if (age < 25 && numOfAcc > 4)
	{
		cout << "We cannot provide insurance" << endl;
	}

	// Case 2: the age of driver is greater than 25 and less than 35
	else if 
		(age > 25 && age < 35 && numOfAcc <= 1)
	{
		premium = basePremium +20;
		cout << "The total monthly premium: $" << premium << endl;
	}

	else if (age > 25 && age < 35 && numOfAcc < 3)
	{
		premium = basePremium + 20 + (numOfAcc * 40);
		cout << "The total monthly premium: $" << premium << endl;
	}

	else if (age > 25 && age < 35 && numOfAcc >= 3 && numOfAcc < 4)
	{
		premium = basePremium + 20 + (numOfAcc * 60);
		cout << " The total monthly premium: $" << premium << endl;
	}

	else if (age > 25 && age < 35 && numOfAcc > 4)
	{
		cout << "We cannot provide insurance" << endl;
	}

	// Case 3: the age of driver is greater than 35

	else if
		(age > 35 && numOfAcc <= 1)
	{
		premium = basePremium;
		cout << "The total monthly premium: $" << premium << endl;
	}

	else if (age > 35 && numOfAcc < 3)
	{
		premium = basePremium + (numOfAcc * 40);
		cout << "The total monthly premium: $" << premium << endl;
	}

	else if (age > 35 && numOfAcc >= 3 && numOfAcc < 4)
	{
		premium = basePremium + (numOfAcc * 60);
		cout << " The total monthly premium: $" << premium << endl;
	}

	else if (age > 35 && numOfAcc > 4)
	{
		cout << "We cannot provide insurance" << endl;
	}

	system("PAUSE");
	return 0;
}