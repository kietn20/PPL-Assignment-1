#include <stdio.h>
#include <stdlib.h>

// Quick sort algorithm
void swap(int *a, int *b);
void quick_sort(int *a, int n);
void quick_sort_helper(int *a, int low, int high);
int partition(int *a, int low, int high);

// Merge sort algorithm
void merge_sort(int *a, int n);
void merge_sort_helper(int *a, int left, int right);
void merge(int *a, int left, int mid, int right);

int main()
{
    printf("Quick sort algorithm\n");
    int a[] = {38, 27, 43, 3, 9, 82, 10, 4, 6, 7, 12, 15, 18, 20, 22, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Merge sort algorithm\n");
    int b[] = {38, 27, 43, 3, 9, 82, 10, 4, 6, 7, 12, 15, 18, 20, 22, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int m = sizeof(b) / sizeof(b[0]);
    merge_sort(b, m);
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);
    printf("\n");

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

void merge_sort(int *a, int n)
{
    merge_sort_helper(a, 0, n - 1);
}

void merge_sort_helper(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_helper(a, left, mid);
        merge_sort_helper(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int *a, int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;

    // dynamically allocate temp arrays to store the left and right subarrays
    int *temp_left = (int *)malloc(left_length * sizeof(int));
    int *temp_right = (int *)malloc(right_length * sizeof(int));

    // Copy data to temp arrays to be merged
    for (int i = 0; i < left_length; i++)
        temp_left[i] = a[left + i];
    for (int j = 0; j < right_length; j++)
        temp_right[j] = a[mid + 1 + j];

    // Initial index of temp_left, temp_right, and merged subarrays
    int i = 0, j = 0, k = left;
    while (i < left_length && j < right_length)
    {
        // determine which element (smallest value) to add to the merged array
        if (temp_left[i] <= temp_right[j]) //
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of temp_left array
    while (i < left_length)
    {
        a[k] = temp_left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of temp_right array
    while (j < right_length)
    {
        a[k] = temp_right[j];
        j++;
        k++;
    }

    free(temp_left);
    free(temp_right);
}