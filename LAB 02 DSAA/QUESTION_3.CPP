#include <iostream>
using namespace std;

int main()
{
    int N, k, count = 0;

    cout << "Enter the number of Toys: ";
    cin >> N;

    int arr[N];

    cout << "Enter your Amount: ";
    cin >> k;

    cout << "Enter the cost of Toys:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "Toy " << i + 1 << ": Rs.";
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }

    cout << "Maximum number of toys you can buy with Rs." << k << " are " << count << endl;

    return 0;
}