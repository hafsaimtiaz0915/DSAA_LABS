#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int newData)
    {
        data = newData;
        next = NULL;
        prev = NULL;
    }
};
class DoublelyLinkedList
{
public:
    Node *head;

    DoublelyLinkedList()
    {
        head = NULL;
    }
    // Adding node at head
    void prependNode(int newData)
    {
        Node *newNode = new Node(newData);
        newNode->next = head;
        if (head != nullptr)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "\n\t\t Value Added." << endl;
    }
    // Adding node at tail
    void appendNode(int newData)
    {
        if (head == NULL)
        {
            prependNode(newData);
        }
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            Node *newNode = new Node(newData);
            ptr->next = newNode;
            newNode->prev = ptr;
        }
        cout << "\n\t\t Value Added." << endl;
    }
    // Insert node at any position
    void insertNode(int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    Node *newNode = new Node(value);

    if (head == NULL)
    {
        if (position == 1)
        {
            head = newNode;
            return;
        }
        else
        {
            cout << "Invalid position. List is empty." << endl;
            return;
        }
    }

    Node *temp = head;
    int index = 1;

    while (temp->next != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (index == position - 1)
    {
        newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
        cout << "\n\t\t Value Added." << endl;
    }
    else
    {
        cout << "Position out of bounds" << endl;
    }
}

    // Delete a node by value
    void deleteNode(int value)
    {
        Node *tempNode = head;
        Node *prevNode;
        Node *nextNode;
        bool found = false;

        if (head == NULL)
        {
            cout << "Empty linked list" << endl;
            return;
        }

        while (tempNode != NULL)
        {
            if (tempNode->data == value)
            {
                Node *toDelete = tempNode;
                prevNode = tempNode->prev;
                nextNode = tempNode->next;

                if (prevNode != nullptr)
                {
                    prevNode->next = nextNode;
                }

                if (nextNode != nullptr)
                {
                    nextNode->prev = prevNode;
                }

                if (tempNode == head)
                {
                    head = nextNode;
                }

                delete toDelete;
                found = true;
                cout << "\n\t\t Value Deleted." << endl;
                break;
            }
            else
            {
                tempNode = tempNode->next;
            }
        }

        if (!found)
        {
            cout << "Value is not found" << endl;
        }
    }

    // Displaying linked list
    void display()
    {
        Node *temp;
        temp = head;
        if (head == NULL)
        {
            cout << "Your linked list is empty" << endl;
        }

        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        
        cout << "NULL" << endl;
    }
    // Destructor
    ~DoublelyLinkedList()
    {
        // Destructor to clean up dynamically allocated nodes
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    DoublelyLinkedList List;
    char choice;
    do
    {
        cout << "\n*******Choose an operation For Doublely LinkedList*****\n"
             << endl;
        cout << "\t[a] Insert a node at head" << endl;
        cout << "\t[b] Insert a node at tail/end/back" << endl;
        cout << "\t[c] Insert a node at any position" << endl;
        cout << "\t[d] Delete a node by value" << endl;
        cout << "\t[e] Display the List" << endl;
        cout << "\n\t\t Your Choice: ";
        cin >> choice;
        cout << "========================================================" << endl;

        int value, position;
        switch (choice)
        {
        case 'a':
        case 'A':
            cout << "\nEnter the value(integer) to insert at the head: ";
            cin >> value;
            List.prependNode(value);
            List.display();
            cout << endl;
            break;
        case 'b':
        case 'B':
            cout << "\nEnter the value(integer) to insert at the tail: ";
            cin >> value;
            List.appendNode(value);
            List.display();
            cout << endl;
            break;
        case 'c':
        case 'C':
            cout << "\nEnter the value(integer) to insert: ";
            cin >> value;
            cout << "Enter the position to insert at: ";
            cin >> position;
            List.insertNode(value, position);
            List.display();
            cout << endl;
            break;
        case 'd':
        case 'D':
            cout << "\nEnter the value(integer) to delete: ";
            cin >> value;
            List.deleteNode(value);
            List.display();
            cout << endl;
            break;
        case 'e':
        case 'E':
            List.display();
            cout << endl;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
            break;
        }
        cout << "Do you want to proceed press [Y] to continue or any key to stop. ";
        cin >> choice;
        cin.ignore();
    } while ((choice == 'y') || (choice == 'Y'));

    return 0;
}
