#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Diagnosis {
public:
	string disease;
	string symptom;
};

void ReadData(Diagnosis data[], int &count)
{
	ifstream file("diagnostic.txt");
	if (!file)
	{
		cout << "Cannot read the file!" << endl;
	}

	while (!file.eof()) {
		file >> data[count].disease;
		file >> data[count].symptom;
		count++;
	}
}


void DiseaseCount(Diagnosis data[], int count)
{
	int dcount = 1;
	for (int i = 1; i < count; i++){
		if (data[i].disease != data[i - 1].disease){
			dcount++;
		}
	}
	cout << "There are " << dcount << " diseases." << endl;
}

void CountByDisease(Diagnosis data[], int count)
{
	int dcount = 1;
	for (int i = 1; i < count; i++){
		if (data[i].disease == data[i - 1].disease){
			dcount++;
		} else {
			cout << "There are " << dcount << " symptoms for " << data[i-1].disease << "." << endl;
			dcount = 1;
		}
	}	
	// let's not miss the last one
	cout << "There are " << dcount << " symptoms for " << data[count-1].disease << "." << endl;
}

void Diagnose(Diagnosis data[], int count)
{
	string symptom;
	cout << "Symptom: ";
	cin >> symptom;

	for (int i = 0; i < count; i++){
		if (data[i].symptom == symptom){
			cout << data[i].disease << endl;
		}
	}
}

int main()
{
	Diagnosis data[1000];
	int count = 0;
	ReadData(data, count);

	while (true)
	{
		cout << "1- Display Disease Count" << endl;
		cout << "2- Symptom Count By Disease" << endl;
		cout << "3- Diagnose" << endl;
		cout << "0- Exit" << endl;
		int choice;
		cout << "your choice: " << endl;
		cin >> choice;

		if (choice == 1){
			DiseaseCount(data, count);
		} else if (choice == 2){
			CountByDisease(data, count);
		}  else if (choice == 3){
			Diagnose(data, count);
		} else if (choice == 0){
			break;
		}
	}

	system("PAUSE");
	return 0;
}