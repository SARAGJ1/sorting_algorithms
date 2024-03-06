#include "sort.h"

/**
 * swap - swap two elements in an array
 *
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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
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
 *
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
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto(array, size, 0, size - 1);
}
