#include "sort.h"

/**
 * knuth - using the kunth sequence to get the gap
 * @n: size of array
 * Return: the value of kunth sequence
 */
int knuth(size_t n)
{
size_t gap = 1;
int m;

while (gap < n)
{
gap = gap * 3 + 1;
}
gap /= 3;
m = gap;
return (m);
}
/**
 * swap - swaps two values
 * @x: the first value
 * @y: the second value
 * Return: nothing
 */
void swap(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}

/**
 * shell_sort - perform shell sort
 * @array: array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
int gap;
int i, j;
int siz = size;

for (gap = knuth(size); gap >= 1; gap = knuth(gap))
{
for (j = gap; j < siz; j++)
{
for (i = j - gap; i >= 0; i -= gap)
{
if (array[i + gap] >= array[i])
break;
else
{
swap(&array[i + gap], &array[i]);
}
}
}
print_array(array, size);
}
}
