#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Genelogy(int mat[13][13],int strok, vector<int> &povt){
    povt.push_back(strok);

   for(int i=0; i<13; i++){
        if(mat[strok][i] != 0 && find(povt.begin(), povt.end(), i) == povt.end()){
            cout << mat[strok][i] << " ";
            //povt.push_back(mat[strok][i]);
            //povt.push_back(mat[strok][i]);
            Genelogy(mat, i, povt);
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


    for(int i = 0; i<13; i++){
        vector<int> povt;
                //povt.push_back(mat[i][j]);
                //povt.push_back(i);
        Genelogy(mat,i, povt);
        cout << i <<" - " ;
        //for(int k = 0; k < povt.size(); k++){
        //    cout << i <<" - "<<povt[k] <<" - " ;
        //}
        cout << endl ;
    } 
}