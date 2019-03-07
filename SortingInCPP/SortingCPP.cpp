#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

void swap_array(int ptr[], int index_i, int index_j);
void print_array(int arr[], size_t len);
void array_restore(int arr_backup[], int arr_to_restore[], int len);

void sort_select(int arr[], int len, bool flag);
void sort_bubble(int arr[], int len, bool flag);
void sort_bubble_optimized(int arr[], int len, bool flag);

int main()
{
	int array_to_sort[] = { 2, 8, 1, 9, 7, 6, 4, 3 };
	int array_backup[] = { 2, 8, 1, 9, 7, 6, 4, 3 };

	//int array_to_sort[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int array_backup[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	size_t len = sizeof(array_to_sort) / sizeof(int);

	cout << "Please select the sorting method: " << endl;
	cout << "1. Select Sort.\n2. Bubble Sort.\n";

	size_t method;
	
	while (1)
	{
		cin >> method;

		switch (method)
		{
		case 1:
			sort_select(array_to_sort, len, true);
			break;
		case 2:
			sort_bubble(array_to_sort, len, true);
			//sort_bubble_optimized(array_to_sort, len, true);
			break;
		default:
			break;
		}

		array_restore(array_backup, array_to_sort, len);
		method = 0;
	}

	_getch();
	return 0;
}

void swap_array(int ptr[], int index_i, int index_j)
{
	int temp = 0;
	temp = ptr[index_i];
	ptr[index_i] = ptr[index_j];
	ptr[index_j] = temp;
}

void print_array(int arr[], size_t len)
{
	for (size_t ii = 0; ii < len; ++ii)
	{
		cout << arr[ii] << " ";
	}
	cout << endl;
}

void sort_select(int arr[], int len, bool flag)
{
	cout << "==================== Select Sort Begin ======================="<<endl;

	cout << "Before sorting: " << endl;
	print_array(arr, len);
	cout << endl;

	if (flag)
	{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{
			cout << "In " << ii << " th selecting stage: " << endl;
			size_t min_index = ii;

			for (size_t jj = ii + 1; jj < len; ++jj)
			{
				if (arr[jj] < arr[min_index])
				{
					min_index = jj;
					cout << "    Current min index : " << min_index << endl;
				}
			}
			swap_array(arr, ii, min_index);
			
			cout << "After " << ii + 1 << "th sorting: ";
			print_array(arr, len);
			cout << endl;
		}
	}
	else{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{
			size_t min_index = ii;

			for (size_t jj = ii + 1; jj < len; ++jj)
			{
				if (arr[jj] < arr[min_index])
				{
					min_index = jj;
				}
			}
			swap_array(arr, ii, min_index);
		}
	}

	cout << "After sorting: " << endl;
	print_array(arr, len);
	cout << endl;
	cout << "==================== Select Sort End =======================" << endl;
}


void sort_bubble(int arr[], int len, bool flag)
{
	cout << "==================== Bubble Sort Begin ======================="<<endl;

	cout << "Before sorting: " << endl;
	print_array(arr, len);
	cout << endl;

	if (flag)
	{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{	
			cout << "In " << ii << "th round sorting: " << endl;

			for (size_t jj = 0; jj < len - ii - 1; ++jj)
			{
				if (arr[jj] > arr[jj + 1])
				{
					swap_array(arr, jj, jj + 1);
					cout << "    After " << jj << "th swaping: ";
					print_array(arr, len);
				}
			}

			cout << "After " << ii << "th sorting: ";
			print_array(arr, len);
			cout << endl;
		}
	}
	else
	{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{
			for (size_t jj = 0; jj < len - ii - 1; ++jj)
			{
				if (arr[jj] > arr[jj + 1])
					swap_array(arr, jj, jj + 1);
			}
		}
	}
	cout << "After sorting: " << endl;
	print_array(arr, len);
	cout << "==================== Bubble Sort End =======================" << endl;
}


void array_restore(int arr_backup[], int arr_to_restore[], int len)
{
	for (size_t ii = 0; ii < len; ++ii)
	{
		arr_to_restore[ii] = arr_backup[ii];
	}
}

void sort_bubble_optimized(int arr[], int len, bool flag)
{
	cout << "==================== Bubble Sort Begin =======================" << endl;

	cout << "Before sorting: " << endl;
	print_array(arr, len);
	cout << endl;

	if (flag)
	{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{
			bool flag_temp = true;

			cout << "In " << ii << "th round sorting: " << endl;

			for (size_t jj = 0; jj < len - ii - 1; ++jj)
			{
				if (arr[jj] > arr[jj + 1])
				{
					swap_array(arr, jj, jj + 1);
					cout << "    After " << jj << "th swaping: ";
					print_array(arr, len);

					flag_temp = false;
				}
			}
			
			if (flag_temp)
			{
				cout << "The array is already sorted!" << endl;
				break;
			}				

			cout << "After " << ii << "th sorting: ";
			print_array(arr, len);
			cout << endl;

		}
	}
	else
	{
		for (size_t ii = 0; ii < len - 1; ++ii)
		{
			for (size_t jj = 0; jj < len - ii - 1; ++jj)
			{
				if (arr[jj] > arr[jj + 1])
					swap_array(arr, jj, jj + 1);
			}
		}
	}
	cout << "After sorting: " << endl;
	print_array(arr, len);
	cout << "==================== Bubble Sort End =======================" << endl;
}


