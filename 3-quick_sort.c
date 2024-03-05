#include "sort.h"

/**
 * swap - swap two elements in an array
 * @x: elem to swap with y
 * @y: elem to swap with x
 * @k: temp elem
 *
 */
void swap(int *x, int *y) {
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
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
int lomuto_partition(int *array, size_t size, int left, int right) {
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++){
		if (array[below] < *pivot) {
			if (above < below) {
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot) {
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}
/**
 * lomuto - Recursive function to implement Quick Sort
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: the index of the first element of the partition
 * @right: the index of the last element of the partition
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void lomuto(int *array, size_t size, int left, int right) {
	int part;

	if (right - left > 0) {
		part = lomuto_partition(array, size, left, right);
		lomuto(array, size, left, part - 1);
		lomuto(array, size, part + 1, right);
	}
}
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size) {
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto(array, size, 0, size - 1);
}
