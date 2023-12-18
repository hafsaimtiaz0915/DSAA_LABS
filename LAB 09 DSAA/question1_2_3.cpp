#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node *newNode(int item)
    {
        Node *temp = new Node;
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Function to print nodes in inorder
    void printInorder(Node *node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << node->key << " \t ";
        printInorder(node->right);
    }

    // Function to print nodes in postorder
    void printPostorder(Node *node)
    {
        if (node == NULL)
            return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->key << " \t ";
    }

    // Function to print nodes in preorder
    void printPreorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->key << " \t ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return newNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }
};

// Function to take input and handle invalid input
template <class T>
void takeInput(T &reference)
{
    cin >> reference;
    while (!cin)
    {
        cout << "\n\tInvalid Input, Try Again: " << endl;
        cout << "\n\t\t Your Input: ";
        cin.clear();
        fflush(stdin);
        cin >> reference;
    }
}

int main()
{
    Node *root = NULL;
    int num = 0;
    string choice;

    do
    {
        cout << "\n\n***Choose an operation***\n"
             << endl;
        cout << "\t[A] Insert a number\n"
             << endl;
        cout << "\t[B] Print Inorder\n"
             << endl;
        cout << "\t[C] Print Postorder\n"
             << endl;
        cout << "\t[D] Print Preorder\n"
             << endl;
        cout << "\t[E] Exit\n"
             << endl;
        cout << "\n\t\t Your Choice: ";
        cin >> choice;
        cout << "\n===============================================================\n" << endl;

        if (choice == "A" || choice == "a")
        {
            cout << "Enter a number (integer): ";
            takeInput(num);
            root = root->insert(root, num);
        }
        else if (choice == "B" || choice == "b")
        {
            if (root == NULL)
                cout << "No element present in binary tree" << endl;
            else    
            root->printInorder(root);
        }
        else if (choice == "C" || choice == "c")
        {
            if (root == NULL)
                cout << "No element present in binary tree" << endl;
            else 
            root->printPostorder(root);
        }
        else if (choice == "D" || choice == "d")
        {
            if (root == NULL)
                cout << "No element present in binary tree" << endl;
            else 
            root->printPreorder(root);
        }

        else if (choice == "E" || choice == "e")
        {
            cout << "\n***Exiting program***\n";
        }
        else
        {
            cout << "\n\tInvalid choice! Please enter a valid option.\n";
            cout << "\tPress Enter to Continue." << endl;
            getch();
        }

        cout << "\n===============================================================\n" << endl;

    } while ((choice != "E") && (choice != "e"));

    return 0;
}