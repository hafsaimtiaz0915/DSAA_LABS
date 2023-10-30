#include <iostream>
using namespace std;

int main()
{
    int N, k, count = 0, *arr;

    cout << "Enter the number of Toys: ";
    cin >> N;

    arr = new int[N];

    cout << "Enter your Amount: ";
    cin >> k;

    cout << "Enter the cost of Toys:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "Toy " << i + 1 << ": Rs.";
        cin >> arr[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    int index = 0;
    while (k > 0 && k >= arr[index])
    {
        k -= arr[index++];
        count++;
    }
    cout << "Maximum number of toys are: " << count << endl;
    cout << "The costs of toys you can buy within Rs." << k << " are: ";
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    return 0;
}
