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
    void SelectionSort(bool flag)
    {
        int min;
        int Swap=0;
        
        for (int i = 0; i < size - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                total_comparison++;
                if (arr[min] > arr[j])
                {
                    // cout<<arr[min]<<">"<<arr[j]<<"arr[min]"<<endl;
                    min = j;
                }
            }
            // cout << "minimum" << min <<"f"<<i<< endl;
            if (min != i)
            {
                swap(&arr[i], &arr[min]);
                Swap++;
                // cout<<"faizan"<<Swap<<endl;
            }
        }
        Analysis("SelectionSort", total_comparison, Swap);
        if(flag)
        { cout << "****" << "SelectionSort" << "*****";
        cout << "\nTotal Comparisons: " << total_comparison;
        cout << "\nTotal Swap:" << Swap << endl;}
       

        
    }
    void BubbleSort(bool flag)
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
         if(flag)
        { cout << "****" << "BubbleSort" << "*****";
        cout << "\nTotal Comparisons: " << total_comparison;
        cout << "\nTotal Swap:" << total_swap << endl;}
       
    }
    void InsertionSort(bool flag)
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
         if(flag)
        { cout << "****" << "SelectionSort" << "*****";
        cout << "\nTotal Comparisons: " << total_comparison;
        cout << "\nTotal Swap:" << total_swap << endl;}
       
    }
};

int main()
{
    vector<int> arr = {12, 4, 6, 7, 1};
    sort obj1;
    // obj1.displaySortedArray();
    // cout << endl;
    // obj1.SelectionSort();
    // obj1.InsertionSort();
    // obj1.displaySortedArray();
    // obj1.displaySortedArray();
    // obj1.BubbleSort();
    // obj1.displaySortedArray();
    // obj1.BestAndWorseTechnique();
    // cout << endl;
    // // sort obj2;
    // obj2.generateRandomArray(6);
    // obj2.displaySortedArray();
    // cout << endl;
    // obj2.InsertionSort();
    // obj2.displaySortedArray();
    // obj2.SelectionSort();
    // obj2.displaySortedArray();
    // obj2.BubbleSort();
    // obj2.displaySortedArray();
    // obj2.BestAndWorseTechnique();
    int choice;
    int size;
    cout<<"Select your sort technique\n1)Selection Sort\n2)Insertion sort\n3)BubbleSort"<<endl;
    cin>>choice;
    cout<<"Enter size of array:";
    cin>>size;
    switch(choice){
        case 1: 
        obj1.generateRandomArray(size);
        obj1.displaySortedArray();
                obj1.InsertionSort(false);
                obj1.BubbleSort(false);
                obj1.SelectionSort(true);
                
                cout<<"After Sorting"<<endl;
                obj1.displaySortedArray();
                obj1.BestAndWorseTechnique();
                
                break;
    
        case 2: obj1.generateRandomArray(size);
                obj1.SelectionSort(false);
                obj1.BubbleSort(false);
                obj1.InsertionSort(true);
                cout<<"After Sorting"<<endl;
                obj1.displaySortedArray();
                obj1.BestAndWorseTechnique();
                break;
    
        case 3: obj1.generateRandomArray(size);
                obj1.InsertionSort(false);
                obj1.SelectionSort(false);
                obj1.BubbleSort(true);
                cout<<"After Sorting"<<endl;
                obj1.displaySortedArray();
                obj1.BestAndWorseTechnique();
                break;
           
}


}
