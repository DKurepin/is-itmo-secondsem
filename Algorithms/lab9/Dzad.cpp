#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<int> &order, vector<int> &visited, vector<vector<int>> &arr, stack<int> &stack, int w) {
    visited[v] = 1;
    for (int u : arr[v]) {
        if (!visited[u]) {
            dfs(u, order, visited, arr, stack, w);
            w++;
            order[u] = w;
            stack.push(u);
        }
    }
}

void reverse(int v, vector<vector<int>> &revArr, vector<int> &comps, int comp) {
    comps[v] = comp;
    for (int u : revArr[v]) {
        if (comps[u]  == 0) {
            reverse(u, revArr, comps, comp);
        }
    }
}

int main() {
    ifstream fin("cond.in");
    ofstream fout("cond.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> arr(n);
    vector<vector<int>> revArr(n);
    int f, k;
    for (int i = 0; i < m; ++i) {
        fin >> f >> k;
        arr[f - 1].push_back(k - 1);
        revArr[k - 1].push_back(f - 1);
    }

    vector<int> visited(n, 0);
    vector<int> order(n);
    vector<int> comps(n);
    stack<int> stack;

    int w = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (visited[i] == 0) {
            dfs(i, order, visited, arr, stack, w);
            w++;
            order[i] = w;
            stack.push(i);
        }
    }

    int comp = 1;
    int vert = 0;
    for (int i = 0; i < revArr.size(); ++i) {
        vert = stack.top();
        stack.pop();
        if (!comps[vert]) {
            reverse(vert, revArr, comps, comp);
            comp++;
        }
    }

    fout << comp - 1 << endl;
    for (int i : comps) {
        fout << i << " ";
    }
    fin.close();
    fout.close();
    return 0;
}