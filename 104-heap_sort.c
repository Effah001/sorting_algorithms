#include "sort.h"

/**
 * sift_down - Helper function to perform sift-down operation in Heap Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @root: Index of the root element of the heap.
 */

void sift_down(int *array, size_t size, size_t root)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != root)
	{
		int temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		sift_down(array, size, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int j = size - 1;

	if (array == NULL || size < 2)
		return;

	for (; i >= 0; i--)
	{
		sift_down(array, size, i);
	}

	for (; j > 0; j--)
	{
		int temp = array[0];
		array[0] = array[j];
		array[j] = temp;
		print_array(array, size);
		sift_down(array, j, 0);
	}
}

