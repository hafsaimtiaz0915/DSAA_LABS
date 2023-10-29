#include<iostream>
using namespace std;

int main() {
    int std_no,contributors_no;
    string **Students,name, contributorName;

    cout << "Enter Number of Classes: ";
    cin >> std_no;
 int contributors[std_no];
    Students = new string*[std_no];

    for (int i = 0; i < std_no; i++) {
        cout << "Enter the Number of Contributors for Class " << i + 1 <<": ";
        cin >> contributors_no;
            contributors[i]= contributors_no;
           
        Students[i] = new string[contributors_no];

        cout << "Now Enter the Names of Contributors" << endl;
            cout << endl;
        for (int j = 0; j < contributors_no; j++) {
            cout << "Contributor " << j + 1 << ": ";
            cin.ignore();
                getline(cin,contributorName);
            Students[i][j] = contributorName;
        }
        cout << endl;
    }

    cout << "Enter the Name of Contributor to search: ";
        getline(cin,name);
    bool found = false;
    int index = -1;

    for (int i = 0; i < std_no; i++) {
        for (int j = 0; j < contributors[i]; j++) {
            if (Students[i][j] == name) {
                found = true;
                index = i;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        cout << name << " has contributed." << endl;
    } else {
        cout << name << " was not found among the contributors." << endl;
    }

    for (int i = 0; i < std_no; i++) {
        delete[] Students[i];
    }
    delete[] Students;

    return 0;
}