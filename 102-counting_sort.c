#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@num: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int num, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (num == 0 || size == 0)
		return (NULL);
	p = malloc(num * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (num * size); i++)
		p[i] = NULL;
	return (p);
}
/**
 * counting_sort - sorts an array of integers in ascending order.
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = NULL, *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
