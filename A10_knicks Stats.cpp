#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player
{
public:
	string Name;
	int Reb;
	int Pts;
	int Ast;
};

void ReadFile(Player players[], int &count)
{
	ifstream file("knicks.txt");
	if (!file.good())
	{
		cout << "Could not read the file. The file does not exist." << endl;
		return;
	}

	while (!file.eof())
	{
		file >> players[count].Name;
		if (players[count].Name == "")
		{
			return;
		}
		file >> players[count].Pts;
		file >> players[count].Reb;
		file >> players[count].Ast;
		count++;
	}
}

void MostScorer(Player players[], int count)
{
	int maxIndex = 0;
	int minIndex = 0;

	for (int i = 0; i < count; i++)
	{
		if (players[i].Pts > players[maxIndex].Pts)
		{
			maxIndex = i;
		}

		if (players[i].Pts < players[minIndex].Pts)
		{
			minIndex = i;
		}
	}

	cout << "Most Scorer: " << players[maxIndex].Name << endl;
	cout << "Least Scorer: " << players[minIndex].Name << endl;
}

void DoubleOrTriple(Player players[], int count, bool triple)
{
	for (int i = 0; i < count; i++)
	{
		int ct = 0;

		if (players[i].Pts > 9) { ct++; }
		if (players[i].Reb > 9) { ct++; }
		if (players[i].Ast > 9) { ct++; }

		if (triple)
		{
			if (ct > 3)
			{
				cout << players[i].Name << " had triple double." << endl;
			}
		}
		else
		{
			if (ct > 2)
			{
				cout << players[i].Name << " had double double." << endl;
			}
		}
		
	}
}

void Report(Player players[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << players[i].Name << " PTS: " << players[i].Pts << "AST: " << players[i].Ast << " REB: " << players[i].Reb << endl;		
	}
}

int main()
{
	Player players[100];
	int count = 0;

	ReadFile(players, count);

	while (true)
	{
		cout << "1- Most Scorer" << endl;
		cout << "2- Double Double" << endl;
		cout << "3- Triple Double" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			MostScorer(players, count);
		}
		else if (choice == 2)
		{
			DoubleOrTriple(players, count, false);
		}
		else if (choice == 3)
		{
			DoubleOrTriple(players, count, true);
		}
		else if (choice == 4)
		{
			Report(players, count);
		}
		else if (choice == 0)
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}