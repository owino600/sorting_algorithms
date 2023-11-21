#include "sort.h"
size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot;
	size_t i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
}

void quick_sort_helper(int *array, size_t low, size_t high)
{
	size_t _index, i;

	if (low < high)
	{
		_index = lomuto_partition(array, low, high);

		printf("Array after swapping: ");
		for (i = low; i <= high; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");

		quick_sort_helper(array, low, _index - 1);
		quick_sort_helper(array, _index + 1, high);
	}
}

void quick_sort(int *array, size_t size) {
	if (size > 0) {
		quick_sort_helper(array, 0, size - 1);
	}
}
