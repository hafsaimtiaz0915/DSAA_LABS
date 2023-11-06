#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data)
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

    void appendNode(char data)
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
};

void swapLinkedList(string word, SinglyLinkedList &list, int stringLength)
{
    Node *current = list.head;
    Node *position = list.head;

    for (int i = 0; i < stringLength; i++)
    {
        while (current != NULL)
        {
            if (word[i] == current->data)
            {
                if (current == position)
                {
                    position = position->next;
                    break;
                }
                else
                {
                    char temp = position->data;
                    position->data = current->data;
                    current->data = temp;
                    position = position->next;
                    break;
                }
            }
            current = current->next;
        }
        current = list.head;
    }
    list.displayList();
}

void checkDictionary(const vector<string> &dictionary, SinglyLinkedList &list, int stringLength)
{
    Node *current = list.head;
    int count = 0;

    for (int i = 0; i < dictionary.size(); i++)
    {
        string word = dictionary[i];
        if (word.length() == stringLength)
        {
            for (int j = 0; j < stringLength; j++)
            {
                current = list.head;
                while (current != NULL)
                {
                    if (word[j] == current->data)
                    {
                        count++;
                        break;
                    }
                    else
                    {
                        current = current->next;
                    }
                }
            }
            if (count == stringLength)
            {
                swapLinkedList(word, list, stringLength);
                return;
            }
            else
            {
                count = 0;
            }
        }
    }
    cout << "Word not found in dictionary" << endl;
}

int main()
{
    SinglyLinkedList list;
    vector<string> dictionary = {
        // 3-Letter Words
        "cat", "dog", "run", "sun", "eat", "hat", "pen", "top", "pig", "box",
        "car", "bus", "bed", "cup", "map", "key", "leg", "egg", "ant", "van",
        "toy", "arm", "win", "fan", "lip", "cap", "job", "nap", "fox", "rag",
        "car", "nut", "gem", "bed", "hay", "gem", "ham", "jet", "tap", "lip",
        "fog", "jug", "mud", "pie", "sky", "rug", "bat", "mop", "pin", "ice",
        "sun", "bug", "bee", "toy", "hop", "den", "fox", "jug", "leg", "fan",
        "pen", "key", "cat", "nut", "van", "car", "bed", "map", "ham", "egg",
        "cup", "lip", "jet", "toy", "hat", "sun", "pen", "cap", "top", "arm",
        "car", "fan", "job", "bus", "bed", "cup", "toy", "pig", "dog", "cat",
        "fox", "nap", "hat", "leg", "eat", "pie", "hat", "top", "ice", "rug",

        // 4-Letter Words
        "bird", "jump", "play", "desk", "moon", "book", "fire", "rose", "blue", "song",
        "star", "lake", "ring", "pear", "fish", "lamp", "tree", "frog", "fish", "bear",
        "kite", "boat", "duck", "coat", "ball", "goat", "barn", "drum", "gate", "nose",
        "gate", "shoe", "cake", "fork", "palm", "corn", "bell", "duck", "frog", "coat",
        "lion", "rain", "wolf", "hand", "frog", "moon", "pine", "fish", "bone", "rice",
        "flag", "leaf", "cake", "duck", "tree", "lamp", "bear", "gate", "hand", "fire",
        "rose", "boat", "kite", "star", "drum", "book", "moon", "palm", "bird", "fish",
        "tree", "lamp", "bell", "bear", "frog", "nose", "fork", "coat", "fire", "lion",
        "rain", "rice", "wolf", "bone", "hand", "flag", "leaf", "cake", "shoe", "gate",
        "pine", "duck", "book", "moon", "kite", "corn", "barn", "goat", "ball", "goat",

        // 5-Letter Words
        "apple", "water", "table", "snake", "queen", "chair", "ocean", "radio", "beach", "horse",
        "music", "plant", "whale", "tiger", "paper", "fence", "smile", "clock", "peace", "lunch",
        "bread", "eagle", "dream", "peach", "child", "party", "river", "lemon", "socks", "stone",
        "stars", "green", "books", "night", "candy", "grape", "watch", "mouse", "north", "socks",
        "snake", "radio", "horse", "tiger", "table", "ocean", "queen", "chair", "apple", "plant",
        "clock", "paper", "water", "smile", "bread", "child", "peace", "fence", "night", "lemon",
        "beach", "lunch", "eagle", "dream", "candy", "river", "music", "peach", "party", "books",
        "mouse", "green", "watch", "stars", "north"};

    string userInput;
    cout << "Enter a string with a length > 2 and < 6 letters: ";
    cin >> userInput;

    if (userInput.length() > 2 && userInput.length() < 6)
    {
        for (int i = 0; i < userInput.length(); i++)
        {
            list.appendNode(userInput[i]);
        }
    }
    else
    {
        cout << "Requirements not met. Input string must be 3 to 5 letters long." << endl;
        return 0;
    }

    cout << "Your input: ";
    list.displayList();
    cout << "Checking the dictionary..." << endl;
    checkDictionary(dictionary, list, userInput.length());

    return 0;
}