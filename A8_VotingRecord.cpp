#include <iostream>
#include <fstream>

using namespace std;


void ReadFile(int voteA[], int voteB[], int &issueCount)
{
	// you may need to change the 
	ifstream inFile("C:\\Users\\Ali\\Desktop\\votes.txt");

	if (inFile.good()) // make sure the file exist and that we can read it
	{
		while (!inFile.eof()) // continue reading until we get to the end of the file
		{
			// I will read in the issue number, but will ignore it
			// as I don't really need it for any of the features of 
			// the program.
			int issue;
			inFile >> issue;

			// the voting of the congressmen for the issue is 
			// important, so I will read them into the array
			inFile >> voteA[issueCount];
			inFile >> voteB[issueCount];
			issueCount++; // increment the voteCount so the next record can go into empty box in the array
		}
	}
	else 
	{
		cout << "Cannot find the file!" << endl;
	}
}

void PerformanceRating(int voteA[], int voteB[], int issueCount)
{
	int missedVoteA = 0;
	int missedVoteB = 0;

	// go through each issue
	for (int i = 0; i < issueCount; i++)
	{
		// if congressman A missed the vote of this issue increment the counter for A
		if (voteA[i] == 0) 
		{
			missedVoteA++;
		}

		// if congressman B missed the vote of this issue increment the counter for B
		if (voteB[i] == 0)
		{
			missedVoteB++;
		}
	}

	double ratingA = missedVoteA / (double)issueCount;
	double ratingB = missedVoteB / (double)issueCount;

	cout << "Congressman A Performance: " << ratingA << endl;
	cout << "Congressman B Performance: " << ratingB << endl;
}

void SimilarityRating(int voteA[], int voteB[], int issueCount)
{
	int sameVote = 0;
	int totalVote = 0;

	// go through each issue
	for (int i = 0; i < issueCount; i++)
	{
		// if both congressmen A and B missed the vote, then skip to next issue
		if (voteA[i] == 0 && voteB[i] == 0)
		{
			continue;
		}
		
		// otherwise if both voted the same, then increment sameVote counter. 
		if (voteA[i] == voteB[i])
		{
			sameVote++;
		}

		// eitherway, we count this as a vote where both did not miss
		totalVote++;
	}

	double similarity = sameVote / (double)totalVote;

	cout << "Similarity Rate: " << similarity << endl;
}

void Summary(int voteA[], int voteB[], int issueCount)
{
	int NayA = 0;
	int YeaA = 0;
	int MissA = 0;

	int NayB = 0;
	int YeaB = 0;
	int MissB = 0;

	// go through each issue count yea, nay and misses for each congressman
	for (int i = 0; i < issueCount; i++)
	{
		if (voteA[i] == -1)
		{
			NayA++;
		} 
		else if (voteA[i] == 0)
		{
			MissA++;
		}
		else if (voteA[i] == 1)
		{
			YeaA++;
		}

		if (voteB[i] == -1)
		{
			NayB++;
		}
		else if (voteB[i] == 0)
		{
			MissB++;
		}
		else if (voteB[i] == 1)
		{
			YeaB++;
		}
	}

	cout << "Congressman A: " << endl;
	cout << "  Yea : " << YeaA << endl;
	cout << "  Nay : " << NayA << endl;
	cout << "  Miss: " << MissA << endl;
	cout << "Congressman B: " << endl;
	cout << "  Yea : " << YeaB << endl;
	cout << "  Nay : " << NayB << endl;
	cout << "  Miss: " << MissB << endl;
}

int main()
{
	// we will keep the votign record of 
	// each congressman in a separate array
	// 
	int voteA[100];
	int voteB[100];
	int issueCount = 0;

	ReadFile(voteA, voteB, issueCount);

	while (true)
	{
		cout << endl;
		cout << "Voting Record Analysis" << endl;
		cout << "======================" << endl;
		cout << "1: Performance Rating" << endl; 
		cout << "2: Similarity Rating" << endl;
		cout << "3: Summary Report" << endl;
		cout << "0: Exit" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			PerformanceRating(voteA, voteB, issueCount);
		}
		else if (choice == 2)
		{
			SimilarityRating(voteA, voteB, issueCount);
		}
		else if (choice == 3)
		{
			Summary(voteA, voteB, issueCount);
		}
		else if (choice == 0)
		{
			break;
		}
	}
}
