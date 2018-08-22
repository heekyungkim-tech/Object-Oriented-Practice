#include <iostream>
#include <fstream>

using namespace std;

// prototypes
void ReadFile(int age[], int loan[], int score[], int &count);
void SummaryReport(int age[], int loan[], int score[], int count);
void HighRiskReport(int age[], int loan[], int score[], int count);
void SimulateLoan(int age[], int loan[], int score[], int count);

int main()
{
	// data will be stored in these arrays
	int age[1000];
	int loan[1000];
	int score[1000];
	int count = 0;
	
	// read the data from file into arrays
	ReadFile(age, loan, score, count);

	while (true)
	{
		cout << endl << "Mortgage Audit v2.0" << endl;
		cout << "====================" << endl;
		cout << "1- Summary Report" << endl;
		cout << "2- High Risk Loans" << endl;
		cout << "3- Simulate Loan" << endl;
		cout << "0- Exit" << endl;
		
		int choice;
		cout << "Your choice? ";
		cin >> choice;

		if (choice == 1)
		{
			SummaryReport(age, loan, score, count);
		}
		else if (choice == 2)
		{
			HighRiskReport(age, loan, score, count);
		}
		else if (choice == 3)
		{
			SimulateLoan(age, loan, score, count);
		}
		else if (choice == 0)
		{
			break;
		}
	}


	system("PAUSE");
	return 0;
}

void ReadFile(int age[], int loan[], int score[], int &count)
{
	ifstream fileIn("mortgage.txt");
	
	// check if the file exist -- warn if the file cannot be found
	if (!fileIn) {
		cout << "Could not load data!" << endl;
		return;
	}

	while (!fileIn.eof())
	{
		fileIn >> age[count];
		fileIn >> loan[count];
		fileIn >> score[count];
		count++;
	}
}

void SummaryReport(int age[], int loan[], int score[], int count)
{
	// let's get the sum of applicant age, loan amount and score
	// we will later divide the sum to number of loans to fid the average
	int sumAge = 0;
	int sumLoan = 0;
	int sumScore = 0;

	for (int i = 0; i < count; i++)
	{
		// sum up age loan and score separately
		sumAge += age[i];
		sumLoan += loan[i];
		sumScore += score[i];
	}

	// compute and report the averages
	cout << "Average Age of Applicants: " << sumAge / count << endl;
	cout << "Average Loan Amount: " << sumLoan / count << endl;
	cout << "Average Score of Applicants: " << sumScore / count << endl;
}


void HighRiskReport(int age[], int loan[], int score[], int count)
{
	cout << "Searching for high risk loans..." << endl;

	// we will go through all loans
	// and for the ones we identify as high risk
	// we will sum up their amount
	int highRiskLoanCount = 0; // how many high risk have we identified?
	int highRiskLoanTotal = 0; // the sum of amounts of loan amounts of high risk loans.

	for (int i = 0; i < count; i++)
	{
		double risk = loan[i] / score[i]; // risk is computed as loan / credit score
		
		if (age[i] < 30)
		{
			// increase 40% for those below 30 years old
			risk *= 1.4;
		}
		else if (age[i] < 50)
		{
			// increase 20% for those below 50 years old (must be greater than equal to 30)
			risk *= 1.2;
		}

		// if the risk factor is above 100000, then this is a high risk loan
		if (risk > 100000)
		{
			highRiskLoanCount += 1;
			highRiskLoanTotal += loan[i];
		}
	}

	cout << "Found " << highRiskLoanCount << " high risk loans." << endl;
	cout << "Total amount of high risk loans is $" << highRiskLoanTotal << "." << endl;
}

void SimulateLoan(int age[], int loan[], int score[], int count)
{
	// ask user for his age and credit score
	int yourage;
	cout << "Your age: ";
	cin >> yourage;

	int yourscore;
	cout << "Your Credit Score (1-8): ";
	cin >> yourscore;

	// we will sum up the loan amounts for the loans that 
	// matches the age and the credit score
	int totalLoan = 0;
	int totalCount = 0;

	for (int i = 0; i < count; i++)
	{
		// make sure that we include loans that are within 5 years of the age of the applicant
		if (age[i] >= yourage - 5 && age[i] <= yourage + 5)
		{
			// the score needs to match exactly
			if (yourscore == score[i])
			{
				// if fits the criteria, sum up the loan amount and increment counter
				totalLoan += loan[i];
				totalCount++;
			}
		}
	}

	// find average and report
	if (totalCount > 0)
	{
		cout << "Likely loan in the amount of $" << totalLoan / totalCount << "." << endl;
	}
	else
	{
		cout << "Sorry we cannot estimate a loan amount for you." << endl;
	}
}
