#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream mat_out("adj_matrix.txt"), list_out("adj_list.txt"), edges_out("edges.txt");
    int n, u, v;
    in >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> adj_list(n);
    vector<pair<int, int>> edges;
    while (in >> u >> v) {
        mat[u][v] = 1;
        mat[v][u] = 1;
        if (u < v) edges.push_back({u, v});
    }
    for (const auto& row : mat) {
        for (int x : row) mat_out << x << " ";
        mat_out << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j]) adj_list[i].push_back(j);
        }
        for (int ng : adj_list[i]) list_out << ng << " ";
        list_out << endl;
    }
    for (const auto& e : edges) edges_out << e.first << " " << e.second << endl;
    return 0;
}