#include "sort.h"

/**
* swap - swaps two values
* @a: int array
* @n: size of array
* @x: value to be swapped
* @y: value to be swapped
*/
void swap(int a[], size_t n, int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	if (*x != *y)
		print_array(a, n);
}

/**
* partition - arranges values from low numbers to high values
* with a pivot splitting the two sides
* @a: array
* @n: size of array
* @start: first value of array
* @end: last value of array
* Return: pivot index
*/
size_t partition(int a[], size_t n, int start, int end)
{
	int pivot = a[end];
	int j = start - 1;
	int i;

	for (i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			j++;
			swap(a, n, &a[i], &a[j]);
		}
	}
	swap(a, n, &a[j + 1], &a[end]);
	return (j + 1);
}

/**
* quicksort_proper - performs quicksort
* @a: array
* @n: size of array
* @start: first value of array
* @end: last value of array
*/
void quicksort_proper(int a[], size_t n, int start, int end)
{
	if (start < end)
	{
		int pIndex = partition(a, n, start, end);

		quicksort_proper(a, n, start, pIndex - 1);
		quicksort_proper(a, n, pIndex + 1, end);
	}
}

/**
* quick_sort - calls quicksort_proper with required arguments
* @array: array
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	quicksort_proper(array, size, 0, size - 1);
}
