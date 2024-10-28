#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int n, int find)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid index

        if (arr[mid] == find)
        {
            return mid; // Target found
        }
        else if (arr[mid] < find)
        {
            left = mid + 1; // Ignore left half
        }
        else
        {
            right = mid - 1; // Ignore right half
        }
    }

    return -1; // Target not found
}

// Main function
int main()
{
    int n, find;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Sorting the array using Bubble Sort
    bubbleSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the element to find: ");
    scanf("%d", &find);

    // Performing Binary Search
    int result = binarySearch(a, n, find);

    if (result != -1)
    {
        printf("Entered element is present at index %d\n", result);
    }
    else
    {
        printf("Entered element is not present\n");
    }

    return 0;
}
