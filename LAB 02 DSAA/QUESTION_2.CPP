#include <iostream>
using namespace std;
class Person
{
public:
    string first_name;
    string last_name;
    int birth_year, birth_date, birth_month;
    Person()
    {
        first_name = '\0';
        last_name = '\0';
        birth_year = 0;
        birth_date = 0;
        birth_month = 0;
    }
    Person(string fn, string ln, int y, int d, int m)
    {
        first_name = fn;
        last_name = ln;
        birth_year = y;
        birth_date = d;
        birth_month = m;
    }
    void input_data()
    {
        cout << "Enter first name : ";
        cin >> first_name;
        cout << "Enter last name : ";
        cin >> last_name;
        cout << "Enter birth year : ";
        cin >> birth_year;
        cout << "Enter birth month : ";
        cin >> birth_month;
        cout << "Enter birth date : ";
        cin >> birth_date;
    }
    void selectionSort(Person people[], int n)
    {
        Person min;
        int location = 0;
        for (int i = 0; i < n - 1; i++)
        {
            min = people[i];
            location = i;
            for (int j = i + 1; j < n; j++)
            {
                if ((min.birth_year > people[j].birth_year) || (min.birth_year == people[j].birth_year && min.birth_month > people[j].birth_month) || (min.birth_year == people[j].birth_year && min.birth_month == people[j].birth_month && min.birth_date == people[j].birth_date))
                {
                    min = people[j];
                    location = j;
                }
            }
            swap(people[i], people[location]);
        }
    }
};
int main()
{
    int N;
    cout << "Enter no of person : ";
    cin >> N;
    Person p[N];
    for (int i = 0; i < N; i++)
    {
        cout << "=================================================" << endl;
        p[i].input_data();
        cout << "=================================================" << endl;
    }
    Person sort;
    sort.selectionSort(p, N);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << p[i].first_name << " " << p[i].last_name << " : " << p[i].birth_year << "/" << p[i].birth_month << "/" << p[i].birth_date << endl;
    }
    return 0;
}