#include <iostream>
using namespace std;
bool checkNeighbour(bool neighbour[][5], int c1, int c2)
{
    for (int i = 0; i < 5; i++)
    {
        if (c1 == c2)
        {
            cout << "same city!";
            exit(0);
        }
        if (neighbour[c1][i] && (neighbour[c2][i]))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    bool neighbours[5][5] = {{false, true, false, false, false},
                             {true, false, true, false, false},
                             {false, true, false, false, true},
                             {false, true, true, false, false},
                             {false, true, true, true, false}};
    int city1;
    int city2;
    cout << "Enter city1:";
    cin >> city1;
    cout << "Enter city2:";
    cin >> city2;
    if (checkNeighbour(neighbours, city1, city2))
    {
        cout << "Have a common neighbour.";
    }
    else
    {
        cout << "Do not have a common neighbour.";
    }
}