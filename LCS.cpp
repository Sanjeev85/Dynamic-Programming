#include <bits/stdc++.h>
using namespace std;
template<typename T>istream &operator>>(istream &in, vector<T> &a) {
    for(auto &i : a) in >> i;
    return in;
}
template<typename T>ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &i : a) out << i << " ";
    return out;
}



string printLCS(string &text1, string &text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];//lcs length
    string ans = "";
    for (int i = 0; i < len; i++) {
        ans += '%';
    }

    int i = n, j = m;
    int index = len - 1;
    while (i > 0 and j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            ans[index] = text1[i - 1];
            index--;
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }

    return ans;
}








int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    int n1 = a.length(), n2 = b.length();
    string t;
    cout << printLCS(a, b);
    return 0;
}



