#include <iostream>
#include <cstdlib>
using namespace std;
void display(float CGPA[],int no_stu){
     for (int i = 0; i < no_stu; i++) {
        cout << "Cgpa of student " << i + 1 << " is " << CGPA[i] << endl;
    } 
}

void calculating_cgpa(int no_stu, float **gpa, int s[]) {
    float cgpa[no_stu];
    int credit_hrs=0;
    for (int i = 0; i < no_stu; i++) {
        cgpa[i] = 0;
        cout << "*************Student " << i + 1 << " GPA*****************" << endl;
        for (int j = 0; j < s[i]; j++) {
            cout << "Enter " << j + 1 << " subject gpa: ";
            cin >> gpa[i][j];
            cgpa[i] += (gpa[i][j] * 3);
            credit_hrs+=3;
        }
        cgpa[i] /= credit_hrs;
    }
    display(cgpa,no_stu);
  
}
int main() {
    int no_student;
    cout << "Enter number of students: ";
    cin >> no_student;

    float **arr = new float *[no_student];
    int Size[no_student];

    for (int i = 0; i < no_student; i++) {
        cout << "Enter no of courses student " << i + 1 << " has taken: ";
        cin >> Size[i];
        arr[i] = new float[Size[i]];
    }

    calculating_cgpa(no_student, arr, Size);

    //deallocate the dynamically allocated memory
    for (int i = 0; i < no_student; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
