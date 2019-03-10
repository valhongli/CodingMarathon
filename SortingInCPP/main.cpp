#include "Algorithms.h"


int main()
{
	int array_to_sort[] = { 2, 8, 1, 9, 7, 6, 4, 3 };
	int array_backup[] = { 2, 8, 1, 9, 7, 6, 4, 3 };

	//int array_to_sort[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int array_backup[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	size_t len = sizeof(array_to_sort) / sizeof(int);

	cout << "Please select the sorting method: " << endl;
	cout << "1. Select Sort.\n2. Bubble Sort.\n3. Insert Sort.\n4. Shell Sort.\n";

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
		case 3:
			sort_insert(array_to_sort, len, true);
		case 4:
			sort_shell(array_to_sort, int(len), true);
		default:
			break;
		}

		array_restore(array_backup, array_to_sort, len);
		method = 0;
	}

	_getch();
	return 0;
}
