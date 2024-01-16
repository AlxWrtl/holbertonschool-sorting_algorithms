#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t index, yndex, min_index;
	int temp;

	for (index = 0; index < (size - 1); index++)
	{
		min_index = index;
		for (yndex = index + 1; yndex < size; yndex++)
		{
			if (array[yndex] < array[min_index])
				min_index = yndex;
		}
		if (min_index != index)
		{
			temp = array[min_index];
			array[min_index] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
