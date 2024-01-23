/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 5. So­lu­cio­na­dor de Su­do­ku:
- Es­cri­be un pro­gra­ma que re­suel­va un rom­pe­ca­be­zas de Su­do­ku in­gre­sa­do
por el usua­rio.
************************************************/
#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
const int EMPTY = 0;

bool find_empty(vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

bool is_valid(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int row_start = row - row % 3;
    int col_start = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + row_start][j + col_start] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(vector<vector<int>>& board) {
    int row, col;

    if (!find_empty(board, row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board)) {
                return true;
            }
            board[row][col] = EMPTY;
        }
    }
    return false;
}

void print_board(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    cout << "Ingrese el rompecabezas de Sudoku (utilice 0 para espacios vacíos):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    if (solve_sudoku(board)) {
        cout << "Solución encontrada:" << endl;
        print_board(board);
    } else {
        cout << "No se encontró solución para el rompecabezas de Sudoku ingresado." << endl;
    }

    return 0;
}

