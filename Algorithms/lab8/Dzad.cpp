#include <fstream>
#include <vector>
#include <iostream>
 
using namespace std;
 
void dfs(vector<vector<int>> &arr, int i, vector<int> &comps, int comp) {
    comps[i] = comp;
    for (auto j : arr[i]) {
        if (comps[j] == 0) {
            dfs(arr, j, comps, comp);
        }
    }
}
 
int main() {
    ifstream fin("components.in");
    ofstream fout("components.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    int f, k;
    for (int i = 0; i < m; i++) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
        arr[k - 1].push_back(f - 1);
    }
 
    vector<int> comps(n, 0);
    int comp = 0;
    for (int i = 0; i < n; i++) {
        if (comps[i] == 0) {
            dfs(arr, i, comps, ++comp);
        }
    }
 
    fout << comp << endl;
    for (int i = 0; i < n; i++) {
        fout << comps[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}