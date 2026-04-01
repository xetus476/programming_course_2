#include <iostream>
#include <random>
using namespace std;

void Del(int n, int m, int count, float** ukaz){
    float koef = ukaz[n][count];
    for(int j = 0; j < m; j++){
        if(abs(koef) != 0){
            ukaz[n][j] /= koef;
        }
    }
}

void ProcessMatrix(float** matrix, int rows, int cols) {
    random_device rd;                
    mt19937 gen(rd());               
    uniform_int_distribution<> dist(1, 10); 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = dist(gen); 
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    cout << endl;  

    int count = 0;

    for(int i = 0; i < rows - 1; i++){
        Del(i, cols, count, matrix);

        for(int k = i + 1; k < rows; k++){
            float umnoz = matrix[k][count];
            for(int l = 0; l < cols; l++){
                matrix[k][l] -= matrix[i][l] * umnoz;
            }
        }
        count++;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    float** matrix = new float*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new float[cols];
    }

    ProcessMatrix(matrix, rows, cols);
    int rank_rash = 0;

    for(int i = 0; i < rows; i++){
        bool allZero = true;

        for(int j = 0; j < cols; j++){
            if (abs(matrix[i][j]) != 0 ){ 
                allZero = false;
                break;
            }
        }

        if (!allZero) rank_rash++;
    }

    int rank = 0;

    for(int i = 0; i < rows; i++){
        bool allZero = true;

        for(int j = 0; j < cols - 1; j++){
            if (abs(matrix[i][j]) != 0 ){ 
                allZero = false;
                break;
            }
        }

        if (!allZero) rank++;
    }

    cout << "Rank = " << rank <<" Rank_rash = " << rank_rash<< endl;

    float mat_resh[cols-1];  
    if (rank == rank_rash && rank == cols- 1){
        for(int i= rows - 1 ; i>=0; i-=1){
            mat_resh[i] = matrix[i][cols - 1]; 

            for(int j = i + 1; j < cols - 1; j++){
                mat_resh[i] -= matrix[i][j] * mat_resh[j];
            }

            mat_resh[i] /= matrix[i][i];
        }

        for(int i = 0; i < rows; i++){
            cout << "x" << i+1 << " = " << mat_resh[i] << endl;
        }
    }
    else{
        cout <<" No solve";
    } 

    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}