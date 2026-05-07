class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int i = 0, j = 0;
        int maxFreq = INT_MIN;

        unordered_map<char, int> freq;
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};