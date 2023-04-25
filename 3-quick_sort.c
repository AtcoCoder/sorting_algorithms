#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integer x and y
 *
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
 * quick_sort - sorts an array of integers in ascending order using quick sort
 *
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;

	sorter(array, low, high, size);
}


/**
 * sorter - performs the recursive operation for the quick_sort function
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void sorter(int *array, int low, int high, size_t size)
{
	int p;

	if (low >= high || low < 0)
	{
		return;
	}
	p = partition(array, low, high, size);
	sorter(array, low, p - 1, size);
	sorter(array, p + 1, high, size);
}

/**
 * partition - algorithm for the quicksort function
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i = i + 1;

	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
