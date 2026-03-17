#include <iostream>
#include <vector>
using namespace std;

bool is_safe(vector<vector<int>>& board, int i_ferz, int j_ferz) {
    if (board[i_ferz][j_ferz] != 0) {
        return false;
    }
    return true;
}

vector<vector<int>> zap(vector<vector<int>>& board, int i_ferz, int j_ferz, int n) {
    board[i_ferz][j_ferz] = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 2) {
                if ((i == i_ferz) || (j == j_ferz) || (abs(i - i_ferz) == abs(j - j_ferz))) {
                    board[i][j] = 1;
                }
            }
        }
    }
    return board;
}

void print_solution(vector<vector<int>>& board, int n, int solution_number) {
    cout << "Reshenie " << solution_number << ": ";
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (board[i][j] == 2) {
                cout << "(" << i + 1 << "," << j + 1 << ") ";
                break;
            }
        }
    }
    cout << endl;
}

int podscet(vector<vector<int>>& board, int row, int n, int& solution_count) {
    if (row == n) {
        solution_count++;
        print_solution(board, n, solution_count);
        return 1;
    }
    
    int total = 0;
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            vector<vector<int>> board_copy = board;
            board = zap(board, row, col, n);
            total += podscet(board, row + 1, n, solution_count);
            board = board_copy;
        }
    }
    
    return total;
}

int konec(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    int solution_count = 0;
    int schet = podscet(board, 0, n, solution_count);
    return schet;
}

int main() {
    int n = 8;
    int total = konec(n);
    cout << "Vsego Resh: " << total << endl;
    return 0;
}