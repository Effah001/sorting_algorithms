#include "sort.h"

/**
 * selection_sort - sorts array of integers using selection sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t x = 0, y = 0, min;
	int temp;

	for (; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
			{
				min = y;
			}
		}

		if (min != x)
		{
			temp = array[x];
			array[x] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
	}
}
