#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Package {
public:
	string dest;
	double cost;

	double Tax(){
		return cost * 0.085;
	}
};

void ReadFile(Package package[], int &count);
void WriteFile(Package package[], int count);
void AddNew(string states[], double costs[], int &count);
void GrandReport(string states[], double costs[], int count);
void SearchByCost(string states[], double costs[], int count);
void SearchByState(string states[], double costs[], int count);

void ReadFile(Package package[], int &count)
{
	ifstream fileIn("data.txt");

	if (!fileIn)
	{
		return;
	}

	while (!fileIn.eof())
	{
		fileIn >> package[count].dest;
		fileIn >> package[count].cost;
		count++;
	}

	fileIn.close();
}

void WriteFile(Package package[], int count)
{
	ofstream fileOut("data.txt");

	for (int i = 0; i < count; i++){
		fileOut << package[i].dest << " " << package[i].cost;
		if (i < count - 1)
		{
			fileOut << endl;
		}
	}

	fileOut.close();
}

void AddNew(Package packages[], int &count)
{
	cout << "State: ";
	cin >> packages[count].dest;
	cout << "Cost: ";
	cin >> packages[count].cost;
	count++;
}


void SearchByState(Package packages[], int count){
	string state;
	cout << "State: ";
	cin >> state;

	for (int i = 0; i < count; i++)
	{
		if (packages[i].dest == state)
		{
			cout << packages[i].dest << " " << packages[i].cost << endl;
		}
	}
}

void SearchByCost(Package packages[], int count)
{
	double cost;
	cout << "Cost: ";
	cin >> cost;

	for (int i = 0; i < count; i++)
	{
		if (packages[i].cost > cost)
		{
			cout << packages[i].dest << " " << packages[i].cost << endl;
		}
	}
}

void GrandReport(Package packages[], int count)
{
	double total = 0;

	for (int i = 0; i < count; i++)
	{
		cout << packages[i].dest << " " << packages[i].cost << endl;
		total += packages[i].cost;
	}

	cout << "The total is " << total << "." << endl;
}



int main()
{
	Package packages[1000];
	int count = 0;

	ReadFile(packages, count);

	while (true)
	{
		cout << "FEDEX" << endl;
		cout << "===============" << endl;
		cout << "1- Create Mail" << endl;
		cout << "2- Search By State" << endl;
		cout << "3- Search By Cost" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			AddNew(packages, count);
		}
		else if (choice == 2)
		{
			SearchByState(packages, count);
		}
		else if (choice == 3)
		{
			SearchByCost(packages, count);
		}
		else if (choice == 4)
		{
			GrandReport(packages, count);
		}
		else if (choice == 0)
		{
			break;
		}
	}

	WriteFile(packages, count);

	system("PAUSE");
	return 0;
}