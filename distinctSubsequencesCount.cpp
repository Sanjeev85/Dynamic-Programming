#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s, string &t,
      vector<vector<int>> &dp) {
    if (j == -1) return 1;
    if (i == -1) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j]) {
        dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    } else
        dp[i][j] = f (i - 1, j, s, t, dp);

    return dp[i][j];
}


int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n - 1, m - 1, s, t, dp);
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    cout << numDistinct(a, b);
    return 0;
}



