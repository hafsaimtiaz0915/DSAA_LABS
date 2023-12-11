#include <iostream>
#include <conio.h>
#include <cctype>

#include "recursive.h"

using namespace std;
int main()
{

    string choice;

    do
    {
        system("cls");
        cout << "\n\n****Choose an operation**\n"
             << endl;
        cout << "\t[A] Calculate factorial of number\n"
             << endl;
        cout << "\t[B] Display Fibonacci Series\n"
             << endl;
        cout << "\t[c] Reverse Printing of Input\n"
             << endl;
        cout << "\t[D] Calculate Power\n"
             << endl;
        cout << "\t[E] Print Odd Numbers\n"
             << endl;
        cout << "\t[F] Exit\n"
             << endl;
        cout << "\n\t\t Your Choice: ";
        cin >> choice;
        cout << "\n===============================================================" << endl;

        if (choice == "A" || choice == "a")
        {
            long long int num;
            cout << "\nEnter number(integer):\n";

            while (true)
            {
                cout << "Number must be greater than 1 or less than 21\n";
                cout << "\n\t\t Your Input: ";
                takeInput(num);
                if (num >= 2 && num <= 20)
                {
                    cout << "\nThe factorial of " << num << " is " << factorial(num) << endl;
                    cout << "\n\tPress Enter to Continue." << endl;
                    getch();
                    break;
                }
                else
                {
                    cout << "\n\tInvalid input." << endl;
                }
            }
        }
        else if (choice == "B" || choice == "b")
        {
            int num1;
            cout << "\nEnter the number of terms in Fibonacci Series\n";
            while (true)
            {
                cout << "\tNumber must be (Integer) greater than 2\n";
                cout << "\n\t\t Your Input: ";
                takeInput(num1);

                if (num1 > 2)
                {

                    cout << "\n Printing Fabionacci Series Up to " << num1 << "terms: \n\n\t\t" << fibonacci(0);
                    for (int i = 1; i < num1; i++)
                        cout << " , " << fibonacci(i);

                    cout << "\n\n\tPress Enter to Continue." << endl;
                    getch();
                    break;
                }
                else
                {
                    cout << "\n\tInvalid input." << endl;
                }
            }
        }
        else if (choice == "C" || choice == "c")
        {

            char symbol;
            while (true)
            {
                cout << "\nEnter Special character:";
                cin >> symbol;
                if (!isalnum(symbol))
                {
                    Character(symbol);
                    cout << "\n\n\tPress Enter to Continue." << endl;
                    getch();
                    break;
                }
                else
                    cout << "\nInvalid Input. ";
            }
        }
        else if (choice == "D" || choice == "d")
        {
            double base;
            int exponent;

            cout << "\nEnter the base (double): ";
            takeInput(base);
            while (true)
            {
                cout << "\nEnter the exponent (non-negative integer): ";
                takeInput(exponent);
                if (exponent > 0)
                {
                    cout << endl
                         << base << " raised to the power " << exponent << " is: " << pow(base, exponent) << endl;
                    cout << "\n\n\tPress Enter to Continue." << endl;
                    getch();
                    break;
                }
                else
                {
                    cout << "\nInvalid input. Please enter a non-negative integer." << endl;
                }
            }
        }
        else if (choice == "E" || choice == "e")
        {
            int n;
            while (true)
            {
                cout << "\nEnter Positive number(Integer): ";
                takeInput(n);
                if (n >= 1)
                {
                    cout << "\n\t\tPrinting odd numbers:" << endl;
                    cout << " a. between 1 and " << n << ":\n\n\t ";
                    print1(n);
                    cout << "\n\n b. between " << n << " and 1:"
                         << "\n\n\t ";
                    print2(n);
                    cout << "\n\n\tPress Enter to Continue." << endl;
                    getch();
                    break;
                }
                else
                    cout << "\n\tInvalid Input." << endl;
            }
        }
        else if (choice == "F" || choice == "f")
            cout << "\n****Exiting program****\n";
        else
        {
            cout << "\n\tInvalid choice! Please enter a valid option.\n";
            cout << "\tPress Enter to Continue." << endl;
            getch();
        }

        cout << "\n===============================================================" << endl;

    } while ((choice != "F") && (choice != "f"));

    return 0;
}