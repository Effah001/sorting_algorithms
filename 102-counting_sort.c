#include "sort.h"


/**
 * counting_sort - Sort an array of integers using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, i;
    int *count, *output;

    if (!array || size < 2)
        return;

    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

     for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    print_array(count, max + 1);

    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = 1; i <= max; i++)
	    count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    print_array(count, max + 1);

    free(count);
    free(output);
}
