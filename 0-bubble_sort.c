#include "sort.h"

/**
* bubble_sort - compares adjacent elements and swaps them
* if they are in the wrong order
* @array: array of integers
* @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, y;

	for (i = 0; i < size; i++)
	{
		for (y = 0; y < size - i - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
