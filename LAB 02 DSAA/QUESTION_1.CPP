#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    int swap_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap_count += 1;
            }
        }
    }
    if (swap_count == 0)
    {
        cout << "Array is already sorted..." << endl;
    }
    else
    {
        cout << "Array is not sorted..." << endl;
        cout << "Sorted array: \n";
        printArray(arr, n);
    }
}
int main()
{
    int arr[] = {2, 9, 6, 6, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);

    return 0;
}
