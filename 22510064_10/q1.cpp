#include <iostream>
#include <vector>
#include <cmath>  // For abs() 

using namespace std;

// Function to check if placing a queen at (row, col) is valid
bool is_valid(vector<int>& queens, int row, int col) {
    for (int i = 0; i < col; i++) {
        // Check for row and diagonal conflicts
        if (queens[i] == row || abs(queens[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve N-Queens
void place_queens(int col, vector<int>& queens, vector<vector<int>>& solutions, int n) {
    if (col == n) {
        // All queens have been placed, add the solution to results
        solutions.push_back(queens);  // Copy the current configuration
        return;
    }
    
    // Try placing a queen in every row for the current column
    for (int row = 0; row < n; row++) {
        if (is_valid(queens, row, col)) {
            queens[col] = row;  // Place the queen
            place_queens(col + 1, queens, solutions, n);  // Move to the next column
            // No need to explicitly backtrack because we overwrite queens[col] in the next iteration
        }
    }
}

// Function to solve N-Queens and return all solutions
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;  // To store all the valid solutions
    vector<int> queens(n, -1);  // To store the position of queens
    place_queens(0, queens, solutions, n);  // Start placing queens from column 0
    return solutions;
}

// Function to print the solutions in 1-based index format
void print_solutions(vector<vector<int>>& solutions) {
    for (const auto& sol : solutions) {
        for (int q : sol) {
            cout << q + 1 << " ";  // Convert 0-based to 1-based indexing
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> solutions = solveNQueens(n);
    cout << "Solutions for N = " << n << ":\n";
    print_solutions(solutions);

    return 0;
}
