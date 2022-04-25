
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

class Solution {
    vector<int> nextSmallerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> nextSmaller(n, n);
        //right boundary n so that right - left will lie inside range
        stack<int> st;
        st.push(0);

        for (int i = 1; i < n; i++) {
            if (arr[st.top()] < arr[i]) {
                st.push(i);
            } else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    nextSmaller[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return nextSmaller;
    }
    vector<int> prevSmallerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> prevSmaller(n, -1);
        stack<int> st;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[st.top()] < arr[i]) {
                st.push(i);
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) {
                    prevSmaller[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return prevSmaller;
    }
    int largetHistogram(vector<int> &arr) {
        int n = arr.size();
        vector<int> lb = prevSmallerElement(arr);
        vector<int> rb = nextSmallerElement(arr);
        int ans = 0;
        for (int i = 0 ; i < n; i++) {
            int width = rb[i] - lb[i] - 1;
            ans = max(ans, width * arr[i]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> currentRow;
        for (int i = 0; i < cols; i++)
            currentRow.push_back(matrix[0][i] - '0');

        int ans = largetHistogram(currentRow);

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    currentRow[j] += (matrix[i][j] - '0');
                } else
                    currentRow[j] = 0;
            }
            ans = max(ans, largetHistogram(currentRow));
        }
        return ans;
    }

};




signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    Solution obj;
    cout << obj.maximalRectangle(matrix) << "\n";

    return 0;
}



