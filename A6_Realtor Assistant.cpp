#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int choice;
	string numprop[20000]; // the property number is between 1-20000
	int propNum; // the property number
	double price[20000]; // th eprice of the property
	int roomNum[20000]; // the number of bedrooms
	int time;
	int count = 0;

	do
	{
		cout << "1 -New Property" << endl;
		cout << "2 -Price Reduction" << endl;
		cout << "3 -Search Property " << endl;
		cout << "4 -Report" << endl;
		cout << "0 -Exit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "What is the property number? ";
			cin >> propNum;

			if (propNum < 1 || propNum > 20000)
			{
				cout << "Invalid Number" << endl;
			}
			else
			{
				cout << "How much is the property? ";
				cin >> price[propNum];

				if (price[propNum] < 50000 || price[propNum] > 100000000)
				{
					cout << "Invalid" << endl;
				}
				else
				{
					cout << "How many bedroom the property has? ";
					cin >> roomNum[propNum];

					if (roomNum[propNum] < 1)
					{
						cout << "invalid. the property does not conform to rules" << endl;
					}
				}
			}
			count++;
		}
		else if (choice == 2)
		{
			cout << "How long has the Property been on the book? ";
			cin >> time;
			if (time >= 1)
			{
				cout << "What is the Property ID? ";
				cin >> propNum;
				double reduct;
				cout << "How much is the Reduction price? ";
				cin >> reduct;
				price[propNum] -= reduct;
				cout << "the changed property price after price reduction is:  " << price[propNum] << endl;
			}
			count++;
	
		}
		else if (choice == 3)
		{
			cout << "Property Number: " << endl;
			cin >> propNum;

			cout << "Property Number: " << propNum << endl;
			cout << "Price: " << price[propNum] << endl;
			cout << "Number of bedroom: " << roomNum[propNum] << endl;
		}

		else if (choice == 4)
		{
				cout << "Property Number, price, room Number: " << propNum <<","<< price[propNum] <<","<< roomNum[propNum] << endl;
				double avg = price[propNum] / count;
				cout << "Average home price: " << avg << endl;
		}

	} while (choice != 0);


	system("PAUSE");
	return 0;
}