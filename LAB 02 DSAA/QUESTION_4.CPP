#include <iostream>
#include <vector>
using namespace std;
class sort
{
    vector<int> arr;
    int size;
    int total_swap, total_comparison;
    string bestTechnique, worstTechnique;
    int bestComparison, worstComparison;
    int bestSwap, worstSwap;

public:
    sort()
    {
        size = 0;
        total_swap = 0;
        total_comparison = 0;
        bestTechnique = "";
        worstTechnique = "";
        bestComparison = -1;
        worstComparison = -1;
        bestSwap = -1;
        worstSwap = -1;
    }
    sort(vector<int> &arr) : arr(arr)
    {
        size = arr.size();
        total_swap = 0;
        total_comparison = 0;
        bestTechnique = "";
        worstTechnique = "";
        bestComparison = -1;
        worstComparison = -1;
        bestSwap = -1;
        worstSwap = -1;
    }

    void generateRandomArray(int size)
    {

        for (int i = 0; i < size; i++)
        {
            arr.push_back(rand() % 10 + 1);
        }
        this->size = size;
    }
    void swap(int *var1, int *var2)
    {
        int temp = *var1;
        *var1 = *var2;
        *var2 = temp;
    }
    void displayArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Analysis(string technique, int comparison, int swap)
    {
        if (bestComparison == -1 || comparison < bestComparison)
        {
            if (bestSwap == -1 || swap < bestSwap)
            {
                bestTechnique = technique;
                bestComparison = comparison;
                bestSwap = swap;
              
            }
        }
       else if (worstComparison == -1 || comparison > worstComparison)
        {
            if (worstSwap == -1 || swap < worstSwap)
            {
                worstComparison = comparison;
                worstTechnique = technique;
                worstSwap = swap;
            }
        }
    }
    void BestAndWorseTechnique()
    {
        cout << "Best Technique: " << bestTechnique << endl;
        cout << "Worst Technique: " << worstTechnique << endl;
    }
    void SelectionSort(bool flag)
    {
        total_swap = 0;
        total_comparison = 0;
        int min;
        vector<int> temp = arr;
        for (int i = 0; i < size - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                total_comparison++;
                if (temp[min] > temp[j])
                {
                    min = j;
                }
            }

            if (min != i)
            {
                swap(&temp[i], &temp[min]);
                total_swap++;
            }
        }
        Analysis("SelectionSort", total_comparison, total_swap);
        if (flag)
        {
            cout << "****"
                 << "SelectionSort"
                 << "*****";
            cout << "\nTotal Comparisons: " << total_comparison;
            cout << "\nTotal Swap:" << total_swap << endl;
        }
    }
    void BubbleSort(bool flag)
    {
        vector<int> temp = arr;
        total_swap = 0;
        total_comparison = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                total_comparison++;
                if (temp[j] > temp[j + 1])
                {
                    swap(&temp[j], &temp[j + 1]);
                    total_swap++;
                }
            }
        }
        Analysis("BubbleSort", total_comparison, total_swap);
        if (flag)
        {
            cout << "****"
                 << "BubbleSort"
                 << "*****";
            cout << "\nTotal Comparisons: " << total_comparison;
            cout << "\nTotal Swap:" << total_swap << endl;
        }
    }
    void InsertionSort(bool flag)
    {
        vector<int> temp = arr;
        total_swap = 0;
        total_comparison = 0;
        int key, j;
        for (int i = 1; i < size; i++)
        {
            key = temp[i];
            j = i - 1;
            while (j >= 0 && temp[j] > key)
            {
                total_comparison++;
                temp[j + 1] = temp[j];
                j--;
                total_swap++;
            }
            temp[j + 1] = key;
        }

        Analysis("InsertionSort", total_comparison, total_swap);
        if (flag)
        {
            cout << "****"
                 << "InsertionSort"
                 << "*****";
            cout << "\nTotal Comparisons: " << total_comparison;
            cout << "\nTotal Swap:" << total_swap << endl;
        }
        arr = temp;
    }
};

int main()
{
    vector<int> arr = {12, 4, 6, 7, 1};
    sort obj1;
    int choice;
    int size;
    cout << "Select your sort technique\n1)Selection Sort\n2)Insertion sort\n3)BubbleSort" << endl;
    cin >> choice;
    cout << "Enter size of array:";
    cin >> size;
    switch (choice)
    {
    case 1:
        obj1.generateRandomArray(size);
        obj1.displayArray();
        obj1.SelectionSort(true);
        obj1.BubbleSort(false);
        obj1.InsertionSort(false);
        cout << "After Sorting" << endl;
        obj1.displayArray();
        obj1.BestAndWorseTechnique();
        break;

    case 2:
        obj1.generateRandomArray(size);
        obj1.displayArray();
        obj1.SelectionSort(false);
        obj1.BubbleSort(false);
        obj1.InsertionSort(true);
        cout << "After Sorting" << endl;
        obj1.displayArray();
        obj1.BestAndWorseTechnique();
        break;

    case 3:
        obj1.generateRandomArray(size);
        obj1.SelectionSort(false);
        obj1.BubbleSort(true);
        obj1.InsertionSort(false);
        cout << "After Sorting" << endl;
        obj1.displayArray();
        obj1.BestAndWorseTechnique();
        break;
    }
}
