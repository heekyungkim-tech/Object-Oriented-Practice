#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Job
{
public:
	string jobName;
	string talentName;
	double cost;
};

void AddANewJob(Job jobs[], int &count)
{
	cout << "Enter job name: ";
	cin >> jobs[count].jobName;

	cout << "Enter talent name: ";
	cin >> jobs[count].talentName;

	cout << "Enter cost: ";
	cin >> jobs[count].cost;

	count++;
}

void SearchbyJob(Job jobs[], int count)
{
	// user tells us the name of the job
	string j;
	cout << "Enter job name: ";
	cin >> j;

	double sum = 0; // sum of the cost of all the jobs whose name matches the name user gave (j)
	int count2 = 0; // this is the number of records that have the same name as the name user gave (j)
	double min = 9999999; // initialized to large number to make sure that the first numebr we get will be taken as min. 
	double max = -9999999; // initialized to small number to make sure that the first numebr we get will be taken as max. 

	for(int i=0; i < count; i++)
	{
		// everything inside this if statement will be executed
		// for only those jobs whose name is same as the 
		// one user entered. 
		if (jobs[i].jobName == j) 
		{
			cout << "Job " << jobs[i].jobName << " " <<  
							  jobs[i].talentName << " " << 
							  jobs[i].cost << endl;

			sum = sum + jobs[i].cost;

			count2 ++;

			if (jobs[i].cost < min) 
				min = jobs[i].cost;

			if (jobs[i].cost > max) 
				max = jobs[i].cost;
		}
	}

	double avg = sum / count2;
	cout << "The total cost of the job is " << sum << endl;
	cout << "The avg cost of the job is " << avg << endl;
	cout << "The min cost of the job is " << min << endl;
	cout << "The max cost of the job is " << max << endl;
}

void DisplayAll(Job jobs[], int count)
{
	// by default reportCount is set to the number of records in the file
	int reportCount = count;

	// now let's check if it is larger than 100
	// if it is, we need to limit it to 100
	if (reportCount > 100)
	{
		reportCount = 100;
	}

	// notice that our for loop goes from zero to reportCount (NOT count!)
	for(int i=0; i < reportCount; i++)
	{
		cout << "Job " << jobs[i].jobName << " " <<  
						  jobs[i].talentName << " " << 
						  jobs[i].cost << endl;
	}
}

void LoadFile(Job jobs[], int &jobCount)
{
	// create a stream for the file with the file name
	// since full path is not specified, it will be in the 
	// same folder as the project file (.vcprj file). 
	ifstream f("data.txt");
	
	// check if file exist
	// if it doesn't exist, 
	// then good() returns false.
	// if file doesn't exist we should just return because nothing to load
	if (!f.good()) return;

	// if we got here that means file exist 
	// (otherwise we would have returned from above statement).
	// since file is there, let's keep reading until 
	// we get to End Of File (eof)
	while(!f.eof())
	{
		// we first read the jobname, followed by talent name and then the cost
		f >> jobs[jobCount].jobName;
		f >> jobs[jobCount].talentName;
		f >> jobs[jobCount].cost;
		jobCount++; // make sure jobCount is sent by referene to this function
	}

	f.close();
}

void SaveFile(Job jobs[], int jobCount)
{
	ofstream f("data.txt");
	
	for(int i=0; i < jobCount; i++)
	{
		f << jobs[i].jobName << " ";
		f << jobs[i].talentName << " ";
		f << jobs[i].cost;
		
		// I want to put a new line to the end of each record
		// except the very last record. Because the new line 
		// at the end of the last record would create an empty record
		// and that empty record would be read as garbage by LoadFile function
		if (i < jobCount -1)
		{
			f << endl; // put a new line only if we are not saving the very last record. 
		}
	}

	f.close();
}

int main()
{
	Job jobs[200];
	int jobCount = 0;

	LoadFile(jobs, jobCount);

	while(true)
	{
		cout << "1- Add a new record" << endl;
		cout << "2- Display By Job" << endl;
		cout << "3- Display All" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "What do you want to do?";
		cin >> choice;

		if (choice ==1 )
			AddANewJob(jobs, jobCount);
		else if (choice == 2)
			SearchbyJob(jobs, jobCount);
		else if (choice == 3)
			DisplayAll(jobs, jobCount);
		else if (choice == 0)
			break;
	}

	SaveFile(jobs, jobCount);

	system("PAUSE");
	return 0;
}
