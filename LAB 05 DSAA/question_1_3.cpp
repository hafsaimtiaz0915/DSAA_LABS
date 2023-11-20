#include <iostream>
#include "stack.h"
#include <cmath>
using namespace std;
bool Checkdelimiter(string Expression, Stack<char> &S)
{
    char ch;
    char temp;

    for (int counter = 0; counter < Expression.length(); counter++)
    {
        ch = Expression[counter];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            S.push(ch);
        }
        else if (ch == '/')
        {
            temp = Expression[counter + 1];
            if (temp == '*')
            {
                S.push(ch);
                counter++;
            }
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            temp = S.pop();
            if ((ch == ')' && temp != '(') || (ch == ']' && temp != '[') || (ch == '}' && temp != '{'))
            {
                return false;
            }
        }
        else if (ch == '*')
        {
            temp = Expression[counter + 1];
            if (temp == '/')
            {
                temp = S.pop();
                if (temp != '/')
                    return false;
            }
        }
    }
    return S.IsEmpty();
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
bool isOperand(char c)
{
    return c >= '0' && c <= '9';
}
bool isExpressionValid(const string &expression)
{
    int operandCount = 0;
    int operatorCount = 0;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (isOperator(expression[0]) || isOperator(expression[(expression.length() - 1)]))
        {
            return false;
        }
        else if (c >= '0' && c <= '9')
        {
            operandCount++;
        }
        else if (c == '[' || c == ']' || c == '(' || c == ')' || c == '{' || c == '}')
        {
            continue;
        }
        else if (isOperator(c))
        {
            operatorCount++;
        }
        else
        {
            return false;
        }
    }
    return operandCount == operatorCount + 1;
}
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}
string infixToPostfix(const string &infixExpression)
{
    string postfixExpression = "";
    Stack<char> operatorStack(infixExpression.length());

    for (int i = 0; i < infixExpression.length(); i++)
    {
        char c = infixExpression[i];
        if (isOperand(c))
        {
            postfixExpression += c;
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.IsEmpty() && operatorStack.get_top() != '(')
            {
                postfixExpression += operatorStack.get_top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else
        {
            while (!operatorStack.IsEmpty() && getPrecedence(c) <= getPrecedence(operatorStack.get_top()))
            {
                postfixExpression += operatorStack.get_top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.IsEmpty())
    {
        postfixExpression += operatorStack.get_top();
        operatorStack.pop();
    }

    return postfixExpression;
}

double evaluatePostfix(const string &postfix)
{
    Stack<double> operandStack(postfix.length());

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (isOperand(c))
        {
            operandStack.push(c - '0');
        }
        else
        {
            double operand2 = operandStack.pop();
            double operand1 = operandStack.pop();

            switch (c)
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            case '^':
                operandStack.push(pow(operand2, operand1));
                break;
            default:
                cout << "Invalid operator" << endl;
            }
        }
    }

    return operandStack.pop();
}

int main()
{
    char choice;
    do
    {
        system("CLS");
        string infixExpression;
        cout << "\n========================================================" << endl;
        cout << "\n\tEnter an infix expression: ";
        getline(cin, infixExpression);
        Stack<char> S(infixExpression.length());

        // Check if the infix expression is correct
        if (Checkdelimiter(infixExpression, S) && isExpressionValid(infixExpression))
        {
            cout << "\n========================================================" << endl;
            cout << "\n\tExpression is correct" << endl;
            cout << "\n========================================================" << endl;
            // Convert infix to postfix
            string postfixExpression = infixToPostfix(infixExpression);
            cout << "\n\tPostfix expression: " << postfixExpression << endl;
            cout << "\n========================================================" << endl;

            double result = evaluatePostfix(postfixExpression);
            cout << "Result: " << result << endl;
            cout << "\n========================================================" << endl;
        }
        else
        {
            cout << "\n========================================================" << endl;
            cout << "\n\tExpression is not correct\n"
                 << endl;
        }
        cout << "========================================================" << endl;
        cout << "\n\tDo you want to solve another expression press [Y] to continue or any key to stop. ";
        cin >> choice;
        cin.ignore();
    } while ((choice == 'y') || (choice == 'Y'));

    return 0;
}
