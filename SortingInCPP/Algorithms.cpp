#include"Algorithms.h"

// ============================ Template Functions =============================
template<typename T>
void swap_array(T ptr[], size_t index_ii, size_t index_jj)
{
	T temp = 0;
	temp = ptr[index_ii];
	ptr[index_ii] = ptr[index_jj];
	ptr[index_jj] = temp;
}
template void swap_array(int ptr[], size_t index_ii, size_t index_jj);
template void swap_array(float ptr[], size_t index_ii, size_t index_jj);
template void swap_array(double ptr[], size_t index_ii, size_t index_jj);
template void swap_array(char ptr[], size_t index_ii, size_t index_jj);

template<typename T>
void print_array(T arr[], size_t len)
{
	for (size_t ii = 0; ii < len; ++ii)
	{
		cout << arr[ii] << " ";
	}
	cout << endl;
}
template void print_array(int arr[], size_t len);
template void print_array(float arr[], size_t len);
template void print_array(double arr[], size_t len);
template void print_array(char arr[], size_t len);

template<typename T>
void array_restore(T arr_backup[], T arr_to_restore[], size_t len)
{
	for (size_t ii = 0; ii < len; ++ii)
	{
		arr_to_restore[ii] = arr_backup[ii];
	}
}
template void array_restore(int arr_backup[], int arr_to_restore[], size_t len);
template void array_restore(float arr_backup[], float arr_to_restore[], size_t len);
template void array_restore(double arr_backup[], double arr_to_restore[], size_t len);
template void array_restore(char arr_backup[], char arr_to_restore[], size_t len);


template<typename T>
void sort_select(T arr[], size_t len, bool flag)
{
	cout << "==================== Select Sort Begin =======================" << endl;

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
template void sort_select(int arr[], size_t len, bool flag);
template void sort_select(float arr[], size_t len, bool flag);
template void sort_select(double arr[], size_t len, bool flag);


template<typename T>
void sort_bubble(T arr[], size_t len, bool flag)
{
	cout << "==================== Bubble Sort Begin =======================" << endl;

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
template void sort_bubble(int arr[], size_t len, bool flag);
template void sort_bubble(float arr[], size_t len, bool flag);
template void sort_bubble(double arr[], size_t len, bool flag);

template<typename T>
void sort_bubble_optimized(T arr[], size_t len, bool flag)
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
void sort_bubble_optimized(int arr[], size_t len, bool flag);
void sort_bubble_optimized(float arr[], size_t len, bool flag);
void sort_bubble_optimized(double arr[], size_t len, bool flag);


template<typename T>
void sort_shell(T arr[], int len, bool flag)
{
	cout << "==================== Insert Sort Begin =======================" << endl;

	cout << "Before sorting: " << endl;
	print_array(arr, len);
	cout << endl;

	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		cout << "*************** Begin of " << gap << "th gap" << " ***************" << endl;

		for (int ii = gap; ii < len; ii++)
		{
			cout << "Current group " << ii << ": " << endl;

			T inserted = arr[ii];

			int jj = ii - gap;

			cout << "jj = " << jj << endl;

			for (; jj >= 0 && inserted < arr[jj]; jj -= gap)
			{
				arr[jj + gap] = arr[jj];
				cout << "After " << jj << "th move: ";
				print_array(arr, len);
			}
			cout << "jj = " << jj << endl;
			arr[jj + gap] = inserted;

			cout << "After " << ii << "th insertion: ";
			print_array(arr, len);
			cout << endl;
		}
		cout << "*************** End of " << gap << "th gap" << "***************" << endl << endl;
	}

	cout << "After sorting: " << endl;
	print_array(arr, len);
	cout << endl;
	cout << "==================== Insert Sort End =======================" << endl;
}
template void sort_shell(int arr[], int len, bool flag);
template void sort_shell(float arr[], int len, bool flag);
template void sort_shell(double arr[], int len, bool flag);

template<typename T>
void sort_insert(T arr[], size_t len, bool flag)
{
	cout << "==================== Insert Sort Begin =======================" << endl;

	cout << "Before sorting: " << endl;
	print_array(arr, len);
	cout << endl;

	for (size_t ii = 1; ii < len; ++ii)
	{
		T inserted = arr[ii];
		cout << "Current number to insert: " << inserted << endl;

		size_t jj = ii - 1;

		for (; jj >= 0 && arr[jj] > inserted; jj--)
		{
			arr[jj + 1] = arr[jj];

			cout << "After move: ";
			print_array(arr, len);
		}

		arr[jj + 1] = inserted;

		cout << "After " << ii << "th " << "sorting: ";
		print_array(arr, len);
		cout << endl;
	}

	cout << "After sorting: " << endl;
	print_array(arr, len);
	cout << endl;
	cout << "==================== Insert Sort End =======================" << endl;
}
template void sort_insert(int arr[], size_t len, bool flag);
template void sort_insert(float arr[], size_t len, bool flag);
template void sort_insert(double arr[], size_t len, bool flag);


/**
* ϣ������C++
*
* @author skywang
* @date 2014/03/11
*/

#include <iostream>
using namespace std;

/*
* ϣ������
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void shellSort1(int* a, int n)
{
	int i, j, gap;

	// gapΪ������ÿ�μ�Ϊԭ����һ�롣
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				// ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
				if (a[j] < a[j - gap])
				{
					int tmp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > tmp)
					{
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = tmp;
				}
			}
		}

	}
}

/*
* ��ϣ�������еĵ������������
*
* ����˵����
*     a -- �����������
*     n -- �����ܵĳ���
*     i -- �����ʼλ��
*     gap -- ��Ĳ���
*
*  ����"��i��ʼ�������gap���ȵ�����ȡ��"����ɵģ�
*/
void groupSort(int* a, int n, int i, int gap)
{
	int j;

	for (j = i + gap; j < n; j += gap)
	{
		// ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
		if (a[j] < a[j - gap])
		{
			int tmp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k] > tmp)
			{
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap] = tmp;
		}
	}
}

/*
* ϣ������
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void shellSort2(int* a, int n)
{
	int i, gap;

	// gapΪ������ÿ�μ�Ϊԭ����һ�롣
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
		for (i = 0; i < gap; i++)
			groupSort(a, n, i, gap);
	}
}

