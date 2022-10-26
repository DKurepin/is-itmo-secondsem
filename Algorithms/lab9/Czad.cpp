#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>> &arr, vector<int> &visited, int &mark) {
    for (auto i : arr[v]) {
        if (!visited[i]) {
            if (visited[v] == 1) {
                visited[i] = 2;
            } else {
                visited[i] = 1;
            }
            dfs(i, arr, visited, mark);
        }
        else if (visited[i] == visited[v]) {
            mark += 1;
        }
    }
}

int main() {
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
        arr[k - 1].push_back(f - 1);
    }

    int mark = 0;
    vector<int> visited(n);
    for (int i = 0; i < arr.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i, arr, visited, mark);
        }
    }
    if (mark == 0) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}
