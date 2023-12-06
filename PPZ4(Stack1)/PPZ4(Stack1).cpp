#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValidString(const string& s) {
   stack<char> charStack;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            charStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (charStack.empty()) {
                return false; // Закрита дужка, але стек порожній, невірно
            }

            char openBracket = charStack.top();
            charStack.pop();

            // Перевірка відповідності відкритої та закритої дужок
            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false;
            }
        }
    }

    return charStack.empty(); // Рядок вірний, якщо стек порожній
}

int main() {
    string inputString;
    cout << "Enter a string with parentheses: ";
    do { cin >> inputString; } while (inputString.length() > 1001 || inputString.length() < 0);

    if (isValidString(inputString)) {
        cout << "The entered string is valid.\n";
    }
    else {
        cout << "The entered string is not valid.\n";
    }

    return 0;
}