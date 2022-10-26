#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
float dist(int x0, int y0, int x1, int y1) {
    int fx = (x0 - x1) * (x0 - x1);
    int fy = (y0 - y1) * (y0 - y1);
    return sqrt(fx + fy);
}
 
int main() {
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
    int n;
    fin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        v.emplace_back(a, b);
    }
    vector<vector<float>> e(n, vector<float>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                e[i][j] = dist(v[i].first, v[i].second, v[j].first, v[j].second);
            } else {
                e[i][j] = 1e6;
            }
        }
    }
 
    v.clear();
    const float INF = 1e6;
    vector<float> dist(n, INF);
    vector<bool> used(n, false);
    dist[0] = 0;
    float ans = 0;
    for (int i = 0; i < n; ++i) {
        float md = INF;
        float u = 0;
        for (auto j = 0; j < n; ++j) {
            if (!used[j] && dist[j] < md) {
                md = dist[j];
                u = j;
            }
        }
        ans += md;
        used[u] = true;
        for (int v = 0; v < n; ++v) {
            dist[v] = min(dist[v], e[u][v]);
        }
    }
    fout << setprecision(10) << ans;
    fin.close();
    fout.close();
    return 0;
}