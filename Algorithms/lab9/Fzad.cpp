#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
void dfs(vector<vector<int>> &arr, vector<int> &res, int v) {
    for (int u: arr[v]) {
        if (res[u] == 0) {
            dfs(arr, res, u);
        }
    }
    for (int i: arr[v]) {
        res[v] = max(res[v], (res[i] + 1) % 2);
    }
}
 
int main() {
    ifstream fin("game.in");
    ofstream fout("game.out");
    int n, m, s;
    fin >> n >> m >> s;
    vector<vector<int>> arr(n);
    vector<int> res(n, 0);
    for (int i = 0; i < m; i++) {
        int f, k;
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
    }
    dfs(arr, res, s - 1);
    if (res[s - 1]) {
        fout << "First player wins";
    } else {
        fout << "Second player wins";
    }
    fin.close();
    fout.close();
    return 0;
}