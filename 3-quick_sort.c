#include "sort.h"

/**
 * swap - swap two elements in an array
 * @x: elem to swap with y
 * @y: elem to swap with x
 */
void swap(int *x, int *y)
{
	int k = *x;

	*x = *y;
	*y = k;
}
/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: the index of the first element of the partition
 * @right: the index of the last element of the partition
 *
 * return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, i, j;

	pivot = array + right;
	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}
/**
 * lomuto - Recursive function to implement Quick Sort
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: the index of the first element of the partition
 * @right: the index of the last element of the partition
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto(array, size, left, part - 1);
		lomuto(array, size, part + 1, right);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto(array, size, 0, size - 1);
}
