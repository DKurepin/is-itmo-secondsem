#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main() {
    ifstream fin("search2.in");
    ofstream fout("search2.out");
    string P;
    string T;
    fin >> P >> T;
    int pl = P.length();
    int tl = T.length();
    string s = P + "#" + T;
    int p[s.size()];
    p[0] = 0;
    int k;
    for (int i = 1; i < s.length(); ++i) {
        k = p[i - 1];
        while (k > 0 and s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        p[i] = k;
    }
    vector<int> res;
    int count = 0;
    for (int i = 0; i <= tl - 1; i++) {
        if (p[pl + i + 1] == pl) {
            res.push_back(i - pl + 2);
            count++;
        }
    }
 
    fout << count << endl;
    for (int re: res) {
        fout << re << " ";
    }
    fin.close();
    fout.close();
    return 0;
}