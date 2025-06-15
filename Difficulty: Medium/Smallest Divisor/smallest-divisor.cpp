class Solution {
  public:
  
  bool valid(vector<int>& arr , int mid , int k){
      int sum = 0;
      for(int i = 0; i<arr.size(); i++){
          sum += ceil((double)arr[i]/mid);
          if(sum > k){
              return false;
          }
      }
      return sum <= k;
  }
  
  
    int smallestDivisor(vector<int>& arr, int k) {
        int low    = 1;
        int high   = *max_element(arr.begin(), arr.end());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;  // mid candidate divisor

            if (valid(arr, mid, k)) {
                result = mid;            // mid works, record and try smaller
                high   = mid - 1;        // search left half
            } else {
                low = mid + 1;           // mid too small, search right half
            }
        }
        return result;
    }
};
