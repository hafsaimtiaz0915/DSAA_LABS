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
        }
    }
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
    }

    // Display the linked list
    void displayList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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

    cout << "\n=======================================================\n" << endl;
    cout << "Initial Linked List: " <<endl ;
    list.displayList();

    // Append nodes and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nAppending 10: " <<endl;
    list.appendNode(10);
    list.displayList();

    cout << "\n=======================================================\n" << endl;
    cout << "\nAppending 20: " <<endl;
    list.appendNode(20);
    list.displayList();

    // Prepend a node and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nPrepending 5: " <<endl ;
    list.prependNode(5);
    list.displayList();

    // Insert a node and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nInserting 15 at position 1: " <<endl ;
    list.insertNode(15, 1);
    list.displayList();

    // Delete a node and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nDeleting node with value 15: " <<endl ;
    list.deleteNode(15);
    list.displayList();

    // Delete the head node and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nDeleting the head node: " <<endl ;
    list.deleteHead();
    list.displayList();

    // Delete the tail node and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nDeleting the tail node: " <<endl;
    list.deleteTail();
    list.displayList();

    // Delete a node at a specified position and display
    cout << "\n=======================================================\n" << endl;
    cout << "\nDeleting node at position 1: " <<endl ;
    list.deleteAtPosition(1);
    list.displayList();

    return 0;
}