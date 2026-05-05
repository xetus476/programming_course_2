#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Puti(int mat[10][10],int strok, int& col_vo){
    int i = 1;
    for(int j = 0; j < 10; j++){
        if(mat[strok][j] == 9){
            col_vo++;
            //cout << col_vo;
            break; 
        }
        else if(mat[strok][j] != 0){
            Puti(mat, j, col_vo);
            i++;
        }
    }

    return col_vo;
}

int main(){
    int a, perv, vtoroe;
    cin >> a;
    int mat[10][10];

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

    int col_vo = 0;
    Puti(mat, 0, col_vo);

    cout <<"colichestvo putei = "<< col_vo;

    return 0;
}