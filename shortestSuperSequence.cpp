#include <bits/stdc++.h>
using namespace std;

int dp[5][5];

int LCSM(int i, int j, string a, string b) {
    if (i == -1 or j == -1)
        return 0;

    if (a[i] == b[j])
        return dp[i][j] = 1 + LCSM(i - 1, j - 1, a, b);
    else
        return dp[i][j] = max(LCSM(i - 1, j, a, b), LCSM(i, j - 1, a, b));
}
// 4
// brute
// groot
// bleed
// blue
// coding
// ninjas
// blinding
// lights

string LCS(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= m; i++)
    	dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
    	dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (s[i-1] == t[j-1])
    			dp[i][j] = 1 + dp[i-1][j-1];
    		else
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    	}
    }


    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    // now make supersequence
    string ans = "";
    int i = n, j = m;
    while (i > 0 and j > 0) {
    	if (s[i-1] == t[j-1]) {
    		ans += s[i-1];
    		i--,j--;
    	}
    	else if (dp[i-1][j] > dp[i][j-1]) {
    		ans += s[i-1];
    		i--;
    	}
    	else {
    		ans += t[j-1];
    		j--;
    	}
    }
    while (i > 0)
    	ans += s[i-1], i--;
    while (j > 0)
    	ans += t[j-1], j--;
    reverse(ans.begin(), ans.end());
    
    return ans;
}



int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    string a, b;
    cin >> a >> b;
    cerr << a << " " << b << endl;
    int n = a.size(), m = b.size();
    cout<<LCS(a, b);

    return 0;
}