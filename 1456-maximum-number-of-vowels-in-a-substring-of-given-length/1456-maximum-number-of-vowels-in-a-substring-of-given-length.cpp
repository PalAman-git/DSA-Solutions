class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;

        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        
        int i=0,j=0;
        int vowelCount = 0;
        int maxVowel = 0;

        while(j<n){
            //insert jth element

            if(isVowel(s[j])){
                vowelCount++;
            }

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                //calculation
                maxVowel = max(maxVowel,vowelCount);

                //remove ith element
                if(isVowel(s[i])){
                    vowelCount--;
                }

                i++;
                j++;
            }
        }

        return maxVowel;
    }
};