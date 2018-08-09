
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int choice;
	string tableAvail[20]; // tables available to be reserved 
	string name;  // the name of customer who reserved a table

	int tableNumber;

	for (int i = 0; i < 20; i++)
	{
		tableAvail[i] = "Available";
	}

	while (true)
	{
		cout << "Restaurant Reservation System" << endl;
		cout << "1- Reserve a Table" << endl;
		cout << "2- Clear Researvation" << endl;
		cout << "3- Report" << endl;
		cout << "0- Exit" << endl;

		int choice;

		cout << "What's your choice?: " << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "what table would you like to reserve? (1-19): " << endl;
			cin >> tableNumber;

			for (int i = 0; i < 20; i++)
			{
				if (tableAvail[tableNumber] == "Available")
				{
					cout << "Table is available. May I take your name please?\n";
					cin >> name;
					tableAvail[tableNumber] = name; 
				}
				else
				{
					cout << "Requested table number is not available." << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "what table would you like to clear ? : " << endl;
			cin >> tableNumber;

			if (tableAvail[tableNumber] == "Available")
			{
				cout << "The reserved table is availble to clear" << endl; 
			}
			else
			{
				tableAvail[tableNumber] == "Available";
				cout << "The selected table is already cleared. nothing to clear ";
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < 20; i++)
			{
				string riport; 
				if (riport == "Available")
				{
					cout << "Available Table: " << i << "\n" << endl;
				}
				else
				{
					cout << "Reserved Table: " << i << tableNumber << "by" << name <<"\n" << endl;
				}
			}
		  }
		} while (choice != 0);

	system("PAUSE");
	return 0;
}