#include <iostream>
#include <vector>
using namespace std;

int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if (i == m - 1 && j == n - 1) return 1; // Reached destination
    if (i >= m || j >= n) return 0; // Out of bounds
    if (dp[i][j] != -1) return dp[i][j]; // Return stored result

    return dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
}

int main() {
    int m = 3, n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Total Unique Paths: " << countPaths(0, 0, m, n, dp) << endl;
    return 0;
}
