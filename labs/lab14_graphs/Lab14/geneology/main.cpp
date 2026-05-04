#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Genelogy(int mat[13][13],int strok, vector<int> &povt, vector<int> &prosm){
    povt.push_back(strok);

   for(int i=0; i<13; i++){
        if(mat[strok][i] != 0 && find(povt.begin(), povt.end(), i) == povt.end()){
            cout << mat[strok][i] << " ";
            prosm.push_back(i);
            Genelogy(mat, i, povt, prosm);
        }
   }
}

int main(){
    int a, perv, vtoroe;
    cin >> a;
    int mat[13][13];

    for(int i = 0; i<13; i++){
        for(int j = 0; j<13; j++){
            mat[i][j] = 0;
        }
    }

    while(a){
        cin >> perv >> vtoroe ; 
        if(perv == -1 && vtoroe ==-1){
            break;
        }
        mat[perv][vtoroe] = vtoroe;
        mat[vtoroe][perv] = perv;
    }

    for(int i = 0; i<13; i++){
        for(int j = 0; j<13; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> prosm;
    int schet = 0;

    for(int i = 0; i<13; i++){
        if(find(prosm.begin(), prosm.end(), i) == prosm.end()){
            schet += 1;
            vector<int> povt;
            Genelogy(mat,i, povt, prosm);
            cout << i <<" - " ;
        }
        cout << endl ;
    } 
    cout << schet <<" semei";
}