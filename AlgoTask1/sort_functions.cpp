#include "sort_functions.h"
#include <iostream >
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
void sort_functions::WriteSorted()
{
	// write the selected test case in text file to view sorted array
	fstream f;
	f.open("Sorted.txt");
	f.clear();
	// write the size of excel size
	f << vec.size() << endl;
	for (int i = 0; i<vec.size(); i++)
	{
		// write the sorted numbers in the text file to display it

		f << vec[i] << " ";
	}
	f << endl;

	f.close();
}
sort_functions::sort_functions()
{
	// constructor to declear 2D array to hold the time comelixity
	time.resize(9);
	for (int i = 0; i < 9; i++)
	{
		time[i].resize(5);
	}
	// read the small numbers from file
	int s, x;
	fstream f;
	f.open("small arrays.txt");
	while (!f.eof())
	{
		if (!(f >> s))
			break;
		vec.clear();
		for (int i = 0; i < s; i++)
		{
			f >> x;
			vec.push_back(x);
		}

		Arrays.push_back(vec);
	}
	f.close();

	// read the large numbers from file
	f.open("large arrays.txt");
	while (!f.eof())
	{
		if (!(f >> s))
			break;

		vec.clear();
		for (int i = 0; i < s; i++)
		{
			f >> x;
			vec.push_back(x);
		}

		Arrays.push_back(vec);
	}
	f.close();
	
	//fill the 2D array of time from previous runs of the program
	f.open("saved_time.txt");
	for (int i = 0; i < Arrays.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			f >> time[i][j] ;

		}
	}
	f.close();
	
}
void sort_functions::choice(int sortnum, int SizeIndex)
{
	//the user chooses the sort type and size
	if (sortnum == 0)
	{
		clock_t f = clock();
		vec.clear();
		// put the selected array in vector to deal with it in the sort
		vec = Arrays[SizeIndex];
		BubbleSort();
		clock_t s = clock();
		double res = (double)(s - f) / CLOCKS_PER_SEC;
		//put the calculated time from the proccess and put it in the 2D array of time
		time[SizeIndex][sortnum] = res;
		cout << "Bubble Sort Time Complexity = " << fixed << setprecision(30) << res << endl;
		// write the sorted elements in the text file and the time on excel 
		WriteSorted();
		WriteOnExcel();
	}
	else if (sortnum == 1) 
	{
		vec.clear();
		// put the selected array in vector to deal with it in the sort
		vec = Arrays[SizeIndex];
		clock_t f = clock();
		SelectionSort();
		clock_t s = clock();
		double res = (double)(s - f) / CLOCKS_PER_SEC;
		//put the calculated time from the proccess and put it in the 2D array of time
		time[SizeIndex][sortnum] = res;
		cout << "Selection Sort Time Complexity = " << fixed << setprecision(30) << res << endl;
		// write the sorted elements in the text file and the time on excel 
		WriteSorted();
		WriteOnExcel();
	}
	else if(sortnum==2)
	{
		vec.clear();
		// put the selected array in vector to deal with it in the sort
		vec = Arrays[SizeIndex];
		clock_t f = clock();
		InsertionSort();
		clock_t s = clock();
		double res = (double)(s - f) / CLOCKS_PER_SEC;
		//put the calculated time from the proccess and put it in the 2D array of time
		time[SizeIndex][sortnum] = res;
		cout << "Insertion Sort Time Complexity = " << fixed << setprecision(30) << res << endl;
		// write the sorted elements in the text file and the time on excel 
		WriteSorted();
		WriteOnExcel();
	}
	else if(sortnum==3)
	{
		vec.clear();
		// put the selected array in vector to deal with it in the sort
		vec = Arrays[SizeIndex];
		clock_t f = clock();
		merge_sort(0, vec.size() - 1);
		clock_t s = clock();
		double res = (double)(s - f) / CLOCKS_PER_SEC;
		//put the calculated time from the proccess and put it in the 2D array of time
		time[SizeIndex][sortnum] = res;
		cout << "Merge Sort Time Complexity = " << fixed << setprecision(30) << res << endl;
		// write the sorted elements in the text file and the time on excel 
		WriteSorted();
		WriteOnExcel();
	}
	else if(sortnum==4)
	{
		vec.clear();
		// put the selected array in vector to deal with it in the sort
		vec = Arrays[SizeIndex];
		clock_t f = clock();
		quicksort(0,vec.size()-1);
		clock_t s = clock();
		double res = (double)(s - f) / CLOCKS_PER_SEC;
		//put the calculated time from the proccess and put it in the 2D array of time
		time[SizeIndex][sortnum] = res;
		cout << "Quick Sort Time Complexity = " << fixed << setprecision(30) << res <<endl ;
		// write the sorted elements in the text file and the time on excel 
		WriteSorted();
		WriteOnExcel();
	}
}
int sort_functions::partitio( int low, int high) 
{
	// select the last element to be the pivot
	int pivot = vec[high];
	int index = low - 1;
	for (int i = low; i < high; i++)
	{
		if (vec[i] <= pivot)
		{
			index++;
			swap(vec[i], vec[index]);
		}
	}
	swap(vec[index + 1], vec[high]);
	return (index + 1);
}
void sort_functions::quicksort( int low, int high)
{
	if (low<high)
	{

		//  select the mid element to be the pivot
		int piv = (low + high) / 2;
		// swap the mid element with the last to deal with it in the quick sort
		swap(vec[high], vec[piv]);
		// get the correct index of the pivot
		int PivotIndex = partitio( low, high);
		//do quick sort for the range on the left of the pivot
		quicksort( low, PivotIndex - 1);
		//do quick sort for the range on the right of the pivot
		quicksort(PivotIndex + 1, high);
	}
}
void sort_functions::BubbleSort()
{

	for (int i = 0; i < vec.size(); i++)
	{
		// compare two element and sort them until the end
		for (int j = 0; j < vec.size() - i - 1; j++)
		{
			if (vec[j]>vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}

}
void sort_functions::InsertionSort()
{
	//
	for (int i = 0; i < vec.size(); i++)
	{
		int j = i - 1;
		int temp = vec[i];
		//get the correct place for the current element from the previous sorted array 
		while (j >= 0 && vec[j]>temp)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}
}
void sort_functions::SelectionSort()
{
	for (int i = 0; i < vec.size(); i++)
	{
		int ind = i;
		//get the minimum element from the sub array and put it in it's correct place
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < vec[ind])
			{
				ind = j;
			}

		}
		swap(vec[i], vec[ind]);
	}
}
void sort_functions::Second_merge(int s, int m, int e)
{
	int * third = new int [e-s+1];
	int k = 0;
	int i = s, j = m + 1;
	while (i <= m && j <= e)
	{
		//compare the element on left and right and put in the new array the smallest between them
		if (vec[i] <= vec[j])
		{
			third[k++]=vec[i++];
		}
		else
		{
			third[k++] = vec[j++];
		}
	}
	while (i <= m)
	{
		//put all the remaining elements on the left array on the new array

		third[k++] = vec[i++];
	}
	while (j <= e)
	{
		//put all the remaining elements on the right array on the new array

		third[k++] = vec[j++];
	}
	for (int i = 0; i < e-s+1 ; i++)
	{
		// replace the values from the new array and put it in the main vector
		vec[s++] = third[i];
	}
}
void sort_functions::merge_sort(int s, int e)
{
	
	if (s >= e)
		return;
	int mid = (s + e) / 2;
	// do merge sort for the elements from start of range to the mid
	merge_sort(s, mid);
	// do merge sort for the elements from mid +1 of range to the end
	merge_sort(mid + 1, e);
	// merge the left part and the second part
	Second_merge(s, mid, e);
}
void sort_functions::WriteOnExcel()
{
	fstream f;
	f.open("trial.csv");
	//fill the excel with the current 2D array
	//use the ',' to move to next column
	// use the 'endl' to move to the next row
	f << ",Bubble Sort ,Selection Sort , Insertion Sort , Merge Sort, Quick Sort" << endl;
	for (int i = 0; i < Arrays.size(); i++)
	{
		f << Arrays[i].size() ;
		for (int j = 0; j < 5; j++)
		{
			f << ',' <<time[i][j] ;
		}
		f << endl;
	}
	f.close();

	//fill text file with the 2D array of time to use it in the next runs for the program
	// avoid losing the values from excel after each run
	f.open("saved_time.txt");
	for (int i = 0; i < Arrays.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			f << time[i][j] << " ";

		}
		f << endl;
	}
	f.close();
}
sort_functions::~sort_functions()
{
}
