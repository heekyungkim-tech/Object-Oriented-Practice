#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PopulationReport(string county[], string state[], double population[], int count);
void PopulousState(string county[], string state[], double population[], int count);
void SimilarCounties(string county[], string state[], double population[], int count);
void CountiesByRange(string county[], string state[], double population[], int count);

int main()
{
	// we can read up to 5000 counties
	string county[5000];
	string state[5000];
	double population[5000];
	int count = 0;

	// read the file
	ifstream fileIn("counties.txt");
	if (fileIn) {
		while (!fileIn.eof())
		{
			fileIn >> county[count];
			fileIn >> state[count];
			fileIn >> population[count];
			count++;
		}
	}
	else
	{
		cout << "Could not find the file!";
		system("PAUSE");
		return 0;
	}

	while (true)
	{
		cout << endl;
		cout << "Census Analysis 2010" << endl;
		cout << "====================" << endl;
		cout << "1- Population Report" << endl;
		cout << "2- Counties By Range" << endl;
		cout << "3- Similar Counties" << endl;
		cout << "4- Populous State" << endl;
		cout << "0- Exit" << endl;
		int choice;
		cout << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			PopulationReport(county, state, population, count);
		} 
		else if (choice == 2)
		{
			CountiesByRange(county, state, population, count);
		}
		else if (choice == 3)
		{
			SimilarCounties(county, state, population, count);
		}
		else if (choice == 4)
		{
			PopulousState(county, state, population, count);
		}
		else if (choice == 0)
		{
			break;
		}
	}
	
	system("PAUSE");
	return 0;
}

// report the most and least populous counties along with the avg county population in US
void PopulationReport(string county[], string state[], double population[], int count)
{
	int minIndex = 0; // assume county at index 0 is the least populous
	int maxIndex = 0; // assume county at index 0 is the most populous
	int sum = 0;	  // we will sum up the population of all counties
	
	// go through all counties
	for (int i = 0; i < count; i++)
	{
		// is the population at i'th county less than the population of the country at minIndex?
		if (population[i] < population[minIndex])
		{
			minIndex = i; // if so, take the index as the index of the least populous county
		}

		// is the population at i'th county larger than the population of the country at maxIndex?
		if (population[i] > population[maxIndex])
		{
			maxIndex = i; // if so, take the index as the index of the most populous county
		}

		sum += population[i]; // add the population of this county to sum
	}

	// we went through all the counties, now we can report our findings
	cout << "Least Populated Country: " << county[minIndex] << "(" << state[minIndex] << ")" << endl;
	cout << "Most Populated Country: " << county[maxIndex] << "(" << state[maxIndex] << ")" << endl;
	cout << "Average County Population is " << sum / count << endl;
}


// ask user for min and max population and then report all counties within that range
void CountiesByRange(string county[], string state[], double population[], int count)
{
	int min;
	cout << "Enter Min. Population: ";
	cin >> min;

	int max;
	cout << "Enter Max. Population: ";
	cin >> max;

	// go thorugh all counties
	for (int i = 0; i < count; i++)
	{
		// is the population of this county within the range user input?
		if (population[i] < max && population[i] > min)
		{
			// if so we can report this county
			cout << county[i] << "(" << state[i] << "): " << population[i] << endl;
		}
	}
}


// find and report the counties that have the same population
void SimilarCounties(string county[], string state[], double population[], int count)
{
	cout << "Here are similar counties: " << endl;

	// go through each county, and at each iteration
	// we will compare this county with the other counties
	// make sure to not go all the way to last county
	// because, the last county cannot be compared to any other county
	for (int i = 0; i < count - 1; i++)
	{
		// now for the county at index i, go through the rest of the indexes (i+1 and on) and compare
		for (int x = i + 1; x < count; x++)
		{
			// are the population of county i same as county x?
			if (population[i] == population[x] && state[i] == state[x])
			{
				// if so report
				cout << county[i] << "(" << state[i] << ") and " << county[x] << "(" << state[x] << ")" << endl;
			}
		}
	}
}

// find the most populous state
void PopulousState(string county[], string state[], double population[], int count)
{
	// notice that the states are in ascending order in the data

	string maxState = "";
	double maxStatePopulation = 0;

	string cState = "Unknonwn";
	double cStatePop = 0;

	// go through the counties
	for (int i = 0; i < count; i++)
	{
		// as long as the state of this county same as the state we are monitoring
		if (state[i] == cState)
		{
			cStatePop += population[i]; // add the population of the county to monitored state population
		}
		else
		{
			// as soon as you find a county whose 
			// state is not the current state we are monitoring
			// that means there is a new state we need to start monitoring
			// but before that, check if the populationwe have accumulated for
			// current state is more than the max we have found so far?
			if (cStatePop > maxStatePopulation)
			{
				// if so, make the max state the currently monitored state
				maxState = cState;
				maxStatePopulation = cStatePop;
			}

			// start monitoring this new state and 
			// set the initial population of this state to the current county
			cState = state[i];
			cStatePop = population[i];
		}
	}

	// the very last state we were monitoring may be the max, check one last time
	if (cStatePop > maxStatePopulation)
	{
		// if so, make the max state the currently monitored state
		maxState = cState;
		maxStatePopulation = cStatePop;
	}

	// now we can report the state we found
	cout << "Most populous state is " << maxState << " with population " << maxStatePopulation << endl;
}