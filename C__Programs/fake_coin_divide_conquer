#include <iostream>
#include <vector>
using namespace std;

// Function to find fake coin index
int findFakeCoin(vector<int>& coins, int left, int right) {
    // Base case: only one coin
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;

    // Calculate sum of left half
    int sumLeft = 0;
    for (int i = left; i <= mid; i++) {
        sumLeft += coins[i];
    }

    // Calculate sum of right half
    int sumRight = 0;
    for (int i = mid + 1; i <= right; i++) {
        sumRight += coins[i];
    }

    // Compare sums
    if (sumLeft < sumRight) {
        // Fake coin is in left half
        return findFakeCoin(coins, left, mid);
    } else {
        // Fake coin is in right half
        return findFakeCoin(coins, mid + 1, right);
    }
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter weights of coins:\n";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int index = findFakeCoin(coins, 0, n - 1);

    cout << "Fake coin found at position: " << index << endl;
    cout << "Weight of fake coin: " << coins[index] << endl;

    return 0;
}