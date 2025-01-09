//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here4
        int s=0 , e = 0;
        
        int sum = 0;
        vector<int>ans;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum>=target){
                e = i;
                while(sum>target){
                    sum -= arr[s];
                    ++s;
                }
                if(sum == target){
                    ans.push_back(s+1);
                    ans.push_back(e+1);
                    return ans;
                }
            }
        }
        return{-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends