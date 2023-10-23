#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using shell sort
 * @array: The array of numbers
 * @size: size of the array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t range = 1;
	size_t y;
	int tmp;
	size_t x = range;

	if (!array || size < 2)
		return;

	while (range <= size / 3)
	{
		range = range * 3 + 1;
	}
	while (range  > 0)
	{
		for (x = range; x < size; x++)
		{
			tmp = array[x];
			y = x;
			while (y >= range && array[y - range] > tmp)
			{
				array[y] = array[y - range];
				y -= range;
			}
			array[y] = tmp;
		}
		print_array(array, size);
		range = (range - 1) / 3;
	}
}
