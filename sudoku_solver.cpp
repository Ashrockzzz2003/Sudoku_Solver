#include <bits/stdc++.h>
using namespace std;

#define N 9

void print_sudokuGrid(int grid[N][N]) {
    //print the sudoku grid after solve
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

bool is_safe(int grid[N][N], int row, int col, int num) {
    //Row Check
    for (int x = 0; x <= N - 1; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    //Column Check
    for (int x = 0; x <= N - 1; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    //subGrids
    int start_row = row - row % ((int)sqrt(N));
    int start_col = col - col % ((int)sqrt(N));

    for (int i = 0; i < ((int)sqrt(N)); i++) {
        for (int j = 0; j < ((int)sqrt(N)); j++) {
            if (grid[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve_sudoku(grid, row, col + 1)) {
                return true;
            }
        }

        grid[row][col] = 0;
    }
    return false;
}

int main() {
    int grid[N][N];

    cout << "Sudoku Solver\n" << endl;

    
    for (int i = 0; i < N; i++) {
        string row_string;
        cout << "Enter Row " << i + 1 << ": ";
        cin >> row_string;
        for (int j = 0; j < N; j++) {
            grid[i][j] = row_string[j] - '0';
        }
    }

    cout << "Question: \n" << endl;
    print_sudokuGrid(grid);
    cout << endl;
    cout << "\nSolution to Sudoku:\n\n";
    if (solve_sudoku(grid, 0, 0)) {
        print_sudokuGrid(grid);
    }
    else {
        cout << "No solution Exists!" << endl;
    }

    cout << "Developed by,\nAshwin Narayanan S";
}
