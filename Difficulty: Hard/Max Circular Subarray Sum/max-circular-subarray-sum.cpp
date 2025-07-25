class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int totalSum = 0;
        int currMax = 0;
        int currMin = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        for(int i= 0; i<arr.size(); i++){
            totalSum += arr[i];
            currMin = min(currMin + arr[i] ,arr[i]);
            currMax = max(currMax + arr[i] , arr[i]);
            maxSum = max(maxSum , currMax);
            minSum = min(minSum , currMin);
        }
        return (maxSum > 0) ? max(maxSum , (totalSum  - minSum )) : maxSum;
    }
};