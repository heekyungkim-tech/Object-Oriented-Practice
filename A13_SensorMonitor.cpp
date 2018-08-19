#include <iostream>

using namespace std;

int main()
{
	double minTemp = 200;		// min temp user submitted
	double maxTemp = -200;		// max temp user submitted
	double sumTemp = 0;			// sum of all temp submitted
	int tempCount = 0;			// # of temp submitted

	while (true)
	{
		cout << endl;
		cout << "Welcome to Sensor Monitor 1.5" << endl;
		cout << "1- Submit Temperature Reading" << endl;
		cout << "2- Temperature Report" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "What do you want to do? ";
		cin >> choice;

		if (choice == 1)
		{
			double temp;
			cout << "What is the temperature? ";
			cin >> temp;

			// make sure that the temperature is within the valid range
			// if it is not, then warn the user
			if (temp < -200 || temp > 200) 
			{
				cout << "Temp. out of range [-200 <= temp <= 200]" << endl;
			} 
			else  
			{
				// temp is within range

				// see if this is the lowest temp yet
				if (temp < minTemp) 
				{
					// it is the lowest temp, let the user know
					cout << "This is the lowest temperature recorded yet." << endl;
					minTemp = temp;  // and update the lowest
				}

				// see if this is the highest temp yet
				if (temp > maxTemp)
				{
					// it is the highest temp, let the user know
					cout << "This is the highest temperature recorded yet." << endl;
					maxTemp = temp; // and update the highest
				}
				
				sumTemp += temp;	// add this temp to the sum of all temps.
				tempCount ++;		// increment the number of temps submitted
			}
		}
		else if (choice == 2)
		{
			cout << "The lowest temp is " << minTemp << endl;
			cout << "The highest temp is " << maxTemp << endl;
			cout << "The average temp is " << sumTemp / tempCount << endl;
		}
		else if (choice == 0)
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}
