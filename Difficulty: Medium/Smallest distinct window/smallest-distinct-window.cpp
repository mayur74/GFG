//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>s;
        for(char c: str) s.insert(c);
        int len = s.size();
        int ans = INT_MAX;
        int i  =0 , j =0;
        unordered_map<char,int>mp;
        while(j<str.size()){
            mp[str[j]]++;
            if(mp.size()>=len){
                while(mp[str[i]]>1){
                    mp[str[i]]--;
                    i++;
                    
                }
                ans=min(ans , j-i+1);
                
            }
            j++;
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends