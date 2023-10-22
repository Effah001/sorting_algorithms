#include "sort.h"

/**
 * quick_sort- sorts the array in asceding order
 * using quick sort
 * @array: The array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	lomuto_part(array, size, 0, size - 1);
	print_array(array, size);

	quick_sort(array, size / 2);
	quick_sort(array + size / 2, size - size / 2);
}

/**
 * lomuto_part - partitions the array using lomuto partition
 * @array: The array to be partitioned
 * @size: size of the array
 * @min: starting index
 * @max: Ending index
 * Return: Index of the pivot element
 */

int lomuto_part(int *array, size_t size, int min, int max)
{
	int pivot = array[max];
	int j = min - 1;
	int i = min;

	for (; i <= max - 1; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			swap(&array[j], &array[i]);
		}
	}

	swap(&array[j + 1], &array[max]);
	return (j + 1);
}

/**
 * swap - swaps two integers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
