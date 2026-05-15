class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();

        int ans = 0;

        unordered_map<char, int> freq;
        for (auto c : text) {
            freq[c]++;
        }

        for (int ch = 'a'; ch <= 'z'; ch++) {
            int i = 0,j=0;
            int diff = 0;

            while(j<n){
                //add the jth element
                if(text[j] != ch) diff++;

                while(diff > 1){
                    if(text[i] != ch){
                        diff--;
                    }
                    i++;
                }

                ans = max(ans,min(j-i+1,freq[ch]));
                j++;
            }
        }

        return ans;
    }
};