#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    int f, k;
    vector<int> arr(n, 0);
    for (int i = 0; i < m; ++i) {
        fin >> f >> k;
        arr[f-1]++;
        arr[k-1]++;
    }
    for (int i : arr) {
        fout << i << " ";
    }
    fin.close();
    fout.close();
    return 0;
}