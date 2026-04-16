#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const float EPS = 1e-7;

void Gaus(float** a, int rows, int cols) {
    int lead = 0;

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) return;

        int i = r;

        while (fabs(a[i][lead]) < EPS) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) return;
            }
        }

        for (int j = 0; j < cols; j++) {
            swap(a[r][j], a[i][j]);
        }

        float div = a[r][lead];
        for (int j = 0; j < cols; j++) {
            a[r][j] /= div;
        }

        for (int k = 0; k < rows; k++) {
            if (k != r) {
                float factor = a[k][lead];
                for (int j = 0; j < cols; j++) {
                    a[k][j] -= factor * a[r][j];
                }
            }
        }

        lead++;
    }
}

void printMatrix(float** a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ofstream fout("data.txt");

    int rows, cols;
    cin >> rows >> cols;

    cols++; 

    float** matrix = new float*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new float[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    fout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << endl;
    fout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << endl;

    Gaus(matrix, rows, cols);

    cout << "Po Gausu:\n";
    printMatrix(matrix, rows, cols);

    int n = cols - 1;

    for (int i = 0; i < rows; i++) {
        bool all_zero = true;
        for (int j = 0; j < n; j++) {
            if (fabs(matrix[i][j]) > EPS) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && fabs(matrix[i][n]) > EPS) {
            cout << "Net Resh\n";
            return 0;
        }
    }

    bool* vedush = new bool[n]{0};
    int rank = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            if (fabs(matrix[i][j]) > EPS) {
                vedush[j] = true;
                rank++;
                break;
            }
        }
    }

    if (rank == n) {
        cout << "Edinstv:\n";
        for (int i = 0; i < n; i++) {
            cout << "x" << i+1 << " = " << matrix[i][n] << endl;
        }
    } else {
        cout << "Mnojestvoo resh\n";

        for (int i = 0; i < n; i++) {
            if (!vedush[i]) {
                cout << "x" << i+1 << " - free" << endl;
            }
        }

        for (int i = 0; i < rows; i++) {
            int lead = -1;

            for (int j = 0; j < n; j++) {
                if (fabs(matrix[i][j]) > EPS) {
                    lead = j;
                    break;
                }
            }

            if (lead == -1) continue;

            cout << "x" << lead+1 << " = " << matrix[i][n];

            for (int j = 0; j < n; j++) {
                if (!vedush[j]) {
                    cout << "-" << matrix[i][j] << "*x" << j+1;
                }
            }

            cout << endl;
        }
    }
    
    fout << matrix[0][n] << " " << matrix[1][n] << endl;

    fout.close();
    system("python plot.py");

    delete[] vedush;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}