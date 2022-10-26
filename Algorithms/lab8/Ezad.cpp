#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
 
using namespace std;
 
    void bfs(vector<vector<int>> &arr, vector<int> &visited, queue<int> q) {
    visited[0] = 0;
    q.push(0);
    int a;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (int i = 0; i < arr[a].size(); i++)
            if (visited[arr[a][i]] == -1) {
                visited[arr[a][i]] = visited[a] + 1;
                q.push(arr[a][i]);
            }
    }
}
 
int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
        arr[k - 1].push_back(f - 1);
    }
 
    vector<int> visited(arr.size(), -1);
    queue<int> q;
    bfs(arr,visited,q);
    for (int i : visited) {
        fout << i << " ";
    }
    fin.close();
    fout.close();
    return 0;
}