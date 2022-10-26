#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> prefixFunc(string &str) {
    int n = str.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = p[j - 1];
        }
        if (str[i] == str[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}
 
int main() {
    int n;
    string str;
    cin >> n >> str;
    str += "#";
    vector<int> prefix = prefixFunc(str);
    vector<vector<int>> res(str.size(), vector<int>(n));
    for (int i = 0; i < str.size(); i++) {
        for (char q = 'a'; q < 'a' + n; q++) {
            if (i > 0 and q != str[i]) {
                res[i][q - 'a'] = res[prefix[i - 1]][q - 'a'];
            } else {
                res[i][q - 'a'] = i + (q == str[i]);
            }
        }
    }
 
    for (auto i: res) {
        for (auto j: i)
            cout << j << " ";
    }
    return 0;
}