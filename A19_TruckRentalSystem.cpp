#include <iostream>

using namespace std;

int main()
{
	bool t1Avail = true;
	bool t2Avail = true;
	int total = 0;

	while (true)
	{
		cout << endl;
		cout << "1- Dispatch" << endl;
		cout << "2- Return" << endl;
		cout << "3- Report" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "choice? ";
		cin >> choice;

		if (choice == 1)
		{
			int truckNo;
			cout << "Truck (1/2)? ";
			cin >> truckNo;

			if ((truckNo == 1 && t1Avail == false) || (truckNo == 2 && t2Avail == false))
			{
				cout << "Requested truck " << truckNo << " is not available." << endl;
			}
			else
			{
				double amount;
				cout << "Amount $";
				cin >> amount;

				total += amount;
				if (truckNo == 1)
				{
					t1Avail = false;
				}
				else 
				{
					t2Avail = false;
				}
			}
		}
		else if (choice == 2)
		{
			int truckNo;
			cout << "Truck (1/2)? ";
			cin >> truckNo;

			if (truckNo == 1)
			{
				t1Avail = true;
			}
			else
			{
				t2Avail = true;
			}
			
			cout << "truck is now available" << endl;
		}
		else if (choice == 3)
		{
			if (t1Avail == true)
			{
				cout << "Truck 1 is available" << endl;
			} 
			else
			{
				cout << "Truck 1 is dispatched" << endl;
			}

			if (t2Avail == true)
			{
				cout << "Truck 2 is available" << endl;
			}
			else
			{
				cout << "Truck 2 is dispatched" << endl;
			}
			
			cout << "Total: " << total << endl;
		}
		else if (choice == 0)
		{
			break;
		}
	}


	system("PAUSE");
	return 0;
}