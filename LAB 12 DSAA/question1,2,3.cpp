#include <iostream>
using namespace std;

class HashTable {
	private:
		int table_size;
		int *table;

	public:
		HashTable(int size) : table_size(size), table(new int[size]) {
			for (int i = 0; i < table_size; ++i) {
				table[i] = -1;
			}
		}

		int hashFunction(int key) {
			return key % table_size;
		}
		int hashFunction2(int key) {
			return 7 - (key % 7);
		}





		void insertLinearProbing(int key) {
			if (isTableFull()) {
				cout << "Hash table is full. Cannot insert more elements." << endl;
				return;
			}
			int index = hashFunction(key);

			while (table[index] != -1) {
				index = (index + 1) % table_size;
			}
			cout << "Adding Key: " << key << " Using Linear Probing:\n";

			table[index] = key;
		}

		void insertQuadraticProbing(int key) {

			if (isTableFull()) {
				cout << "Hash table is full. Cannot insert more elements." << endl;
				return;
			}
			int index = hashFunction(key);
			int i = 1;

			while (table[index] != -1) {
				index = (index + i * i) % table_size;
				i++;
			}
			cout << "Adding Key: " << key << " Using Quadratic Probing:\n";

			table[index] = key;
		}

		void insertDoubleHashing(int key) {
			int index = hashFunction(key);
			int i = 1;

			while (table[index] != -1) {
				index = (index + i * hashFunction2(key)) % table_size;
				i++;
			}

			table[index] = key;
		}


		int searchLinearProbing(int key) {
			int index = hashFunction(key);
			int i = 1;

			while (table[index] != -1) {
				if (table[index] == key) {
					return index;
				}
				index = (index + 1) % table_size;
			}

			return -1;
		}

		int searchQuadraticProbing(int key) {
			int index = hashFunction(key);
			int i = 1;

			while (table[index] != -1) {
				if (table[index] == key) {
					return index;
				}
				index = (index + i * i) % table_size;
				i++;
			}

			return -1;
		}

		int searchDoubleHashing(int key) {
			int index = hashFunction(key);
			int i = 1;

			while (table[index] != -1) {
				if (table[index] == key) {
					return index;
				}
				index = (index + i * hashFunction2(key)) % table_size;
				i++;
			}

			return -1; // Key not found
		}


		void removeLinearProbing(int key) {
			if (isTableEmpty()) {
				cout << "Hash table is empty. Cannot perform removal." << endl;
				return;
			}

			int index = searchLinearProbing(key);

			if (index != -1) {
				table[index] = -1;
				cout << "Key " << key << " removed successfully using Linear Probing." << endl;
			} else {
				cout << "Key " << key << " not found in the hash table using Linear Probing." << endl;
			}
		}

		void removeQuadraticProbing(int key) {
			if (isTableEmpty()) {
				cout << "Hash table is empty. Cannot perform removal." << endl;
				return;
			}

			int index = searchQuadraticProbing(key);

			if (index != -1) {
				table[index] = -1;
				cout << "Key " << key << " removed successfully using Quadratic Probing." << endl;
			} else {
				cout << "Key " << key << " not found in the hash table using Quadratic Probing." << endl;
			}
		}

		void removeDoubleHashing(int key) {
			if (isTableEmpty()) {
				cout << "Hash table is empty. Cannot perform removal." << endl;
				return;
			}

			int index = searchDoubleHashing(key);

			if (index != -1) {
				table[index] = -1;
				cout << "Key " << key << " removed successfully using Double Probing." << endl;

			} else {
				cout << "Key " << key << " not found in the hash table using Double Probing." << endl;
			}
		}

		bool isTableEmpty() {
			for (int i = 0; i < table_size; i++) {
				if (table[i] != -1) {
					return false;
				}
			}
			return true;
		}


		bool isTableFull() {
			for (int i = 0; i < table_size; i++) {
				if (table[i] == -1) {
					return false;
				}
			}
			return true;
		}

		void displayHashTable() {
			for (int i = 0; i < table_size; i++) {
				cout << i;
				if (table[i] != -1) {
					cout << " ==> " << table[i];
				}
				cout << endl;
			}
		}
};

