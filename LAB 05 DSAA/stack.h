#include<iostream>
using namespace std;
template <class T>
class Stack {
    T *arr;
    int size;
    int top;

public:
    Stack() {
        arr = nullptr;
        size = 0;
        top = -1;
    }

    Stack(int size) {
        this->size = size;
        arr = new T[size];
        top = -1;
    }

    bool IsFull() {
        return top == size - 1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    void push(T data) {
        if (!IsFull()) {
            arr[++top] = data;
        } else {
            cout << "Stack is full. Resizing..." << endl;
            resize();
            arr[++top] = data;
        }
    }

    T pop() {
        if (!IsEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack is empty" << endl;
        }
    }
    T get_top(){
        return arr[top];
    }
    int get_size(){
        return size;
    }

    void resize() {
        int newSize = size * 2;
        T *newArr = new T[newSize];
        for (int i = 0; i <= top; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
        cout << "Stack resized. New size: " << size << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};


