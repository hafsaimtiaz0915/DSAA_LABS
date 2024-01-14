#include <iostream>
#include <cstdlib>
/*QUESTION : 01 
SEARCH METHOD
The search method takes a key value and searches for it in the binary search tree, printing the depth at which the key is found.
FIND METHOD
The find method takes a key value, a pointer to a parent node, and a pointer to a key location. It searches for the key in the 
binary search tree and returns the key (if found) and its parent.*/

using namespace std;

struct nod
{
    int info;
    struct nod *l;
    struct nod *r;
} *r;

class BST
{
public:
	bool found =false;
    void searchAndFind(int key, nod *&parent, nod *&key_location, int &depth);
    void find(int i, nod **par, nod **loc);
    void insert(nod *, nod *);
    void del(int);
    void casea(nod *, nod *);
    void caseb(nod *, nod *);
    void casec(nod *, nod *);
    void show(nod *, int);
};

void BST::searchAndFind(int key, nod *&parent, nod *&key_location, int &depth)
{
    nod *ptr = r;
    found = false;
    parent = nullptr;
    key_location = nullptr;
    depth = 0;

    while (ptr != nullptr)
    {
        depth++;
        if (key == ptr->info)
        {
            key_location = ptr;
            found = true ;
            return;
        }

        parent = ptr;
        if (key < ptr->info)
            ptr = ptr->l;
        else
            ptr = ptr->r;
    }
}

void BST::insert(nod *tree, nod *newnode)
{
    if (r == NULL)
    {
        r = new nod;
        r->info = newnode->info;
        r->l = NULL;
        r->r = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Element already in the tree" << endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->l != NULL)
            insert(tree->l, newnode);
        else
        {
            tree->l = newnode;
            (tree->l)->l = NULL;
            (tree->l)->r = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }
    else
    {
        if (tree->r != NULL)
            insert(tree->r, newnode);
        else
        {
            tree->r = newnode;
            (tree->r)->l = NULL;
            (tree->r)->r = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}
void BST::find(int i, nod **par, nod **loc)
{
    nod *ptr, *ptrsave;
    if (r == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (i == r->info)
    {
        *loc = r;
        *par = NULL;
        return;
    }
    if (i < r->info)
        ptr = r->l;
    else
        ptr = r->r;
    ptrsave = r;
    while (ptr != NULL)
    {
        if (i == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (i < ptr->info)
            ptr = ptr->l;
        else
            ptr = ptr->r;
    }
    *loc = NULL;
    *par = ptrsave;
}

void BST::del(int i)
{
    nod *par, *loc;
    if (r == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    find(i, &par, &loc);
    if (loc == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }
    if (loc->l == NULL && loc->r == NULL)
    {
        casea(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc->l != NULL && loc->r == NULL)
    {
        caseb(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc->l == NULL && loc->r != NULL)
    {
        caseb(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc->l != NULL && loc->r != NULL)
    {
        casec(par, loc);
        cout << "item deleted" << endl;
    }
    delete loc; // Use delete instead of free for C++
}

void BST::casea(nod *par, nod *loc)
{
    if (par == NULL)
    {
        r = NULL;
    }
    else
    {
        if (loc == par->l)
            par->l = NULL;
        else
            par->r = NULL;
    }
}

void BST::caseb(nod *par, nod *loc)
{
    nod *child;
    if (loc->l != NULL)
        child = loc->l;
    else
        child = loc->r;
    if (par == NULL)
        r = child;
    else
    {
        if (loc == par->l)
            par->l = child;
        else
            par->r = child;
    }
}

void BST::casec(nod *par, nod *loc)
{
    nod *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->r;
    
    while (ptr->l != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->l;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->l == NULL && suc->r == NULL)
        casea(parsuc, suc);
    else
        caseb(parsuc, suc);
    if (par == NULL)
        r = suc;
    else
    {
        if (loc == par->l)
            par->l = suc;
        else
            par->r = suc;
    }
    suc->l = loc->l;
    suc->r = loc->r;
}

void BST::show(nod *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        show(ptr->r, level + 1);
        cout << endl;
        if (ptr == r)
            cout << "Root->: ";
        else
        {
            for (i = 0; i < level; i++)
                cout << " ";
        }
        cout << ptr->info;
        show(ptr->l, level + 1);
    }
}

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
    BST bst;
    nod *t;
    int num = 0;
    string choice;

    do
    {
        cout << "\n\n*Choose an operation*\n"
             << endl;
        cout << "\t[A] Insert Element(Integer)\n"
             << endl;
        cout << "\t[B] Delete Element\n"
             << endl;
        cout << "\t[C] Search Element\n"
             << endl;
        cout << "\t[D] Display Binary Search Tree\n"
             << endl;
        cout << "\t[F] Exit\n"
             << endl;
        cout << "\n\t\t Your Choice: ";
        cin >> choice;
        cout << "\n===============================================================" << endl;

        if (choice == "A" || choice == "a")
        {
            cout << "Enter a number (integer): ";
            takeInput(num);
            t = new nod;
            t->info = num;
            bst.insert(r, t);
        }
        else if (choice == "B" || choice == "b")
        {
            if (r == NULL)
            {
                cout << "No element present in Binary Search tree" << endl;
                continue;
            }
            cout << "Enter the number to be deleted: ";
            cin >> num;
            bst.del(num);
        }
        else if (choice == "C" || choice == "c")
        {
            if (r != NULL)
            {
            	 nod *par = NULL;
    nod *loc = NULL;
     int keyDepth=0;
                cout << "Enter Element to Search:" << endl;
                cin >> num;
                bst.searchAndFind(num, par, loc, keyDepth);
                if(bst.found){
                	 cout << "Depth: " << keyDepth << endl;

                if (par != nullptr)
                    cout << "Parent: " << par->info << endl;
                else
                    cout << "Parent: NULL" << endl;

                if (loc != nullptr)
                    cout << "Value: " << loc->info << endl;
                else
                    cout << "Value: NULL" << endl;
				}
				else{
					cout << " value not found" << endl;
				}
            }
        }
        else if (choice == "D" || choice == "d")
        {
            if (r == NULL)
            {
                cout << "No element present in Binary Search tree" << endl;
                continue;
            }
            cout << "Displaying Binary Search Tree\n"
                 << endl;
            bst.show(r, 1);
            cout << endl;
        }
        else if (choice == "e" || choice == "E")
        {
            cout << "\n**Exiting program\n";
        }
        else
        {
            cout << "\n\tInvalid choice! Please enter a valid option.\n";
        }

        cout << "\n===============================================================" << endl;

    } while ((choice != "E") && (choice != "e"));

    return 0;
}