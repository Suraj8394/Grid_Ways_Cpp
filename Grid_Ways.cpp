#include <iostream>
using namespace std;

// Function to count grid paths using recursion
int countWays(int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) return 1; // Reached destination
    if (i >= m || j >= n) return 0; // Out of bounds

    // Move right and down
    return countWays(i + 1, j, m, n) + countWays(i, j + 1, m, n);
}

int main() {
    int m = 3, n = 3; // Grid size
    cout << "Total unique paths: " << countWays(0, 0, m, n) << endl;
    return 0;
}
