#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define ll long long
template<typename T>istream &operator>>(istream &in, vector<T> &a) {
    for(auto &i : a) in >> i;
    return in;
}
template<typename T>ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &i : a) out << i << " ";
    return out;
}


vector<int> largestDivisibleSubset(vector<int> &arr) {
    int n = arr.size();
    sort(begin(arr), end(arr));
    vector<int> dp(n, 1), parent(n);
    int lastIndex = 0, currMax = 0;;


    for (int i = 0; i < n; i++) {
        parent[i] = i;
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                if (1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > currMax) {
            currMax = dp[i];
            lastIndex = i;
        }
    }

    vector<int> result;
    result.push_back(arr[lastIndex]);
    while (parent[lastIndex] != lastIndex) {
        lastIndex = parent[lastIndex];
        result.push_back(arr[lastIndex]);
    }
    reverse(result.begin(), result.end());
    return result;
}
void __DO__SOMETHING__() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    cout << largestDivisibleSubset(arr);
}



signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int T(1);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        __DO__SOMETHING__();
    }

    return 0;
}

