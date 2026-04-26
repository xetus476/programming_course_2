#include <iostream>
#include <vector>
using namespace std;

int main() {
    int col_versh, col_svyz;
    cin >> col_versh;
    int mat_smej[col_versh][col_versh];

    for(int i = 0; i <col_versh; i++){
        for(int j = 0; j <col_versh; j++){
            mat_smej[i][j] = 0;
        }

    }

    cin >> col_svyz;
    int chisl_1, chisl_2;
    for(int i = 0; i<col_svyz; i++){
        cin >> chisl_1 >> chisl_2;

        mat_smej[chisl_1 - 1][chisl_2 - 1] = 1;
        mat_smej[chisl_2 - 1][chisl_1 - 1] = 1;
    }

    for(int i = 0; i <col_versh; i++){
        for(int j = 0; j <col_versh; j++){
            cout << mat_smej[i][j]<< " ";
        }
        cout << endl;
    }


    cout << endl;

    vector<vector<int>> adj(col_versh);

    for(int i = 0; i <col_versh; i++){
        for(int j = 0; j <col_versh; j++){
            if(mat_smej[i][j] == 1){
                adj[i].push_back(j + 1);
            }
            
        }
    }

    for (int i = 0; i < col_versh; i++) {
        cout << i + 1 << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    vector<vector<int>> rebra(col_versh);
    for (int i = 0; i < col_versh; i++) {
        for (int v : adj[i]) {
            rebra[i].push_back(i + 1);
            rebra[i].push_back(v);
        }
        cout << endl;
    }

    int count = 0;

    for (int i = 0; i < col_versh; i++) {
        for (int v : rebra[i]) {
            cout << v << " ";

            count++;
            if(count%2 == 0){
                cout << endl;
                count = 0;
            }
        }
    }

    

    return 0;
}
