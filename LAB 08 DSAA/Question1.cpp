#include <iostream>
using namespace std;

// Function to merge two subarrays of arr[]
// First subarray is arr[l..mid]
// Second subarray is arr[mid+1..r]
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1; // Calculate sizes of the subarrays
    int n2 = r - mid;

    int a1[n1], a2[n2]; // Create temporary arrays for the subarrays

    // Copy data to temporary arrays a1[] and a2[]
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = l; // Initial index of merged subarray

    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a1[], if any
    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of a2[], if any
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2; // Find the middle point

        // Recursive calls to divide the array into subarrays
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, mid, r);
    }
}
template <class T>
void takeInput(T &refrence)
{
    cin >> refrence;
    while (!cin)
    {
        cout << "Invalid Input, Try Again: ";
        cin.clear();
        fflush(stdin);
        cin >> refrence;
    }
}

int main()
{
    int size = 0;
    int *arr;
    for (int i = 0; size < 1; i++)
    {
        cout << "\n\tEnter the size of the array: ";
        takeInput(size);
        if (size < 1)
        {
            cout << "\n\tInvalid size entered. Please enter a valid positive integer." << endl;
        }
    }

    arr = new int[size];

    cout << "\n\tEnter elements(int) for the array" << endl;
    for (int j = 0; j < size; j++)
    {
        cout << "\n\tEnter " << j + 1 << " element(int) :";
        takeInput(arr[j]);
    }

    mergesort(arr, 0, size - 1);

    cout << "\n\tSorted array(ascending order):\n\t ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }

    delete[] arr;
    return 0;
}
