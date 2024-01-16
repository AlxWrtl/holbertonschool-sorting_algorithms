#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array.
 * @element1: Pointer to the first element.
 * @element2: Pointer to the second element.
 *
 * Description: This function swaps the values of the two elements
 *              pointed by element1 and element2. A temporary variable
 *              is used to facilitate the swap.
 */
void swap_elements(int *element1, int *element2)
{
	int temp = *element1;  /* Temporary storage for the first element */
	*element1 = *element2; /* Assign second element's value to first */
	*element2 = temp;	   /* Assign stored first element's value to second */
}

/**
 * partition_array - Partitions an array using the Lomuto scheme.
 * @array: The array to be partitioned.
 * @start_index: The starting index of the partition.
 * @end_index: The ending index of the partition.
 * @size: The total size of the array.
 *
 * Description: This function implements the Lomuto partition scheme,
 *              which is used in the Quick Sort algorithm. It reorders
 *              the elements in the array such that elements less than
 *              the pivot are on the left, and others are on the right.
 *
 * Return: The partition index where the array is divided.
 */
int partition_array(int *array, int start_index, int end_index, size_t size)
{
	int pivot = array[end_index];	   /* Pivot element */
	int partition_index = start_index; /* Partitioning index */

	for (int j = start_index; j < end_index; j++)
	{
		/* If current element is smaller than the pivot */
		if (array[j] < pivot)
		{
			swap_elements(&array[partition_index], &array[j]);
			/* Print array if elements are swapped */
			if (partition_index != j)
			{
				print_array(array, size);
			}
			partition_index++; /* Move partition index */
		}
	}
	/* Swap pivot into its correct position */
	swap_elements(&array[partition_index], &array[end_index]);
	/* Print array if pivot is moved */
	if (partition_index != end_index)
	{
		print_array(array, size);
	}
	return (partition_index); /* Return partition index */
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
void recursive_quick_sort(
	int *array, int start_index, int end_index, size_t size)
{
	/* Only sort if start index is less than end index */
	if (start_index < end_index)
	{
		int pivot_index = partition_array(array, start_index, end_index, size);

		recursive_quick_sort(array, start_index, pivot_index - 1, size);
		recursive_quick_sort(array, pivot_index + 1, end_index, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function is an entry point to the Quick Sort algorithm.
 *              It checks if the array is not NULL and if the size is suitable
 *              for sorting (i.e., more than one element). If these conditions
 *              are met, it calls the recursive_quick_sort function to perform
 *              the sorting process.
 *
 * Note: The function does not return any value. The sorting is performed
 *       in-place, modifying the original array.
 */
void quick_sort(int *array, size_t size)
{
	/* Check for null array or insufficient size */
	if (array == NULL || size < 2)
		return; /* No action needed for empty or single-element array */

	/* Begin recursive Quick Sort on the entire array */
	recursive_quick_sort(array, 0, size - 1, size);
}
