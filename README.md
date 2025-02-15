# 🟢 Grid Ways (Unique Paths) – Explanation in Detail  

## 🔍 **Problem Statement**  
Given an `m × n` grid, you are at the **top-left corner** and need to reach the **bottom-right corner**. You can **only move right (→) or down (↓)**. Find the total number of possible unique paths.  

### **Example 1:**
```
Input: 3 x 3 Grid
Output: 6
```
### **Example 2:**
```
Input: 2 x 2 Grid
Output: 2
```

---

## 🛠 **Approaches to Solve Grid Ways**  

### **1️⃣ Recursive Approach (Backtracking) – Brute Force**  

🔹 **How it works:**  
- Start from `(0,0)`.  
- Move **right** (`→`) or **down** (`↓`).  
- If you reach `(m-1, n-1)`, count it as a valid path.  
- If you move out of bounds, return `0`.  

### **C++ Code (Recursive)**
```cpp
#include <iostream>
using namespace std;

int countPaths(int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) return 1; // Reached destination
    if (i >= m || j >= n) return 0; // Out of bounds

    return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
}

int main() {
    int m = 3, n = 3;
    cout << "Total Unique Paths: " << countPaths(0, 0, m, n) << endl;
    return 0;
}
```
### **Time Complexity:** `O(2^(m+n))` (Exponential)  
🔴 **Inefficient for large grids** because of repeated calculations.

---

### **2️⃣ Dynamic Programming (Memoization) – Optimized Approach**  

🔹 **How it works:**  
- Use a **2D DP array `dp[m][n]`** to store precomputed values.  
- If a subproblem is already solved, return its stored value.  

### **C++ Code (Memoization)**
```cpp
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
```
### **Time Complexity:** `O(m × n)`  
✅ **Much faster than recursion**.

---

### **3️⃣ Combinatorial Approach (Best Method) – Formula Based**  

🔹 **How it works:**  
- The number of unique paths from `(0,0) → (m-1, n-1)` is given by:  
  \[
  \text{Total Paths} = \frac{(m+n-2)!}{(m-1)! \times (n-1)!}
  \]
- This formula **chooses `(m-1)` down moves** from `m+n-2` total moves.

### **C++ Code (Using Factorial Formula)**
```cpp
#include <iostream>
using namespace std;

long long factorial(int num) {
    long long res = 1;
    for (int i = 1; i <= num; i++) res *= i;
    return res;
}

long long uniquePaths(int m, int n) {
    return factorial(m + n - 2) / (factorial(m - 1) * factorial(n - 1));
}

int main() {
    int m = 3, n = 3;
    cout << "Total Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}
```
### **Time Complexity:** `O(m + n)`  
✅ **Most efficient approach!**

---

## 📈 **Time Complexity Comparison**  

| Method | Time Complexity | Space Complexity | Efficiency |
|--------|---------------|----------------|------------|
| Recursion | `O(2^(m+n))` | `O(1)` | ❌ **Very slow** |
| DP Memoization | `O(m × n)` | `O(m × n)` | ✅ **Fast** |
| Combinatorial | `O(m + n)` | `O(1)` | 🔥 **Best** |

---

## 🔥 **Conclusion**  
✔ **Use Recursion** for small grids (e.g., `3x3`).  
✔ **Use Dynamic Programming** for moderate-sized grids.  
✔ **Use Combinatorial Formula** for large grids (`100x100`).  
