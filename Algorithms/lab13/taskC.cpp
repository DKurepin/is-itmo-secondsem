#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
//    ifstream fin("prefix.in");
//    ofstream fout("prefix.out");
    string str;
    cin >> str;
    int p[str.size()];
    int k;
    p[0] = 0;
    for (int i = 1; i < str.size(); i++) {
        k = p[i - 1];
        while (k > 0 and str[i] != str[k]) {
            k = p[k - 1];
        }
        if (str[i] == str[k]) {
            k += 1;
        }
        p[i] = k;
    }
    for (int i = 0; i < str.size(); i++) {
        cout << p[i] << " ";
    }
//
//    fin.close();
//    fout.close();
    return 0;
}