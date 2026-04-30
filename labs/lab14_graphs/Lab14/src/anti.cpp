#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");          
    ofstream fout1("upr1.txt");      
    ofstream fout2("upr2.txt");         
    ofstream fout3("upr3.txt");       

    int col_versh, col_svyz;
    fin >> col_versh;

    int mat_smej[col_versh][col_versh];

    for(int i = 0; i < col_versh; i++){
        for(int j = 0; j < col_versh; j++){
            mat_smej[i][j] = 0;
        }
    }

    fin >> col_svyz;
    int chisl_1, chisl_2;

    for(int i = 0; i < col_svyz; i++){
        fin >> chisl_1 >> chisl_2;

        mat_smej[chisl_1 - 1][chisl_2 - 1] = 1;
        mat_smej[chisl_2 - 1][chisl_1 - 1] = 1;
    }

    for(int i = 0; i < col_versh; i++){
        for(int j = 0; j < col_versh; j++){
            fout1 << mat_smej[i][j] << " ";
        }
        fout1 << endl;
    }

    vector<vector<int>> adj(col_versh);

    for(int i = 0; i < col_versh; i++){
        for(int j = 0; j < col_versh; j++){
            if(mat_smej[i][j] == 1){
                adj[i].push_back(j + 1);
            }
        }
    }

    for (int i = 0; i < col_versh; i++) {
        fout2 << i + 1 << ": ";
        for (int v : adj[i]) {
            fout2 << v << " ";
        }
        fout2 << endl;
    }

    vector<vector<int>> rebra(col_versh);

    for (int i = 0; i < col_versh; i++) {
        for (int v : adj[i]) {
            rebra[i].push_back(i + 1);
            rebra[i].push_back(v);
        }
    }
    
    int count = 0;

    for (int i = 0; i < col_versh; i++) {
        for (int v : rebra[i]) {
            fout3 << v << " ";
            count++;

            if(count % 2 == 0){
                fout3 << endl;
                count = 0;
            }
        }
    }

    fin.close();
    fout1.close();
    fout2.close();
    fout3.close();

    return 0;
}