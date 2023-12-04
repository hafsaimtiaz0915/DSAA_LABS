
#include <iostream>
using namespace std;
class Queue
{ // A class to represent a queue
private:
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue(int siz) : front(-1), rear(-1), size(0), capacity(siz)
    {
        array = new int[capacity];
    }
    void insert(int j)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot insert element." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = j;
        size++;
        if (front == -1)
        {
            front = rear;
        }
    }
    int remove()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot remove element." << endl;
            return -1;
        }
        int removedElement = array[front];
        front = (front + 1) % capacity;
        size--;
        return removedElement;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }
        return array[front];
    }
    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getSize()
    {
        return size;
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << array[i] << endl;
            }
        }
    }
};
int main()
{
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    Queue myQueue(queueSize);

    char choice;
    int removedValue, frontValue;
    do
    {
        system("CLS");
        cout << "\n****************Choose an operation**********************\n";
        cout << "\t[a] Insert\n";
        cout << "\t[b] Remove\n";
        cout << "\t[c] Peek\n";
        cout << "\t[d] Check if the queue is empty\n";
        cout << "\t[e] Check if the queue is full\n";
        cout << "\t[f] Get the size of the queue\n";
        cout << "\t[g] Display elements of queue\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "========================================================" << endl;

        switch (choice)
        {
        case 'A':
        case 'a':
            int value;
            cout << "Enter the value to insert (integer): ";
            cin >> value;
            myQueue.insert(value);
            myQueue.displayQueue();
            break;

        case 'B':
        case 'b':
            removedValue = myQueue.remove();
            if (removedValue != -1)
            {
                cout << "Removed element: " << removedValue << endl;
            }

            break;
        case 'C':
        case 'c':
            frontValue = myQueue.peek();
            if (frontValue != -1)
            {
                cout << "Front element: " << frontValue << endl;
            }
            break;
        case 'D':
        case 'd':
            cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
            break;
        case 'E':
        case 'e':
            cout << "Is the queue full? " << (myQueue.isFull() ? "Yes" : "No") << endl;
            break;
        case 'F':
        case 'f':
            cout << "Queue size: " << myQueue.getSize() << endl;
            break;
        case 'G':
        case 'g':
            myQueue.displayQueue();
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
        cout << "Do you want to proceed press [Y] to continue or any key to stop. ";
        cin >> choice;
        cin.ignore();

    } while ((choice == 'y') || (choice == 'Y'));

    return 0;
}
