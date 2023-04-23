#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array.
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t i = 0, j = 0, min = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
