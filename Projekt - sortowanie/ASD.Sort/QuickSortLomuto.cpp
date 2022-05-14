#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int p, int r)
{
    int q = arr[r];
    int i = (p - 1);

    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= q)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int q = partition(arr, p, r);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}