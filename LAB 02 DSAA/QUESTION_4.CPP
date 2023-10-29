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
    void displaySortedArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Analysis(string technique, int comparison, int swap)
    {
        cout << "****" << technique << "*****";
        cout << "\nTotal Comparisons: " << comparison;
        cout << "\nTotal Swap:" << swap << endl;
        if (bestComparison == -1 || comparison < bestComparison)
        {
            bestTechnique = technique;
            bestComparison = comparison;
        }
        if (worstComparison == -1 || comparison > worstComparison)
        {
            worstComparison = comparison;
            worstTechnique = technique;
        }
    }
    void BestAndWorseTechnique()
    {
        cout << "Best Technique: " << bestTechnique << endl;
        cout << "Worst Technique: " << worstTechnique << endl;
    }
    void SelectionSort()
    {
        int min;
        for (int i = 0; i < size - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                total_comparison++;
                if (arr[min] > arr[j])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                swap(&arr[i], &arr[min]);
                total_swap++;
            }
        }
        Analysis("SelectionSort", total_comparison, total_swap);
    }
    void BubbleSort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                total_comparison++;
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    total_swap++;
                }
            }
        }
        Analysis("BubbleSort", total_comparison, total_swap);
    }
    void InsertionSort()
    {
        int key, j;
        for (int i = 1; i < size; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                total_comparison++;
                arr[j + 1] = arr[j];
                j--;
                total_swap++;
            }
            arr[j + 1] = key;
        }
        Analysis("InsertionSort", total_comparison, total_swap);
    }
};

int main()
{
    vector<int> arr = {12, 4, 6, 7, 1};
    sort obj1(arr);
    obj1.displaySortedArray();
    cout << endl;
    obj1.InsertionSort();
    obj1.displaySortedArray();
    obj1.SelectionSort();
    obj1.displaySortedArray();
    obj1.BubbleSort();
    obj1.displaySortedArray();
    obj1.BestAndWorseTechnique();
    cout << endl;
    sort obj2;
    obj2.generateRandomArray(6);
    obj2.displaySortedArray();
    cout << endl;
    obj2.InsertionSort();
    obj2.displaySortedArray();
    obj2.SelectionSort();
    obj2.displaySortedArray();
    obj2.BubbleSort();
    obj2.displaySortedArray();
    obj2.BestAndWorseTechnique();
}