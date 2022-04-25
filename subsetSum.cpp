#include <bits/stdc++.h>
using namespace std;


class SUBSET_SUM {
public:
    bool RECURSION(int target, vector<int> &arr, int ind) {
        if (target == 0) return true;
        if (ind == 0) return (arr[0] == target);

        bool pick = RECURSION(target, arr, ind - 1);
        bool notPick = false;
        if (target >= arr[ind]) {
            notPick = RECURSION(target - arr[ind], arr, ind - 1);
        }
        return pick | notPick;
    }
    bool MEMO(int target, vector<int> &arr, int ind, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (ind == 0) return (arr[0] == target);

        if (dp[ind][target] != -1) return dp[ind][target];

        bool pick = MEMO(target, arr, ind - 1, dp);
        bool notPick = false;
        if (target >= arr[ind]) {
            notPick = MEMO(target - arr[ind], arr, ind - 1, dp);
        }
        return dp[ind][target] = pick | notPick;
    }
    bool BOTTOM_UP(const int TARGET, vector<int> &arr) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(TARGET + 1, false));

        //base case
        for (int i = 0; i < n; i++) dp[i][0] = true; //1st column
        dp[0][arr[0]] = true; // 1st row

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= TARGET; target++) {
                bool pick = dp[ind - 1][target];
                bool notPick = false;
                if (target >= arr[ind])
                    notPick = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = pick | notPick;
            }
        }
        return dp[n - 1][TARGET];
    }
};



int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    int target;
    cin >> target;
    SUBSET_SUM subset;
    cout << subset.BOTTOM_UP(target, arr);



    return 0;
}