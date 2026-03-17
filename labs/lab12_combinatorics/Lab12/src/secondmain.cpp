#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;

vector<int> S(MAX_N + 1, 0);
vector<int> Q(MAX_N + 1, 0);
vector<int> R(2 * MAX_N + 1, 0);
vector<int> L(2 * MAX_N + 1, 0);

int solution_count = 0;

void print_solution(int n) {
    cout << "Rastanvka " << ++solution_count << ": (";
    for (int j = 1; j <= n; j++) {
        cout << Q[j];
        if (j < n) cout << ", ";
    }
    cout << ")" << endl;
}

void Queen(int j, int n) {
    for (int i = 1; i <= n; i++) {
        if (S[i] == 0 && R[j - i + n] == 0 && L[j + i] == 0) {
            S[i] = 1;
            R[j - i + n] = 1;
            L[j + i] = 1;
            Q[j] = i;
            
            if (j == n) {
                print_solution(n);
            } else {
                Queen(j + 1, n);
            }
            
            S[i] = 0;
            R[j - i + n] = 0;
            L[j + i] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Vvedite n";
    cin >> n;
    
    for (int i = 1; i <= n; i++) S[i] = 0;
    for (int i = 1 - n; i <= n - 1; i++) R[i + n] = 0;
    for (int i = 2; i <= 2 * n; i++) L[i] = 0;
    
    solution_count = 0;
    Queen(1, n);
    
    cout << "Vsego resh: " << solution_count << endl;
    
    return 0;
}