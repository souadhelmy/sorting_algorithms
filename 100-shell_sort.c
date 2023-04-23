#include "sort.h"

/**
  * shell_sort - sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 0;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp;
					j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != tmp)
				array[j] = tmp;

		}
		print_array(array, size);
	}
}
