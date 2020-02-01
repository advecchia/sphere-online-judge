#include <iostream>
using namespace std;

const int ANSWER_OF_THE_LIFE=42;

/**
 * Will read from input until receive the answer of the life, the universe and everything.
 */
int main() {
    int input;
    while(cin >> input) {
        if (ANSWER_OF_THE_LIFE == input) {
            return 0;
        }
        cout << input;
        cout << "\n";
    }
}
