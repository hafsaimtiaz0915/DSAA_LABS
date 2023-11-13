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
class CircularDoublelyLinkedList
{
public:
    Node *head;
    Node *tail;

    CircularDoublelyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Adding node at head
    void prependNode(int newData)
    {
        Node *newNode = new Node(newData);

        if (head != NULL)
        {
            Node *lastNode = head->prev;

            newNode->next = head;
            head->prev = newNode;
            newNode->prev = lastNode;
            lastNode->next = newNode;

            head = newNode;
        }
        else
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        cout << "\n\t\t Value Added." << endl;
    }
    // Adding node at tail
    void appendNode(int newData)
    {
        Node *newNode = new Node(newData);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *lastNode = head->prev;
            lastNode->next = newNode;
            newNode->prev = lastNode;
            newNode->next = head;
            head->prev = newNode;
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
                head->next = head;
                head->prev = head;
            }
            else
            {
                cout << "Invalid position. List is empty." << endl;
            }
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1; ++i)
        {
            current = current->next;
            if (current == head)
            {
                cout << "Invalid position. List is not long enough." << endl;
                return;
            }
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        if (position == 1)
            head = newNode;
    }

    // Delete a node by value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node *current = head;

        do
        {
            if (current->data == value)
            {
                if (current->next == current)
                {
                    // Only one node in the list
                    delete current;
                    head = nullptr;
                    return;
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head)
                {
                    head = current->next;
                }

                delete current;
                return;
            }

            current = current->next;
        } while (current != head);

        cout << "Value not found in the list. Cannot delete." << endl;
    }

    // Displaying linked list
void display()
    {
        Node *temp = head;
        cout << "\n*Displaying Circular Linked List*\n"
             << endl;
        if (head != NULL)
        {
        	        	cout << "\t";

            do
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            } while (temp != head);
            cout << "(head)" << temp->data << endl;
        }
        else
        {
            cout << "Your linked list is empty" << endl;
        }
        cout << "\n=========================================================================" << endl;
    }
    // Destructor
    ~CircularDoublelyLinkedList()
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
    CircularDoublelyLinkedList List;
    char choice;
    do
    {       
	 cout << "====================================================================================" << endl;
        cout << "\n\t\t\tChoose an operation For Circular LinkedList\n"
             << endl;
        cout << "\t\t[a] Insert a node at head" << endl;
        cout << "\t\t[b] Insert a node at tail/end/back" << endl;
        cout << "\t\t[c] Insert a node at any position" << endl;
        cout << "\t\t[d] Delete a node by value" << endl;
        cout << "\t\t[e] Quit" << endl;
        cout << "\n\t\t\t Your Choice: ";
        cin >> choice;
	 cout << "====================================================================================" << endl;

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
            return 0;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
            break;
        }
    } while ((choice != 'e') && (choice != 'E'));

    return 0;
}
