#include <iostream>
using namespace std;

// Function for sequential search
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;   // element found
        }
    }
    return -1;  // element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = sequentialSearch(arr, n, key);

    if (result != -1) {
        cout << "Element found at index " << result;
    } else {
        cout << "Element not found";
    }

    return 0;
}
