#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Puti(int mat[10][10]){

}

int main(){
    int a, perv, vtoroe;
    cin >> a;
    int mat[a][a];

    for(int i = 0; i<a; i++){
        for(int j = 0; j<a; j++){
            mat[i][j] = 0;
        }
    }

    while(a){
        cin >> perv >> vtoroe ; 
        if(perv == -1 && vtoroe ==-1){
            break;
        }
        mat[perv][vtoroe] = vtoroe;
    }

    for(int i = 0; i<a; i++){
        for(int j = 0; j<a; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for(int j = 0; j<a; j++ ){
        Puti(mat);
    }
}