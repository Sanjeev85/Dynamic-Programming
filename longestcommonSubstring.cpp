#include <bits/stdc++.h>
using namespace std;
#define printArr(arr) cerr<<#arr<< " is \n"; for(auto i : arr) cerr<<i<<" ";cerr<<endl;
template<typename T>istream &operator>>(istream &in, vector<T> &a) {
    for(auto &i : a) in >> i;
    return in;
}
template<typename T>ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &i : a) out << i << " ";
    return out;
}



int longestCommonSubstring(int i, int j, string &s, string &t) {
    if (i == -1 or j == -1)
        return 0;

    if (s[i] == t[j]) {
        return 1 + longestCommonSubstring(i - 1, j - 1, s, t);
    } else {
        return max(longestCommonSubstring(i - 1, j, s, t),
                   longestCommonSubstring(i, j - 1, s, t));
    }
}





int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif


    map<int, int> mp;
    for (int i = 0; i < 5; i++){
        mp[i] = i;
    }

    for (auto it : mp) {
        if (it.second %2 == 0) {
            mp.erase(it.first);
        }
    }
    for (auto it : mp) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
