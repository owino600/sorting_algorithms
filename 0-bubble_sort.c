#include "sort.h"
/**
 * bubble_sort - sort array elements in ascending order
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, index;
	int temp;

	if (size < 2L)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (index = 0; index < size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
