#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order
 * @array: pointer to the array to sort
 * @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	unsigned int index, yndex;

	for (index = 0; index < (size - 1); index++)
	{
		swapped = 0;
		for (yndex = 0; yndex < (size - index - 1); yndex++)
		{
			if (array[yndex] > array[yndex + 1])
			{
				temp = array[yndex];
				array[yndex] = array[yndex + 1];
				array[yndex + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
