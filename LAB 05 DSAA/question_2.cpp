#include <iostream>
#include <string>
#include "stack.h"
using namespace std;



bool checking(string word,Stack<char> stack) {

    for (int i = (stack.get_size()+1) / 2,j=0; i < stack.get_size(); i++,j++) {
        	if (word[j] != stack.get_top())
            	return false;
          	stack.pop();
	}
    return true;
}


int main() {
    string word,newWord;
	char choice = 'n';
    
    do{
	
    cout << "--------------------------------------------------------------------------" << endl;
	cout << "Enter a String, number, or phrase without special characters: "<< endl;
        cout << "\n\tYour Input:  ";
            	getline(cin, word);


    for (int i = 0; i < word.length(); i++) {
        if ((word[i] >= 48 && word[i] <= 57)||(word[i] >= 65 && word[i] <= 90)||(word[i] >= 97 && word[i] <= 122)){
            newWord += tolower(word[i]);
            choice = 'n';
        }
        else if (word[i] == ' ')
        	continue;   
        else{
        	cout << "\n Invalid Input! Don't Enter Special Characters.\n" << endl;
        	choice = 'y'; 
        	newWord = "";
        	break;
		}    
    }
	}while(choice == 'y');

    Stack<char> stack(newWord.length());

    for (int i = 0; i < newWord.length(); i++) {
        stack.push(newWord[i]);
    }
    if (checking(newWord,stack))
        cout << "\n\t\t It is a Palindrome." << endl;
    else
        cout << "\n\t\t It is not a Palindrome." << endl;
        cout << "\n--------------------------------------------------------------------------" <<endl;
    return 0;
}