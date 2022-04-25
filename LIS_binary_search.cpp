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

int Length_of_LIS(vector<int> &arr, int n) {
	vector<int> temp;
	temp.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > temp.back()) {
			temp.push_back(arr[i]);
		}
		else {
			int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - begin(temp);
			temp[ind] = arr[i];
		}
	}
	return temp.size();
}

//normal tabulation
int32_t lis(vector<int> &arr) {
	int n = arr.size();
	vector<int> LIS(n, 1);
	int result = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				LIS[i] = max(LIS[i], 1 + dp[j]);
			}
		}
		result = max(result, LIS[i]);
	}
	return result;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n; cin>>n;
    vector<int> arr(n); cin>>arr;
    cout<<lis(arr);
    return 0;
}



