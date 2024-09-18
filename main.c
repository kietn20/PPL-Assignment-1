#include <stdio.h>

// Quick sort algorithm
void swap(int *a, int *b);
void quick_sort(int *a, int n);
void quick_sort_helper(int *a, int low, int high);
int partition(int *a, int low, int high);

// Merge sort algorithm

int main()
{
    printf("Quick sort algorithm\n");
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Merge sort algorithm\n");
    // ...
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *a, int length)
{
    quick_sort_helper(a, 0, length - 1);
}

void quick_sort_helper(int *a, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(a, low, high);
        quick_sort_helper(a, low, pivot_index - 1);
        quick_sort_helper(a, pivot_index + 1, high);
    }
}

int partition(int *a, int low, int high)
{
    int pivot_value = a[low];

    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (a[j] < pivot_value)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[low], &a[i - 1]);
    return i - 1;
}