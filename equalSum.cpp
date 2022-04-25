#include <bits/stdc++.h>
using namespace std;

class EQUAL_SUM_PARTITION {
public:
    bool RECURSION(vector<int> &ARR, int TARGET, int IND) {
        if (TARGET == 0) return true;
        if (IND == 0) return (ARR[0] == TARGET);

        bool notPick = RECURSION(ARR, TARGET, IND - 1);
        bool pick = false;
        if (ARR[IND] <= TARGET)
            pick = RECURSION(ARR, TARGET - ARR[IND], IND - 1);

        return pick | notPick;
    }
    bool MEMO(vector<int> &ARR, int TARGET, int IND, vector<vector<int>> &DP) {
        if (TARGET == 0) return true;
        if (IND == 0) return (ARR[0] == TARGET);

        if (DP[IND][TARGET] != -1) return DP[IND][TARGET];
        bool notPick = MEMO(ARR, TARGET, IND - 1, DP);
        bool pick = false;
        if (ARR[IND] <= TARGET)
            pick = MEMO(ARR, TARGET - ARR[IND], IND - 1, DP);

        return DP[IND][TARGET] = pick | notPick;
    }
    bool BOTTOM_UP(vector<int> &arr) {
    	int n = arr.size();
        int target = 0;
        target = accumulate(arr.begin(), arr.end(), target);
        if (target%2 != 0) return false;
        target /= 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;

    	for (int ind = 1; ind < n; ind++) {
    		for (int targ = 1; targ <= target; targ++) {
    			bool notPick = dp[ind-1][targ];
    			bool pick = false;
    			if (targ >= arr[ind])
    				pick = dp[ind-1][targ - arr[ind]];

    			dp[ind][targ] = pick | notPick;
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
 	EQUAL_SUM_PARTITION obj;
    int sum = accumulate(arr.begin(), arr.end(), sum);
    sum /= 2;
    cerr<<sum<<endl;
 	cout<<obj.RECURSION(arr, sum, n-1)<<endl;
    return 0;
}