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


int minCoins(int ind, int target, vector<int> &arr) {
    if (ind == 0) {
        if (target % arr[0] == 0) return target / arr[0];
        return 1e9;
    }


    int pick = INT_MAX;
    if(target >= arr[ind]) {
        pick = 1 + minCoins(ind, target - arr[ind], arr);
    }
    int notPick = minCoins(ind - 1, target, arr);

    return min(notPick, pick);
}





int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int>arr(n);
    cin >> arr;
    cout << minCoins(n - 1, target, arr);
    return 0;
}



