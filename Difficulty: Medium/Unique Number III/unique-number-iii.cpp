//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int ele=0 , mask , ones;
        for(int i =0; i<32; i++){
            ones = 0;
            mask=(1<<i);
            for(int j=0; j<arr.size(); j++){
                if(arr[j]&mask) ones++;
                
            }
            if((ones%3)!=0) ele|=mask;
        }
        return ele;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends