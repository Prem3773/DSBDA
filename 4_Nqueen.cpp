#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int n;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // Check row on left side
        for (int j = 0; j < col; j++)
            if (board[row][j])
                return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    bool solveNQueensUtil(int col) {
        if (col >= n)
            return true;

        for (int i = 0; i < n; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (solveNQueensUtil(col + 1))
                    return true;

                board[i][col] = 0; // Backtrack
            }
        }
        return false;
    }

public:
    NQueens(int size) : n(size) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void solve() {
        if (!solveNQueensUtil(0)) {
            cout << "Solution does not exist!" << endl;
            return;
        }
        printBoard();
    }

    void printBoard() {
        cout << "\nSolution Board: (1 represents Queen)\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of chess board (N x N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid board size!" << endl;
        return 1;
    }

    NQueens nQueens(n);
    nQueens.solve();

    return 0;
}
