//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        unordered_map<int , int>prefixSumIndex;
        int prefixSum = 0 , maxlenght= 0;
        
        for(int i = 0; i<arr.size(); i++){
            prefixSum += arr[i];
            
            if(prefixSum == k){
                maxlenght = max(maxlenght , i+1);
            }
            
            if(prefixSumIndex.find(prefixSum - k) != prefixSumIndex.end()){
                maxlenght = max(maxlenght, i - prefixSumIndex[prefixSum - k]);
            }
            
            if(prefixSumIndex.find(prefixSum) == prefixSumIndex.end()){
                prefixSumIndex[prefixSum] = i;
            }
        }
        
        return maxlenght;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends