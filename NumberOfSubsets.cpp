#include <bits/stdc++.h>
using namespace std;


class NUMBER_OF_SUBSETS {
public:
    int recursion(int ind, int target, vector<int> &arr) {
        if (ind == -1) {
            if (target == 0)
                return 1;
            return 0;
        }

        int pick = 0;
        if (arr[ind] <= target)
            pick = recursion(ind - 1, target - arr[ind], arr);
        int32_t notPick = recursion(ind - 1, target, arr);

        return pick + notPick;
    }
    int memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
        // if (ind == -1) {
        //     if (target == 0)
        //         return 1;
        //     return 0;
        // }
        //or
        if (target == 0) return 1;
        if (ind == 0) {
            return target == arr[0];
        }
        if (dp[ind][target] != -1) return dp[ind][target];
        int pick = 0;
        if (arr[ind] <= target)
            pick = memo(ind - 1, target - arr[ind], arr, dp);
        int32_t notPick = memo(ind - 1, target, arr, dp);

        return dp[ind][target] = pick + notPick;
    }

    int bottom_up(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<pair<int, int>, int> dp;

        //base case
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        dp[0][arr[0]] = 1;

        for (int  ind = 1; ind < n; ind++) {
            for (int tg = 1 ; tg <= target; tg++) {
                int pick = 0;
                if (arr[ind] <= tg)
                    pick = dp[ind - 1][tg - arr[ind]];
                int32_t notPick = dp[ind - 1][tg];;

                dp[ind][tg] = pick + notPick;
            }
        }
        return dp[n-1][target];
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
    NUMBER_OF_SUBSETS subset;
    cout << subset.bottom_up(arr, target);



    return 0;
}