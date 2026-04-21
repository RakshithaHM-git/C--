#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 256

void badCharHeuristic(char pattern[], int m, int badchar[]) {
    for (int i = 0; i < SIZE; i++)
        badchar[i] = -1;

    for (int i = 0; i < m; i++)
        badchar[(int)pattern[i]] = i;
}

void boyerMoore(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badchar[SIZE];
    badCharHeuristic(pattern, m, badchar);

    int s = 0;

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;

            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } 
        else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}

int main() {
    char text[100], pattern[100];

    cout << "Enter the text: ";
    cin.getline(text, 100);

    cout << "Enter the pattern: ";
    cin.getline(pattern, 100);

    boyerMoore(text, pattern);

    return 0;
}