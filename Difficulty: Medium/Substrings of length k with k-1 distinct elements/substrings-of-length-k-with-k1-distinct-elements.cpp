class Solution {
public:
    int substrCount(string& s, int k) {
        int n = s.length();

        vector<int> freq(26, 0);  // frequency array to store count of characters in current window
        int         distinct = 0; // number of distinct characters in current window
        int         result   = 0; // to store final count of valid substrings

        int i = 0;                // window start
        int j = 0;                // window end

        while (j < n) {
            if (freq[s[j] - 'a'] == 0) {
                distinct++;     // new character enters the window
            }
            freq[s[j] - 'a']++; // increment frequency of current character

            if (j - i + 1 > k) {
                // window size exceeded, shrink from left
                freq[s[i] - 'a']--; // remove character at position i
                if (freq[s[i] - 'a'] == 0) {
                    distinct--;     // character completely removed from window
                }
                i++;                // move window start
            }

            if (j - i + 1 == k) {
                // when window size is exactly k
                if (distinct == k - 1) {
                    result++; // valid substring
                }
            }

            j++; // expand window
        }
        return result;
    }
};