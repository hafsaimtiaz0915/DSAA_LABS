#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class SinglyLinkedList
{
public:
    Node *head;
    // Default Constructor
    SinglyLinkedList()
    {
        head = NULL;
    }
    // Copy Constructor
    SinglyLinkedList(const SinglyLinkedList &ob)
    {
        head = ListCopier(ob.head);
    }

    // copying list Function
    Node *ListCopier(Node *source)
    {
        if (source == NULL)
        {
            return NULL;
        }

        Node *newNode = new Node(source->data);
        newNode->next = ListCopier(source->next);
        return newNode;
    }

    // Append a node with the given data to the end of the linked list
    void appendNode(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    // Prepend a node with the given data to the beginning of the linked list
    void prependNode(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    // Display the linked list
    void displayList()
    {
        Node *temp = head;
        cout << "\t\t";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL \n"
             << endl;
    }

    // reversing the List
    void reverseList()
    {
        Node *currentNode = head;
        Node *previous = NULL;
        Node *nextNode = NULL;

        while (currentNode != NULL)
        {
            nextNode = currentNode->next;
            currentNode->next = previous;
            previous = currentNode;
            currentNode = nextNode;
        }
        head = previous;
    }
    // Finding Duplicate in the linked list
    void findDuplicates()
    {
        Node *current = head;
        bool foundDuplicate = false;

        while (current != NULL)
        {
            Node *checker = current->next;

            while (checker != NULL)
            {
                if (current->data == checker->data)
                {
                    cout << "Duplicate found of number: " << current->data << endl;
                    foundDuplicate = true;
                }

                checker = checker->next;
            }

            current = current->next;
        }

        if (!foundDuplicate)
        {
            cout << "No duplicates found." << endl;
        }
    }
    // selection sort on the linked list
    void selectionSort()
    {
        Node *currentNode = head;

        while (currentNode != NULL)
        {
            Node *minNode = currentNode;
            Node *ptr = currentNode->next;

            while (ptr != NULL)
            {
                if (ptr->data < minNode->data)
                {
                    minNode = ptr;
                }
                ptr = ptr->next;
            }

            if (minNode != currentNode)
            {
                int tempData = currentNode->data;
                currentNode->data = minNode->data;
                minNode->data = tempData;
            }

            currentNode = currentNode->next;
        }
    }
    // Destructor to free memory when the object is destroyed
    ~SinglyLinkedList()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    SinglyLinkedList list;
    int num, i = 1;
    char choice;
    cout << "\n********* Enter the Elements of Linked List in Integer *********" << endl;
    do
    {
        cout << "Number " << i << ": ";
        cin >> num;
        list.appendNode(num);
        cout << "Do you want to add more? Press [Y] to continue or any key to stop. ";
        cin >> choice;
        cin.ignore();
        i++;
    } while ((choice == 'y') || (choice == 'Y'));
    cout << "====================================================" << endl;
    cout << "\nOriginal linked list: \n" << endl;
    list.displayList();
    cout << "====================================================\n" << endl;
    // sorting linked list
    SinglyLinkedList sortList(list);
    // reverse linked list
    SinglyLinkedList reverseList(list);
    reverseList.reverseList();
    cout << "\n1. Reversed Linked List: \n" << endl;
    reverseList.displayList(); // displaying reversed linked list
    cout << "====================================================" << endl;
    sortList.selectionSort();
    cout << "\n2. Linked list after Sorting: \n" << endl;
    sortList.displayList(); // displaying sorted linked 
     cout << "====================================================\n" << endl;
    list.findDuplicates();
    cout << "\n====================================================" << endl;

    return 0;
}