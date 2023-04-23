#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@num1: array element
*@num2: array element
*/
void swap(int *array, int num1, int num2)
{

	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: the array to be sorted.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
