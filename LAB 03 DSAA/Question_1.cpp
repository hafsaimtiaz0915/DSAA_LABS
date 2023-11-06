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

    SinglyLinkedList()
    {
        head = NULL;
    }

    // Append a node with the given data to the end of the linked list
    void appendNode(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            cout << "\n\t\t Value Added." << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            cout << "\n\t\t Value Added." << endl;
        }
    }

    // Prepend a node with the given data to the beginning of the linked list
    void prependNode(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "\n\t\t Value Added." << endl;
    }

    // Insert a node with the given data at the specified position
    void insertNode(int data, int position)
    {
        if (position < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *newNode = new Node(data);

        if (position == 0)
        {
            prependNode(data);
        }
        else
        {
            Node *temp = head;
            int index = 0;
            while (index < position - 1 && temp != NULL)
            {
                temp = temp->next;
                index++;
            }
            if (temp == NULL)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "\n\t\t Value Added." << endl;
        }
    }

    // Delete a node with the given data value
    void deleteNode(int data)
    {
        if (head == NULL)
        {
            cout << "Empty linked list" << endl;
            return;
        }

        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\n\t\t Node with Value " << data << " is Deleted." << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == data)
            {
                Node *toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "\n\t\t Node with Value " << data << " is Deleted." << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Node not found" << endl;
    }

    // Delete the head node
    void deleteHead()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\n\t\t Head is Deleted." << endl;
        }
    }

    // deleting the tail
    void deleteTail()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "\n\t\t Tail is Deleted." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout << "\n\t\t Tail is Deleted." << endl;
        }
    }

    // Delete a node at a specified position
    void deleteAtPosition(int position)
    {
        if (position < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        if (position == 0)
        {
            deleteHead();
            return;
        }

        Node *temp = head;
        for (int i = 0; temp != NULL && i < position - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "\n\t\t Node at position " << position << " is Deleted." << endl;
    }

    // Display the linked list
    void displayList()
    {
        Node *temp = head;
        cout << "\n*Displaying Linked List*\n"
             << endl;
        cout << "\t\t";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << "\n=========================================" << endl;
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
    SinglyLinkedList List;
    char choice;
    do
    {
         cout << "\n*******Choose an operation For LinkedList*****\n"<< endl;
        cout << "\t[a] Insert a node at head" << endl;
        cout << "\t[b] Insert a node at tail/end/back" << endl;
        cout << "\t[c] Insert a node at any position" << endl;
        cout << "\t[d] Delete a node by value" << endl;
        cout << "\t[e] Delete head" << endl;
        cout << "\t[f] Delete tail" << endl;
        cout << "\t[g] Delete a node at any position" << endl;
        cout << "\t[h] Display the List" << endl;
        cout << "\t[i] Quit" << endl;
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
            List.displayList();
            cout << endl;
            break;
        case 'b':
        case 'B':
            cout << "\nEnter the value(integer) to insert at the tail: ";
            cin >> value;
            List.appendNode(value);
            List.displayList();
            cout << endl;
            break;
        case 'c':
        case 'C':
            cout << "\nEnter the value(integer) to insert: ";
            cin >> value;
            cout << "Enter the position to insert at: ";
            cin >> position;
            List.insertNode(value, position);
            List.displayList();
            cout << endl;
            break;
        case 'd':
        case 'D':
            cout << "\nEnter the value(integer) to delete: ";
            cin >> value;
            List.deleteNode(value);
            List.displayList();
            cout << endl;
            break;
        case 'e':
        case 'E':
            List.deleteHead();
            List.displayList();
            cout << endl;
            break;
        case 'f':
        case 'F':
            List.deleteTail();
            List.displayList();
            cout << endl;
            break;
        case 'g':
        case 'G':
            cout << "\nEnter the position to delete: ";
            cin >> position;
            List.deleteAtPosition(position);
            List.displayList();
            cout << endl;
            break;
        case 'h':
        case 'H':
            List.displayList();
            cout << endl;
            break;
        case 'i':
        case 'I':
            return 0;
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
