#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers x and y
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: is the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;


	for (i = 0; i < size; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
