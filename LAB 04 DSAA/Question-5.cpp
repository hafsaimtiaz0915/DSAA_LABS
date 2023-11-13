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

    }
    void display()
    {
        Node *temp = head;
        if (head != NULL)
        {
        	cout << "\t\t";
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
};
void BreakCircularLinkedlist(CircularDoublelyLinkedList &list)
{
    CircularDoublelyLinkedList half1, half2;
    int count = 1;
    Node *current = list.head;
    while (current->next != list.head)
    {
        count++;
        current = current->next;
    }
    current = list.head;
    for (int i = 0; i < count / 2; i++)
    {
        half1.appendNode(current->data);
        current = current->next;
    }
            cout << "\n*Displaying Circular Linked List*\n" << endl;

    list.display();
                cout << "\n*Half Linked List 1*\n" << endl;

    half1.display();
    for (int i = count / 2; i < count; i++)
    {
        half2.appendNode(current->data);
        current = current->next;
    }
                    cout << "\n*Half Linked List 2*\n" << endl;

    half2.display();
}
int main()
{
    CircularDoublelyLinkedList list;
    list.appendNode(0);
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);
    list.appendNode(5);
    BreakCircularLinkedlist(list);
}