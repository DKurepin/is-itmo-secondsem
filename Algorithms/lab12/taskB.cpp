#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    vector<int> arr;
    int n;
    cin >> n;
    int u;
    for (int i = 0; i < n; i++) {
        cin >> u;
        arr.push_back(u);
    }
 
    vector<int> prev(n + 1);
    vector<int> pos(n + 1);
    vector<int> d(n + 1);
 
    pos[0] = -1;
    d[0] = INT_MIN;
    int length = 0;
 
    for (int i = 1; i < d.size(); i++) {
        d[i] = INT_MAX;
    }
 
    for (int i = 0; i < n; ++i) {
        auto a = lower_bound(d.begin(), d.end(), arr[i]);
        int j = a - d.begin();
        if (d[j - 1] < arr[i] && arr[i] < d[j]) {
            d[j] = arr[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            if (length < j) {
                length = j;
            }
        }
    }
 
    vector<int> res;
    int p = pos[length];
    while (p != -1) {
        res.push_back(arr[p]);
        p = prev[p];
    }
    reverse(res.begin(), res.end());
 
    cout << res.size() << endl;
    for (auto i: res) {
        cout << i << " ";
    }
    return 0;
}