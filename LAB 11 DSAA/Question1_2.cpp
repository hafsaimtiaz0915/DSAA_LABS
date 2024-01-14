#include <iostream>
#include <vector>
using namespace std;
class Heap
{
    bool min, max;
    vector<int> arr;


public:
    Heap()
    {
        min = false;
        max = false;

    }
    Heap(bool selection)
    {
        if (selection)
        {
            min = true;
            max = false;
        }
        else
        {
            max = true;
            min = false;
        }

    }
    
    void insert(int num)
    {
        if (arr.size() == 0)
        {
            arr.push_back(num);
        }
        else
        {
            arr.push_back(num);
            for (int i =arr.size() / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
        }
    }

    void display()
{   if (arr.size()>0) {
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << ",";
            }
        } else {
            cout<<"Tree is empty"<<endl;
        }
    }
    void heapify(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int parent = index;
        if (min)
        {
            if (left < arr.size() && arr[left] < arr[parent])
                parent = left;
            if (right < arr.size() && arr[right] < arr[parent])
                parent = right;
        }
        else
        {
            if (left < arr.size() && arr[left] > arr[parent])
                parent = left;
            if (right < arr.size() && arr[right] > arr[parent])
                parent = right;
        }
        if (parent != index)
        {
            swap(arr[index], arr[parent]);
            heapify(parent);
        }
    }
    void Delete(int num)
    {
        int i;
        bool flag = false;
        for (i = 0; i < arr.size(); i++)
        {
            if (num == arr[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            swap(arr[i], arr[arr.size() - 1]);
            arr.pop_back();
            for (int i = arr.size() / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
        }
        else
        {
            cout << "Value Not Found!" << endl;
        }
    }
    int peek()
    {
        if (arr.size() > 0)
            return arr[0];
        else
            cout << "Tree is empty" << endl;
    }
    int Extract()
    {
        int num;
        if (arr.size() > 0)
        {
            swap(arr[0], arr[arr.size() - 1]);
            num = arr[arr.size() - 1];
            arr.pop_back();
            heapify(0);
            return num;
        }
        else
        {
            cout << "tree is empty" << endl;
        }
    }
};

template <class T>
void takeInput(T &reference)
{
    cin >> reference;
    while (!cin)
    {
        cout << "\n\tInvalid Input, Try Again: " << endl;
        cout << "\n\t\t Your Input: ";
        cin.clear();
        cin.ignore();
        cin >> reference;
    }
}
int main()
{
    int choiceheap;
    int option;
    Heap *heap;
    do
    {
        cout << "Enter your choice minheap[1] or maxheap[2]" << endl;
        takeInput(choiceheap);

        if (choiceheap == 1)
        {
            heap = new Heap(true);
        }
        else if (choiceheap == 2)
        {
            heap = new Heap(false);
        }
        else
        {
            cout << "\n\tInvalid choice! Please enter a valid option.\n";
        }

        cout << "\n===============================================================" << endl;
    } while (choiceheap != 1 && choiceheap != 2);

    string choice;

    do
    {
        cout << "\n\n*Choose an operation*\n"
             << endl;
        cout << "\t[A] Insert Element(Integer)\n"
             << endl;
        cout << "\t[B] Delete Element(Integer)\n"
             << endl;
        cout << "\t[C] Peek Element\n"
             << endl;
        cout << "\t[D] Extract Element\n"
             << endl;
        cout << "\t[E] Display Heap\n"
             << endl;
        cout << "\t[F] Exit\n"
             << endl;
        cout << "\n\t\t Your Choice: ";
        takeInput(choice);
        cout << "\n===============================================================" << endl;

        if (choice == "A" || choice == "a")
        {
            int num;
            cout << "Enter your Number" << endl;
            takeInput(num);
            heap->insert(num);
        }
        else if (choice == "B" || choice == "b")
        {
            int num;
            cout << "Enter your Number" << endl;
            takeInput(num);
            heap->Delete(num);
        }
        else if (choice == "C" || choice == "c")
        {
            cout << "Root is " << heap->peek() << endl;
        }
        else if (choice == "D" || choice == "d")
        {
            cout << "Root is " << heap->Extract() <<" and it is  deleted"<< endl;
        }
        else if (choice == "e" || choice == "E")
        {
            heap->display();
        }
        else if (choice == "f" || choice == "F")
        {
            cout << "\n**Exiting program\n";
        }
        else
        {
            cout << "\n\tInvalid choice! Please enter a valid option.\n";
        }

        cout << "\n===============================================================" << endl;

    } while ((choice != "f") && (choice != "F"));
    return 0;
}