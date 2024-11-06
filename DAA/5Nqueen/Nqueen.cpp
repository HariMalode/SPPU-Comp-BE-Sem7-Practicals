#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// Helper function to perform backtracking
void solve(int n, int row, vector<string>& board, vector<vector<string>>& solutions, unordered_set<int>& columns, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
    // If all rows have a queen placed, add board to solutions
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; ++col) {
        // Check if column or diagonals are occupied
        if (columns.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) continue;

        // Place the queen and mark column and diagonals
        board[row][col] = 'Q';
        columns.insert(col);
        posDiag.insert(row + col);
        negDiag.insert(row - col);

        // Move to the next row
        solve(n, row + 1, board, solutions, columns, posDiag, negDiag);

        // Backtrack: remove the queen and unmark column and diagonals
        board[row][col] = '.';
        columns.erase(col);
        posDiag.erase(row + col);
        negDiag.erase(row - col);
    }
}

vector<vector<string>> solveNQueens(int n, int firstQueenCol) {
    // Initialize board and data structures for tracking
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;
    unordered_set<int> columns, posDiag, negDiag;

    // Place the first queen in the specified column of the first row
    board[0][firstQueenCol] = 'Q';
    columns.insert(firstQueenCol);
    posDiag.insert(firstQueenCol);
    negDiag.insert(-firstQueenCol);

    // Start solving from the second row
    solve(n, 1, board, solutions, columns, posDiag, negDiag);
    return solutions;
}

int main() {
    int n = 6;
    int firstQueenCol = 1;

    // Get all solutions
    vector<vector<string>> solutions = solveNQueens(n, firstQueenCol);

    // Print one solution
    if (!solutions.empty()) {
        cout << "One of the solutions is:" << endl;
        for (const auto& row : solutions[0]) {
            cout << row << endl;
        }
    } else {
        cout << "No solutions found." << endl;
    }

    return 0;
}
