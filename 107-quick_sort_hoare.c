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
	print_array(a, n);
}

/**
* partition_hoare - partitions using hoare method
* with a pivot splitting the two sides
* @a: array
* @n: size of array
* @lo: first value of array
* @hi: last value of array
* Return: pivot index
*/
int partition_hoare(int a[], size_t n, int lo, int hi)
{
	int pivot = a[hi];
	int i = lo;
	int j = hi;

	while (1)
	{
		while (a[i] < pivot)
			i++;

		while (a[j] > pivot)
			j--;
		if (i < j)
			swap(a, n, &a[i], &a[j]);
		else
			return (i);

		i++;
		j--;
	}
}


/**
* qs - performs quicksort with hoare partition
* @arr: array
* @n: size of array
* @low: first value of array
* @high: last value of array
*/
void qs(int arr[], size_t n, int low, int high)
{
	if (low < high)
	{
		int pivot = partition_hoare(arr, n, low, high);

		qs(arr, n, low, pivot - 1);
		qs(arr, n, pivot, high);
	}
}

/**
* quick_sort_hoare - calls quicksort_proper with required arguments
* @array: array
* @size: size of array
*/
void quick_sort_hoare(int array[], size_t size)
{
	qs(array, size, 0, size - 1);
}
