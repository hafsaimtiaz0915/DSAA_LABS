#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node *next;
		Node *previous;
		Node() {
			data = 0;

		}
		Node(int d) {
			data = d;
			next = NULL;
			previous = NULL;
		}
};
class DoublyLinkedList {
	public:
		Node * head;
		
		DoublyLinkedList() {
			head = NULL;
		}
		
		DoublyLinkedList(Node *n) {
			head = n;
		}
		
		void appendNode(int data) {
			Node* newNode = new Node(data);

			if(head == NULL) {
				head = newNode;
			} 
			else {
				Node *ptr = head;
					while(ptr->next!=NULL) {
						ptr = ptr->next;
					}
					
				ptr->next =  newNode;
				newNode->previous = ptr;

			}
		}

		void displayList() {
			Node *temp = head;			
					cout << "\t" << temp->data;
			while (temp->next!= NULL) {
				cout << " <-> " << temp->next->data ;
				temp = temp->next;
			}
			cout << " -> NULL \n"
			     << endl;
		}

		void Concatenating(const DoublyLinkedList& ob) {
			
			Node *current = ob.head;			
			while(current!=NULL) {
				appendNode(current->data);
				current=current->next;
			}
		}

		void selectionSort() {
			Node *currentNode = head;

			while (currentNode != NULL) {
				Node *maxNode = currentNode;
				Node *ptr = currentNode->next;

				while (ptr != NULL) {
					if (ptr->data > maxNode->data) {
						maxNode = ptr;
					}
					ptr = ptr->next;
				}

				if (maxNode != currentNode) {
					int tempData = currentNode->data;
					currentNode->data = maxNode->data;
					maxNode->data = tempData;
				}

				currentNode = currentNode->next;
			}
		}

		~DoublyLinkedList() {
			Node* temp = head;
			while (temp != NULL) {
				Node* nextNode = temp->next;
					delete temp;
				temp = nextNode;
			}
		}

};

int main() {
	DoublyLinkedList L,M,N;
	
	for(int i=1; i<=10; i++) {
		if(i%2==0)
			L.appendNode(i);
		else
			M.appendNode(i);
	}
	
	cout << "========================================================================" << endl;

	cout << "\nDouble Link list With Even Numbers from 2 to 10\n" << endl;
	cout << "\t";

	L.displayList();
	cout << "========================================================================" << endl;

	cout << "\nDouble Link list With Odd Numbers from 1 to 9\n" << endl;
	cout << "\t";
	M.displayList();
	
		N.Concatenating(L);
		N.Concatenating(M);
	cout << "========================================================================" << endl;
	cout << "\nDouble Link list after concatenating list L and M\n" << endl;
			N.displayList();
			
	cout << "========================================================================" << endl;
	cout << "\nDouble Link list after Sorting in Descending Order\n" << endl;
		N.selectionSort();
		N.displayList();
	cout << "========================================================================" << endl;
	
	return 0;
}