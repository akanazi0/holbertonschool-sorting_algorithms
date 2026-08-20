#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the bubble sort algorithm
 * @array: the array to be sorted
 * @size: the number of elements in @array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i,j;
	int tmp = 0;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
			}

			print_array(array, size);
	    }

	}
}
