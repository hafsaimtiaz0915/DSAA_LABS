#include <iostream>
using namespace std;
template<class DT>
class Node {
public:
    DT data;
    Node<DT> *next;

    Node(DT data) {
        this->data = data;
        this->next = NULL;
    }
};

template<class DT>
class Queue {
	private:
			Node<DT> *front;
			int rear;
			int capacity;
//include private variables according to the underlying data structure 
public:
	 Queue(int c=0){
		capacity = c;
		rear = -1;
        front = NULL;
    }

//puts element at the rear end of the Queue if it is not full. Must be O(1) 
void Put(){
	
	DT element;
	cin >> element;
	
	Node<DT> *newNode = new Node<DT>(element);

        if (IsEmpty())
        {
            front = newNode;
            cout << "\n\t Value Added." << endl;
            rear++;
        }
        else if(!IsFull())
        {
            Node<DT> *ptr = front;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            cout << "\n\t Value Added." << endl;
            rear++;
        }
        else
        	cout << "\n\tQueue is Full." << endl;
}
//if queue not empty then delete the element at front of the Queue. Must be O(1) 
DT Get(){
	DT value;
        if (front->next == NULL)
        {
        	value = front->data;
            delete front;
            front = NULL;
            rear = -1;
        }
        else
        {
            Node<DT> *temp = front;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
                    	value = temp->next->data;
            delete temp->next;
            temp->next = NULL;
                        --rear;

        }
        return value;
}
void Display() {
        if (IsEmpty()) {
            cout << "\nQueue is empty." << endl;
        } 
		else {
            Node<DT> *temp = front;
            cout << "\n\n Queue elements: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    
void Resize(int newCapacity) {
    if (newCapacity < 0) {
        cout << "\n\tInvalid capacity. Please provide a non-negative capacity.\n";
        return;
    }
    else if (newCapacity < capacity) {
        cout << "\n\tNew capacity is smaller than the current size. Cannot resize.\n";
        return;
    }
    else 
    	capacity = newCapacity;

    cout << "\n\tQueue resized to capacity: " << newCapacity << endl;
}

//return true if the Queue is empty and false if it is not 
bool IsEmpty(){
	return (front == NULL);
}
//return true if the Queue is full and false if it is not 
bool IsFull(){
    return rear == capacity - 1;
}
int getSize(){
	return capacity;
}

~Queue()
    {
        while (front != NULL)
        {
            Node<DT> *temp = front;
            front = front->next;
            delete temp;
        }
    }
};
int main() {
    string choice;
	int size;
		cout << "Enter the Capacity of Queue: ";;
			cin >> size;
			    Queue<int> *q = new Queue<int>(size);

    do {
        cout << "\n\n****Choose an operation For Queue**\n" << endl;
        cout << "\t[A] Enqueue\n" << endl;
        cout << "\t[B] Dequeue\n" << endl;
        cout << "\t[c] Size of Queue\n" << endl;
        cout << "\t[D] Display Queue\n" << endl;
        cout << "\t[E] Resize Queue\n" << endl;
        cout << "\t[F] Exit\n" << endl;
        	cout << "\n\t\t Your Choice: ";
       		 	cin >> choice;

        if (choice == "A" || choice == "a") {
        	cout << "\n\nEnter the element to enqueue: ";
                q->Put();
        }
		else if (choice == "B" || choice == "b") {
                if (!q->IsEmpty()){
                    cout << "\n\nDequeued element: " << q->Get() << endl;
                }else
                    cout << "\n\nQueue is empty.Cannot dequeue.\n";
    	} 
		else if (choice == "C" || choice == "c") {
            cout << "\nSize of Queue: " << q->getSize()<< endl;
    	}
    	else if (choice == "D" || choice == "d") 
			q->Display();
		else if (choice == "E" || choice == "e"){
			int newCapacity;
				cout << "\n\nEnter the new capacity: ";
            		cin >> newCapacity;
            q->Resize(newCapacity);
    	}
		else if (choice == "F" || choice == "f")
					cout << "\n\tExiting program.\n";
		else
                cout << "\n\tInvalid choice. Please enter a valid option.\n";
                
		cout << "\n===============================================================" << endl;

    } while ((choice != "F") && (choice != "f"));
  
      	delete q; 
    
	return 0;
}
