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


int minCostApples(int ind, vector<int> &prices, int quantity, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (quantity % (ind + 1) == 0 && prices[ind] != -1) {
            return prices[ind] * (quantity / (ind + 1));
        }
        return 1e9;
    }

    if (dp[ind][quantity] != -1) return dp[ind][quantity];

    int notTake = minCostApples(ind - 1, prices, quantity, dp);
    int take = INT_MAX;
    if (quantity >= (ind + 1) && prices[ind] != -1) {
        take = prices[ind] + minCostApples(ind, prices, quantity - (ind + 1), dp);
    }
    return dp[ind][quantity] = min(take, notTake);
}



void __DO__SOMETHING__() {
    int n, Fr;
    cin >> n >> Fr;
    vector<int> arr(Fr);
    cin >> arr;
    vector<vector<int>>dp(Fr+1, vector<int> (Fr+1, -1));
    int ans = minCostApples(Fr - 1, arr, Fr, dp);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}



int main() {
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

