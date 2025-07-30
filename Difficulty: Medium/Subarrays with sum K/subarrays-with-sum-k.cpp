class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumFreq;
        int sum = 0, count = 0;
        
        // Initialize map with 0 sum to handle case where subarray starts from index 0
        prefixSumFreq[0] = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // Check if there is a prefix subarray we can subtract to get sum = k
            if(prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }
            
            // Store/update current sum frequency
            prefixSumFreq[sum]++;
        }
        
        return count;
    }
};
