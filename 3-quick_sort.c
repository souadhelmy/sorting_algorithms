#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order.
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lower, int higher, size_t size)
{
        int i = lower - 1, j = lower;
        int axis = array[higher], tmp = 0;

        for (; j < higher; j++)
        {
                if (array[j] < axis)
                {
                        i++;
                        if (array[i] != array[j])
                        {
                                tmp = array[i];
                                array[i] = array[j];
                                array[j] = tmp;
                                print_array(array, size);
                        }
                }
	    }
        if (array[i + 1] != array[higher])
        {
                tmp = array[i + 1];
                array[i + 1] = array[higher];
                array[higher] = tmp;
                print_array(array, size);
        }
        return (i + 1);
}
void quick_s(int *array, int lower, int higher, size_t size)
{
        int axis;

        if (lower < higher)
        {
                axis = partition(array, lower, higher, size);
                quick_s(array, lower, axis - 1, size);
                quick_s(array, axis + 1, higher, size);
        }
}
