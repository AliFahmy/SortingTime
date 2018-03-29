#pragma once
#include <vector>
using namespace std;
static class sort_functions
{
public:
	vector < vector <int> > Arrays;
	vector < int > vec;
	vector < vector < double > > time;
	sort_functions();
	void choice(int sortnum , int sizee);
	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void WriteSorted();
	void WriteOnExcel();
	void merge_sort(int s, int e);
	void sort_functions::Second_merge(int s, int m, int e);
	void quicksort( int low, int high);
	int partitio( int low, int high);
	~sort_functions();
};

