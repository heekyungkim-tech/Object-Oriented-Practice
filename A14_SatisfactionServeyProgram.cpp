#include <iostream>

using namespace std;

int main()
{
	int lowest = 5;
	int highest = 0;
	double sum = 0;
	int count = 0;

	while (true)
	{
		cout << "Welcome to China Border Protection" << endl;
		cout << "======= Satisfaction Survey ======" << endl;
		cout << "1- Submit a Rating" << endl;
		cout << "2- View Ratings" << endl;
		cout << "3- Reset Ratings" << endl;
		cout << "0- Exit" << endl;

		int choice;
		cout << "your choice? ";
		cin >> choice;

		if (choice == 1)
		{
			int rating;
			cout << "what is your rating (1-4)? ";
			cin >> rating;

			if (rating > 4 || rating < 1)
			{
				cout << "Invalid rating." << endl;
			} 
			else
			{
				sum += rating;
				count ++;

				if (rating < lowest)
				{
					lowest = rating;
				}
				
				if (rating > highest)
				{
					highest = rating;
				}
			}
		}
		else if (choice == 2)
		{
			if (count == 0)
			{
				cout << "there are no rating" << endl;
			}
			else
			{
				cout << "Lowest: " << lowest << endl;
				cout << "Highest: " << highest << endl;
				cout << "Sum: " << sum << endl;

				double avg = sum / count;
				cout << "Avg: " << avg << endl;
			}
		}
		else if (choice == 3)
		{
			lowest = 5;
			highest = 0;
			sum = 0;
			count = 0;
		}
		else if (choice == 0)
		{
			break;
		}

	}



	system("PAUSE");
	return 0;
}