#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    char mass_c[20][11];
    string stroki[20];

    int n;
    cout << "Введите количество строк (не более 20): ";
    cin >> n;

    for(int i=0; i<n ; i++){
        cin >>mass_c[i];
    }

    for(int i = 0; i<n;i++){
        cin >> stroki[i];
    }

    for(int i=1; i<n ; i+=2){
        cout <<"Масив строк =" <<mass_c[i] << endl;
    }
    cout <<"\n";

    for(int i=1; i<n ; i+=2){
        cout <<"строки c++ =" <<stroki[i] << endl;
    }
}