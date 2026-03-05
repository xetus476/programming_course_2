#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void Packing(int n, int* mass, int* pac_mass){
    int srav = 0;
    for(int i = 0; i < n; i++){
        if(mass[i] == srav){
            pac_mass[srav] +=1;
        }else{
            i -= 1;
            srav += 1;
        }
    }
    return ;
}

void UnPacking(int* pac_mass, int* unp_mass){
    int k = 0;
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < pac_mass[i]; j++){
            unp_mass[k] = i;
            k+=1;
        }
    }

    return ; 

}



int main() {
    int n;
    cin >> n;

    int* mass = new int[n]; 
    int pac_mass[18];
    int* unp_mass = new int[n]; 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 17);

    for (int i = 0; i < n; ++i) {
        mass[i] = distrib(gen);
    }

    for (int i = 0; i < n; ++i) {
        cout << mass[i] << " ";
    }
    cout << endl;
    sort(mass, mass + n);

    
    for (int i=0; i<n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    
    for(int i = 0 ; i<18 ; i++ ){
        pac_mass[i] = 0 ;
    }

    Packing(n, mass, pac_mass);

    for(int i = 0 ; i<18 ; i++ ){
        cout << pac_mass[i] <<" " ;
    }
    cout << endl;

    UnPacking(pac_mass, unp_mass);

    for(int i = 0; i < n; i++ ){
        cout << unp_mass[i] << " ";
    }

    delete[] mass;  
    mass = nullptr;

    delete[] pac_mass;  

    delete[] unp_mass;  
    unp_mass = nullptr;
    
    return 0;
}
