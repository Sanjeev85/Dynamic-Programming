#include <bits/stdc++.h>
using namespace std;

class subsetsWithGivenDiff {
public:
    int recursion(int ind, vector<int> &arr, int target) {
        if (ind == -1) {
            return target == 0;
        }
        int pick = 0;
        if (target >= arr[ind])
            pick = recursion(ind - 1, arr, target - arr[ind]);
        int notPick = recursion(ind - 1, arr, target);

        return pick + notPick;
    }
};



int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr) cin >> ele;
    int diff;
    cin >> diff;
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), sum);
    int tofind = (sum + diff) / 2;
    subsetsWithGivenDiff obj;
    cout << obj.recursion(n - 1, arr, tofind);
    return 0;
}



