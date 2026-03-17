#include <iostream>

using namespace std;

void Print(int n, int *mas){
    for(int i = 1; i<=n ; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
}

void Per(int k, int n,int *P, int *R){
    for(int i = 1; i <= n; i++){
        if(R[i] == 0){
            P[k] = i;
            R[i] = 1;
            if(k == n){
                Print(n, P);
            }else{
                Per(k+1, n, P, R);
            }
            R[i] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int R[n + 1];
    int P[n + 1];

    for(int i = 0; i<=n ; i++){
        R[i] = 0;
    }
    
    Per(1, n, P, R);
}

