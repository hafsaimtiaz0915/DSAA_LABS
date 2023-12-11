#include <iostream>
using namespace std;

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high)
{
    int p = arr[high]; // Choosing the pivot element (here, the last element)
    int i = low - 1;   // Index of smaller element

    // Traverse through the array
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            // Swap elements to move smaller elements to the left of the pivot
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot element at its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partitioning index
}

// Function to perform Quick Sort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the partitioning index
        int p = partition(arr, low, high);

        // Sort elements before and after the partition recursively
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
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

    quicksort(arr, 0, size - 1);

    cout << "\n\tSorted array(ascending order):\n\t ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }

    delete[] arr;
    return 0;
}