//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n); // Previous and next smaller elements

        stack<int> st;

        // Finding previous smaller elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        // Clear the stack for next smaller computation
        while (!st.empty()) st.pop();

        // Finding next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        // Array to store max of mins for each window size
        vector<int> ans(n + 1, INT_MIN);

        // Compute max of mins for each window size
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1; // Length of the window where arr[i] is min
            ans[windowSize] = max(ans[windowSize], arr[i]);
        }

        // Fill the array from right to left
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Remove the extra element at index 0 and return the result
        return vector<int>(ans.begin() + 1, ans.end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends