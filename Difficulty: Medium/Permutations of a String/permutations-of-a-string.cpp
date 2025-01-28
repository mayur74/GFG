//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> result;
        string current;
        vector<bool> used(s.size(), false);
        
        sort(s.begin() ,s.end());
        
        function<void()> backtrack = [&](){
            if(current.size() == s.size()){
                result.push_back(current);
                return;
                
            }
            for(int i = 0; i<s.size(); ++i){
                if(used[i]) continue;
                
                if(i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
                
                current.push_back(s[i]);
                used[i] = true;
                
                backtrack();
                
                current.pop_back();
                used[i] =false;
            }
        };
        backtrack();
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends