#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <locale.h>
using namespace std;

void DivRow(int row, int cols, int col, float** mat) {
    float lead = mat[row][col];

    
    if (lead == 0) {
        cout << "Ошибка: деление на ноль в строке " << row + 1 << endl;
        return;
    }
    

    for (int j = 0; j < cols; j++) {
        mat[row][j] /= lead;
    }
}

void Gauss(float** mat, int rows, int cols) {

    cout << "Введите элементы матрицы (" << rows << " строки, " << cols << " столбца):" << endl;
    cout << "Формат: x1 x2 x3 ... и свободный член" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
            if (j == cols - 2) cout << "| ";
        }
        cout << endl;
    }
    cout << endl;

    int cur_col = 0;

    for (int cur_row = 0; cur_row < rows - 1; cur_row++) {

       
        if (mat[cur_row][cur_col] <= 0.0001) {
            cout << "На позиции [" << cur_row << "][" << cur_col << "] ноль, ищем замену..." << endl;
            int found = -1;
            for (int i = cur_row + 1; i < rows; i++) {
                if (mat[i][cur_col] != 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
              
                cout << "Меняем строку " << cur_row + 1 << " со строкой " << found + 1 << endl;
                for (int j = 0; j < cols; j++) {
                    float temp = mat[cur_row][j];
                    mat[cur_row][j] = mat[found][j];
                    mat[found][j] = temp;
                }
            }
            else {
                cout << "В столбце " << cur_col << " нет ненулевых элементов, пропускаем..." << endl;
                cur_col++;
                cur_row--;
                continue;
            }
        }


        DivRow(cur_row, cols, cur_col, mat);

        for (int next_row = cur_row + 1; next_row < rows; next_row++) {
            float mult = mat[next_row][cur_col];

          
            if (mult == 0) continue;
           

            for (int j = 0; j < cols; j++) {
                mat[next_row][j] -= mat[cur_row][j] * mult;
            }
        }
        cur_col++;
    }

    cout << "Матрица после прямого хода:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
            if (j == cols - 2) cout << "| ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows, cols;

    cout << "Введите количество строк (уравнений): ";
    cin >> rows;
    cout << "Введите количество столбцов (неизвестных + 1): ";
    cin >> cols;

    float** mat = new float* [rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new float[cols];
    }

    Gauss(mat, rows, cols);

    int rank_full = 0;
    for (int i = 0; i < rows; i++) {
        bool zero = true;
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                zero = false;
                break;
            }
        }
        if (!zero) rank_full++;
    }

    int rank = 0;
    for (int i = 0; i < rows; i++) {
        bool zero = true;
        for (int j = 0; j < cols - 1; j++) {
            if (mat[i][j] != 0) {
                zero = false;
                break;
            }
        }
        if (!zero) rank++;
    }

    cout << "Rank = " << rank << " Rank_full = " << rank_full << endl;

    float* sol = new float[rows];
    if (rank == rank_full && rank == cols - 1) {
        for (int i = rows - 1; i >= 0; i--) {
            sol[i] = mat[i][cols - 1];
            for (int j = i + 1; j < cols - 1; j++) {
                sol[i] -= mat[i][j] * sol[j];
            }
            if (mat[i][i] != 0) {
                sol[i] /= mat[i][i];
            }
        }

        cout << "\nРешение системы:" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "x" << i + 1 << " = " << sol[i] << endl;
        }
    }
    else {
        cout << "\nНет единственного решения" << endl;
        if (rank == rank_full && rank < cols - 1) {
            cout << "Система имеет бесконечно много решений" << endl;
        }
        else if (rank != rank_full) {
            cout << "Система несовместна (нет решений)" << endl;
        }
    }

    delete[] sol;
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}