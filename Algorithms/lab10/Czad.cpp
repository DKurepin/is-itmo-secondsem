#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
 
using namespace std;
 
struct Edges {
    int vert2;
    int vert3;
    int w;
};
 
int find(int vert1, vector<int> &p) {
    while (vert1 != p[vert1]) {
        vert1 = p[vert1];
    }
    return vert1;
}
 
bool check(int vert1, int vert2, vector<int> &p) {
    return find(vert1, p) == find(vert2, p);
}
 
void unite(int vert1, int vert2, vector<int> &p, vector<int> &s) {
    vert1 = find(vert1, p);
    vert2 = find(vert2, p);
    if (s[vert1] > s[vert2]) {
        swap(vert1, vert2);
    }
    s[vert2] += s[vert1];
    p[vert1] = vert2;
}
 
int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");
    int n, m;
    fin >> n >> m;
    vector<Edges> e;
    vector<int> s(n, 1);
    vector<int> p(n);
    long long res = 0;
 
    for (int i = 0; i < m; i++) {
        int a, b, w;
        fin >> a >> b >> w;
        e.emplace_back(Edges{--a, --b, w});
        e.emplace_back(Edges{b, a, w});
    }
    sort(e.begin(), e.end(), [](const Edges &left, const Edges &right) {
        return left.w < right.w;
    });
 
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
 
    for (auto edge: e) {
        if (!check(edge.vert2, edge.vert3, p)) {
            unite(edge.vert2, edge.vert3, p, s);
            res += edge.w;
        }
    }
    fout << res;
    fin.close();
    fout.close();
    return 0;
}