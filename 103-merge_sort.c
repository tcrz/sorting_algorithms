#include "sort.h"

/**
 * merge - mereg the divided arrays into new array
 * @arr : the array to be sorted
 * @lb: lower boundary
 * @mid: the middle element of the array
 * @ub: upper boundary
 * @b: the copy array
 */

void merge(int arr[], int lb, int mid, int ub, int b[])
{
	int i, j, k;
	i = lb;
	k = lb;
	j = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(b + ub, mid - lb);
	printf("[right]: ");
	print_array(b + mid, lb - mid);
	while (i <= mid - 1 && j <= ub)
	{
		if (arr[i] <= arr[j])
		{
			b[k] = arr[i];
			i++;
		}
		else
		{
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > mid - 1)
	{
		while (j <= ub)
		{
			b[k] = arr[j];
			k++;
			j++;
		}
	}
	else if (j > ub)
	{
		while (i <= mid - 1)
		{
			b[k] = arr[i];
			k++;
			i++;
		}
		for (k = lb; k <= ub; k++)
			arr[k] = b[k];
	}
	printf("[Done]: ");
	print_array(b + lb, ub - lb);
}

/**
 * mergesort_main - to divide and array until it single element
 * @arr: array
 * @lb: lower boundary
 * @ub: upper boundary
 * @b: copy of array
 */

void mergesort_main(int arr[], int lb, int ub, int b[])
{
	int i;
	int mid;
	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		mergesort_main(arr, lb, mid - 1, b);
		mergesort_main(arr, mid, ub, b);
		merge(arr, lb, mid, ub, b);
		for (i = lb; i < ub; i++)
			b[i] = arr[i];
	}
}

/**
 * merge_sort - to sort array using merge sort
 * @array: array to be sorted
 * @size: the size of array
 */

void merge_sort(int *array, size_t size)
{
	int *b;
	int nb;
	int i;
	nb = size;
	if (array == NULL || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;
	for (i = 0; i < nb; i++)
		b[i] = array[i];
	nb = nb - 1;
	mergesort_main(array, 0, nb, b);
	free(b);
}
