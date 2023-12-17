#include <iostream>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    /* first recur on left child */
    printInorder(node->left);
    /* then print the data of node */
    cout << node->data << " ";
    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in postorder*/
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;
    /* first recur on left child */
    printPostorder(node->left);
    /* now recur on right child */
    printPostorder(node->right);
    /* then print the data of node */
    cout << node->data << " ";
}
/* Given a binary tree, print its nodes in postorder*/
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    cout << node->data << " ";
    /* first recur on left child */
    printPreorder(node->left);
    /* now recur on right child */
    printPreorder(node->right);
}
/* Driver code*/
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function call
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
    return 0;
}