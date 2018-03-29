#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "sort_functions.h"
using namespace std;

int main()
{
	sort_functions mysorter;
	int sortnum;
	
	
	do
	{ 
	cout << "0 For BUBBLE SORT" << endl;
	cout << "1 For SELECTION SORT" << endl;
	cout << "2 For INSERTION SORT" << endl;
	cout << "3 For MERGE SORT" << endl;
	cout << "4 For Quick SORT" << endl;
	cin >> sortnum;
	if(sortnum<3)
	{
		for (int i = 0; i<mysorter.Arrays.size()-3; i++)
		{
			cout << i << " For " << mysorter.Arrays[i].size() << " Random Numbers" << endl;;
		}
	}
	else {
		for (int i = 0; i < mysorter.Arrays.size(); i++)
		{
			cout << i << " For " << mysorter.Arrays[i].size() << " Random Numbers" << endl;;
		}
	}
	int sizechoice;
	cin >> sizechoice;
	mysorter.choice(sortnum, sizechoice);
	} while (sortnum >= 0&&sortnum<5);
	return 0;
}