#include <iostream>
#include <time.h>

using namespace std;

int main()
{	
	srand((unsigned int)time(0));
	// Number baseball game
	int iNumber[9] = {};

	// Put numbers from 1 to 9 in order.
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}
	
	// For swap
	int iTemp, idx1, idx2;

	// Shuffle 1000 times.
	int iShuffle = 1000;
	for (int i = 0; i < iShuffle; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << "* * *" << endl;
//	cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];

	while (true)
	{
		cout << "Please enter 3 numbers between 1 and 9 (0 : Quit) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] < 0 || iInput[0] > 9 ||
			iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "You have entered an invalid number." << endl;
			continue;
		}

		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
		{
			cout << "Duplicate numbers have been entered." << endl;
			continue;
		}

		// Change Strike and Ball to 0 for next turn
		iStrike = iBall = 0;

		// var i is to Find the index of the number to be matched.
		for (int i = 0; i < 3; ++i)
		{
			// var j is to Find the index of the number you received. 
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
					{
						++iStrike;
					}
					else
					{
						++iBall;
					}
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "You got the numbers.";
			break;
		}
		else if (iStrike == 0 && iBall == 0)
		{
			cout << "Out" << endl;
		}
		else
		{
			cout << iStrike << " strike " << iBall << " ball" << endl;
		}
	}
	
	return 0;
}