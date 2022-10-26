#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool dfs(int v, vector<int> &visited, vector<vector<int>> &arr, vector<int> &top) {
    visited[v] = 1;
    for (int i = 0; i < arr[v].size(); i++) {
        int a = arr[v][i];
        if (visited[a] == 0) {
            if (dfs(a, visited, arr, top)) {
                return true;
            }
        }
        else if (visited[a] == 1) {
            return true;
        }
    }
    visited[v] = 2;
    top.push_back(v);
    return false;
}

int main() {
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
    }

    vector<int> top;
    vector<int> visited(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        if (!visited[i]) {
            if (dfs(i, visited, arr, top)) {
                fout << -1 << ' ';
                return 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        fout << top[i] + 1 << ' ';
    }
    fin.close();
    fout.close();
    return 0;
}