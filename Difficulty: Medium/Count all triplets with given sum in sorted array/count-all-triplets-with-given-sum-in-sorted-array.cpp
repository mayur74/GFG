//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
         int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i) { 
            int j = i + 1, k = n - 1;    

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum == target) {
                    if (arr[j] == arr[k]) {
                        
                        int num_duplicates = k - j + 1;
                        count += (num_duplicates * (num_duplicates - 1)) / 2;
                        break; 
                    } else {
                        
                        int left_count = 1, right_count = 1;

                        while (j + 1 < k && arr[j] == arr[j + 1]) {
                            left_count++;
                            j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k - 1]) {
                            right_count++;
                            k--;
                        }

                        count += left_count * right_count;
                        j++;
                        k--;
                    }
                } else if (sum < target) {
                    j++; 
                } else {
                    k--; 
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends