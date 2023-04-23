#include "sort.h"

/**
  * bubble_sort - A function for bubble sorting.
  *
  * @array: The array to be sorted.
  * @size: THe length of the aaray.
  * Return:none
  */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp = 0;

	if (array == NULL || size < 0)
		return;
	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
