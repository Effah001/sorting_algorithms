#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the Bubble sort algorithm.
 * @array: The array to be sorted
 * @size: Size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp;
	int swpd;

	for (x = 0; x < size - 1; x++)
	{
		swpd = 0;
		for (y = 0 ; y < size - x - 1; ++y)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;

				swpd = 1;

				print_array(array, size);
			}
		}
		if (swpd == 0)
		break;
	}
}
