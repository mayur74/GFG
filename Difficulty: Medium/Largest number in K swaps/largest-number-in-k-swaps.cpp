//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string maxNum;

    // Helper function to swap characters
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }

    void findMax(string &s, int k, int idx) {
        if (k == 0) return;

        int n = s.length();
        char maxChar = s[idx];

        // Find the maximum digit from current index to end
        for (int i = idx + 1; i < n; ++i) {
            if (s[i] > maxChar)
                maxChar = s[i];
        }

        // If current character is already max, no need to reduce k
        if (maxChar != s[idx]) k--;

        // Try all positions that have maxChar and are after idx
        for (int i = n - 1; i >= idx; --i) {
            if (s[i] == maxChar) {
                swap(s[i], s[idx]);
                if (s.compare(maxNum) > 0)
                    maxNum = s;
                findMax(s, k, idx + 1);
                swap(s[i], s[idx]); // backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        findMax(s, k, 0);
        return maxNum;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends