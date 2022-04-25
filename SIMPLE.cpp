#include <bits/stdc++.h>
using namespace std;

class FIB {
    int fib_Bottom_up(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int Fib(int n) {
        if (n == 0 || n == 1) return n;
        return Fib(n - 1) + Fib(n - 2);
    }
    int fib(int n, vector<int> &dp) {
        if (n == 0 || n == 1) return n;
        if (dp[n] != -1) return dp[n];

        int a = fib(n - 1, dp);
        int b = fib(n - 2, dp);
        dp[n] = a + b;
        return dp[n];
    }
};

class climbingSTAIRS {
    int climbingStairs(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        int a =  climbingStairs(n - 1);
        int b =  climbingStairs(n - 2);
        int c =  climbingStairs(n - 3);
        return a + b + c;
    }
    int climbingStairs(int n, vector<int> &dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        int a =  climbingStairs(n - 1, dp);
        int b =  climbingStairs(n - 2, dp);
        int c =  climbingStairs(n - 3, dp);
        return dp[n] = a + b + c;
    }
    int climbingStairsBottomUp(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i < 2) {
                dp[i] = dp[i - 1];
            } else if (i < 3) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
        }
        return dp[n];
    }
    int climbingStairsVariable(vector<int> &arr, int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= arr[i] && i + j <= n; j++) {
                dp[i] += min(dp[i], dp[i + j]);
            }
            if (dp[i] != INT_MAX)
                dp[i] ++ ;
        }
        return dp[0];
    }
};



class TARGET_SUM {
public:
    bool RECURSION(int target, int ind, vector<int> &arr) {
        if (ind == arr.size()) {
            if (target == 0)
                return true;
            else
                return false;
        }
        if (target == 0) return true;
        bool ans = false;
        if (target - arr[ind] >= 0) {
            ans |= RECURSION(target - arr[ind], ind + 1, arr);
        }
        ans |= RECURSION(target, ind + 1, arr);

        return ans;
    }
    bool MEMO(int target, int ind, vector<int> &arr, vector<vector<int>> &dp) {
        if (ind == arr.size()) {
            if (target == 0)
                return true;
            else
                return false;
        }
        if (target == 0) return true;
        bool ans = false;

        if(dp[ind][target] != -1) return dp[ind][target];

        if (target - arr[ind] >= 0) {
            ans |= MEMO(target - arr[ind], ind + 1, arr, dp);
        }
        ans |= MEMO(target, ind + 1, arr, dp);

        return dp[ind][target] = ans;
    }
};

bool BOTTOM_UP(int target, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= target; i++) {//for 1st row
        if (arr[0] == i) {
            dp[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][target];
}









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
    cerr << "target = " << target << endl;
    bool res = BOTTOM_UP(target, arr) ;
    if (res)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;


}