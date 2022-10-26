#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
void dfs(int &v, vector<vector<int>> &arr, vector<int> &visited, vector<int> &res) {
    visited[v] = 1;
    for (int u: arr[v]) {
        if (visited[u] != 1) {
            dfs(u, arr, visited, res);
        }
    }
    res.push_back(v);
}
 
bool hamilton(vector<vector<int>> &arr, vector<int> &res) {
    for (int i = res.size() - 1; i > 0; i--) {
        int v = res[i];
        bool flag = true;
        for (int j : arr[v]) {
            if (j == res[i - 1]) {
                flag = false;
            }
        }
        if (flag) {
            return false;
        }
    }
    return true;
}
 
 
int main() {
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
    }
 
    vector<int> visited(n, 0);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (visited[i] != 1) {
            dfs(i, arr, visited, res);
        }
    }
    if (hamilton(arr, res)) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}