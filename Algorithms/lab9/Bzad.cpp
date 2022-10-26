#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int &v, vector<vector<int>> &arr, vector<int> &path, vector<int> &visited, int &f, int &k) {
    visited[v] = 1;
    for (int i = 0; i < arr[v].size(); ++i) {
        int a = arr[v][i];
        if (visited[a] == 0) {
            path[a] = v;
            if (dfs(a, arr, path, visited, f, k)) {
                return true;
            }
        }
        else if (visited[a] == 1) {
            f = a;
            k = v;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
    }

    vector<int> path(n, -1);
    vector<int> visited(n);
    f = -1;

    for (int i = 0; i < n; i++) {
        if (dfs(i, arr, path, visited, f, k)) {
            break;
        }
    }
    if (f == -1) {
        fout << "NO";
    }
    else {
        vector<int> cycle;
        cycle.push_back(f);
        for (int i = k; i != f; i = path[i]) {
            cycle.push_back(i);
        }
        reverse(cycle.begin(), cycle.end());
        fout << "YES" << endl;
        for (int i : cycle) {
            fout << i + 1 << ' ';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
