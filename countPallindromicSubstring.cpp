#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl;
template<typename T>istream &operator>>(istream &in, vector<T> &a) {
    for(auto &i : a) in >> i;
    return in;
}
template<typename T>ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &i : a) out << i << " ";
    return out;
}

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}


//using recursion without overlapping subproblems
int countPallindromes(int ind, string &s) {
    if (ind == s.size() - 1)
        return 1;

    int count = countPallindromes(ind + 1, s);

    for (int i = ind; i < ind + 1; i++) {
        for (int len = 1; len <= s.size() - i; len++) {
            if (isPalindrome(s.substr(i, len)))
                count++;
        }
    }
    return count;
}

//using expand around center technique
int expandAroundCenter(int ind, string &s) {
    int lt = ind, rt = ind;
    int n = s.size();
    int count = 0;
    //this will count all pal of odd length
    //take current ind as middle and expand towards left and right & check for pal
    while (lt > -1 && rt < n && s[lt--] == s[rt++])
        count++;

    //for even length
    lt = ind, rt = ind + 1;
    while (lt > -1 && rt < n && s[lt--] == s[rt++])
        count++;

    return count;
}

//DP approach
int countPalDynamic(string &s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool> (n, false));

    //row will represent start index and col will represent end index
    //base case length of str == 1
    int count = 0;
    for (int strLen = 0; strLen < dp.size(); strLen++) {
        for (int start = 0, end = strLen; end < dp.size(); start++, end++) {
            if (strLen == 0) // one length string
                dp[start][end] = true;
            else if (strLen == 1) {
                dp[start][end] = (s[start] == s[end]);
            } else { //length greater than 2
                dp[start][end] = (s[start] == s[end]) && dp[start + 1][end - 1];

            }
            if (dp[start][end])
                count++;
        }
    }

    cerr << "dp array\n";
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    return count;

}
















signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string a;
    cin >> a;
    cout << a << endl;
    cout << countPallindromes(0, a) << endl;
    int count1 = 0;
    for (int ind = 0; ind < a.size(); ind++)
        count1 += expandAroundCenter(ind, a);
    cout << count1 << endl;
    cout << "countpal dynamic\n";
    cout << countPalDynamic(a) << endl;
    return 0;
}



