#include "sort.h"

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	sort_partition(array, size, 0, size - 1);
}
void sort_partition(int *array, int size, int first, int last)
{
	int pivot = 0;

	if (first < last)
	{
		pivot = get_pivot_index(array, size, first, last);
		if (pivot - first > 1)
		{
			sort_partition(array, size, first, pivot - 1);
		}
		if (last - pivot > 1)
		{
			sort_partition(array, size, pivot + 1, last);
		}
	}
}
void swap(int **array, int first_index, int second_index)
{
	int temp = 0;

	temp = (*array)[first_index];
	(*array)[first_index] = (*array)[second_index];
	(*array)[second_index] = temp;
}
int get_pivot_index(int *array, size_t size, int first, int last)
{
	int pivot = 0;
	int left = 0, new_pivot = 0;

	pivot = last;
	left = first;
	new_pivot = first - 1;

	for (; left < last; left++)
	{
		if (array[left] <= array[pivot])
		{
			new_pivot++;
			if (new_pivot != left)
			{
				swap(&array, new_pivot, left);
				print_array(array, size);
			}
		}
	}
	if ((new_pivot + 1) != last)
	{
		swap(&array, new_pivot + 1, last);
		print_array(array, size);
	}
	return (new_pivot + 1);
}
