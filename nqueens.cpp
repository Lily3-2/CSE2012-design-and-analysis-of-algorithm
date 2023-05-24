//N Queens Problem
//The goal of this puzzle is to arrange N chessboard queens in such a way that no queen can attack any other queen on the board. Chess queens can strike in any direction, including diagonally, vertically, and horizontally.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col) {
  int i, j;

  // Check this row on left side
  for (i = 0; i < col; i++) {
    if (board[row][i]) {
      return false;
    }
  }

  // Check upper diagonal on left side
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }

  // Check lower diagonal on left side
  for (i = row, j = col; j >= 0 && i < board.size(); i++, j--) {
    if (board[i][j]) {
      return false;
    }
  }

  return true;
}

bool solveNQueens(vector<vector<int>> &board, int col) {
  if (col >= board.size()) {
    return true;
  }

  for (int row = 0; row < board.size(); row++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1;
      if (solveNQueens(board, col + 1)) {
        return true;
      }
      board[row][col] = 0;
    }
  }

  return false;
}

void printBoard(vector<vector<int>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n;
  cout<<"Enter the number of queens: ";
  cin>>n;

  // Initialize the board with all zeros
  vector<vector<int>> board(n, vector<int>(n, 0));

  if (solveNQueens(board, 0)) {
    cout << "Solution found: \n";
    printBoard(board);
  } else {
    cout << "Solution not found for n = " << n << "\n";
  }

  return 0;
}
