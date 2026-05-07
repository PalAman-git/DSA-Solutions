class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();

        int i=0,j=0;

        unordered_map<char,int> freq;
        for(int i=0;i<word2.length();i++){
            freq[word2[i]]++;
        }

        int distinctChar=freq.size();
        long long output = 0;

        while(j < n){
            if(freq[word1[j]] == 1) distinctChar--;
            freq[word1[j]]--;

            while(distinctChar == 0){

                output += n - j;

                freq[word1[i]]++;

                if(freq[word1[i]] == 1) distinctChar++;

                i++;
            }

            j++;
        }

        return output;
    }
};