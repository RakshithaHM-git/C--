#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern) {
    int d = 256;     // number of characters
    int q = 101;     // prime number
    int m = pattern.length();
    int n = text.length();

    int p = 0;   // hash value for pattern
    int t = 0;   // hash value for text
    int h = 1;

    // Calculate h = (d^(m-1)) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {

        // If hash values match, check characters
        if (p == t) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Make hash value positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    rabinKarp(text, pattern);

    return 0;
}
