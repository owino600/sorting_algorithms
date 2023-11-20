#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				swap(&array[i], &array[j]);
			}
		}
		printf(" Array after swapping is %zu:", i + 1);
		for (int k = 0; k < size; k++)
		{
			printf("%d ", array[k]);
		}
		printf("\n");
	}
}
