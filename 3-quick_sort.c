#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array.
 * @array: Pointer to the array where the swap will occur.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @size: Size of the array.
 *
 * Description: This function swaps the values of the two elements
 *              at indices i and j in the array. A temporary variable
 *              is used to facilitate the swap. If a swap occurs,
 *              the array is printed.
 */
void swap_elements(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * partition - Partitions an integer array using the Lomuto partition scheme.
 * @array: Pointer to the integer array to be partitioned.
 * @start: Starting index of the range to be partitioned.
 * @end: Ending index of the range to be partitioned.
 * @size: Size of the array.
 * Return: The final index of the pivot.
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start;

	for (int j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			swap_elements(array, i, j, size);
			i++;
		}
	}

	swap_elements(array, i, end, size);
	return i;
}

/**
 * recursive_quick_sort - Applies Quick Sort algorithm recursively.
 * @array: The array to sort.
 * @start_index: Starting index for the current partition.
 * @end_index: Ending index for the current partition.
 * @size: Size of the entire array.
 *
 * Description: This function recursively sorts parts of the array
 *              using the Quick Sort algorithm. It divides the array
 *              into partitions, then sorts each partition recursively.
 */
void recursive_quick_sort(int *array, int start_index, int end_index, size_t size)
{
	if (start_index < end_index)
	{
		int pivot_index = partition(array, start_index, end_index, size);
		recursive_quick_sort(array, start_index, pivot_index - 1, size);
		recursive_quick_sort(array, pivot_index + 1, end_index, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}
