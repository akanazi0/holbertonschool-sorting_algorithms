#include "sort.h"

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array of integers to partition
 * @size: size of the array
 * @low: starting index of partition
 * @high: ending index of partition
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_range - recursively sorts partition ranges using Quick sort
 * @array: array of integers
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 */
void quick_sort_range(int *array, size_t size, int low, int high)
{
	int p_idx;

	if (low < high)
	{
		p_idx = lomuto_partition(array, size, low, high);
		quick_sort_range(array, size, low, p_idx - 1);
		quick_sort_range(array, size, p_idx + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_range(array, size, 0, (int)size - 1);
}