template <class T>
void takeInput(T &reference) {
	cin >> reference;
	while (!cin) {
		cout << "\n\tInvalid Input, Try Again: " << endl;
		cout << "\n\t\t Your Input: ";
		cin.clear();
		cin.ignore();
		cin >> reference;
	}
}

int main() {
	int chooseProb;
	int size, key;

	cout << "Enter the Size of Table: ";
	takeInput(size);

	HashTable *htLinear = nullptr;
	HashTable *htQuadratic = nullptr;
	HashTable *htDouble = nullptr;

	do {
		cout << "\n\n*Select The Type Of Probing*\n"
		     << endl;
		cout << "\t[1] Linear Probing\n"
		     << endl;
		cout << "\t[2] Quadratic Probing\n"
		     << endl;
		cout << "\t[3] Double Hashing\n"
		     << endl;
		cout << "\n\t\t Your Choice: ";
		takeInput(chooseProb);

		switch (chooseProb) {
			case 1:
				htLinear = new HashTable(size);
				break;
			case 2:
				htQuadratic = new HashTable(size);
				break;
			case 3:
				htDouble = new HashTable(size);
				// Implement Double Hashing
				break;
			default:
				cout << "\n\tInvalid choice! Please enter a valid option.\n";
				break;
		}

		cout << "\n===============================================================" << endl;
	} while (chooseProb != 1 && chooseProb != 2 && chooseProb != 3);

	string choice;

	do {
		cout << "\n\n*Choose an operation*\n"
		     << endl;
		cout << "\t[A] Insert Element(Integer)\n"
		     << endl;
		cout << "\t[B] Delete Element(Integer)\n"
		     << endl;
		cout << "\t[C] Search Element\n"
		     << endl;
		cout << "\t[D] Display Hashing Table\n"
		     << endl;
		cout << "\t[E] Exit\n"
		     << endl;
		cout << "\n\t\t Your Choice: ";
		takeInput(choice);
		cout << "\n===============================================================" << endl;

		if (choice == "A" || choice == "a") {
			cout << "Enter your key: ";
			takeInput(key);
			switch (chooseProb) {
				case 1:
					htLinear->insertLinearProbing(key);
					break;

				case 2:
					htQuadratic->insertQuadraticProbing(key);
					break;

				case 3:
					htDouble->insertDoubleHashing(key);
					break;
			}
		} else if (choice == "B" || choice == "b") {
			cout << "Enter the key to delete: ";
			takeInput(key);

			switch (chooseProb) {
				case 1:
					htLinear->removeLinearProbing(key);
					break;

				case 2:
					htQuadratic->removeQuadraticProbing(key);
					break;

				case 3:
					htDouble->removeDoubleHashing(key);
					break;
			}
		} else if (choice == "C" || choice == "c") {
			cout << "Enter your key to search: ";
			takeInput(key);
			switch (chooseProb) {
				case 1:
					if (htLinear->searchLinearProbing(key) != -1) {
						cout << "key: " << key << " found at index: " << htLinear->searchLinearProbing(key) << endl;
					} else {
						cout << "Value not found" << endl;
					}

					break;

				case 2:
					if (htQuadratic->searchQuadraticProbing(key) != -1) {
						cout << "key: " << key << " found at index: " << htQuadratic->searchQuadraticProbing(key) << endl;
					} else {
						cout << "Value not found" << endl;
					}

					break;

				case 3:
					if (htDouble->searchDoubleHashing(key) != -1) {
						cout << "key: " << key << " found at index: " << htDouble->searchDoubleHashing(key) << endl;
					} else {
						cout << "Value not found" << endl;
					}
					break;
			}
		} else if (choice == "D" || choice == "d") {
			switch (chooseProb) {
				case 1:
					cout << "Displaying the Table: " << endl;
					htLinear->displayHashTable();
					break;
				case 2:
					cout << "Displaying the Table: " << endl;
					htQuadratic->displayHashTable();
					break;
				case 3:
					cout << "Displaying the Table: " << endl;
					htDouble->displayHashTable();
					break;
			}
		}

		else if (choice == "e" || choice == "E") {
			cout << "\n**Exiting program\n";
		} else {
			cout << "\n\tInvalid choice! Please enter a valid option.\n";
		}

		cout << "\n===============================================================" << endl;

	} while ((choice != "E") && (choice != "e"));

	delete htLinear;
	delete htQuadratic;
	delete htDouble;

	return 0;
}