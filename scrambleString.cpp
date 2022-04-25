#include <bits/stdc++.h>
using namespace std;


bool isScrambled(string s1, string s2, unordered_map<string, bool> &dp) {

    if (s1 == s2) return true;

    if (dp.find(s1 + "%" + s2) != dp.end()) return dp[s1 + "%" + s2];

    bool ans = false;
    for (int i = 1; i < s1.size(); i++) {
        int n = s1.size();
        //swap
        if (isScrambled(s1.substr(0, i), s2.substr(n - i), dp)
                and isScrambled(s1.substr(i), s2.substr(0, n - i), dp))
            ans = ans || true;
        //not swap
        if (isScrambled(s1.substr(0, i), s2.substr(0, i), dp)
                and isScrambled(s1.substr(i), s2.substr(i), dp))
            ans = ans || true;

    }
    return dp[s1 + "%" + s2] = ans;
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    unordered_map<string, bool> dp;
    cout << isScrambled(a, b, dp) << endl;

    return 0;
}



