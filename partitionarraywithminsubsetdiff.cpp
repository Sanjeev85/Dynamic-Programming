#include <bits/stdc++.h>
using namespace std;



class PARTITION_ARRAY_SUBSET_DIFF_MIN {
public:
    //same subset sum code for evaluating final result
    void BOTTOM_UP(vector<int> &arr) {
        int n = arr.size();
        int TARGET = 0;
        TARGET = accumulate(arr.begin(), arr.end(), TARGET);
        vector<vector<bool>> dp(n, vector<bool> (TARGET + 1, false));
        //base case
        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (arr[0] < TARGET) dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= TARGET; target++) {

                bool notPick = dp[ind - 1][target];
                bool pick = false;
                if (target >= arr[ind]) {
                    pick = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = pick | notPick;
            }
        }

        //now we have the last row as how many thigs we can form from this array
        vector<int> canFormSum, differenceSum;
        for (int target = 0; target <= TARGET; target++) {
            if (dp[n - 1][target])
                canFormSum.push_back(target);
        }
        for(int ele : canFormSum)
            differenceSum.push_back(TARGET - ele);
        int ans = INT_MAX;
        for (int i = 0 ; i < canFormSum.size(); i++) {
            ans = min(ans, abs(canFormSum[i] - differenceSum[i]));
        }
        cout << ans << endl;
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
    PARTITION_ARRAY_SUBSET_DIFF_MIN obj;
    obj.BOTTOM_UP(arr);


}