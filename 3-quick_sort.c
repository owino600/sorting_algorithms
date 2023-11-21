#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array.
 * @array: The array to modify.
 * @index1: The index of the first element.
 * @index2: The index of the second element.
 */
void swap_elements(int *array, size_t index1, size_t index2)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[index1];
		array[index1] = array[index2];
		array[index2] = tmp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub-array using the
 * quicksort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t partition_index, i;
	int pivot;

	/*Base case: If the array has 0 or 1 elements, it is already sorted.*/
	if ((low >= high) || (array == NULL))
		return;

	/*choose the pivot (last element of sub-array*/
	pivot = array[high];
	partition_index = low;

	/*Iterates through sub-array*/
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (partition_index != i)
			{
				swap_elements(array, partition_index, i);
				print_array(array, size);
			}
			partition_index++;
		}
	}

	if (partition_index != high)
	{
		swap_elements(array, partition_index, high);
		print_array(array, size);/*print array after each swap*/
	}

	if (partition_index > low)
		quick_sort_range_lomuto(array, low, partition_index - 1, size);
	if (high > partition_index)
		quick_sort_range_lomuto(array, partition_index + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		/*call helper function to perform the quicksort of entire array*/
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}

