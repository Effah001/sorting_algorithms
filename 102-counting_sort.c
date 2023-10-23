#include "sort.h"


/**
 * counting_sort - Sort an array of integers using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{

	int max = 0, ln = 0, x = 0;
	int *count = NULL, *output = NULL;

	if (!array || size < 2)
		return;

	ln = size;
	max = array[0];
	for (x = 1; x < ln; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (x = 0; x <= max; x++)
		count[x] = 0;

	for (x = 0; x < ln; x++)
		count[array[x]]++;

	for (x = 1; x <= max; x++)
		count[x] += count[x - 1];

	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (x = size - 1; x >= 0; x--)
	{
		output[count[array[x]] - 1] = array[x];
			count[array[x]]--;
	}

	for (x = 0; x < ln; x++)
		array[x] = output[x];

	free(count);
	free(output);
}
