#include "sort.h"
/**
* swap - Swaps two integers in an array
* @a: The first integer
* @b: The second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/**
* lomuto_partition - Partitions the array using the Lomuto scheme
* @array: The array to partition
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*
* Return: The final partition index
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size); /* Print after every swap */
}
}
}
if (array[high] != array[i + 1])
{
swap(&array[i + 1], &array[high]);
print_array(array, size); /* Print after the final pivot swap */
}
return (i + 1);
}
/**
* quicksort - Recursively applies Quick Sort to the array
* @array: The array to sort
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*/
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_idx = lomuto_partition(array, low, high, size);
quicksort(array, low, pivot_idx - 1, size);
quicksort(array, pivot_idx + 1, high, size);
}
}
/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
quicksort(array, 0, size - 1, size);
}
