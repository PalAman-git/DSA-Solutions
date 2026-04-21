class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n = s.length();

        int l=0;
        int maxLen = 0;

        for(int r=0;r<n;r++){

            freq[s[r]]++;

            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
        }

        return maxLen;
    }
};